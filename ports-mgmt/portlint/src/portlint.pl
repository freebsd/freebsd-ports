#! /usr/bin/perl
# ex:ts=4
#
# portlint - lint for port directory
# implemented by:
#	Jun-ichiro itojun Hagino <itojun@itojun.org>
#	Yoshishige Arai <ryo2@on.rim.or.jp>
#
# Copyright(c) 1997 by Jun-ichiro Hagino <itojun@itojun.org>.
# All rights reserved.
# Freely redistributable.  Absolutely no warranty.
#
# Please note that this perl code used to be able to handle (Open|Net|Free)BSD
# bsd.port.mk.  There are significant differences in those so you'll have
# hard time upgrading this...
# This code now mainly supports FreeBSD, but patches to update support for
# OpenBSD and NetBSD will be accepted.
#
# $FreeBSD$
# $Id: portlint.pl,v 1.74 2005/03/21 19:50:06 marcus Exp $
#

use vars qw/ $opt_a $opt_A $opt_b $opt_C $opt_c $opt_h $opt_t $opt_v $opt_M $opt_N $opt_B $opt_V /;
use Getopt::Std;
use File::Find;
use IPC::Open2;
use strict;

my ($err, $warn);
my ($extrafile, $parenwarn, $committer, $verbose, $usetabs, $newport);
my $contblank;
my $portdir;
my $makeenv = "";

$err = $warn = 0;
$extrafile = $parenwarn = $committer = $verbose = $usetabs = $newport = 0;
$contblank = 1;
$portdir = '.';

# version variables
my $major = 2;
my $minor = 7;
my $micro = 0;

sub l { '[{(]'; }
sub r { '[)}]'; }
sub s { '[ \t]'; }

my $l = &l;
my $r = &r;
my $s = &s;

# default setting - for FreeBSD
my $portsdir = '/usr/ports';
my $rcsidstr = 'FreeBSD';
my $multiplist = 0;
my $ldconfigwithtrue = 0;
my $rcsidinplist = 0;
my $mancompress = 1;
my $manstrict = 0;
my $newxdef = 1;
my $automan = 1;
my $autoinfo = 1;
my $manchapters = '123456789ln';
my $localbase = '/usr/local';

my %lang_pref = qw(
	arabic		ar
	chinese		zh
	french		fr
	german		de
	hebrew		iw
	hungarian	hu
	japanese	ja
	korean		ko
	polish		pl
	portuguese	pt
	russian		ru
	ukrainian	uk
	vietnamese	vi
);
my @lang_cat = keys %lang_pref;
my @lang_short = values %lang_pref;
my $re_lang_short = '(' . join('|', @lang_short) . ')-';

my ($prog) = ($0 =~ /([^\/]+)$/);
sub usage {
	print STDERR <<EOF;
usage: $prog [-AabCchvtN] [-M ENV] [-B#] [port_directory]
	-a	additional check for scripts/* and pkg-*
	-A	turn on all additional checks (equivalent to -abcNt)
	-b	warn \$(VARIABLE)
	-c	committer mode
	-C	pedantic committer mode (equivalent to -abct)
	-h	show summary of command line options
	-v	verbose mode
	-t	nit pick about use of spaces
	-N	writing a new port
	-V	print the version and exit
	-M ENV	set make variables to ENV (ex. PORTSDIR=/usr/ports.work)
	-B#	allow # contiguous blank lines (default: $contblank line)
EOF
		exit 0;
}

sub version {
	print "$prog version $major.$minor.$micro\n";
	exit $major;
}

getopts('AabCchtvB:M:NV');

&usage if $opt_h;
&version if $opt_V;
$extrafile = 1 if $opt_a || $opt_A || $opt_C;
$parenwarn = 1 if $opt_b || $opt_A || $opt_C;
$committer = 1 if $opt_c || $opt_A || $opt_C;
$verbose = 1 if $opt_v;
$newport = 1 if $opt_N || $opt_A;
$usetabs = 1 if $opt_t || $opt_A || $opt_C;
$contblank = $opt_B if $opt_B;
$makeenv = $opt_M if $opt_M;

$portdir = $ARGV[0] ? $ARGV[0] : '.';

# OS dependent configs
# os	portsdir	rcsid		mplist	ldcfg	plist-rcsid mancompresss strict	localbase	newxdef	automan	autoinfo
my @osdep = split(/\n/, <<EOF);
FreeBSD	/usr/ports	FreeBSD		0	0	0		1	0	/usr/local	1	1	1
NetBSD	/usr/pkgsrc	NetBSD		1	1	1		0	1	/usr/pkg	0	0	0
EOF
my $osname = `uname -s`;
$osname =~ s/\n$//;
foreach my $i (@osdep) {
	if ($i =~ /^$osname\t(.*)/) {
		print "OK: found OS config for $osname.\n" if ($verbose);
		($portsdir, $rcsidstr, $multiplist, $ldconfigwithtrue,
			$rcsidinplist, $mancompress, $manstrict, $localbase,
			$newxdef, $automan, $autoinfo)
				= split(/\t+/, $1);
		last;
	}
}

# The PORTSDIR environment variable overrides our defaults.
$portsdir = $ENV{PORTSDIR} if ( defined $ENV{'PORTSDIR'} );

if ($verbose) {
	print "OK: config: portsdir: \"$portsdir\" ".
		"rcsidstr: \"$rcsidstr\" ".
		"multiplist: $multiplist ".
		"ldconfigwithtrue: $ldconfigwithtrue ".
		"rcsidinplist: $rcsidinplist ".
		"mancompress: $mancompress ".
		"manstrict: $manstrict ".
		"localbase: $localbase ".
		"\n";
}

#
# just for safety.
#
if (! -d $portdir) {
	print STDERR "FATAL: invalid directory $portdir specified.\n";
	exit 1;
}

chdir "$portdir" || die "$portdir: $!";

# get make vars
my @varlist =  qw(
	PORTNAME PORTVERSION PORTREVISION PORTEPOCH PKGNAME PKGNAMEPREFIX
	PKGNAMESUFFIX DISTVERSIONPREFIX DISTVERSION DISTVERSIONSUFFIX
	DISTNAME DISTFILES CATEGORIES MASTERDIR MAINTAINER MASTER_SITES
	WRKDIR WRKSRC NO_WRKSUBDIR PATCHDIR SCRIPTDIR FILESDIR
	PKGDIR COMMENT DESCR PLIST PKGCATEGORY PKGINSTALL PKGDEINSTALL
	PKGREQ PKGMESSAGE MD5_FILE .CURDIR INSTALLS_SHLIB USE_LIBTOOL_VER
	INDEXFILE PKGORIGIN CONFLICTS PKG_VERSION PKGINSTALLVER
	PLIST_FILES OPTIONS INSTALLS_OMF
);

my $cmd = join(' -V ', "make $makeenv MASTER_SITE_BACKUP=''", @varlist);

my %makevar;
my $i = 0;
for (split(/\n/, `$cmd`)) {
	print "OK: makevar: $varlist[$i] = $_\n" if ($verbose);
	$makevar{$varlist[$i]} = $_;
	$i++;
}

#
# variables for global checks.
#
my $sharedocused = 0;
my %plistmanall = ();
my %plistmangz = ();
my %plistman = ();
my %manlangs = ();

my %predefined = ();
# historical, no longer in FreeBSD's bsd.sites.mk
foreach my $i (split(/\n/, <<EOF)) {
GNU 		ftp://prep.ai.mit.edu/pub/gnu/%SUBDIR%/
GNU			ftp://wuarchive.wustl.edu/systems/gnu/%SUBDIR%/
GNU			ftp://ftp.ecrc.net/pub/gnu/%SUBDIR%/
PERL_CPAN	ftp://ftp.cdrom.com/pub/perl/CPAN/modules/by-module/%SUBDIR%/
SUNSITE		ftp://sunsite.unc.edu/pub/Linux/%SUBDIR%/
SUNSITE		ftp://ftp.funet.fi/pub/mirrors/sunsite.unc.edu/pub/Linux/%SUBDIR%/
SUNSITE		ftp://ftp.infomagic.com/pub/mirrors/linux/sunsite/%SUBDIR%/
TEX_CTAN	ftp://ftp.cdrom.com/pub/tex/ctan/%SUBDIR%/
TEX_CTAN	ftp://ftp.tex.ac.uk/public/ctan/tex-archive/%SUBDIR%/
GNOME		ftp://ftp.cybertrails.com/pub/gnome/%SUBDIR%/
AFTERSTEP	ftp://ftp.alpha1.net/pub/mirrors/ftp.afterstep.org/%SUBDIR%/
AFTERSTEP	ftp://casper.yz.yamagata-u.ac.jp/pub/X11/apps/afterstep/%SUBDIR%/
WINDOWMAKER	ftp://ftp.io.com/pub/%SUBDIR%/
EOF
	my ($j, $k) = split(/\t+/, $i);
	$predefined{$k} = $j;
}

# Read bsd.sites.mk
my $sites_mk = "$portsdir/Mk/bsd.sites.mk";
open(MK, $sites_mk) || die "$sites_mk: $!";
my @site_groups = grep($_ = /^MASTER_SITE_(\w+)/ && $1, <MK>);
close(MK);

$cmd = join(' -V MASTER_SITE_', "make $makeenv -f - all", @site_groups);

$i = 0;

open2(\*IN, \*OUT, $cmd);

print OUT <<EOF;
all:
	# do nothing

.include "$sites_mk"
EOF

close(OUT);

while (<IN>) {
	my $g = $site_groups[$i];
	for my $s (split()) {
		$predefined{$s} = $g;
	}
	$i++;
}

close(IN);

#
# check for files.
#
my @checker = ($makevar{DESCR}, 'Makefile', $makevar{MD5_FILE});
my %checker = (
	$makevar{DESCR} => \&checkdescr,
	'Makefile' => \&checkmakefile,
	$makevar{MD5_FILE} => \&TRUE
);
if ($extrafile) {
	my @files = (
				 <$makevar{SCRIPTDIR}/*>,
				 @makevar{qw(DESCR PLIST PKGINSTALL PKGDEINSTALL PKGREQ PKGMESSAGE)}
				);

	foreach my $i (@files) {
		next if (! -T $i);
		next if (defined $checker{$i});
		if ($i =~ /\bpkg-plist$/
		 || ($multiplist && $i =~ /\bpkg-plist/)) {
			unshift(@checker, $i);
			$checker{$i} = \&checkplist;
		} else {
			push(@checker, $i);
			$checker{$i} = \&checkpathname;
		}
	}
}
foreach my $i (<$makevar{PATCHDIR}/patch-*>) {
	next if (! -T $i);
	next if (defined $checker{$i});
	push(@checker, $i);
	$checker{$i} = \&checkpatch;
}
foreach my $i (@checker) {
	print "OK: checking $i.\n" if ($verbose);
	if (! -f "$i") {
		&perror("FATAL: no $i in \"$portdir\".") unless $i eq $makevar{MD5_FILE} && $makevar{DISTFILES} eq "";
	} else {
		my $proc = $checker{$i};
		&$proc($i) || &perror("Cannot open the file $i\n");
		if ($proc ne \&checkpatch) {
			&checklastline($i)
				|| &perror("Cannot open the file $i\n");
		}
	}
}

# Check to make sure there is no pkg-comment file anymore.
if (-f 'pkg-comment') {
	&perror("FATAL: Use of pkg-comment is obsolete.  Use the COMMENT macro within the port's Makefile instead.");
}

if ($committer) {
	sub find_proc {
		return if /^\.\.?$/;

		(my $fullname = $File::Find::name) =~ s#^\./##;

		print "OK: checking the file name of $fullname.\n" if ($verbose);

		if ($fullname eq 'work') {
			&perror("FATAL: $fullname: be sure to cleanup the working directory ".
					"before committing the port.");

			$File::Find::prune = 1;
		} elsif (-l) {
			&perror("Warning: $fullname: this is a symlink. ".
					"CVS will ignore it.");
		} elsif (-z) {
			&perror("FATAL: $fullname: empty file and should be removed. ".
				    "If it still needs to be there, put a dummy comment ".
					"to state that the file is intentionally left empty.");
		} elsif (-d && scalar(my @x = <$_/{*,.?*}>) <= 1) {
			&perror("FATAL: $fullname: empty directory should be removed.");
		} elsif (/^\./) {
			&perror("Warning: $fullname: dotfiles are not preferred. ".
					"If this file is a dotfile to be installed as an example, ".
					"consider importing it as \"dot$_\".");
		} elsif (/\.(orig|rej|bak)$/ || /~$/ || /^\#/) {
			&perror("FATAL: $fullname: for safety, be sure to cleanup ".
					"backup files before committing the port.");
		} elsif (/(^|\.)core$/) {
			&perror("FATAL: $fullname: for safety, be sure to cleanup ".
					"core files before committing the port.");
		} elsif ($_ eq 'CVS' && -d) {
			if ($newport) {
				&perror("FATAL: $fullname: for safety, be sure to cleanup ".
						"CVS directories before importing the new port.");
			}

			$File::Find::prune = 1;
		}
	}

	find(\&find_proc, '.');

	sub checksubdir {
		my $dir = shift;

		print "OK: checking CVS status of \"$dir\".\n" if ($verbose);
		opendir DIR, $dir;
		my @filenames = readdir DIR;
		closedir DIR;

		my %entries;
		if (-f "$dir/CVS/Entries") {
			open ENTRIES, "<$dir/CVS/Entries";
			while (<ENTRIES>) {
				chomp;
				my @entry = split /\//;
				if ($entry[0] eq 'D') {
					$entries{ $entry[1] } = $entry[0]
						if $entry[1];
				}
				elsif ($entry[0] eq '') {
					if ($entry[2] =~ /^-/) {
						$entries{ $entry[1] } = 'x';
					}
					elsif ($entry[2] eq '0') {
						$entries{ $entry[1] } = 'n';
					}
					else {
						$entries{ $entry[1] } = 'f';
					}
				}
				else {
					&perror("WARN: can not parse CVS line $_");
				}
			}
			close ENTRIES;
		} else {
			&perror("WARN: no CVS directories. Use -N to check a new port.");
			return;
		}

		if (-f "$dir/CVS/Entries.Log") {
			open ENTRIES, "<$dir/CVS/Entries.Log";
			while (<ENTRIES>) {
				chomp;
				my $cmd;
				my @entry = split /\//;
				if (/^(.) (.*)$/) {
					$cmd = $1;
					@entry = split /\//, $2;
				}
				else {
					$cmd = 'A';
					@entry = split /\//;
				}
					if ($cmd eq 'A') {
						if ($entry[0] eq 'D') {
							$entries{ $entry[1] } = $entry[0]
								if $entry[1];
						}
					elsif ($entry[0] eq '') {
						if ($entry[2] =~ /^-/) {
							$entries{ $entry[1] } = 'x';
						}
						elsif ($entry[2] eq '0') {
							$entries{ $entry[1] } = 'n';
						}
						else {
							$entries{ $entry[1] } = 'f';
						}
					}
					else {
						&perror("WARN: can not parse CVS line $_");
					}
				}
				elsif ($cmd eq 'R') {
					delete $entries{ $entry[1] }
						if $entry[1];
				}
				# ignore unknown commands
			}
			close ENTRIES;
		}

		foreach (@filenames) {
			next
				if /^(?:\.\.?|CVS)$/;
			my $filename = $dir eq '.' ? $_ : "$dir/$_";
			if (-d $filename) {
				if (!$entries{$_} || $entries{$_} ne 'D') {
					&perror("FATAL: directory $filename not in CVS.");
				}
				else {
					delete $entries{$_};
					checksubdir($filename);
				}
			}
			else {
				if (!$entries{$_}) {
					&perror("FATAL: file $filename not in CVS.")
						unless (eval { /$ENV{'PL_CVS_IGNORE'}/, 1 } &&
							/$ENV{'PL_CVS_IGNORE'}/);
				}
				elsif ($entries{$_} eq 'D') {
					&perror("FATAL: file $filename is a directory in CVS.");
				}
				elsif ($entries{$_} eq 'x') {
					&perror("FATAL: file $filename is deleted in CVS.");
				}
				elsif ($entries{$_} eq 'n') {
					if (!system("egrep", "-q", "\\\$$rcsidstr\[^\$\]+\\\$", $filename)) {
						&perror("WARN: RCS tag \"\$$rcsidstr\$\" ".
							"should be empty in new file $filename.");
					}
					delete $entries{$_};
				}
				else {
					delete $entries{$_};
				}
			}
		}

		while (my ($file, $type) = each %entries) {
			next if $type eq 'x';
			if ($type eq 'D') {
				&perror("FATAL: CVS directory $dir/$file missing");
			}
			else {
				&perror("FATAL: CVS file $dir/$file missing");
			}
		}
	}

	checksubdir('.')
		unless $newport;

	# Check for ports that may break INDEX
	my $indexerr = `env LOCALBASE=/nonexistentlocal X11BASE=/nonexistentx make $makeenv describe 2>&1 >/dev/null`;
	chomp $indexerr;
	$indexerr =~ tr/\n/ /s;
	&perror("FATAL: breaks INDEX ($indexerr).")
		if ($indexerr);
}
if ($err || $warn) {
	print "$err fatal errors and $warn warnings found.\n"
} else {
	print "looks fine.\n";
}
exit $err;

#
# pkg-descr
#
sub checkdescr {
	my($file) = @_;
	my(%maxchars) = ($makevar{DESCR}, 80);
	my(%maxlines) = ($makevar{DESCR}, 24);
	my(%errmsg) = ($makevar{DESCR},	"exceeds $maxlines{$makevar{DESCR}} ".
					"lines, make it shorter if possible.");
	my($longlines, $linecnt, $tmp) = (0, 0, "");

	open(IN, "< $file") || return 0;
	while (<IN>) {
		$tmp .= $_;
		chomp || &perror("WARN: $file: should terminate in '\n'.");
		$linecnt++;
		$longlines++ if ($maxchars{$file} < length);
	}
	if ($linecnt > $maxlines{$file}) {
		&perror("WARN: $file $errmsg{$file}".
			"(currently $linecnt lines)");
	} else {
		print "OK: $file: has $linecnt lines.\n" if ($verbose);
	}
	if ($longlines > 0) {
		&perror("WARN: $file: includes lines that exceed $maxchars{$file} ".
			"characters.");
	}
	if ($tmp =~ /[\033\200-\377]/) {
		&perror("WARN: $file: includes iso-8859-1, or ".
			"other local characters.  files should be in ".
			"plain 7-bit ASCII");
	}
	if ($file =~ /\bpkg-descr/ && $tmp =~ m,http://,) {
		my $has_url = 0;
		my $has_www = 0;
		foreach my $line (grep($_ =~ "http://", split(/\n+/, $tmp))) {
			$has_url = 1;
			if ($line =~ m,WWW:[ \t]+http://,) {
				$has_www = 1;
			}
		}

		if (!$has_url) {
			&perror("WARN: $file: add \"WWW: UR:\" for this port if possible");
		}

		if ($has_url && ! $has_www) {
			&perror("FATAL: $file: contains a URL but no \"WWW:\"");
		}
	}
	close(IN);
}

#
# pkg-plist
#
sub checkplist {
	my($file) = @_;
	my($curdir) = ($localbase);
	my($inforemoveseen, $infoinstallseen, $infoseen) = (0, 0, 0);
	my($infobeforeremove, $infoafterinstall) = (0, 0);
	my($infooverwrite) = (0);
	my($rcsidseen) = (0);

	my(@exec_info) = ();
	my(@unexec_info) = ();
	my(@infofile) = ();

	my $seen_dirrm_docsdir;

	open(IN, "< $file") || return 0;
	while (<IN>) {
		if ($_ =~ /[ \t]+\n?$/) {
			&perror("WARN: $file [$.]: whitespace before end ".
				"of line.");
		}

		# make it easier to handle.
		$_ =~ s/\s+$//;
		$_ =~ s/\n$//;

		if ($osname eq 'NetBSD' && $_ =~ /<\$ARCH>/) {
			&perror("WARN: $file [$.]: use of <\$ARCH> deprecated, ".
				"use \${MACHINE_ARCH} instead.");
		}
		if (m'lib/perl5/site_perl/%%PERL_VER%%') {
			&perror("WARN: $file [$.]: use \%\%SITE_PERL\%\% ".
					"instead of lib/perl5/site_perl/\%\%PERL_VER\%\%.");
		}
		$seen_dirrm_docsdir++ if /^(\%\%PORTDOCS\%\%)?\@dirrm\s+\%\%DOCSDIR\%\%/ || /^(\%\%PORTDOCS\%\%)?\@unexec\s+(\/bin\/)?rmdir\s+\%D\/\%\%DOCSDIR\%\%\s+2\>\s*\/dev\/null\s+\|\|\s+(\/usr\/bin\/)?true/;
		if ($_ =~ /^\@/) {
			if ($_ =~ /^\@(cwd|cd)[ \t]+(\S+)/) {
				$curdir = $2;
			} elsif ($_ =~ /^\@unexec[ \t]+rm[ \t]/) {
				if ($_ !~ /%[DB]/) {
					&perror("WARN: $file [$.]: use \"%D\" or \"%B\" to ".
						"specify prefix.");
				}
				if ($_ !~ /true$/ && $_ !~ /rm -f/) {
					&perror("WARN: $file [$.]: add \"2>&1 ".
						">/dev/null || true\" ".
						"to \"\@unexec rm\".");
				}
			} elsif ($_ =~ /^\@unexec[ \t]+rmdir/) {
				if ($_ !~ /%[DB]/) {
					&perror("WARN: $file [$.]: use \"%D\" or \"%B\" to ".
						"specify prefix.");
				}
				if ($_ !~ /true$/) {
				&perror("WARN: $file [$.]: use \"\@dirrm\" ".
					"instead of \"\@unexec rmdir\".");
				}
			} elsif (!$autoinfo && $_ =~ /^\@exec[ \t]+install-info\s+(.+)\s+(.+)$/) {
				$infoinstallseen = $.;
				push(@exec_info, $1);
			} elsif (!$autoinfo && $_ =~ /^\@unexec[ \t]+install-info[ \t]+--delete\s+(.+)\s+(.+)$/) {
				$inforemoveseen = $.;
				push(@unexec_info, $1);
			} elsif ($autoinfo && $_ =~ /^\@unexec[ \t]+install-info[ \t]+--delete\s+(.+)\s+(.+)$/) {
				&perror("WARN: $file [$.]: \@unexec install-info is deprecated in favor of adding info files into the Makefile using the INFO macro.");
			} elsif ($_ =~ /^\@(exec|unexec)/) {
				if (/ldconfig/) {
					if ($ldconfigwithtrue
					 && !/\/usr\/bin\/true/) {
						&perror("FATAL: $file [$.]: ldconfig ".
							"must be used with ".
							"\"||/usr/bin/true\".");
					}
				&perror("WARN: $file [$.]: possible ".
					"direct use of ldconfig ".
					"in PLIST found. use ".
					"INSTALLS_SHLIB instead.");
				}
				if (/scrollkeeper/) {
					&perror("WARN: $file [$.]: possible ".
						"direct use of scrollkeeper commands ".
						"in PLIST found.  Use ".
						"INSTALLS_OMF instead ".
						"(see http://www.FreeBSD.org/gnome/docs/porting.html ".
						"for more details).");
				}
			} elsif ($_ =~ /^\@(comment)/) {
				$rcsidseen++ if (/\$$rcsidstr[:\$]/);
			} elsif ($_ =~ /^\@(owner|group|mode)\s/) {
				&perror("WARN: $file [$.]: \@$1 should not be needed");
			} elsif ($_ =~ /^\@(dirrm|option)/) {
				; # no check made
			} else {
				&perror("WARN: $file [$.]: ".
					"unknown pkg-plist directive \"$_\"");
			}
			next;
		}

		if ($_ =~ /^\//) {
			&perror("FATAL: $file [$.]: use of full pathname ".
				"disallowed.");
		}

		if ($_ =~ /charset\.alias$/ || $_ =~ /locale\.alias$/) {
			&perror("WARN: $file [$.]: installing charset.alias or locale.alias, ".
				"please add USE_GETTEXT=yes and use libintl from devel/gettext ".
				"instead of from outdated bundled one if possible. ".
				"See http://www.freebsd.org/cgi/query-pr.cgi?pr=ports/71531 ".
				"for more details.");
		}

		if ($_ =~ /\.la$/ && $makevar{USE_LIBTOOL_VER} eq '') {
			&perror("WARN: $file [$.]: installing libtool archives, ".
				"please use USE_LIBTOOL_VER in Makefile if possible.  ".
				"See http://www.FreeBSD.org/gnome/docs/porting.html ".
				"for a way to completely eliminate .la files.");
		}

		if ($_ =~ /\%gconf.*\.xml/ || $_ =~ /gconf.*\.schemas?/) {
			&perror("FATAL: $file [$.]: explicitly listing \%gconf key files ".
				"or GConf schema files in the plist is not supported. ".
				"Use GCONF_SCHEMAS in the Makefile instead. ".
				"See http://www.FreeBSD.org/gnome/docs/porting.html ".
				"for more details.");
		}

		if ($_ =~ m|lib/pkgconfig/[^\.]+.pc$|) {
			&perror("FATAL: $file [$.]: installing pkg-config files into ".
				"lib/pkgconfig.  All pkg-config files must be installed ".
				"into libdata/pkgconfig for them to be found by pkg-config.");
		}

		if ($_ =~ m|^lib/lib[^\/]+\.so(\.\d+)?$| &&
			$makevar{INSTALLS_SHLIB} eq '') {
			&perror("WARN: $file [$.]: installing shared libraries, ".
				"please define INSTALLS_SHLIB as appropriate");
		}

		if ($_ =~ m|\.omf$| && $makevar{INSTALLS_OMF} eq '') {
			&perror("WARN: $file [$.]: installing OMF files, ".
				"please define INSTALLS_OMF (see the FreeBSD GNOME ".
				"porting guide at ".
				"http://www.FreeBSD.org/gnome/docs/porting.html ".
				"for more details)");
		}

		if ($autoinfo && $_ =~ /\.info$/) {
			&perror("WARN: $file [$.]: enumerating info files in the plist is deprecated in favor of adding info files into the Makefile using the INFO macro.");
		}

		if ($autoinfo && $_ =~ /\.info-\d+$/) {
			&perror("FATAL: $file [$.]: numbered info files are obsolete and not portable; add info files using the INFO macro in the Makefile.");
		}

		if (!$autoinfo) {
			if ($_ =~ /^info\/.*info(-[0-9]+)?$/) {
				$infoseen = $.;
				$infoafterinstall++ if ($infoinstallseen);
				$infobeforeremove++ if (!$inforemoveseen);
				push(@infofile, $_);
			}

			if ($_ =~ /^info\/dir$/) {
				&perror("FATAL: $file [$.]: \"info/dir\" should not be listed.".
					"Use install-info to add/remove ".
					"an entry.");
				$infooverwrite++;
			}
		}

		if ($_ =~ /^(\%\%PORTDOCS\%\%)?share\/doc\//) {
			&perror("WARN: $file [$.]: consider using DOCSDIR macro");
			$sharedocused++;
		} elsif ($_ =~ /^(\%\%PORTDOCS\%\%)?\%\%DOCSDIR\%\%/) {
			$sharedocused++;
		}

		if ($_ =~ /^share\/examples\//) {
			&perror("WARN: $file [$.]: consider using EXAMPLESDIR macro");
		}

		{
			my $tmpportname = quotemeta($makevar{PORTNAME});
			if ($_ =~ /^share\/$tmpportname\//) {
				&perror("WARN: $file [$.]: consider using DATADIR macro");
			}
		}

		if ($_ =~ m#man/([^/]+/)?man([$manchapters])/([^\.]+\.[$manchapters])(\.gz)?$#) {
			if ($4 eq '') {
				$plistman{$2} .= ' ' . $3;
				if ($mancompress) {
					&perror("FATAL: $file [$.]: ".
						"unpacked man file $3 ".
						"listed. must be gzipped.");
				}
			} else {
				$plistmangz{$2} .= ' ' . $3;
				if (!$mancompress) {
					&perror("FATAL: $file [$.]: ".
						"gzipped man file $3$4 ".
						"listed. unpacked one should ".
						"be installed.");
				}
			}
			$plistmanall{$2} .= ' ' . $3;
			if ($1 ne '') {
				$manlangs{substr($1, 0, length($1) - 1)}++;
			}
		}

		if ($curdir !~ m#^$localbase#
		 && $curdir !~ m#^/usr/X11R6#) {
			&perror("WARN: $file [$.]: installing to ".
				"directory $curdir discouraged. ".
				"could you please avoid it?");
		}

		if ("$curdir/$_" =~ m#^$localbase/share/doc#) {
			print "OK: $file [$.]: seen installation to share/doc. ".
				"($curdir/$_)\n" if ($verbose);
			$sharedocused++;
		}
	}

	if ($sharedocused && !$seen_dirrm_docsdir) {
		&perror("WARN: $file: Both ``\%\%PORTDOCS\%\%\@dirrm \%\%DOCSDIR\%\%'' and ``\%\%PORTDOCS\%\%\@unexec \%D/\%\%DOCSDIR\%\% 2>/dev/null || true'' are missing.  At least one should be used.");
	}

	if (!$autoinfo) {
# check that every infofile has an exec install-info and unexec install-info
		my $exec_install = join(" ", @exec_info);
		$exec_install .= ' ';
		my $unexec_install = join(" ", @unexec_info);
		$unexec_install .= ' ';

		foreach my $if (@infofile) {
			next if ($if =~ m/info-/);
			if ($exec_install !~ m/\%D\/\Q$if\E/) {
				&perror("FATAL: $file: you need an '\@exec install-info \%D/$if \%D/info/dir' line");
			}
			if ($unexec_install !~ m/\%D\/$if/) {
				&perror("FATAL: $file: you need an '\@unexec install-info --delete \%D/$if \%D/info/dir' line");
			}
		}
	}

	if ($rcsidinplist && !$rcsidseen) {
		&perror("FATAL: $file: RCS tag \"\$$rcsidstr\$\" must be present ".
			"as \@comment.")
	}

	if (((!$autoinfo && !$infoseen) || $autoinfo)) {
		close(IN);
		return 1;
	}

	if (!$autoinfo && $infoseen) {
		if (!$infoinstallseen) {
			if ($infooverwrite) {
				&perror("FATAL: $file: install-info must be used to ".
					"add/delete entries into \"info/dir\".");
			}
			&perror("FATAL: $file: \"\@exec install-info \%D/...  \%D/info/dir\" must be placed ".
				"after all the info files.");
		} elsif ($infoafterinstall) {
			&perror("FATAL: $file [$infoinstallseen]: move ".
				"\"\@exec install-info\" line to make ".
				"sure that it is placed after all the info files.");
		}
		if (!$inforemoveseen) {
			&perror("FATAL: $file: \"\@unexec install-info --delete \%D/... \%D/info/dir\" must ".
				"be placed before any of the info files listed.");
		} elsif ($infobeforeremove) {
			&perror("FATAL: $file [$inforemoveseen]: move ".
				"\"\@exec install-info --delete\" ".
				"line to make sure ".
				"that it is placed before any of the info files. ");
		}
	}

	close(IN);
}

#
# misc files
#
sub checkpathname {
	my($file) = @_;
	my($whole);

	open(IN, "< $file") || return 0;
	$whole = '';
	while (<IN>) {
		$whole .= $_;
	}
	&abspathname($whole, $file);
	close(IN);
}

sub checklastline {
	my($file) = @_;
	my($whole);

	open(IN, "< $file") || return 0;
	$whole = '';
	while (<IN>) {
		$whole .= $_;
	}
	if ($whole !~ /\n$/) {
		&perror("FATAL: $file: the last line has to be ".
			"terminated by \\n.");
	}
	if ($whole =~ /\n([ \t]*\n)+$/) {
		&perror("WARN: $file: seems to have unnecessary blank lines ".
			"at the last part.");
	}

	close(IN);
}

sub checkpatch {
	my($file) = @_;
	my($whole);

	if (-z "$file") {
		&perror("FATAL: $file: has no content. should be removed ".
			"from repository.");
		return;
	}

	open(IN, "< $file") || return 0;
	$whole = '';
	while (<IN>) {
		$whole .= $_;
	}
	if ($committer && $whole =~ /\$([A-Z][A-Za-z0-9]+)(:[^\n]+)?\$/) {
		my $lineno = &linenumber($`);
		&perror("WARN: $file [$lineno]: includes possible RCS tag \"\$$1\$\". ".
			"use binary mode (-ko) on commit/import.") unless
			$1 eq $rcsidstr;
	}

	if ($committer && $whole =~ /\wjavavm\w/) {
		my $lineno = &linenumber($`);
		&perror("WARN: $file [$lineno]: since javavmwrapper 2.0, the ".
			"``javavm'' command to invoke a JVM is deprecated.  Use ".
			"``java'' instead");
	}

	close(IN);
}

#
# Makefile
#
sub checkmakefile {
	my($file) = @_;
	my($rawwhole, $whole, $idx, @sections);
	my($i, $j, $k, $l);
	my @cat = ();
	my $has_lang_cat = 0;
	my $port_lang = '';
	my $tmp;
	my $bogusdistfiles = 0;
	my @varnames = ();
	my($portname, $portversion, $distfiles, $distversionprefix, $distversion, $distversionsuffix, $distname, $extractsufx) = ('', '', '', '', '');
	my $masterport = 0;
	my $slaveport = 0;
	my $use_gnome_hack = 0;
	my $use_java = 0;
	my $use_ant = 0;
	my($realwrksrc, $wrksrc, $nowrksubdir) = ('', '', '');
	my(@mman, @pman);
	my(@mopt, @oopt);
	my($pkg_version, $versiondir, $versionfile) = ('', '', '');
	my $useindex = 0;
	my %deprecated = ();
	my %autocmdnames = ();

	open(IN, "< $file") || return 0;
	$rawwhole = '';
	$tmp = 0;
	while (<IN>) {
		if ($_ =~ /[ \t]+\n?$/) {
			&perror("WARN: $file [$.]: whitespace before ".
				"end of line.");
		}
		if ($_ =~ /^        /) {	# 8 spaces here!
			&perror("WARN: $file [$.]: use tab (not space) to make ".
				"indentation");
		}
		if ($usetabs) {
			if (m/^[A-Za-z0-9_-]+.?= /) {
				if (m/[?+]=/) {
					&perror("WARN: $file [$.]: use a tab (not space) after a ".
						"variable name");
				} else {
					&perror("FATAL: $file [$.]: use a tab (not space) after a ".
						"variable name");
				}
			}
		}
#
# I'm still not very convinced, for using this kind of magical word.
# 1. This kind of items are not important for Makefile;
#    portlint should not require any additional rule to Makefile.
#    portlint should simply implement items that are declared in Handbook.
# 2. If we have LINTSKIP, we can't stop people using LINTSKIP too much.
#    IMHO it is better to warn the user and let the user think twice,
#    than let the user escape from portlint.
# Uncomment this part if you are willing to use these magical words.
# Thu Jun 26 11:37:56 JST 1997
# -- itojun
#
#		if ($_ =~ /^# LINTSKIP\n?$/) {
#			print "OK: skipping from line $. in $file.\n"
#				if ($verbose);
#			$tmp = 1;
#			next;
#		}
#		if ($_ =~ /^# LINTAGAIN\n?$/) {
#			print "OK: check start again from line $. in $file.\n"
#				if ($verbose);
#			$tmp = 0;
#			next;
#		}
#		if ($_ =~ /# LINTIGNORE/) {
#			print "OK: ignoring line $. in $file.\n" if ($verbose);
#			next;
#		}
#		next if ($tmp);
		$rawwhole .= $_;
	}
	close(IN);

	#
	# whole file: blank lines.
	#
	$whole = "\n" . $rawwhole;
	study $whole;
	print "OK: checking contiguous blank lines in $file.\n"
		if ($verbose);
	$i = "\n" x ($contblank + 2);
	if ($whole =~ /$i/) {
		my $lineno = &linenumber($`);
		&perror("FATAL: $file [$lineno]: contiguous blank lines ".
			"(> $contblank lines) found.");
	}

	#
	# whole file: $(VARIABLE)
	#
	if ($parenwarn) {
		print "OK: checking for \$(VARIABLE).\n" if ($verbose);
		if ($whole =~ /\$\([\w\d]+\)/) {
			my $lineno = &linenumber($`);
			&perror("WARN: $file [$lineno]: use \${VARIABLE}, instead of ".
				"\$(VARIABLE).");
		}
	}

	#
	# whole file: PLIST_FILES and PLIST_DIRS
	#
	print "OK: checking PLIST_FILES and PLIST_DIRS.\n" if ($verbose);
	if ($whole =~ /\nPLIST_FILES.?=/ || $whole =~ /\nPLIST_DIRS.?=/) {
		if (-f 'pkg-plist') {
			my $lineno = &linenumber($`);
			&perror("WARN: $file [$lineno]: You may remove pkg-plist ".
					"if you use PLIST_FILES and/or PLIST_DIRS.");
		}
		my @plist_files = split(/\s+/, $makevar{PLIST_FILES});
		foreach my $plist_file (@plist_files) {
			if ($plist_file =~ m|^lib/lib[^\/]+\.so(\.\d+)?$| &&
				$makevar{INSTALLS_SHLIB} eq '') {
				&perror("WARN: PLIST_FILES: installing shared libraries, ".
					"please define INSTALLS_SHLIB as appropriate");
				last;
			}
		}
		foreach my $plist_file (@plist_files) {
			if ($plist_file =~ m|\.omf$| && $makevar{INSTALLS_OMF} eq '') {
				&perror("WARN: PLIST_FILES: installing OMF files, ".
					"please define INSTALLS_OMF (see the FreeBSD GNOME ".
					"porting guide at ".
					"http://www.FreeBSD.org/gnome/docs/porting.html ".
					"for more details)");
				last;
			}
		}

	}

	#
	# whole file: USE_* used too late
	#
	pos($whole) = 0;
	if ($whole =~ /^\.include\s+<bsd\.port\.pre\.mk>$/gm) {
		print "OK: checking for USE_* used too late.\n" if ($verbose);
		my @use_early = qw(
			APACHE
			BZIP2
			GNUSTEP
			IMAKE
			JAVA
			KDE(?:BASE|LIBS)_VER
			(?:LIB)?RUBY
			LINUX_PREFIX
			OPENSSL
			PHP
			PYTHON
			QT2?
			QT_VER
			X_PREFIX
			ZIP
		);

		my @other_early = qw(
			EMACS_PORT_NAME
			OPTIONS
		);

		my $earlypattern = join('|', 'USE_(?:'.join('|', @use_early).')',
			@other_early);

		while ($whole =~ /^($earlypattern)[+?:!]?=/gmo) {
			my $lineno = &linenumber($`);
			&perror("FATAL: $file [$lineno]: $1 is set after ".
				"including bsd.port.pre.mk.");
		}
	}

	#
	# whole file: USE_* as a user-settable option
	#
	print "OK: checking for USE_* as a user-settable option.\n" if ($verbose);
	while ($whole =~ /\n\s*\.\s*(?:el)?if[^\n]*?\b(\w*USE_)(\w+)(?\![^\n]*\n#?\.error)/g) {
		my $lineno = &linenumber($`);
		&perror("WARN: $file [$lineno]: is $1$2 a user-settable option? ".
			"Consider using WITH_$2 instead.")
		if ($1.$2 ne 'USE_GCC');
	}

	#
	# whole file: NO_CHECKSUM
	#
	# XXX Don't compress newlines since it messes up line number calculation.
	#$whole =~ s/\n#[^\n]*/\n/g;
	#$whole =~ s/\n\n+/\n/g;
	print "OK: checking NO_CHECKSUM.\n" if ($verbose);
	if ($whole =~ /\nNO_CHECKSUM/) {
		my $lineno = &linenumber($`);
		&perror("FATAL: $file [$lineno]: use of NO_CHECKSUM discouraged. ".
			"it is intended to be a user variable.");
	}

	#
	# whole file: USE_SIZE
	#
	print "OK: checking USE_SIZE.\n" if ($verbose);
	if ($whole =~ /\nUSE_SIZE/) {
			my $lineno = &linenumber($`);
			&perror("WARN: $file [$lineno]: use of USE_SIZE is no longer ".
					"required.");
	}

	#
	# whole file: MACHINE_ARCH
	#
	print "OK: checking MACHINE_ARCH.\n" if ($verbose);
	if ($whole =~ /\nMACHINE_ARCH/) {
		my $lineno = &linenumber($`);
		&perror("FATAL: $file [$lineno]: MACHINE_ARCH should never be ".
		    "overridden.");
	}

	#
	# whole file: PKGNAME
	#
	print "OK: checking PKGNAME.\n" if ($verbose);
	if ($whole =~ /\nPKGNAME.?=/) {
		my $lineno = &linenumber($`);
		&perror("FATAL: $file [$lineno]: PKGNAME is obsoleted by PORTNAME, ".
			"PORTVERSION, PKGNAMEPREFIX and PKGNAMESUFFIX.");
	}

	#
	# whole file: IS_INTERACTIVE/NOPORTDOCS
	#
	print "OK: checking IS_INTERACTIVE.\n" if ($verbose);
	if ($whole =~ /\nIS_INTERACTIVE/) {
		if ($whole !~ /defined\((BATCH|FOR_CDROM)\)/) {
			my $lineno = &linenumber($`);
			&perror("WARN: $file [$lineno]: use of IS_INTERACTIVE ".
				"discouraged. provide batch mode by using BATCH and/or ".
				"FOR_CDROM.");
		}
	}
	print "OK: checking for use of NOPORTDOCS.\n" if ($verbose);
	if ($whole =~ /NOPORTSDOC/) {
		my $lineno = &linenumber($`);
		&perror("WARN: $file [$lineno]: NOPORTSDOC found.  Do you ".
			"mean NOPORTDOCS?");
	}
	if ($sharedocused && $whole !~ /defined\s*\(?NOPORTDOCS\)?/
	 && $whole !~ /def\s*\(?NOPORTDOCS\)?/
	 && $whole !~ m#(\$[\{\(]PREFIX[\}\)]|$localbase)/share/doc#) {
		&perror("WARN: $file: use \".if !defined(NOPORTDOCS)\" to wrap ".
			"installation of files into $localbase/share/doc.");
	}

	#
	# whole file: check for USE_GETTEXT
	#
	print "OK: checking for USE_GETTEXT without WITHOUT_NLS.\n" if ($verbose);
	if ($whole =~ /\nUSE_GETTEXT/ && $whole !~ /def(?:ined)?\s*\(?WITHOUT_NLS\)?/) {
			&perror("WARN: $file: Consider adding support for a WITHOUT_NLS ".
					"knob to conditionally disable gettext support.");
	}

	#
	# whole file: check for deprecated commands
	#
	print "OK: checking for deprecated macros.\n" if $verbose;
	%deprecated = (
			USE_LIBTOOL		=> 'USE_LIBTOOL_VER',
			USE_AUTOCONF	=> 'USE_AUTOHEADER_VER',
			USE_AUTOMAKE	=> 'USE_AUTOMAKE_VER',
			WANT_LIBTOOL	=> 'WANT_LIBTOOL_VER',
			WANT_AUTOCONF	=> 'WANT_AUTOCONF_VER',
			WANT_AUTOMAKE	=> 'WANT_AUTOMAKE_VER',
			USE_MESA		=> 'USE_GL',
	);

	for my $depmacro (keys %deprecated) {
		if ($whole =~ /\n($depmacro)[+?:!]?=/) {
			&perror("FATAL: $file: $depmacro is ".
				"deprecated, use $deprecated{$1} instead");
		}
	}

	if ($whole =~ /\n(_USE_BSD_JAVA_MK_1_0)[+?:!]?=/) {
		&perror("WARN: $file: This port uses bsd.java.mk 1.0 syntax. ".
			"You should consider updating it to 2.0 syntax. ".
			"Please refer to the Porter's Handbook for further ".
			"information");
	}

	#
	# whole file: direct use of command names
	#
	my %cmdnames = ();
	print "OK: checking direct use of command names.\n" if ($verbose);
	foreach my $i (qw(
awk basename brandelf cat chmod chown cp cpio dialog dirname egrep expr
false file find gmake grep gzcat ldconfig ln md5 mkdir mv objcopy paste patch
pax perl printf rm rmdir ruby sed sh sort touch tr which xargs xmkmf
	)) {
		$cmdnames{$i} = "\$\{\U$i\E\}";
	}
	$cmdnames{'echo'} = '${ECHO_CMD} or ${ECHO_MSG}';
	$cmdnames{'env'} = '${SETENV}';
	$cmdnames{'gunzip'} = '${GUNZIP_CMD}';
	$cmdnames{'gzip'} = '${GZIP_CMD}';
	$cmdnames{'install'} = '${INSTALL_foobaa}';
	$cmdnames{'python'} = '${PYTHON_CMD}';
	$cmdnames{'strip'} = '${STRIP_CMD}';
	$cmdnames{'unzip'} = '${UNZIP_CMD}';
	foreach my $i (qw(aclocal autoconf autoheader automake autoreconf autoupdate autoscan ifnames libtool libtoolize)) {
		$autocmdnames{$i} = "\$\{" . ( ( $i !~ /auto|aclocal|libtool/ ) ? "AUTO" : "" ) . "\U$i\E\}";
	}
	#
	# ignore parameter string to echo command.
	# note that we leave the command as is, since we need to check the
	# use of echo itself.
	$j = $whole;
	$j =~ s/([ \t][\@\-]{0,2})(echo|\$[\{\(]ECHO[\}\)]|\$[\{\(]ECHO_MSG[\}\)])[ \t]+(?:"(?:\\'|\\"|[^"])*"|'(?:\\'|\\"|[^'])*')[ \t]*;?(\n?)/$1$2;$3/g; #"
	# ignore variables names in .for loops, but not what's at the end
	# of the for loop
	$j =~ s/(\.for +)([^ ]*)( .*)/$1$3/;
	foreach my $i (keys %cmdnames) {
		# XXX This is a hack.  Really, we should break $j up into individual
		# lines, and go through each one.
		while ($j =~ /^(.*$i.*)$/gm) {
			my $curline = $1;
			my $lineno = &linenumber($`);
			if ($curline =~ /(?:^|\s)[\@\-]{0,2}$i(?:$|\s)/
				&& $curline !~ /^[A-Z]+_TARGET[?+]?=[^\n]+$i/m
				&& $curline !~ /^IGNORE(.)?=[^\n]+$i/m
				&& $curline !~ /^BROKEN(.)?=[^\n]+$i/m
				&& $curline !~ /^RESTRICTED(.)?=[^\n]+$i/m
				&& $curline !~ /^NO_PACKAGE(.)?=[^\n]+$i/m
				&& $curline !~ /^NO_CDROM(.)?=[^\n]+$i/m
				&& $curline !~ /^MAINTAINER(.)?=[^\n]+$i/m
				&& $curline !~ /^CATEGORIES(.)?=[^\n]+$i/m
				&& $curline !~ /^#.+$/m
				&& $curline !~ /\-\-$i/m
				&& $curline !~ /^COMMENT(.)?=[^\n]+$i/m) {
					&perror("WARN: $file [$lineno]: possible direct use of ".
						"command \"$i\" found. use ".
						"$cmdnames{$i} instead.");
			}
		}
	}

	foreach my $i (keys %autocmdnames) {
		# XXX Same hack as above.
		while ($j =~ /^(.*($i\d*).*)$/gm) {
			my $lm = $1;
			my $sm = $2;
			my $lineno = &linenumber($`);
			if ($lm =~ /(^|\s+)[\@\-]{0,2}($i\d*)\b/
				&& $lm !~ /^[A-Z]+_TARGET[?+]?=[^\n]+($i\d*)/m
				&& $lm !~ /^IGNORE(.)?=[^\n]+($i\d*)/m
				&& $lm !~ /^BROKEN(.)?=[^\n]+($i\d*)/m
				&& $lm !~ /^RESTRICTED(.)?=[^\n]+($i\d*)/m
				&& $lm !~ /^NO_PACKAGE(.)?=[^\n]+($i\d*)/m
				&& $lm !~ /^NO_CDROM(.)?=[^\n]+($i\d*)/m
				&& $lm !~ /^MAINTAINER(.)?=[^\n]+($i\d*)/m
				&& $lm !~ /^CATEGORIES(.)?=[^\n]+($i\d*)/m
				&& $lm !~ /^#.+$/m
				&& $lm !~ /^COMMENT(.)?=[^\n]+($i\d*)/m) {
					&perror("WARN: $file [$lineno]: possible direct use of ".
						"command \"$sm\" found. Use $autocmdnames{$i} ".
						"instead and set according USE_*_VER= flag");
			}
		}
	}

	#
	# while file: check for use of paths that have macro replacements
	#
	my %pathnames = ();
	print "OK: checking for paths that have macro replacements.\n"
		if ($verbose);
	$pathnames{'${PREFIX}/share/java/classes'} = 'JAVADIR';
	$pathnames{'${PREFIX}/share/java'} = 'JAVASHAREDIR';
	foreach my $i (keys %pathnames) {
		my $lineno = &linenumber($`);
		if ($j =~ m|$i|gm) {
			&perror("FATAL: $file [$lineno]: you should use ".
				"$pathnames{$i} rather than $i");
		}
	}

	#
	# whole file: ldconfig must come with "true" command
	#
	if ($ldconfigwithtrue
	 && $j =~ /(ldconfig|\$[{(]LDCONFIG[)}])/
	 && $j !~ /(\/usr\/bin\/true|\$[{(]TRUE[)}])/) {
	 	my $lineno = &linenumber($`);
		&perror("FATAL: $file [$lineno]: ldconfig must be used with ".
			"\"||\${TRUE}\".");
	}

	#
	# whole file: ${GZIP_CMD} -9 (or any other number)
	#
	if ($j =~ /\${GZIP_CMD}\s+-(\w+(\s+-)?)*(\d)/) {
		my $lineno = &linenumber($`);
		&perror("WARN: $file [$lineno]: possible use of \"\${GZIP_CMD} -$3\" ".
			"found. \${GZIP_CMD} includes \"-\${GZIP}\" which ".
			"sets the compression level.");
	}

	#
	# whole file: ${MKDIR} -p
	#
	if ($j =~ /\${MKDIR}\s+-p/) {
		my $lineno = &linenumber($`);
		&perror("WARN: $file [$lineno]: possible use of \"\${MKDIR} -p\" ".
			"found. \${MKDIR} includes ".
			"\"-p\" by default.");
	}

	#
	# whole file: ${MACHINE_ARCH}
	#
	if ($j =~ /\${MACHINE_ARCH}\s*[!=]=/) {
		my $lineno = &linenumber($`);
		&perror("FATAL: $file [$lineno]: MACHINE_ARCH should never be tested ".
			"directly; use ARCH instead.");
	}

	#
	# whole file: full path name
	#
	&abspathname($whole, $file);

	#
	# whole file: SITE_PERL
	#
	print "OK: checking SITE_PERL.\n" if ($verbose);
	if ($whole =~ /\nSITE_PERL[?:]?=/) {
		my $lineno = &linenumber($`);
		&perror("FATAL: $file [$lineno]: use of SITE_PERL discouraged. ".
				"it is set in bsd.port.mk.");
	}

	#
	# whole file: ${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
	#
	if ($j =~ m'\${(?:LOCALBASE|PREFIX)}/lib/perl5/site_perl/\${PERL_VER}') {
		my $lineno = &linenumber($`);
		&perror("WARN: $file [$lineno]: possible use of \"\${LOCALBASE}/lib/perl5/site_perl/\${PERL_VER}\" ".
				"found. use \"\${SITE_PERL}\" instead.");
	}

	#
	# whole file: USE_GNOME check
	#
	if ($whole =~ /^USE_GNOME[?:]?=\s*(.*)$/m) {
		if ($1 =~ /gnomehack/) {
			$use_gnome_hack = 1;
		}
	}

	#
	# whole file: USE_JAVA check
	#
	if ($whole =~ /^USE_JAVA[?:]?=\s*(.*)$/m) {
		$use_java = 1;
	}

	#
	# whole file: USE_ANT check
	#
	if ($whole =~ /^USE_ANT[?:]?=\s*(.*)$/m) {
		$use_ant = 1;
	}

	#
	# whole file: USE_JAVA not defined, but other Java components are requested
	#
	if (!$use_java && ($use_ant || $whole =~ /^JAVA_VERSION[?:]?=\s*(.*)$/m ||
		$whole =~ /^JAVA_OS[?:]?=\s*(.*)$/m ||
		$whole =~ /^JAVA_VENDOR[?:]?=\s*(.*)$/m ||
		$whole =~ /^JAVA_RUN[?:]?=\s*(.*)$/m ||
		$whole =~ /^JAVA_BUILD[?:]?=\s*(.*)$/m ||
		$whole =~ /^USE_JIKES[?:]?=\s*(.*)$/m)) {
		&perror("FATAL: $file: the port uses Java features, but USE_JAVA ".
			"is not defined");
	}

	#
	# whole file: check for USE_ANT and USE_GMAKE both defined
	#
	if ($use_ant && $whole =~ /^USE_GMAKE[?:]?=\s*(.*)$/m) {
		&perror("WARN: $file: a port shall not define both USE_ANT ".
			"and USE_GMAKE");
	}

	#
	# whole file: check for JAVA_BUILD and NO_BUILD
	#
	if ($whole =~ /^NO_BUILD[?:]?=\s*(.*)$/m &&
		$whole =~ /^JAVA_BUILD[?:]?=\s*(.*)$/m) {
		&perror("FATAL: $file: JAVA_BUILD and NO_BUILD cannot be set ".
			"at the same time");
	}

	#
	# slave port check
	#
	my $masterdir = $makevar{MASTERDIR};
	if ($masterdir ne '' && $masterdir ne $makevar{'.CURDIR'}) {
		$slaveport = 1;
		print "OK: slave port detected, checking for inclusion of $masterdir/Makefile.\n"
			if ($verbose);
		if ($whole =~ /^\.\s*include\s*[<"]bsd\.port(?:\.post)?\.mk[">]/m) {
			&perror("FATAL: $file: supposedly non-slave port with".
				" .CURDIR != MASTERDIR");
		} elsif ($whole =~ /^\.\s*include\s*[<"]bsd\.port\.pre\.mk[">]/m) {
			&perror("FATAL: $file: slave ports may not include".
				" bsd.port.pre.mk");
		}
		if ($whole !~ /\n\.include\s+"\$\{MASTERDIR\}\/Makefile"\s*$/s) {
			&perror("FATAL: $file: the last line of a slave port's Makefile has to be".
				' .include "${MASTERDIR}/Makefile"');
		}
		print "OK: checking master port in $masterdir.\n" if ($verbose);
		if (! -e "$masterdir/Makefile") {
			&perror("WARN: unable to locate master port in $masterdir");
		}
		if ($whole !~ /^MASTERDIR=\s*\$\{\.CURDIR\}(?:\/\.\.){1,2}(?:\/[\w\@.+-]+){1,2}\s*$/m) {
			&perror("WARN: $file: slave ports must define MASTERDIR=".
				'${.CURDIR}/..(/../<category>)/<port>');
		}
	} else {
		#$slaveport = 0;
		print "OK: non-slave port detected, checking for anything after bsd.port(.post).mk.\n"
			if ($verbose);
		if ($whole !~ /\n\.include\s+<bsd\.port(?:\.post)?\.mk>\s*$/s) {
			&perror("FATAL: $file: the last line of Makefile has to be".
				' .include <bsd.port(.post).mk>');
		}
		if ($whole =~ /^MASTERDIR\s*[+?:!]?\s*=/m) {
			&perror("WARN: $file: non-slave ports may not define MASTERDIR");
		}
	}

	#
	# break the makefile into sections.
	#
	$tmp = $rawwhole;
	# keep comment, blank line, comment in the same section
	$tmp =~ s/(#.*\n)\n+(#.*)/$1$2/g;
	@sections = split(/\n\n+/, $tmp);
	for ($i = 0; $i <= $#sections; $i++) {
		if ($sections[$i] !~ /\n$/) {
			$sections[$i] .= "\n";
		}
	}
	$idx = 0;

	#
	# section 1: comment lines.
	#
	print "OK: checking comment section of $file.\n" if ($verbose);
	my @linestocheck = split("\n", <<EOF);
Whom
Date [cC]reated
EOF
	if ($osname eq 'NetBSD') {
		unshift(@linestocheck, '(New )?[pP](ackage|ort)s [cC]ollection [mM]akefile [fF]or');
	} else {
		unshift(@linestocheck, '(New )?[pP]orts [cC]ollection [mM]akefile [fF]or');
	}
	$tmp = $sections[$idx++];
	$tmp = "\n" . $tmp;	# to make the begin-of-line check easier

	if ($tmp =~ /\n[^#]/) {
		&perror("FATAL: $file: non-comment line in comment section.");
	}
	foreach my $i (@linestocheck) {
		$j = $i;
		$j =~ s/\(.*\)\?//g;
		$j =~ s/\[(.)[^\]]*\]/$1/g;
		if ($tmp !~ /# $i:[ \t]+\S+/) {
			&perror("FATAL: $file: no \"$j\" line in comment section.");
		} else {
			print "OK: \"$j\" seen in $file.\n" if ($verbose);
		}
	}
	if ($tmp =~ m/Version [rR]equired/) {
		&perror("WARN: $file: Version required is no longer needed in the comment section.");
	}
	my $tmp2 = "";
	for (split(/\n/, $tmp)) {
		$tmp2 .= $_ if (m/\$$rcsidstr/);
	}
	if ($tmp2 !~ /#(\s+)\$$rcsidstr([^\$]*)\$$/) {

		&perror("FATAL: $file: no \$$rcsidstr\$ line in comment ".
			"section.");
	} else {
		print "OK: \$$rcsidstr\$ seen in $file.\n" if ($verbose);
		if ($1 ne ' ') {
			&perror("WARN: $file: please use single whitespace ".
				"right before \$$rcsidstr\$ tag.");
		}
		if ($2 ne '') {
			if ($verbose || $newport) {	# XXX
				&perror("WARN: $file: ".
				    ($newport ? 'for new port, '
					      : 'is it a new port? if so, ').
				    "make \$$rcsidstr\$ tag in comment ".
				    "section empty, to make CVS happy.");
			}
		}
	}

	#
	# for the rest of the checks, comment lines are not important.
	#
	for ($i = 0; $i < scalar(@sections); $i++) {
		$sections[$i] = "\n" . $sections[$i];
		$sections[$i] =~ s/\n#[^\n]*//g;
		$sections[$i] =~ s/\n\n+/\n/g;
		$sections[$i] =~ s/\\\n/ /g;
		$sections[$i] =~ s/^\n//;
	}

	#
	#
	# section 2: PORTNAME/PORTVERSION/...
	#
	print "OK: checking first section of $file (PORTNAME/...).\n"
		if ($verbose);
	$tmp = $sections[$idx++];

	# check the order of items.
	&checkorder('PORTNAME', $tmp, $file, qw(
PORTNAME PORTVERSION DISTVERSIONPREFIX DISTVERSION DISTVERSIONSUFFIX
PORTREVISION PORTEPOCH CATEGORIES MASTER_SITES MASTER_SITE_SUBDIR
PKGNAMEPREFIX PKGNAMESUFFIX DISTNAME EXTRACT_SUFX DISTFILES
DIST_SUBDIR EXTRACT_ONLY
	));

	# check the items that has to be there.
	$tmp = "\n" . $tmp;
	print "OK: checking PORTNAME/PORTVERSION/DISTVERSION.\n" if ($verbose);
	if ($tmp !~ /\nPORTNAME(.)?=/) {
		&perror("FATAL: $file: PORTNAME has to be there.") unless ($slaveport && $makevar{PORTNAME} ne '');
	} elsif ($1 ne '') {
		&perror("WARN: $file: unless this is a master port, PORTNAME has to be set by \"=\", ".
			"not by \"$1=\".") unless ($masterport);
	}
	if ($tmp !~ /\n(PORTVERSION|DISTVERSION)(.)?=/) {
		&perror("FATAL: $file: PORTVERSION or DISTVERSION has to be there.") unless ($slaveport && ($makevar{PORTVERSION} ne '' || $makevar{DISTVERSION} ne ''));
	} elsif ($2 ne '') {
		&perror("WARN: $file: unless this is a master port, PORTVERSION has to be set by \"=\", ".
			"not by \"$2=\".") unless ($masterport);
	}
	if ($tmp =~ /\nPORTVERSION.?=/ && $tmp =~ /\nDISTVERSION.?=/) {
		&perror("FATAL: $file: either PORTVERSION or DISTVERSION must be ".
			"specified, not both.");
	}
	if ($newport) {
		print "OK: checking for existence of PORTREVISION in new port.\n"
			if ($verbose);
		if ($tmp =~ /^PORTREVISION(.)?=/m) {
			&perror("WARN: $file: new ports should not set PORTREVISION.");
		}
	}
	if ($newport) {
		print "OK: checking for existence of PORTEPOCH in new port.\n"
			if ($verbose);
		if ($tmp =~ /^PORTEPOCH(.)?=/m) {
			&perror("WARN: $file: new ports should not set PORTEPOCH.");
		}
	}
	print "OK: checking CATEGORIES.\n" if ($verbose);
	if ($tmp !~ /\nCATEGORIES(.)?=/) {
		&perror("FATAL: $file: CATEGORIES has to be there.") unless ($slaveport && $makevar{CATEGORIES} ne '');
	} elsif (($i = $1) ne '' && $i =~ /[^?+]/) {
		&perror("WARN: $file: unless this is a master port, CATEGORIES should be set by \"=\", \"?=\", or \"+=\", ".
			"not by \"$i=\".") unless ($masterport);
	}

	@cat = split(/\s+/, $makevar{CATEGORIES});
	if (@cat == 0) {
		&perror("FATAL: $file: CATEGORIES left blank. set it to \"misc\"".
		" if nothing seems apropriate.");
	}

	if ($use_java && !grep /^java$/, @cat) {
		&perror("WARN: $file: the port uses Java but is not part of the ".
			"``java'' category");
	}

	if (scalar(@cat) == 1 && $cat[0] eq "java") {
		&perror("FATAL: $file: the ``java'' category shall not be the only ".
			"one for a port");
	}

	if ($newport && scalar(@cat) > 0 && $cat[0] eq "java") {
		&perror("WARN: $file: save for ports directly related to the Java ".
			"language, porters are encouraged not to use ``java'' as ".
			"the main category for a port");
	}

	if ($committer && $makevar{'.CURDIR'} =~ m'${portsdir}/([^/]+)/[^/]+/?$') {
		if ($cat[0] ne $1 && $makevar{PKGCATEGORY} ne $1 ) {
			&perror("FATAL: $file: category \"$1\" must be listed first");
		}
	}

#MICHAEL: can these three lang cat checks be combined?
	# skip the first category specification if it's a language specific one.
	if (grep($_ eq $cat[0], @lang_cat)) {
		$has_lang_cat = 1;
		$port_lang = $lang_pref{$cat[0]};
		shift @cat;
	}

	# skip further if more language specific ones follow.
	if (@cat && grep($_ eq $cat[0], @lang_cat)) {
		&perror("WARN: $file: multiple language specific categories detected. ".
		"are you sure?");
		do {
			shift @cat;
		} while (@cat && grep($_ eq $cat[0], @lang_cat));
	}

	# check x11 in CATEGORIES
	if ($newxdef) {
#MICHAEL: I don't understand this line
		if (2 <= @cat && $cat[1] eq "x11") {
			&perror("WARN: $file: only specific kind of apps should ".
				"specify \"x11\" in CATEGORIES. ".
				"Do you mean just USE_XLIB? ".
				"Then remove \"x11\" from CATEGORIES.");
		}
	}

	if (2 <= @cat) {
		# skip the first one that we know is _not_ language specific.
		shift @cat;

		# any language specific one after non language specific ones?
		foreach my $cat (@cat) {
			if (grep($_ eq $cat, @lang_cat)) {
				$has_lang_cat = 1;
				$port_lang = $lang_pref{$cat};
				&perror("WARN: $file: when you specify multiple categories, ".
				"language specific category should come first.");
			}
		}
	}

	# check the URL
	if (($tmp =~ /\nMASTER_SITES[+?]?=[ \t]*([^\n]*)\n/
	 && $1 !~ /^[ \t]*$/) || ($makevar{MASTER_SITES} ne '')) {
		print "OK: seen MASTER_SITES, sanity checking URLs.\n"
			if ($verbose);
		my @sites = split(/\s+/, $1);
		my $skipnext = 0;
		foreach my $i (@sites) {
			if ($skipnext) {
				$skipnext = 0;
				next;
			}
			$skipnext++ if ($i =~ /^#/);
			if ($i =~ m#^\w+://#) {
				&urlcheck($i, $file);
				unless (&is_predefined($i, $file)) {
					print "OK: URL \"$i\" ok.\n"
						if ($verbose);
				}
			} else {
				print "OK: non-URL \"$i\" ok.\n"
					if ($verbose);
			}
		}
	} else {
		&perror("WARN: $file: no MASTER_SITES found. is it ok?");
	}

	# check DISTFILES and related items.
	$distfiles = $1 if ($tmp =~ /\nDISTFILES[+?]?=[ \t]*([^\n]+)\n/);
	#$portname = $1 if ($tmp =~ /\nPORTNAME[+?]?=[ \t]*([^\n]+)\n/);
	#$portversion = $1 if ($tmp =~ /\nPORTVERSION[+?]?=[ \t]*([^\n]+)\n/);
	$portname = $makevar{PORTNAME};
	$portversion = $makevar{PORTVERSION};
	$distversionprefix = $makevar{DISTVERSIONPREFIX};
	$distversion = $makevar{DISTVERSION};
	$distversionsuffix = $makevar{DISTVERSIONSUFFIX};
	$distname = $1 if ($tmp =~ /\nDISTNAME[+?]?=[ \t]*([^\n]+)\n/);
	$extractsufx = $1 if ($tmp =~ /\nEXTRACT_SUFX[+?]?=[ \t]*([^\n]+)\n/);

	# check bogus EXTRACT_SUFX.
	if ($extractsufx ne '') {
		print "OK: seen EXTRACT_SUFX, checking value.\n" if ($verbose);
		if ($distfiles ne '') {
			&perror("WARN: $file: no need to define EXTRACT_SUFX if ".
				"DISTFILES is defined.");
		}
		if ($extractsufx eq '.tar.gz') {
			&perror("WARN: $file: EXTRACT_SUFX is \".tar.gz.\" ".
				"by default. you don't need to specify it.");
		}
	} else {
		print "OK: no EXTRACT_SUFX seen, using default value.\n"
			if ($verbose);
		$extractsufx = '.tar.gz';
	}

	print "OK: sanity checking PORTNAME/PORTVERSION/DISTVERSIONPREFIX/DISTVERSION/DISTVERSIONSUFFIX.\n" if ($verbose);
	if ($distname ne '') {
		if ($distname eq "$portname-$portversion") {
			&perror("WARN: $file: DISTNAME is \${PORTNAME}-\${PORTVERSION} by ".
				"default, you don't need to define DISTNAME.");
		} else {
			if ($distname eq "$portname-$distversionprefix$distversion$distversionsuffix") {
				&perror("WARN: $file: DISTNAME is \${PORTNAME}-\${DISTVERSIONPREFIX}\${DISTVERSION}\${DISTVERSIONSUFFIX} by ".
					"default, you don't need to define DISTNAME.");
			}
		}
		if ($distname =~ /PORTREVISION/) {
			&perror("FATAL: $file: DISTNAME contains a reference to ".
				"PORTREVISION.  You should only be using PORTVERSION");
		}
		if ($distname =~ /PORTEPOCH/) {
			&perror("FATAL: $file: DISTNAME contains a reference to ".
				"PORTEPOCH.  You should only be using PORTVERSION");
		}
	}
	if ($portname =~ /^$re_lang_short/) {
		&perror("FATAL: $file: language prefix is automatically".
			" set by PKGNAMEPREFIX.".
			" you must remove it from PORTNAME.");
	}
	if ($portname =~ /([|<>=! ])/) {
		&perror("FATAL: $file: PORTNAME contains the illegal character \"$1\".".
			" You should modify \"$portname\".");
	} elsif ($portname =~ /\$[\{\(].+[\}\)]/) {
		&perror("WARN: $file: using variable in PORTNAME.".
			" consider using PKGNAMEPREFIX and/or PKGNAMESUFFIX.");
	} elsif ($portname =~ /([^\w._@+-])/) {
		&perror("WARN: $file: using \"$1\" in PORTNAME.".
			" You should modify \"$portname\".");
	} elsif ($portname =~ /-/ && $distname ne '') {
		&perror("WARN: $file: using hyphen in PORTNAME.".
			" consider using PKGNAMEPREFIX and/or PKGNAMESUFFIX.");
	}
	if ($portversion eq '' && $distversion eq '') {
		&perror("FATAL: $file: either PORTVERSION or DISTVERSION must be specified");
	}
	if ($portversion =~ /^pl[0-9]*$/
	|| $portversion =~ /^[0-9]*[A-Za-z]?[0-9]*(\.[0-9]*[A-Za-z]?[0-9+]*)*$/) {
		print "OK: PORTVERSION \"$portversion\" looks fine.\n" if ($verbose);
	} elsif ($portversion =~ /^[^\-]*\$[{\(].+[\)}][^\-]*$/) {
		&perror("WARN: $file: using variable, \"$portversion\", as version ".
			"number");
	} elsif ($portversion =~ /([-,_<>=! #*])/) {
		&perror("FATAL: $file: PORTVERSION must not contain \"$1\". ".
			"You should modify \"$portversion\".");
	} else {
		&perror("FATAL: $file: PORTVERSION looks illegal. ".
			"You should modify \"$portversion\".");

	}

	$pkg_version = $makevar{PKG_VERSION};

	if ($makevar{CONFLICTS}) {
		print "OK: checking CONFLICTS.\n" if ($verbose);
		foreach my $conflict (split ' ', $makevar{CONFLICTS}) {
			my $selfconflict;
			if ($makevar{PKGINSTALLVER} >= 20040125) {
				$selfconflict = !system($pkg_version, '-T',
					$makevar{PKGNAME}, $conflict);
			} else {
				my $conflictre = $conflict;
				$conflictre =~ s/[.+]/\\$&/g;
				$conflictre =~ s/\*/.*/g;
				$conflictre =~ s/\?/./g;
				$conflictre =~ s/\[!/[^/g;
				$selfconflict = ($makevar{PKGNAME} =~ /^$conflictre$/);
			}
			if ($conflict !~ /(?:[<>=]|[]?*]$)/) {
				&perror("WARN: Conflict \"$conflict\" specified too narrow. ".
					"You should end it with a wildcard (-[0-9]*).");
			} elsif ($conflict !~ /[<>=-][^-]*[0-9][^-]*$/) {
				&perror("WARN: Conflict \"$conflict\" specified too broad. ".
					"You should end it with a version number fragment (-[0-9]*).");
			}
			if ($selfconflict) {
				&perror("FATAL: Package conflicts with itself. ".
					"You should remove \"$conflict\" from CONFLICTS.");
			}
		}
	}

	$versiondir = $ENV{VERSIONDIR} ? $ENV{VERSIONDIR} : '/var/db/chkversion';

	$versionfile = "$versiondir/VERSIONS";
	$useindex = !-r "$versionfile";

	$versionfile = "$portsdir/$makevar{INDEXFILE}"
		if $useindex;

	if (-r "$versionfile") {
		print "OK: checking if PORTVERSION is going backwards.\n" if ($verbose);
		open VERSIONS, "<$versionfile";

		while (<VERSIONS>) {
			my($origin, $version) = ('', '');
			chomp;
			next if /^(#|$)/;
			if ($useindex) {
				($version, $origin) = split /\|/;
				$origin =~ s,^.*/([^/]+/[^/]+)/?$,$1,;
			} else {
				($origin, $version) = split;
			}
			if ($origin eq $makevar{PKGORIGIN}) {
				my $newversion = $makevar{PKGNAME};
				my $oldversion = $version;
				my $result = '';

				$newversion =~ s/^.*-//;
				$oldversion =~ s/^.*-//;

				$result = `$pkg_version -t '$newversion' '$oldversion'`;
				chomp $result;
				if ($result eq '<') {
					&perror("FATAL: $file: $makevar{PKGNAME} < $version. ".
						"Choose another PORTVERSION or bump PORTEPOCH.");
				#	$backwards{$origin} = "$pkgname{$origin} < $version";
				}
				last;
			}
		}
		close VERSIONS;
	}

	# if DISTFILES have only single item, it is better to avoid DISTFILES
	# and to use combination of DISTNAME and EXTRACT_SUFX.
	# example:
	#	DISTFILES=package-1.0.tgz
	# should be
	#	DISTNAME=     package-1.0
	#	EXTRACT_SUFX= .tgz
	if ($distfiles =~ /^\S+$/ && $distfiles !~ /:[^\/:]+$/) {
		$bogusdistfiles++;
		print "OK: seen DISTFILES with single item, checking value.\n"
			if ($verbose);
		&perror("WARN: $file: use of DISTFILES with single file ".
			"discouraged. distribution filename should be set by ".
			"DISTNAME and EXTRACT_SUFX.");
		if ($distfiles eq (($distname ne '') ? $distname : "$portname-$portversion") . $extractsufx) {
			&perror("WARN: $file: definition of DISTFILES not necessary. ".
				"DISTFILES is \${DISTNAME}/\${EXTRACT_SUFX} ".
				"by default.");
		}

		# display advice only in certain cases.
#MICHAEL: will this work with multiple distfiles in this list?  what about
#         doing the same sort of thing for DISTNAME, is it needed?
		if ($distfiles =~ /^\Q$i\E([\-.].+)$/) {
			&perror("WARN: $file: how about \"EXTRACT_SUFX=$1\"".
				", instead of DISTFILES?");
		}
	}

	# additional checks for committer.
	if ($committer && $has_lang_cat) {
		&perror("WARN: $file: be sure to include language code ".
			"\"$port_lang-\" ".
			"in the module alias name.");
	}

	if ($committer) {
		if (opendir(DIR, ".")) {
			my @tgz = grep(/\.tgz$/, readdir(DIR));
			closedir(DIR);

			if (@tgz) {
				my $tgz = (2 <= @tgz)
				? '{' . join(',', @tgz) . '}'
				: $tgz[0];

				&perror("WARN: be sure to remove $portdir/$tgz ".
				"before committing the port.");
			}
		}
	}

	push(@varnames, qw(
PORTNAME PORTVERSION PORTREVISION PORTEPOCH CATEGORIES MASTER_SITES
MASTER_SITE_SUBDIR PKGNAMEPREFIX PKGNAMESUFFIX DISTNAME EXTRACT_SUFX
DISTFILES EXTRACT_ONLY
	));

	#
	# section 3: PATCH_SITES/PATCHFILES(optional)
	#
	print "OK: checking second section of $file (PATCH*: optional).\n"
		if ($verbose);
	$tmp = $sections[$idx];

	if ($tmp =~ /(PATCH_SITES|PATCH_SITE_SUBDIR|PATCHFILES|PATCH_DIST_STRIP)/) {
		&checkearlier($file, $tmp, @varnames);

		if ($tmp =~ /^PATCH_SITES=/) {
			print "OK: seen PATCH_SITES.\n" if ($verbose);
			$tmp =~ s/^[^\n]+\n//;
		}
		if ($tmp =~ /^PATCH_SITE_SUBDIR=/) {
			print "OK: seen PATCH_SITE_SUBDIR.\n" if ($verbose);
			$tmp =~ s/^[^\n]+\n//;
		}
		if ($tmp =~ /^PATCHFILES=/) {
			print "OK: seen PATCHFILES.\n" if ($verbose);
			$tmp =~ s/^[^\n]+\n//;
		}
		if ($tmp =~ /^PATCH_DIST_STRIP=/) {
			print "OK: seen PATCH_DIST_STRIP.\n" if ($verbose);
			$tmp =~ s/^[^\n]+\n//;
		}

		&checkextra($tmp, 'PATCH_SITES', $file);

		$idx++;
	}

	push(@varnames, qw(
PATCH_SITES PATCHFILES PATCH_DIST_STRIP
	));

	#
	# section 4: MAINTAINER
	#
	print "OK: checking third section of $file (MAINTAINER).\n"
		if ($verbose);
	$tmp = $sections[$idx++];

	&checkearlier($file, $tmp, @varnames);
	&checkorder('MAINTAINER', $tmp, $file, qw(
MAINTAINER COMMENT
	));

	$tmp = "\n" . $tmp;
	if ($tmp =~ /\nMAINTAINER\??=([^\n]+)/) {
		my $addr = $1;
		$addr =~ s/^\s*//;
		$addr =~ s/\s*$//;
		if ($addr =~ /[\s,<>()]/) {
			&perror("FATAL: $file: MAINTAINER should be a single address without comment.");
		}
		if ($addr !~ /^[^\@]+\@[\w\d\-\.]+$/) {
			&perror("FATAL: $file: MAINTAINER address, $addr, does not appear to be a valid email address.");
		}
		$tmp =~ s/\nMAINTAINER\??=[^\n]+//;
	} elsif ($whole !~ /\nMAINTAINER[?]?=/) {
		&perror("FATAL: $file: no MAINTAINER listed.") unless ($slaveport && $makevar{MAINTAINER} ne '');
	}
	$tmp =~ s/\n\n+/\n/g;

	# check COMMENT
	if ($tmp !~ /\nCOMMENT(.)?=/) {
		&perror("FATAL: $file: COMMENT has to be there.") unless ($slaveport && $makevar{COMMENT} ne '');
	} elsif ($1 ne '') {
		&perror("WARN: $file: unless this is a master port, COMMENT has to be set by \"=\", ".
			"not by \"$1=\".") unless ($masterport);
	} else { # check for correctness
		if (($makevar{COMMENT} !~ /^["0-9A-Z]/) || ($makevar{COMMENT} =~ m/\.$/)) { #"
			&perror("WARN: $file: COMMENT should begin with a capital, and end without a period");
		} elsif (length($makevar{COMMENT}) > 70) {
			&perror("WARN: $file: COMMENT exceeds 70 characters limit.");
		}
	}

	push(@varnames, qw(
MAINTAINER COMMENT
	));

	#
	# section 5: *_DEPENDS (may not be there)
	#
	print "OK: checking fourth section of $file (*_DEPENDS).\n"
		if ($verbose);
	$tmp = $sections[$idx];

	# NOTE: EXEC_DEPENDS is obsolete, so it should not be listed.
	@linestocheck = qw(
EXTRACT_DEPENDS LIB_DEPENDS PATCH_DEPENDS BUILD_DEPENDS RUN_DEPENDS
FETCH_DEPENDS DEPENDS DEPENDS_TARGET
	);

	if ($tmp =~ /(LIB_|BUILD_|RUN_|FETCH_)?DEPENDS/) {
		&checkearlier($file, $tmp, @varnames);

		my %seen_depends;

		if (!defined $ENV{'PORTSDIR'}) {
			$ENV{'PORTSDIR'} = $portsdir;
		}
		foreach my $i (grep(/^[A-Z_]*DEPENDS[?+]?=/, split(/\n/, $tmp))) {
			$i =~ s/^([A-Z_]*DEPENDS)[?+]?=[ \t]*//;
			$j = $1;
			$seen_depends{$j}++;
			if ($j ne 'DEPENDS' &&
				$i =~ /^\${([A-Z_]+DEPENDS)}\s*$/ &&
				$seen_depends{$1} &&
				$j ne $1)
			{
				print "OK: $j refers to $1, skipping checks.\n"
					if ($verbose);
				next;
			}
			print "OK: checking ports listed in $j.\n"
				if ($verbose);
			foreach my $k (split(/\s+/, $i)) {
				my @l = split(':', $k);

				print "OK: checking dependency value for $j.\n"
					if ($verbose);
				if (($j eq 'DEPENDS'
				  && scalar(@l) != 1 && scalar(@l) != 2)
				 || ($j ne 'DEPENDS'
				  && scalar(@l) != 2 && scalar(@l) != 3)) {
					&perror("WARN: $file: wrong dependency value ".
						"for $j. $j requires ".
						($j eq 'DEPENDS'
							? "1 or 2 "
							: "2 or 3 ").
						"colon-separated tuples.");
					next;
				}
				my %m = ();
				if ($j eq 'DEPENDS') {
					$m{'dir'} = $l[0];
					$m{'tgt'} = $l[1];
				} else {
					$m{'dep'} = $l[0];
					$m{'dir'} = $l[1];
					$m{'tgt'} = $l[2];
				}
				print "OK: dep=\"$m{'dep'}\", ".
					"dir=\"$m{'dir'}\", tgt=\"$m{'tgt'}\"\n"
					if ($verbose);

				# check USE_PERL5
				if ($m{'dep'} =~ /^perl5(\.\d+)?$/) {
					&perror("WARN: $file: dependency to perl5 ".
						"listed in $j. consider using ".
						"USE_PERL5.");
				}

				# check USE_ICONV
				if ($m{'dep'} =~ /^(iconv\.\d+)$/) {
					&perror("WARN: $file: dependency to $1 ".
						"listed in $j.  consider using ".
						"USE_ICONV.");
				}

				# check USE_GETTEXT
				if ($m{'dep'} =~ /^(intl\.\d+)$/) {
					&perror("WARN: $file: dependency to $1 ".
						"listed in $j.  consider using ".
						"USE_GETTEXT.");
				}

				# check USE_GMAKE
				if ($m{'dep'} =~ /^(gmake|\${GMAKE})$/) {
					&perror("WARN: $file: dependency to $1 ".
						"listed in $j. consider using ".
						"USE_GMAKE.");
				}

				# check USE_QT
				if ($m{'dep'} =~ /^(qt\d)+$/) {
					&perror("WARN: $file: dependency to $1 ".
						"listed in $j. consider using ".
						"USE_QT.");
				}

				# check USE_GETOPT_LONG
				if ($m{'dep'} =~ /^(gnugetopt\.\d)+$/) {
					&perror("WARN: $file: dependency to $1 ".
							"listed in $j.  consider using ".
							"USE_GETOPT_LONG.");
				}

				# check LIBLTDL
				if ($m{'dep'} =~ /^(ltdl\.\d)+$/) {
					&perror("WARN: $file: dependency to $1 ".
						"listed in $j.  consider using ".
						"USE_LIBLTDL.");
				}

				# check JAVALIBDIR
				if ($m{'dep'} =~ m|share/java/classes|) {
					&perror("FATAL: $file: you should use \${JAVALIBDIR} ".
						"in BUILD_DEPENDS/RUN_DEPENDS to define ".
						"dependencies on JAR files installed in ".
						"\${JAVAJARDIR}");
				}

				# check backslash in LIB_DEPENDS
				if ($osname eq 'NetBSD' && $j eq 'LIB_DEPENDS'
				 && $m{'dep'} =~ /\\\\./) {
					&perror("WARN: $file: use of backslashes in ".
						"$j is deprecated.");
				}

				# check for PREFIX
				if ($m{'dep'} =~ /\${PREFIX}/) {
					&perror("FATAL: $file: \${PREFIX} must not be ".
						"contained in *_DEPENDS. ".
						"use \${LOCALBASE} or ".
						"\${X11BASE} instead.");
				}

				# check port dir existence
				$k = $m{'dir'};
				$k =~ s/\${PORTSDIR}/$ENV{'PORTSDIR'}/;
				$k =~ s/\$[\({]PORTSDIR[\)}]/$ENV{'PORTSDIR'}/;
				if (! -d $k) {
					&perror("WARN: $file: no port directory $k ".
						"found, even though it is ".
						"listed in $j.");
				} else {
					print "OK: port directory $k found.\n"
						if ($verbose);
				}
			}
		}
		foreach my $i (@linestocheck) {
			$tmp =~ s/$i[?+]?=[^\n]+\n//g;
		}

		&checkextra($tmp, '*_DEPENDS', $file);

		$idx++;
	}

	push(@varnames, @linestocheck);
	&checkearlier($file, $tmp, @varnames);

	#
	# Makefile 6: check the rest of file
	#
	print "OK: checking the rest of the $file.\n" if ($verbose);
	$tmp = join("\n\n", @sections[$idx .. scalar(@sections)-1]);

	$tmp = "\n" . $tmp;	# to make the begin-of-line check easier

	&checkearlier($file, $tmp, @varnames);

	# check WRKSRC/NO_WRKSUBDIR
	#
	# do not use DISTFILES/DISTNAME to control over WRKSRC.
	# DISTNAME is for controlling distribution filename.
	# example:
	#	DISTNAME= package
	#	DISTFILES=package-1.0.tgz
	# should be
	#	DISTNAME=    package-1.0
	#	EXTRACT_SUFX=.tgz
	#	WRKSRC=      ${WRKDIR}/package
	#
	print "OK: checking WRKSRC.\n" if ($verbose);
	$wrksrc = $nowrksubdir = '';
	$wrksrc = $1 if ($tmp =~ /\nWRKSRC[+?]?=[ \t]*([^\n]*)\n/);
	$nowrksubdir = $1 if ($tmp =~ /\nNO_WRKSUBDIR[+?]?=[ \t]*([^\n]*)\n/);
	if ($nowrksubdir eq '') {
		$realwrksrc = $wrksrc ? "$wrksrc/$distname"
				      : "\${WRKDIR}/$distname";
	} else {
		$realwrksrc = $wrksrc ? $wrksrc : '${WRKDIR}';
	}
	print "OK: WRKSRC seems to be $realwrksrc.\n" if ($verbose);

	if ($nowrksubdir eq '') {
		print "OK: no NO_WRKSUBDIR, checking value of WRKSRC.\n"
			if ($verbose);
		if ($wrksrc eq 'work' || $wrksrc =~ /^$[\{\(]WRKDIR[\}\)]/) {
			&perror("WARN: $file: WRKSRC is set to meaningless value ".
				"\"$1\".".
				($nowrksubdir eq ''
					? " use \"NO_WRKSUBDIR=yes\" instead."
					: ""));
		}
		if ($bogusdistfiles) {
			if ($distname ne '' && $wrksrc eq '') {
			    &perror("WARN: $file: do not use DISTFILES and DISTNAME ".
				"to control WRKSRC. how about ".
				"\"WRKSRC=\${WRKDIR}/$distname\"?");
			} else {
			    &perror("WARN: $file: DISTFILES/DISTNAME affects WRKSRC. ".
				"take caution when changing them.");
			}
		}
	} else {
		print "OK: seen NO_WRKSUBDIR, checking value of WRKSRC.\n"
			if ($verbose);
		if ($wrksrc eq 'work' || $wrksrc =~ /^$[\{\(]WRKDIR[\}\)]/) {
			&perror("WARN: $file: definition of WRKSRC not necessary. ".
				"WRKSRC is \${WRKDIR} by default.");
		}
	}

	# check RESTRICTED/NO_CDROM/NO_PACKAGE
	print "OK: checking RESTRICTED/NO_CDROM/NO_PACKAGE.\n" if ($verbose);
	if ($committer && $tmp =~ /\n(RESTRICTED|NO_CDROM|NO_PACKAGE)[+?]?=/) {
		&perror("WARN: $file: \"$1\" found. do not forget to update ".
			"ports/LEGAL.");
	}

	# check NO_CONFIGURE/NO_PATCH
	print "OK: checking NO_CONFIGURE/NO_PATCH.\n" if ($verbose);
	if ($tmp =~ /\n(NO_CONFIGURE|NO_PATCH)[+?]?=/) {
		&perror("FATAL: $file: \"$1\" was obsoleted. remove this.");
	}

	# check MAN[1-9LN]
	print "OK: checking MAN[0-9LN].\n" if ($verbose);
	foreach my $i (keys %plistmanall) {
		print "OK: pkg-plist MAN$i=$plistmanall{$i}\n" if ($verbose);
	}
	if ($tmp =~ /PERL_CONFIGURE=\s*/
		&& $tmp =~ /MAN3PREFIX=\s*\${PREFIX}\/lib\/perl5\/\${PERL_VERSION}/) {
		&perror("WARN: $file: MAN3PREFIX is ".
			"\"\${PREFIX}/lib/perl5/\${PERL_VERSION}\" ".
			"when PERL_CONFIGURE is set.  You do not need to specify it.");
	}
	foreach my $i (split(//, $manchapters)) {
		if ($tmp =~ /MAN\U$i\E=\s*([^\n]*)\n/) {
			print "OK: Makefile MAN\U$i\E=$1\n" if ($verbose);
		}
	}
	foreach my $i (split(//, $manchapters)) {
		next if ($i eq '');
		if ($tmp =~ /MAN\U$i\E=\s*([^\n]*)\n/) {
			@mman = grep($_ !~ /^\s*$/, split(/\s+/, $1));
			@pman = grep($_ !~ /^\s*$/,
				split(/\s+/, $plistmanall{$i}));
			foreach my $j (@mman) {
				print "OK: checking $j (Makefile)\n"
					if ($verbose);
				if ($automan && grep($_ eq $j, @pman)) {
					&perror("FATAL: $file: duplicated manpage ".
						"entry $j: content of ".
						"MAN\U$i\E will be automatically ".
						"added to pkg-plist.");
				} elsif (!$automan && !grep($_ eq $j, @pman)) {
					&perror("WARN: $file: manpage $j ".
						"MAN\U$i\E but not in pkg-plist.");
				}
			}
			foreach my $j (@pman) {
				print "OK: checking $j (pkg-plist)\n" if ($verbose);
				if (!grep($_ eq $j, @mman)) {
					&perror("WARN: $file: manpage $j in pkg-plist ".
						"but not in MAN\U$i\E.");
				}
			}
		} else {
			if ($plistmanall{$i}) {
				if ($manstrict) {
					&perror("FATAL: $file: manpage for chapter ".
						"$i must be listed in ".
						"MAN\U$i\E. ");
				} else {
					&perror("WARN: $file: manpage for chapter ".
						"$i should be listed in ".
						"MAN\U$i\E, ".
						"even if compression is ".
						"not necessary.");
				}
			}
			if ($mancompress && $plistman{$i}) {
				&perror("WARN: $file: MAN\U$i\E will help you ".
					"compressing manual page in chapter ".
					"\"$i\".");
			} elsif (!$mancompress && $plistmangz{$i}) {
				&perror("WARN: $file: MAN\U$i\E will help you ".
					"uncompressing manual page in chapter ".
					"\"$i\".");
			}
		}
	}
	if ($tmp !~ /MANLANG/ && scalar(keys %manlangs)) {
		$i = (keys %manlangs)[0];
		&perror("WARN: $file: how about using MANLANG for ".
			"designating manual language, such as \"$i\"?");
	}

	# check INFO
	print "OK: checking INFO.\n" if ($verbose);
	if ($autoinfo && $tmp =~ /\nINFO=\s*([^\n]*)\n/) {
		my @minfo = grep($_ !~ /^\s*$/, split(/\s+/, $1));
		foreach $i (@minfo) {
			if ($i =~ /\.info(-\d+)?$/) {
				&perror("FATAL: $file: do not include the .info extension ".
					"on files listed in the INFO macro.");
			}
		}
	}

	# check USE_X11 and USE_IMAKE
	if ($tmp =~ /\nUSE_IMAKE[?+]?=/
	 && $tmp =~ /\n(USE_X11)[?+]?=/) {
		&perror("WARN: $file: since you already have USE_IMAKE, ".
			"you don't need $1.");
	}
	# check USE_X11 and USE_IMAKE
	if ($newxdef && $tmp =~ /\nUSE_IMAKE[?+]?=/
	 && $tmp =~ /\n(USE_X_PREFIX)[?+]?=/) {
		&perror("WARN: $file: since you already have USE_IMAKE, ".
			"you don't need $1.");
	}

	# check USE_X11 and USE_X_PREFIX
	if ($newxdef && $tmp =~ /\nUSE_X11[?+]?=/
	 && $tmp !~ /\nUSE_X_PREFIX[?+]?=/) {
		&perror("FATAL: $file: meaning of USE_X11 was changed in Aug 1998. ".
			"use USE_X_PREFIX instead.");
	}

	# check direct use of important make targets.
	if ($tmp =~ /\n(fetch|extract|patch|configure|build|install):/) {
		&perror("FATAL: $file: direct redefinition of make target \"$1\" ".
			"discouraged. redefine \"do-$1\" instead.");
	}

	# check for incorrect use of the pre-everything target.
	if ($tmp =~ /\npre-everything:[^:]/) {
		&perror("FATAL: $file: use pre-everything:: instead of pre-everything:");
	}

	if ($tmp =~ /^pre-patch:/m && $use_gnome_hack) {
		&perror("FATAL: $file: pre-patch target overwrites gnomehack component. ".
			"use post-patch instead.");
	}

	if ($tmp =~ /^do-build:/m && $use_ant) {
		&perror("FATAL: $file: USE_ANT is intended only for ports that ".
			"build with Ant.  You should not override ``do-build'' when ".
			"defining USE_ANT");
	}

	# check OPTIONS
	print "OK: checking OPTIONS.\n" if ($verbose);
	@oopt = ($makevar{OPTIONS} =~ /(\w+)\s+\".*?\"\s+\w+/sg);
	@mopt = ($tmp =~ /\(?\s*WITH(?:OUT)?_(\w+)\s*\)?/mg);
	foreach my $i (@oopt) {
		if (!grep(/^$i$/, @mopt)) {
			&perror("WARN: $file: $i is listed in OPTIONS, ".
				"but neither WITH_$i nor WITHOUT_$i appears.");
		}
	}
	foreach my $i (@mopt) {
		next if ($i eq 'NLS'); # skip WITHOUT_NLS
		if (!grep(/^$i$/, @oopt)) {
			# XXX: disabled temporarily.
			# OPTIONS is still "in flux"
			#&perror("WARN: $file: WITH_$i or WITHOUT_$i appears, ".
			#	"consider using OPTIONS macro.");
		}
	}

	1;
}

sub perror {
	my(@msg) = @_;
	if ($msg[0] =~ /^FATAL/) {
		$err++;
	} else {
		$warn++;
	}
	print join("\n", @msg) . "\n";
}

sub checkextra {
	my($str, $section, $file) = @_;

	$str = "\n" . $str if ($str !~ /^\n/);
	$str =~ s/\n#[^\n]*/\n/g;
	$str =~ s/\n\.[^\n]+/\n/g;
	$str =~ s/\n\n+/\n/g;
	$str =~ s/^\s+//;
	$str =~ s/\s+$//;
	return if ($str eq '');

	if ($str =~ /^([\w\d]+)/) {
		&perror("WARN: $file: extra item placed in the ".
			"$section section, ".
			"for example, \"$1\".");
	} else {
		&perror("WARN: $file: extra item placed in the ".
			"$section section.");
	}
}

sub checkorder {
	my($section, $str, $file, @order) = @_;
	my(@items, $i, $j, $k, $invalidorder);

	print "OK: checking the order of $section section.\n" if ($verbose);

	@items = ();
	foreach my $i (split("\n", $str)) {
		$i =~ s/[+?]?=.*$//;
		push(@items, $i);
	}

	@items = reverse(@items);
	$j = -1;
	$invalidorder = 0;
	while (scalar(@items)) {
		$i = pop(@items);
		$k = 0;
		while ($k < scalar(@order) && $order[$k] ne $i) {
			$k++;
		}
		if ($order[$k] eq $i) {
			if ($k < $j) {
				&perror("FATAL: $file: $i appears out-of-order.");
				$invalidorder++;
			} else {
				print "OK: seen $i, in order.\n" if ($verbose);
			}
			$j = $k;
		# This if condition tests for .if, .else (in all forms),
		# .for and .endfor and .include
		} elsif ($i !~ m/^\.(if|el|endif|for|endfor|include)/) {
			&perror("FATAL: $file: extra item \"$i\" placed in the ".
				"$section section.");
		}
	}
	if ($invalidorder) {
		&perror("FATAL: $file: order must be " . join('/', @order) . '.');
	} else {
		print "OK: $section section is ordered properly.\n"
			if ($verbose);
	}
}

sub checkearlier {
	my($file, $str, @varnames) = @_;
	my($i);

	print "OK: checking items that has to appear earlier.\n" if ($verbose);
	foreach my $i (@varnames) {
		if ($str =~ /\n$i\??=/) {
			&perror("WARN: $file: \"$i\" has to appear earlier.");
		}
	}
}

sub linenumber {
	my $text = shift;
	my @lines;

	@lines = split /\n/, $text;

	return scalar(@lines);
}

sub abspathname {
	my($str, $file) = @_;
	my($s, $i, %cmdnames);
	my($pre);

	# trim all trailing backslash and newline
	$str =~ s/\\\n\s*/ /g;

	# ignore parameter string to reinplace command
	$str =~ s/([ \t][\@-]?(?:sed|\$[\{\(]SED[\}\)]|\$[\{\(]REINPLACE_CMD[\}\)]))((?:\s+\-\w+)*\s+(?:"(?:\\"|[^"\n])*"|'(?:\\'|[^'\n])*'))+(.*)/$1$3/g; #'

	# ignore parameter string to echo command
	$str =~ s/[ \t][\@-]?(echo|\$[\{\(]ECHO[\}\)]|\$[\{\(]ECHO_MSG[\}\)])[ \t]+("(\\'|\\"|[^"])*"|'(\\'|\\"|[^"])*')[ \t]*[;\n]//; #'

	print "OK: checking direct use of full pathnames in $file.\n"
		if ($verbose);
	foreach my $s (split(/\n+/, $str)) {
		$i = '';
		$s =~ s/#.*$//;
		if ($s =~ /(^|[ \t\@'"-])(\/[\w\d])/) { #'
			# suspected pathnames are recorded.
			$i = $2 . $';
			$pre = $` . $1;

			if ($pre =~ /MASTER_SITE_SUBDIR/) {
				# MASTER_SITE_SUBDIR lines are ok.
				$i = '';
			}
		}
		if ($i ne '') {
			$i =~ s/\s.*$//;
			$i =~ s/['"].*$//; #'
			$i = substr($i, 0, 20) . '...' if (20 < length($i));
			&perror("WARN: $file: possible use of absolute pathname ".
				"\"$i\".") unless ($i =~ m,^/compat/,);
		}
	}

	print "OK: checking direct use of pathnames, phase 1.\n" if ($verbose);
%cmdnames = split(/\n|\t+/, <<EOF);
/usr/opt	\${PORTSDIR} instead
$portsdir	\${PORTSDIR} instead
$localbase	\${PREFIX} or \${LOCALBASE}, as appropriate
/usr/X11	\${PREFIX} or \${X11BASE}, as appropriate
EOF
	foreach my $i (keys %cmdnames) {
		if ($str =~ /$i/) {
			&perror("WARN: $file: possible direct use of \"$&\" ".
				"found. if so, use $cmdnames{$i}.");
		}
	}

	print "OK: checking direct use of pathnames, phase 2.\n" if ($verbose);
%cmdnames = split(/\n|\t+/, <<EOF);
distfiles	\${DISTDIR} instead
pkg		\${PKGDIR} instead
files		\${FILESDIR} instead
scripts		\${SCRIPTDIR} instead
patches		\${PATCHDIR} instead
work		\${WRKDIR} instead
EOF
	foreach my $i (keys %cmdnames) {
		if ($str =~ /(\.\/|\$[\{\(]\.CURDIR[\}\)]\/|[ \t])(\b$i)\//) {
			&perror("WARN: $file: possible direct use of \"$i\" ".
				"found. if so, use $cmdnames{$i}.");
		}
	}
}

sub is_predefined {
	my($url, $file) = @_;
	my($site, $site_re);
	my $subdir_re = quotemeta quotemeta '/%SUBDIR%/';
	for my $site (keys %predefined) {
		$site_re = quotemeta $site;
		$site_re =~ s,$subdir_re,/(.*)/,;

		if ($url =~ /$site_re/) {
			&perror("WARN: $file: how about using ".
				"\"\${MASTER_SITE_$predefined{$site}}\" with ".
				"\"MASTER_SITE_SUBDIR=$1\", instead of \"$url\"?");
			return &TRUE;
		}
	}
	undef;
}

sub urlcheck {
	my ($url, $file) = @_;
	if ($url !~ m#^\w+://#) {
		&perror("WARN: $file: \"$url\" doesn't appear to be a URL to me.");
	}
	if ($url !~ m#/(:[^/:]+)?$#) {
		&perror("FATAL: $file: URL \"$url\" should ".
			"end with \"/\" or a group name (e.g. :something).");
	}
	if ($url =~ m#://[^/]*:/#) {
	&perror("FATAL: $file: URL \"$url\" contains ".
				"extra \":\".");
	}
	if ($osname == 'FreeBSD' && $url =~ m#(www\.freebsd\.org)/~.+/#i) {
		&perror("WARN: $file: URL \"$url\", ".
			"$1 should be ".
			"people.FreeBSD.org");
	}
}
sub TRUE {1;}

# Local variables:
# tab-width: 4
# End:
