#!/usr/bin/perl -w
#-
# Copyright (c) 2000 Dag-Erling Coïdan Smørgrav
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer
#    in this position and unchanged.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
# 3. The name of the author may not be used to endorse or promote products
#    derived from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
# IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
# OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
# IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
# NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
# THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
#      $FreeBSD$
#

use strict;
use Data::Dumper;
use Fcntl;
use Getopt::Long;

my $VERSION	= "1.6";

# Constants
sub ANONCVS_ROOT	{ ":pserver:anoncvs\@anoncvs.FreeBSD.org:/home/ncvs" }
sub REQ_EXPLICIT	{ 1 }
sub REQ_IMPLICIT	{ 2 }

# Global parameters
my $cvs	      = "/usr/bin/cvs"; # CVS command
my $dbdir     = "/var/db/pkg";	# Package database directory
my $index     = undef;		# Index file
my $portsdir  = "/usr/ports";	# Ports directory
my $tag	      = undef;		# cvs tag to use
my $date      = undef;		# cvs date to use

# Global flags
my $anoncvs   = 0;		# Use anoncvs.FreeBSD.org
my $clean     = 0;		# Clean ports
my $cvsroot   = 0;		# CVS root directory
my $exclude   = 0;		# Do not list installed ports
my $fetch     = 0;		# Fetch ports
my $help      = 0;		# Show help text
my $info      = 0;		# Show port info
my $packages  = 0;		# Build packages
my $list      = 0;		# List ports
my $build     = 0;		# Build ports
my $update    = 0;		# Update ports tree from CVS
my $verbose   = 0;		# Verbose mode
my $version   = 0;		# Show version
my $ecks      = 0;		# The undocumented option.

# Global variables
my %ports;			# Maps ports to their directory.
my %strop;			# Inverse of the above map
my %dependencies;		# Maps ports to their dependency lists.
my %reqd;			# Ports that need to be installed

#
# Shortcut for 'print STDERR'
#
sub stderr(@) {
    print(STDERR @_);
}

#
# Similar to err(3)
#
sub err($$@) {
    my $code = shift;		# Return code
    my $fmt = shift;		# Format string
    my @args = @_;		# Arguments

    my $msg;			# Error message

    $msg = sprintf($fmt, @args);
    stderr("$msg: $!\n");
    exit($code);
}

#
# Similar to errx(3)
#
sub errx($$@) {
    my $code = shift;		# Return code
    my $fmt = shift;		# Format string
    my @args = @_;		# Arguments

    my $msg;			# Error message

    $msg = sprintf($fmt, @args);
    stderr("$msg\n");
    exit($code);
}

#
# Print an info message
#
sub info($) {
    if ($verbose) {
	chomp($_[0]);
	stderr(">>> $_[0]\n");
    }
}

#
# Change working directory
#
sub cd($) {
    my $dir = shift;		# Directory to change to

    info("cd $dir");
    chdir($dir)
	or err(1, "unable to chdir to %s", $dir);
}

#
# Run a command using system()
#
sub cmd(@) {
    
    info(join(" ", @_));
    return (system(@_) == 0);
}

#
# Run CVS
#
sub cvs($;@) {
    my $cmd = shift;		# CVS command

    my @args;			# Arguments to CVS

    push(@args, "-f", "-z3", "-R",
	 $verbose ? "-q" : "-Q", $cmd, "-A");
    if ($cmd eq "checkout") {
	push(@args, "-P");
    } elsif ($cmd eq "update") {
	push(@args, "-P", "-d");
    }
    if ($tag) {
	push(@args, "-r$tag");
    }
    if ($date) {
	push(@args, "-D$date");
    }
    push(@args, @_);
    return cmd($cvs, @args);
}

#
# Run make
#
sub make($@) {
    my $port = shift;		# Port category/name
    my @args = @_;
    
    push(@args, "PORTSDIR=$portsdir")
	unless ($portsdir eq "/usr/ports");
    cd("$portsdir/$ports{$port}");
    cmd("make", @args);
}

#
# The undocumented command.
#
sub ecks() {

    local *FILE;		# File handle

    sysopen(FILE, "/var/db/port.mkversion", O_RDWR|O_CREAT|O_TRUNC, 0644)
	or err(1, "open()");
    print(FILE "20380119\n");
    close(FILE);
}

#
# Update the index file
#
sub update_index() {
    
    my $parent;		# Parent directory

    $parent = $portsdir;
    $parent =~ s/\/*ports\/*$//;
    cd($parent);
    if (-f "ports/INDEX" || (-d "ports" && -d "ports/CVS")) {
	cvs("update", "ports/INDEX")
	    or errx(1, "error updating the index file");
    } else {
	cvs("checkout", "-l", "ports")
	    or errx(1, "error checking out the index file");
    }
    cvs("update", "-l", "ports/Mk")
	or errx(1, "error updating the Makefiles");
}

#
# Read the ports index
#
sub read_index() {

    local *INDEX;		# File handle
    my $line;			# Line from file

    sysopen(INDEX, $index, O_RDONLY)
	or err(1, "can't open $index");
    while ($line = <INDEX>) {
	my @port;		# Port info
	my @depend;		# Dependencies

	@port = split(/\|/, $line);
	$port[1] =~ s|^/usr/ports/*||;
	$ports{$port[0]} = $port[1];
	$strop{$port[1]} = $port[0];
	@depend = split(' ', "$port[7] $port[8]");
	$dependencies{$port[0]} = \@depend;
    }
    close(INDEX);
    info(keys(%ports) . " ports in index");
}

#
# Add a port to the list of required ports
#
sub add_port($$);		# Prototype to silence warning
sub add_port($$) {
    my $port = shift;		# Port to add
    my $req = shift;		# Requirement (explicit or implicit)

    my $err = 0;		# Error count

    if (exists($reqd{$port})) {
	$reqd{$port} |= $req;
	return 0;
    }
    if (!exists($ports{$port})) {
	my @suggest;		# Suggestions
	
	stderr("can't find required port '$port'");
	@suggest = grep(/^$port/i, keys(%ports));
	if (@suggest == 1 && $suggest[0] =~ m/^$port[0-9.-]/) {
	    $port = shift(@suggest);
	    stderr(", assuming you mean '$port'.\n");
	} elsif (@suggest) {
	    stderr(", maybe you mean:\n  " . (join("\n  ", @suggest)) . "\n");
	    return 1;
	} else {
	    stderr("\n");
	    return 1;
	}
    }
    $reqd{$port} = $req;
    foreach $port (@{$dependencies{$port}}) {
	$err += add_port($port, &REQ_IMPLICIT);
    }
    return $err;
}

#
# Find master directory for a port
#
sub find_master($$) {
    my $category = shift;	# Category
    my $port = shift;		# Port

    local *FILE;		# File handle
    my $master;			# Master directory

    open(FILE, "$portsdir/$category/$port/Makefile")
	or err(1, "unable to read Makefile for $category/$port");
    while (<FILE>) {
	if (/^MASTERDIR\s*=\s*(\S+)\s*$/) {
	    $master = $1;
	    $master =~ s/^\$\{.CURDIR\}//;
	    $master = "/$category/$port/$master";
	    $master =~ s|/+|/|g;
	    1 while ($master =~ s|/[^\./]*/\.\./|/|);
	    $master =~ s|^/||;
	    close(FILE);
	    return $master;
	}
    }
    close(FILE);
    return undef;
}

#
# Update all necessary files to build the specified ports
#
sub update_ports_tree(@) {
    my @ports = @_;		# Ports to update
    
    my $port;			# Port name
    my $category;		# Category name
    my %updated;		# Hash of updated ports
    my %additional;		# Additional dependencies
    my $todo;			# Have something to do

    foreach $port (@ports) {
	$additional{$ports{$port}} = 1;
    }
    for (;;) {
	my %update_now;		# Ports that need updating now
	my $master;		# Master port
	
	foreach $port (keys(%additional)) {
	    ($category, $port) = split(/\//, $port);
	    if (!$updated{$category}->{$port}) {
		$update_now{$category}->{$port} = 1;
		$updated{$category}->{$port} = 1;
	    }
	}
	last unless keys(%update_now);
	cd($portsdir);
	cvs("update", "-l", keys(%update_now))
	    or errx(1, "error updating the category directories");
	foreach $category (keys(%update_now)) {
	    cd("$portsdir/$category");
	    cvs("update", keys(%{$update_now{$category}}))
		or errx(1, "error updating the '$category' category");
	}
	foreach $category (keys(%update_now)) {
	    foreach $port (keys(%{$update_now{$category}})) {
		if ($master = find_master($category, $port)) {
		    $additional{$master} = 1;
		}
	    }
	}
    }
}

#
# Show port info
#
sub show_port_info($) {
    my $port = shift;		# Port to show info for

    local *FILE;		# File handle
    my $info;			# Port info

    sysopen(FILE, "$portsdir/$ports{$port}/pkg/DESCR", O_RDONLY)
	or err(1, "can't read description for $port");
    $info = join("| ", <FILE>);
    close(FILE);
    print("+--- $port:\n| ${info}+---\n");
}

#
# List installed ports
#
sub list_installed() {

    local *DIR;			# Directory handle
    my $port;			# Port name
    my $unknown;		# Unknown ports

    opendir(DIR, $dbdir)
	or err(1, "can't read database directory");
    print("Installed ports:\n");
    foreach $port (readdir(DIR)) {
	next if ($port eq "." || $port eq ".." || ! -d "$dbdir/$port");
	if (exists($ports{$port})) {
	    print("   $port\n");
	} else {
	    print(" ? $port\n");
	    ++$unknown;
	}
    }
    if ($unknown) {
	print("Recommend you run pkg_version(1).\n");
    }
}

#
# Clean a port
#
sub clean_port($) {
    my $port = shift;		# Port to clean

    make($port, "clean");
}

#
# Clean the tree
#
sub clean_tree() {

    my $port;			# Port name
    
    # We could just cd to $portsdir and 'make clean', but it'd
    # be extremely noisy due to only having a partial tree
    #errx(1, Dumper(\%strop));
    foreach $port (keys(%ports)) {
	if (-d "$portsdir/$ports{$port}") {
	    make($port, "clean", "NO_DEPENDS=yes");
	}
    }
}

#
# Fetch a port
#
sub fetch_port($) {
    my $port = shift;		# Port to fetch

    make($port, "fetch");
}

#
# Build a port
#
sub build_port($) {
    my $port = shift;		# Port to build

    make($port, 
	 $packages ? ("package", "DEPENDS_TARGET=package") : "install",
	 "clean");
}

#
# Print usage message and exit
#
sub usage() {

    stderr("Usage: porteasy [-abcefhikluVv] [-d dir] [-D date]\n" .
	   "    [-p dir] [-r dir] [-t tag] [port ...]\n");
    exit(1);
}

#
# Print version
#
sub version() {
    
    stderr("porteasy $VERSION\n");
    exit(1);
}

#
# Print help text
#
sub help() {
    
    stderr("porteasy $VERSION

Options:
  -a, --anoncvs            Use the FreeBSD project's anoncvs server
  -b, --build              Build required ports
  -c, --clean              Clean the specified ports
  -e, --exclude-installed  Exclude installed ports
  -f, --fetch              Fetch distfiles
  -h, --help               Show this information
  -i, --info               Show info about specified ports
  -k, --packages           Build packages for the specified ports
  -l, --list               List required ports and their dependencies
  -u, --update             Update relevant portions of the ports tree
  -V, --version	           Show version number
  -v, --verbose            Verbose mode

Parameters:
  -D, --date=DATE          Specify CVS date
  -d, --dbdir=DIR          Specify package directory (default $dbdir)
  -p, --portsdir=DIR       Specify ports directory (default $portsdir)
  -r, --cvsroot=DIR        Specify CVS root
  -t, --tag=TAG            Specify CVS tag

Report bugs to <des\@freebsd.org>.
");
    exit(1);
}

MAIN:{
    my $port;			# Port name
    my $err = 0;		# Error count

    # Scan command line options
    Getopt::Long::Configure("auto_abbrev", "bundling");
    GetOptions(
	       "a|anoncvs"		=> \$anoncvs,
	       "b|build"		=> \$build,
	       "c|clean"		=> \$clean,
	       "D|date=s"		=> \$date,
	       "d|dbdir=s"		=> \$dbdir,
	       "e|exclude-installed"	=> \$exclude,
	       "f|fetch"		=> \$fetch,
	       "h|help"			=> \$help,
	       "i|info"			=> \$info,
	       "k|packages"		=> \$packages,
	       "l|list"			=> \$list,
	       "p|portsdir=s"		=> \$portsdir,
	       "r|cvsroot=s"		=> \$cvsroot,
	       "t|tag=s"		=> \$tag,
	       "u|update"		=> \$update,
	       "V|version"		=> \$version,
	       "v|verbose"		=> \$verbose,
	       "x|ecks"			=> \$ecks,
	       )
	or usage();

    if ($help) {
	help();
    }

    if ($version) {
	version();
    }
    
    if ($ecks) {
	ecks();
    }
    
    if (!@ARGV && (!$clean && !$info || $build || $fetch)) {
	usage();
    }
    
    if ($portsdir !~ m/^\//) {
	$portsdir = `pwd` . $portsdir;
	$portsdir =~ s/\n/\//s;
    }

    if ($portsdir !~ m/\/ports\/?$/) {
	errx(1, "ports directory must be named 'ports'");
    }
    
    $index = "$portsdir/INDEX";

    # 'package' implies 'build', which implies 'fetch'.
    if ($packages) {
	$build = 1;
    }
    if ($build) {
	$fetch = 1;
    }
    
    # Set and check CVS root
    if ($anoncvs) {
	$cvsroot = &ANONCVS_ROOT;
    }
    if ($cvsroot) {
	$ENV{'CVSROOT'} = $cvsroot;
    }
    if (!$ENV{'CVSROOT'}) {
	errx(1, "No CVS root, please use the -r option or set \$CVSROOT");
    }
    
    # Read the ports index
    if ($update) {
	update_index();
    }
    read_index();

    # Read list of explicitly required ports
    foreach $port (@ARGV) {
	$err += add_port($port, &REQ_EXPLICIT);
    }
    if ($err) {
	errx(1, "some required ports were not found.");
    }

    # Deselect ports which are already installed
    if ($exclude) {
	foreach $port (keys(%reqd)) {
	    if (-d "$dbdir/$port") {
		info("$port is already installed");
		delete $reqd{$port};
	    }
	}
    }
    
    # List required packages
    if ($list) {
	foreach $port (sort(keys(%reqd))) {
	    print((($reqd{$port} & &REQ_EXPLICIT) ? " * " : "   "),
		  "$port\n");
	}
    }

    # Update port directories
    if ($update && ($build || $fetch || $info)) {
	update_ports_tree(keys(%reqd));
    }

    # Show info
    if ($info) {
	if (@ARGV) {
	    list_installed();
	}
	foreach $port (keys(%reqd)) {
	    if ($reqd{$port} & &REQ_EXPLICIT) {
		show_port_info($port);
	    }
	}
    }

    # Clean
    if ($clean) {
	if (@ARGV) {
	    clean_tree();
	}
	foreach $port (keys(%reqd)) {
	    if (!($reqd{$port} & &REQ_IMPLICIT)) {
		clean_port($port);
	    }
	}
    }
    
    # Fetch ports
    if ($fetch) {
	foreach $port (keys(%reqd)) {
	    fetch_port($port);
	}
    }

    # Build ports - only the explicitly required ones, since the
    # 'already installed' test may give false negatives (most commonly
    # XFree86)
    if ($build || $packages) {
	foreach $port (keys(%reqd)) {
	    if (!($reqd{$port} & &REQ_IMPLICIT)) {
		build_port($port);
	    }
	}
    }

    # Done!
    exit(0);
}
