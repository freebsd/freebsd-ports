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
# $Id: portlint.pl,v 1.28.2.1 2000/04/24 02:12:36 mharo Exp $
#

use vars qw/ $opt_a $opt_b $opt_c $opt_h $opt_t $opt_v $opt_M $opt_N $opt_B $opt_V /;
use Getopt::Std;
use File::Find;
use IPC::Open2;
#use strict;

my ($err, $warn);
my ($extrafile, $parenwarn, $committer, $verbose, $usetabs, $newport);
my $contblank;
my $portdir;
my $makeenv;

$err = $warn = 0;
$extrafile = $parenwarn = $committer = $verbose = $usetabs = $newport = 0;
$contblank = 1;
$portdir = '.';

# version variables
my $major = 2;
my $minor = 3;

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
my $manchapters = '123456789ln';
my $localbase = '/usr/local';

my %lang_pref = qw(
	chinese		zh
	french		fr
	german		de
	hebrew		iw
	hungarian	hu
	japanese	ja
	korean		ko
	portuguese	pt
	russian		ru
	ukrainian	uk
	vietnamese	vi
);
my @lang_cat = keys %lang_pref;
my @lang_pref = values %lang_pref;
my $re_lang_pref = '(' . join('|', @lang_pref) . ')-';

my ($prog) = ($0 =~ /([^\/]+)$/);
sub usage {
	print STDERR <<EOF;
usage: $prog [-abchvtN] [-M ENV] [-B#] [port_directory]
	-a	additional check for scripts/* and pkg-*
	-b	warn \$(VARIABLE)
	-c	committer mode
	-h	show summary of command line options
	-v	verbose mode
	-t	nit pick about use of spaces
	-N	writing a new port
	-M ENV	set make variables to ENV (ex. PORTSDIR=/usr/ports.work)
	-B#	allow # contiguous blank lines (default: $contblank line)
EOF
		exit 0;
}

sub version {
	print "$prog version $major.$minor\n";
	exit $major;
}


getopts('AabchtvB:M:NV');

&usage if $opt_h;
&version if $opt_V;
$extrafile = 1 if $opt_a || $opt_A;
$parenwarn = 1 if $opt_b || $opt_A;
$committer = 1 if $opt_c || $opt_A;
$verbose = 1 if $opt_v;
$newport = 1 if $opt_N || $opt_A;
$usetabs = 1 if $opt_t || $opt_A;
$contblank = $opt_B if $opt_B;
$makeenv = $opt_M;

$portdir = $ARGV[0] ? $ARGV[0] : '.';

# OS dependent configs
# os	portsdir	rcsid		mplist	ldcfg	plist-rcsid mancompresss strict	localbase	newxdef	automan
my @osdep = split(/\n/, <<EOF);
FreeBSD	/usr/ports	FreeBSD		0	0	0		1	0	/usr/local	1	1
NetBSD	/usr/pkgsrc	NetBSD		1	1	1		0	1	/usr/pkg	0	0
EOF
my $osname = `uname -s`;
$osname =~ s/\n$//;
foreach my $i (@osdep) {
	if ($i =~ /^$osname\t(.*)/) {
		print "OK: found OS config for $osname.\n" if ($verbose);
		($portsdir, $rcsidstr, $multiplist, $ldconfigwithtrue,
			$rcsidinplist, $mancompress, $manstrict, $localbase,
			$newxdef, $automan)
				= split(/\t+/, $1);
		last;
	}
}
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
	PKGNAMESUFFIX DISTNAME DISTFILES CATEGORIES MASTERDIR MAINTAINER
	MASTER_SITES WRKDIR WRKSRC NO_WRKSUBDIR PATCHDIR SCRIPTDIR FILESDIR
	PKGDIR COMMENT DESCR PLIST PKGINSTALL PKGDEINSTALL PKGREQ PKGMESSAGE
	MD5_FILE .CURDIR INSTALLS_SHLIB
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
$sites_mk = "$portsdir/Mk/bsd.sites.mk";
open(MK, $sites_mk) || die "$sites_mk: $!";
my @site_groups = grep($_ = /^MASTER_SITE_(\w+)/ && $1, <MK>);
close(MK);

my $cmd = join(' -V MASTER_SITE_', "make $makeenv -f - all", @site_groups);

my $i = 0;

open2(IN, OUT, $cmd);

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
my @checker = ($makevar{COMMENT}, $makevar{DESCR}, 'Makefile', $makevar{MD5_FILE});
my %checker = (
			   $makevar{COMMENT} => 'checkdescr',
			   $makevar{DESCR} => 'checkdescr',
			   'Makefile' => 'checkmakefile',
			   $makevar{MD5_FILE} => 'TRUE'
			  );
if ($extrafile) {
	my @files = (
				 <$makevar{SCRIPTDIR}/*>,
				 @makevar{COMMENT,DESCR,PLIST,PKGINSTALL,PKGDEINSTALL,PKGREQ,PKGMESSAGE}
				);

	foreach my $i (@files) {
		next if (! -T $i);
		next if (defined $checker{$i});
		if ($i =~ /\bpkg-plist$/
		 || ($multiplist && $i =~ /\bpkg-plist/)) {
			unshift(@checker, $i);
			$checker{$i} = 'checkplist';
		} else {
			push(@checker, $i);
			$checker{$i} = 'checkpathname';
		}
	}
}
foreach my $i (<$makevar{PATCHDIR}/patch-*>) {
	next if (! -T $i);
	next if (defined $checker{$i});
	push(@checker, $i);
	$checker{$i} = 'checkpatch';
}
foreach my $i (@checker) {
	print "OK: checking $i.\n";
	if (! -f "$i") {
		&perror("FATAL: no $i in \"$portdir\".") unless $i eq $makevar{MD5_FILE} && $makevar{DISTFILES} eq "";
	} else {
		my $proc = $checker{$i};
		&$proc($i) || &perror("Cannot open the file $i\n");
		if ($proc ne 'checkpatch') {
			&checklastline($i)
				|| &perror("Cannot open the file $i\n");
		}
	}
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
			$problem = 1;
		} elsif (-d && scalar(@x = <$_/{*,.?*}>) <= 1) { 
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
}
if ($err || $warn) {
	print "$err fatal errors and $warn warnings found.\n"
} else {
	print "looks fine.\n";
}
exit $err;

#
# pkg-comment, pkg-descr
#
sub checkdescr {
	my($file) = @_;
	my(%maxchars) = ($makevar{COMMENT}, 70, $makevar{DESCR}, 80);
	my(%maxlines) = ($makevar{COMMENT}, 1, $makevar{DESCR}, 24);
	my(%errmsg) = ($makevar{COMMENT}, "must be one-liner.",
			  $makevar{DESCR},	"exceeds $maxlines{$makevar{DESCR}} ".
					"lines, make it shorter if possible.");
	my($longlines, $linecnt, $tmp) = (0, 0, "");

	open(IN, "< $file") || return 0;
	while (<IN>) {
		$tmp .= $_;
		chomp || &perror("WARN: $file should terminate in '\n'.");
		$linecnt++;
		$longlines++ if ($maxchars{$file} < length);
	}
	if ($linecnt > $maxlines{$file}) {
		&perror("WARN: $file $errmsg{$file}".
			"(currently $linecnt lines)");
	} else {
		print "OK: $file has $linecnt lines.\n" if ($verbose);
	}
	if ($longlines > 0) {
		&perror("WARN: $file includes lines that exceed $maxchars{$file} ".
			"characters.");
	}
	if ($tmp =~ /[\033\200-\377]/) {
		&perror("WARN: $file includes iso-8859-1, or ".
			"other local characters.  $file should be ".
			"plain ascii file.");
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

		if ($has_url && ! $has_www) {
			&perror("FATAL: $file: contains a URL but no WWW:");
		}
	}
	if ($file =~ /\bpkg-comment/) {
		if (($tmp !~ /^["0-9A-Z]/) || ($tmp =~ m/\.$/)) { #"
			&perror("WARN: pkg-comment should begin with a capital, and end without a period");
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

	open(IN, "< $file") || return 0;
	while (<IN>) {
		if ($_ =~ /[ \t]+\n?$/) {
			&perror("WARN: $file $.: whitespace before end ".
				"of line.");
		}

		# make it easier to handle.
		$_ =~ s/\s+$//;
		$_ =~ s/\n$//;

		if ($osname eq 'NetBSD' && $_ =~ /<\$ARCH>/) {
			&perror("WARN: $file $.: use of <\$ARCH> deprecated, ".
				"use \${MACHINE_ARCH} instead.");
		}
		if ($_ =~ /^\@/) {
			if ($_ =~ /^\@(cwd|cd)[ \t]+(\S+)/) {
				$curdir = $2;
			} elsif ($_ =~ /^\@unexec[ \t]+rmdir/) {
				if ($_ !~ /true$/) {
				&perror("WARN: use \"\@dirrm\" ".
					"instead of \"\@unexec rmdir\".");
				}
			} elsif ($_ =~ /^\@exec[ \t]+install-info\s+(.+)\s+(.+)$/) {
				$infoinstallseen = $.;
				push(@exec_info, $1);
			} elsif ($_ =~ /^\@unexec[ \t]+install-info[ \t]+--delete\s+(.+)\s+(.+)$/) {
				$inforemoveseen = $.;
				push(@unexec_info, $1);
			} elsif ($_ =~ /^\@(exec|unexec)/) {
				if (/ldconfig/) {
					if ($ldconfigwithtrue
					 && !/\/usr\/bin\/true/) {
						&perror("FATAL: $file $.: ldconfig ".
							"must be used with ".
							"\"||/usr/bin/true\".");
					}
				&perror("WARN: $file $.: possible ".
					"direct use of ldconfig ".
					"in PLIST found. use ".
					"INSTALLS_SHLIB instead.");
				}
			} elsif ($_ =~ /^\@(comment)/) {
				$rcsidseen++ if (/\$$rcsidstr[:\$]/);
			} elsif ($_ =~ /^\@(owner|group)\s/) {
				&perror("WARN: \@$1 should not be needed in pkg-plist");
			} elsif ($_ =~ /^\@(dirrm|option)/) {
				; # no check made
			} else {
				&perror("WARN: $file $.: ".
					"unknown pkg-plist directive \"$_\"");
			}
			next;
		}

		if ($_ =~ /^\//) {
			&perror("FATAL: $file $.: use of full pathname ".
				"disallowed.");
		}

		if ($_ =~ /\.la$/) {
			&perror("WARN: $file $.: installing libtool archives, ".
				"please use USE_LIBTOOL in Makefile if possible");
		}

		if ($_ =~ /\.so(\.\d+)?$/ && $makevar{INSTALLS_SHLIB} eq '') {
			&perror("WARN: $file $.: installing shared libraries, ".
				"please define INSTALLS_SHLIB as appropriate");
		}

		if ($_ =~ /^info\/.*info(-[0-9]+)?$/) {
			$infoseen = $.;
			$infoafterinstall++ if ($infoinstallseen);
			$infobeforeremove++ if (!$inforemoveseen);
			push(@infofile, $_);
		}

		if ($_ =~ /^info\/dir$/) {
			&perror("FATAL: \"info/dir\" should not be listed in ".
				"$file. use install-info to add/remove ".
				"an entry.");
			$infooverwrite++;
		}

		if ($_ =~ m#man/([^/]+/)?man([$manchapters])/([^\.]+\.[$manchapters])(\.gz)?$#) {
			if ($4 eq '') {
				$plistman{$2} .= ' ' . $3;
				if ($mancompress) {
					&perror("FATAL: $file $.: ".
						"unpacked man file $3 ".
						"listed. must be gzipped.");
				}
			} else {
				$plistmangz{$2} .= ' ' . $3;
				if (!$mancompress) {
					&perror("FATAL: $file $.: ".
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
			&perror("WARN: $file $.: installing to ".
				"directory $curdir discouraged. ".
				"could you please avoid it?");
		}

		if ("$curdir/$_" =~ m#^$localbase/share/doc#) {
			print "OK: seen installation to share/doc in $file. ".
				"($curdir/$_)\n" if ($verbose);
			$sharedocused++;
		}
	}

# check that every infofile has an exec install-info and unexec install-info
	my $exec_install = join(" ", @exec_info);
	$exec_install .= ' ';
	my $unexec_install = join(" ", @unexec_info);
	$unexec_install .= ' ';

	foreach my $if (@infofile) {
		next if ($if =~ m/info-/);
		if ($exec_install !~ m/\%D\/\Q$if\E/) {
			&perror("FATAL: you need an '\@exec install-info \%D/$if \%D/info/dir' line in your pkg-plist");
		}
		if ($unexec_install !~ m/\%D\/$if/) {
			&perror("FATAL: you need an '\@unexec install-info --delete \%D/$if \%D/info/dir' line in your pkg-plist");
		}
	}

	if ($rcsidinplist && !$rcsidseen) {
		&perror("FATAL: RCS tag \"\$$rcsidstr\$\" must be present ".
			"in $file as \@comment.")
	}

	if (!$infoseen) {
		close(IN);
		return 1;
	}
	if (!$infoinstallseen) {
		if ($infooverwrite) {
			&perror("FATAL: install-info must be used to ".
				"add/delete entries into \"info/dir\".");
		}
		&perror("FATAL: \"\@exec install-info \%D/...  \%D/info/dir\" must be placed ".
			"after all the info files.");
	} elsif ($infoafterinstall) {
		&perror("FATAL: move \"\@exec install-info\" line to make ".
			"sure that it is placed after all the info files. ".
			"(currently on line $infoinstallseen in $file)");
	}
	if (!$inforemoveseen) {
		&perror("FATAL: \"\@unexec install-info --delete \%D/... \%D/info/dir\" must ".
			"be placed before any of the info files listed.");
	} elsif ($infobeforeremove) {
		&perror("FATAL: move \"\@exec install-info --delete\" ".
			"line to make sure ".
			"that it is placed before any of the info files. ".
			"(currently on line $inforemoveseen in $file)");
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
		&perror("FATAL: the last line of $file has to be ".
			"terminated by \\n.");
	}
	if ($whole =~ /\n([ \t]*\n)+$/) {
		&perror("WARN: $file seems to have unnecessary blank lines ".
			"at the last part.");
	}

	close(IN);
}

sub checkpatch {
	my($file) = @_;
	my($whole);

	if (-z "$file") {
		&perror("FATAL: $file has no content. should be removed ".
			"from repository.");
		return;
	}

	open(IN, "< $file") || return 0;
	$whole = '';
	while (<IN>) {
		$whole .= $_;
	}
	if ($committer && $whole =~ /\$([A-Za-z0-9]+)[:\$]/) {
		&perror("WARN: $file includes possible RCS tag \"\$$1\$\". ".
			"use binary mode (-ko) on commit/import.");
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
	my $lang_pref = '';
	my $tmp;
	my $bogusdistfiles = 0;
	my @varnames = ();
	my($portname, $portversion, $distfiles, $distname, $extractsufx) = ('', '', '', '', '');
	my $masterport = 0;
	my $slaveport = 0;
	my($realwrksrc, $wrksrc, $nowrksubdir) = ('', '', '');
	my(@mman, @pman);

	open(IN, "< $file") || return 0;
	$rawwhole = '';
	$tmp = 0;
	while (<IN>) {
		if ($_ =~ /[ \t]+\n?$/) {
			&perror("WARN: $file $.: whitespace before ".
				"end of line.");
		}
		if ($_ =~ /^        /) {	# 8 spaces here!
			&perror("WARN: $file $.: use tab (not space) to make ".
				"indentation");
		}
		if ($usetabs) {
			if (m/^[A-Za-z0-9_-]+.?= /) {
				if (m/[?+]=/) {
					&perror("WARN: $file $.: use a tab (not space) after a ".
						"variable name");
				} else {
					&perror("FATAL: $file $.: use a tab (not space) after a ".
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
	print "OK: checking contiguous blank lines in $file.\n"
		if ($verbose);
	$i = "\n" x ($contblank + 2);
	if ($whole =~ /$i/) {
		my @linesbefore = split(/\n/, $`);
		&perror("FATAL: contiguous blank lines (> $contblank lines) found ".
			"in $file at line " . ($#linesbefore + 1) . ".");
	}

	#
	# whole file: $(VARIABLE)
	#
	if ($parenwarn) {
		print "OK: checking for \$(VARIABLE).\n" if ($verbose);
		if ($whole =~ /\$\([\w\d]+\)/) {
			&perror("WARN: use \${VARIABLE}, instead of ".
				"\$(VARIABLE).");
		}
	}

	#
	# whole file: NO_CHECKSUM
	#
	$whole =~ s/\n#[^\n]*/\n/g;
	$whole =~ s/\n\n+/\n/g;
	print "OK: checking NO_CHECKSUM.\n" if ($verbose);
	if ($whole =~ /\nNO_CHECKSUM/) {
		&perror("FATAL: use of NO_CHECKSUM discouraged. ".
			"it is intended to be a user variable.");
	}
	
	#
	# whole file: PKGNAME
	#
	print "OK: checking PKGNAME.\n" if ($verbose);
	if ($whole =~ /\nPKGNAME.?=/) {
		&perror("FATAL: PKGNAME is obsoleted by PORTNAME, ".
			"PORTVERSION, PKGNAMEPREFIX and PKGNAMESUFFIX.");
	}

	#
	# whole file: IS_INTERACTIVE/NOPORTDOCS
	#
	print "OK: checking IS_INTERACTIVE.\n" if ($verbose);
	if ($whole =~ /\nIS_INTERACTIVE/) {
		if ($whole !~ /defined\((BATCH|FOR_CDROM)\)/) {
			&perror("WARN: use of IS_INTERACTIVE discouraged. ".
				"provide batch mode by using BATCH and/or ".
				"FOR_CDROM.");
		}
	}
	print "OK: checking for use of NOPORTDOCS.\n" if ($verbose);
	if ($sharedocused && $whole !~ /defined\(NOPORTDOCS\)/
	 && $whole !~ m#(\$[\{\(]PREFIX[\}\)]|$localbase)/share/doc#) {
		&perror("WARN: use \".if !defined(NOPORTDOCS)\" to wrap ".
			"installation of files into $localbase/share/doc.");
	}

	#
	# whole file: direct use of command names
	#
	my %cmdnames = ();
	print "OK: checking direct use of command names.\n" if ($verbose);
	foreach my $i (qw(
awk basename cat chmod chown cp echo expr false gmake grep gzcat
ldconfig ln md5 mkdir mv patch rm rmdir sed sh touch tr which xmkmf
	)) {
		$cmdnames{$i} = "\$\{\U$i\E\}";
	}
	$cmdnames{'env'} = '${SETENV}';
	$cmdnames{'gunzip'} = '${GUNZIP_CMD}';
	$cmdnames{'gzip'} = '${GZIP_CMD}';
	$cmdnames{'install'} = '${INSTALL_foobaa}';
	#
	# ignore parameter string to echo command.
	# note that we leave the command as is, since we need to check the
	# use of echo itself.
	$j = $whole;
	$j =~ s/([ \t][\@-]?)(echo|\$[\{\(]ECHO[\}\)]|\$[\{\(]ECHO_MSG[\}\)])[ \t]+("(\\'|\\"|[^"])*"|'(\\'|\\"|[^'])*')[ \t]*[;\n]/$1$2;/; #"
	foreach my $i (keys %cmdnames) {
		if ($j =~ /[ \t\/]$i[ \t\n;]/
		 && $j !~ /\n[A-Z]+_TARGET[?+]?=[^\n]+$i/) {
			&perror("WARN: possible direct use of command \"$i\" ".
				"found. use $cmdnames{$i} instead.");
		}
	}

	#
	# whole file: ldconfig must come with "true" command
	#
	if ($ldconfigwithtrue
	 && $j =~ /(ldconfig|\$[{(]LDCONFIG[)}])/
	 && $j !~ /(\/usr\/bin\/true|\$[{(]TRUE[)}])/) {
		&perror("FATAL: ldconfig must be used with \"||\${TRUE}\".");
	}

	#
	# whole file: ${GZIP_CMD} -9 (or any other number)
	#
	if ($j =~ /\${GZIP_CMD}\s+-(\w+(\s+-)?)*(\d)/) {
		&perror("WARN: possible use of \"\${GZIP_CMD} -$3\" ".
			"found. \${GZIP_CMD} includes \"-\${GZIP}\" which ".
			"sets the compression level.");
	}

	#
	# whole file: ${MKDIR} -p
	#
	if ($j =~ /\${MKDIR}\s+-p/) {
		&perror("WARN: possible use of \"\${MKDIR} -p\" ".
			"found. \${MKDIR} includes \"-p\" by default.");
	}

	#
	# whole file: full path name
	#
	&abspathname($whole, $file);

	#
	# slave port check
	#
	my $masterdir = $makevar{MASTERDIR};
	if ($masterdir ne '' && $masterdir ne $makevar{'.CURDIR'}) {
		$slaveport = 1;
		print "OK: checking master port in $masterdir.\n" if ($verbose);
		if (! -e "$masterdir/Makefile") {
			&perror("WARN: unable to locate master port in $masterdir");
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
		&perror("FATAL: non-comment line in comment section of $file.");
	}
	foreach my $i (@linestocheck) {
		$j = $i;
		$j =~ s/\(.*\)\?//g;
		$j =~ s/\[(.)[^\]]*\]/$1/g;
		if ($tmp !~ /# $i:[ \t]+\S+/) {
			&perror("FATAL: no \"$j\" line in comment section of $file.");
		} else {
			print "OK: \"$j\" seen in $file.\n" if ($verbose);
		}
	}
	if ($tmp =~ m/Version [rR]equired/) {
		&perror("WARN: Version required is no longer needed in the comment section of $file.");
	}
	my $tmp2 = "";
	for (split(/\n/, $tmp)) {
		$tmp2 .= $_ if (m/\$$rcsidstr/);
	}
	if ($tmp2 !~ /#(\s+)\$$rcsidstr([^\$]*)\$$/) {

		&perror("FATAL: no \$$rcsidstr\$ line in $file comment ".
			"section.");
	} else {
		print "OK: \$$rcsidstr\$ seen in $file.\n" if ($verbose);
		if ($1 ne ' ') {
			&perror("WARN: please use single whitespace ".
				"right before \$$rcsidstr\$ tag.");
		}
		if ($2 ne '') {
			if ($verbose || $newport) {	# XXX
				&perror("WARN: ".
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
	&checkorder('PORTNAME', $tmp, qw(
PORTNAME PORTVERSION PORTREVISION PORTEPOCH CATEGORIES MASTER_SITES
MASTER_SITE_SUBDIR PKGNAMEPREFIX PKGNAMESUFFIX DISTNAME EXTRACT_SUFX
DISTFILES DIST_SUBDIR EXTRACT_ONLY
	));

	# check the items that has to be there.
	$tmp = "\n" . $tmp;
	print "OK: checking PORTNAME/PORTVERSION.\n" if ($verbose);
	if ($tmp !~ /\nPORTNAME(.)?=/) {
		&perror("FATAL: PORTNAME has to be there.") unless ($slaveport && $makevar{PORTNAME} ne '');
	} elsif ($1 ne '') {
		&perror("WARN: unless this is a master port, PORTNAME has to be set by \"=\", ".
			"not by \"$1=\".") unless ($masterport);
	}
	if ($tmp !~ /\nPORTVERSION(.)?=/) {
		&perror("FATAL: PORTVERSION has to be there.") unless ($slaveport && $makevar{PORTVERSION} ne '');
	} elsif ($1 ne '') {
		&perror("WARN: unless this is a master port, PORTVERSION has to be set by \"=\", ".
			"not by \"$1=\".") unless ($masterport);
	}
	print "OK: checking CATEGORIES.\n" if ($verbose);
	if ($tmp !~ /\nCATEGORIES(.)?=/) {
		&perror("FATAL: CATEGORIES has to be there.") unless ($slaveport && $makevar{CATEGORIES} ne '');
	} elsif (($i = $1) ne '' && $i =~ /[^?+]/) {
		&perror("WARN: unless this is a master port, CATEGORIES should be set by \"=\", \"?=\", or \"+=\", ".
			"not by \"$i=\".") unless ($masterport);
	}

	@cat = split(/\s+/, $makevar{CATEGORIES});
	if (@cat == 0) {
		&perror("FATAL: CATEGORIES left blank. set it to \"misc\"".
		" if nothing seems apropriate.");
	}

#MICHAEL: can these three lang cat checks be combined?
	# skip the first category specification if it's a language specific one.
	if (grep($_ eq $cat[0], @lang_cat)) {
		$has_lang_cat = 1;
		$lang_pref = $lang_pref{$cat[0]};
		shift @cat;
	}
	
	# skip further if more language specific ones follow.
	if (@cat && grep($_ eq $cat[0], @lang_cat)) {
		&perror("WARN: multiple language specific categories detected. ".
		"are you sure?");
		do {
			shift @cat;
		} while (@cat && grep($_ eq $cat[0], @lang_cat));
	}

	# check x11 in CATEGORIES
	if ($newxdef) {
#MICHAEL: I don't understand this line
		if (2 <= @cat && $cat[1] eq "x11") {
			&perror("WARN: only specific kind of apps should ".
				"specify \"x11\" in CATEGORIES. ".
				"Do you mean just USE_XLIB? ".
				"Then remove \"x11\" from CATEGORIES.");
		}
	}

	if (2 <= @cat) {
		# skip the first one that we know is _not_ language specific.
		shift @cat;
	
		# any language specific one after non language specific ones?
		my $cat;
		if (grep(do { $cat = $_; grep($_ eq $cat, @cat) }, @lang_cat)) {
			$has_lang_cat = 1;
			$lang_pref = $lang_pref{$cat};
			&perror("WARN: when you specify multiple categories, ".
			"language specific category should come first.");
		}
	}

	# check the URL
	if (($tmp =~ /\nMASTER_SITES[+?]?=[ \t]*([^\n]*)\n/
	 && $1 !~ /^[ \t]*$/) || ($makevar{MASTER_SITES} ne '')) {
		print "OK: seen MASTER_SITES, sanity checking URLs.\n"
			if ($verbose);
		my @sites = split(/\s+/, $1);
		foreach my $i (@sites) {
			if ($i =~ m#^\w+://#) {
				&urlcheck($i);
				unless (&is_predefined($i)) {
					print "OK: URL \"$i\" ok.\n"
						if ($verbose);
				}
			} else {
				print "OK: non-URL \"$i\" ok.\n"
					if ($verbose);
			}
		}
	} else {
		&perror("WARN: no MASTER_SITES found. is it ok?");
	}

	# check DISTFILES and related items.
	$distfiles = $1 if ($tmp =~ /\nDISTFILES[+?]?=[ \t]*([^\n]+)\n/);
	#$portname = $1 if ($tmp =~ /\nPORTNAME[+?]?=[ \t]*([^\n]+)\n/);
	#$portversion = $1 if ($tmp =~ /\nPORTVERSION[+?]?=[ \t]*([^\n]+)\n/);
	$portname = $makevar{PORTNAME};
	$portversion = $makevar{PORTVERSION};
	$distname = $1 if ($tmp =~ /\nDISTNAME[+?]?=[ \t]*([^\n]+)\n/);
	$extractsufx = $1 if ($tmp =~ /\nEXTRACT_SUFX[+?]?=[ \t]*([^\n]+)\n/);

	# check bogus EXTRACT_SUFX.
	if ($extractsufx ne '') {
		print "OK: seen EXTRACT_SUFX, checking value.\n" if ($verbose);
		if ($distfiles ne '') {
			&perror("WARN: no need to define EXTRACT_SUFX if ".
				"DISTFILES is defined.");
		}
		if ($extractsufx eq '.tar.gz') {
			&perror("WARN: EXTRACT_SUFX is \".tar.gz.\" ".
				"by default. you don't need to specify it.");
		}
	} else {
		print "OK: no EXTRACT_SUFX seen, using default value.\n"
			if ($verbose);
		$extractsufx = '.tar.gz';
	}

	print "OK: sanity checking PORTNAME/PORTVERSION.\n" if ($verbose);
	if ($distname ne '' && $distname eq "$portname-$portversion") {
		&perror("WARN: DISTNAME is \${PORTNAME}-\${PORTVERSION} by default, ".
			"you don't need to define DISTNAME.");
	}
	if ($portname =~ /^$re_lang_pref/) {
		&perror("FATAL: language prefix is automatically".
			" set by PKGNAMEPREFIX.".
			" you must remove it from PORTNAME.");
	}
	if ($portname =~ /\$[\{\(].+[\}\)]/) {
		&perror("WARN: using variable in PORTNAME.".
			" consider using PKGNAMEPREFIX and/or PKGNAMESUFFIX.");
	} elsif ($portname =~ /-/ && $distname ne '') {
		&perror("WARN: using hyphen in PORTNAME.".
			" consider using PKGNAMEPREFIX and/or PKGNAMESUFFIX.");
	}
	if ($portversion eq '') {
		&perror("FATAL: PORTVERSION must be specified");
	}
	if ($portversion =~ /^pl[0-9]*$/
	|| $portversion =~ /^[0-9]*[A-Za-z]?[0-9]*(\.[0-9]*[A-Za-z]?[0-9]*)*$/) {
		print "OK: PORTVERSION \"$portversion\" looks fine.\n" if ($verbose);
	} elsif ($portversion =~ /^[^\-]*\$[{\(].+[\)}][^\-]*$/) {
		&perror("WARN: using variable, \"$portversion\", as version number");
	} elsif ($portversion =~ /-/) {
		&perror("FATAL: PORTVERSION should not contain a hyphen.".
			"should modify \"$portversion\".");
	} else {
		&perror("FATAL: PORTVERSION looks illegal. ".
			"should modify \"$portversion\".");

	}

	# if DISTFILES have only single item, it is better to avoid DISTFILES
	# and to use combination of DISTNAME and EXTRACT_SUFX.
	# example:
	#	DISTFILES=package-1.0.tgz
	# should be
	#	DISTNAME=     package-1.0
	#	EXTRACT_SUFX= .tgz
	if ($distfiles =~ /^\S+$/) {
		$bogusdistfiles++;
		print "OK: seen DISTFILES with single item, checking value.\n"
			if ($verbose);
		&perror("WARN: use of DISTFILES with single file ".
			"discouraged. distribution filename should be set by ".
			"DISTNAME and EXTRACT_SUFX.");
		if ($distfiles eq (($distname ne '') ? $distname : "$portname-$portversion") . $extractsufx) {
			&perror("WARN: definition of DISTFILES not necessary. ".
				"DISTFILES is \${DISTNAME}/\${EXTRACT_SUFX} ".
				"by default.");
		}

		# display advice only in certain cases.
#MICHAEL: will this work with multiple distfiles in this list?  what about
#         doing the same sort of thing for DISTNAME, is it needed?
		if ($distfiles =~ /^\Q$i\E([\-.].+)$/) {
			&perror("WARN: how about \"EXTRACT_SUFX=$1\"".
				", instead of DISTFILES?");
		}
	}

	# additional checks for committer.
	if ($committer && $has_lang_cat) {
		&perror("WARN: be sure to include language code \"$lang_pref-\" ".
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
	print "OK: checking second section of $file (PATCH*: optinal).\n"
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

		&checkextra($tmp, 'PATCH_SITES');

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
	$tmp = "\n" . $tmp;
	if ($tmp =~ /\nMAINTAINER\??=[^\n]+/) {
		$tmp =~ s/\nMAINTAINER\??=[^\n]+//;
	} elsif ($whole !~ /\nMAINTAINER[?]?=/) {
		&perror("FATAL: no MAINTAINER listed in $file.") unless ($slaveport && $makevar{MAINTAINER} ne '');
	}
	$tmp =~ s/\n\n+/\n/g;

	&checkextra($tmp, 'MAINTAINER');

	push(@varnames, 'MAINTAINER');

	#
	# section 5: *_DEPENDS (may not be there)
	#
	print "OK: checking fourth section of $file (*_DEPENDS).\n"
		if ($verbose);
	$tmp = $sections[$idx];

	# NOTE: EXEC_DEPENDS is obsolete, so it should not be listed.
	@linestocheck = qw(
LIB_DEPENDS BUILD_DEPENDS RUN_DEPENDS FETCH_DEPENDS DEPENDS DEPENDS_TARGET
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
					&perror("WARN: wrong dependency value ".
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
					&perror("WARN: dependency to perl5 ".
						"listed in $j. consider using ".
						"USE_PERL5.");
				}

				# check USE_GMAKE
				if ($m{'dep'} =~ /^(gmake|\${GMAKE})$/) {
					&perror("WARN: dependency to $1 ".
						"listed in $j. consider using ".
						"USE_GMAKE.");
				}

				# check USE_QT
				if ($m{'dep'} =~ /^(qt\d)+$/) {
					&perror("WARN: dependency to $1 ".
						"listed in $j. consider using ".
						"USE_QT.");
				}

				# check backslash in LIB_DEPENDS
				if ($osname eq 'NetBSD' && $j eq 'LIB_DEPENDS'
				 && $m{'dep'} =~ /\\\\./) {
					&perror("WARN: use of backslashes in ".
						"$j is deprecated.");
				}

				# check for PREFIX
				if ($m{'dep'} =~ /\${PREFIX}/) {
					&perror("FATAL: \${PREFIX} must not be ".
						"contained in *_DEPENDS. ".
						"use \${LOCALBASE} or ".
						"\${X11BASE} instead.");
				}

				# check port dir existence
				$k = $m{'dir'};
				$k =~ s/\${PORTSDIR}/$ENV{'PORTSDIR'}/;
				$k =~ s/\$[\({]PORTSDIR[\)}]/$ENV{'PORTSDIR'}/;
				if (! -d $k) {
					&perror("WARN: no port directory $k ".
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

		&checkextra($tmp, '*_DEPENDS');

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
			&perror("WARN: WRKSRC is set to meaningless value ".
				"\"$1\".".
				($nowrksubdir eq ''
					? " use \"NO_WRKSUBDIR=yes\" instead."
					: ""));
		}
		if ($bogusdistfiles) {
			if ($distname ne '' && $wrksrc eq '') {
			    &perror("WARN: do not use DISTFILES and DISTNAME ".
				"to control WRKSRC. how about ".
				"\"WRKSRC=\${WRKDIR}/$distname\"?");
			} else {
			    &perror("WARN: DISTFILES/DISTNAME affects WRKSRC. ".
				"take caution when changing them.");
			}
		}
	} else {
		print "OK: seen NO_WRKSUBDIR, checking value of WRKSRC.\n"
			if ($verbose);
		if ($wrksrc eq 'work' || $wrksrc =~ /^$[\{\(]WRKDIR[\}\)]/) {
			&perror("WARN: definition of WRKSRC not necessary. ".
				"WRKSRC is \${WRKDIR} by default.");
		}
	}

	# check RESTRICTED/NO_CDROM/NO_PACKAGE
	print "OK: checking RESTRICTED/NO_CDROM/NO_PACKAGE.\n" if ($verbose);
	if ($committer && $tmp =~ /\n(RESTRICTED|NO_CDROM|NO_PACKAGE)[+?]?=/) {
		&perror("WARN: \"$1\" found. do not forget to update ".
			"ports/LEGAL.");
	}

	# check NO_CONFIGURE/NO_PATCH
	print "OK: checking NO_CONFIGURE/NO_PATCH.\n" if ($verbose);
	if ($tmp =~ /\n(NO_CONFIGURE|NO_PATCH)[+?]?=/) {
		&perror("FATAL: \"$1\" was obsoleted. remove this.");
	}

	# check MAN[1-9LN]
	print "OK: checking MAN[0-9LN].\n" if ($verbose);
	foreach my $i (keys %plistmanall) {
		print "OK: pkg-plist MAN$i=$plistmanall{$i}\n" if ($verbose);
	}
	foreach my $i (split(//, $manchapters)) {
		if ($tmp =~ /MAN\U$i\E=\s*([^\n]*)\n/) {
			print "OK: Makefile MAN$i=$1\n" if ($verbose);
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
					&perror("FATAL: duplicated manpage ".
						"entry $j: content of ".
						"MAN$i will be automatically ".
						"added to pkg-plist.");
				} elsif (!$automan && !grep($_ eq $j, @pman)) {
					&perror("WARN: manpage $j in $file ".
						"MAN$i but not in pkg-plist.");
				}
			}
			foreach my $j (@pman) {
				print "OK: checking $j (pkg-plist)\n" if ($verbose);
				if (!grep($_ eq $j, @mman)) {
					&perror("WARN: manpage $j in pkg-plist ".
						"but not in $file MAN$i.");
				}
			}
		} else {
			if ($plistmanall{$i}) {
				if ($manstrict) {
					&perror("FATAL: manpage for chapter ".
						"$i must be listed in ".
						"$file MAN\U$i\E. ");
				} else {
					&perror("WARN: manpage for chapter ".
						"$i should be listed in ".
						"MAN\U$i\E, ".
						"even if compression is ".
						"not necessary.");
				}
			}
			if ($mancompress && $plistman{$i}) {
				&perror("WARN: MAN\U$i\E will help you ".
					"compressing manual page in chapter ".
					"\"$i\".");
			} elsif (!$mancompress && $plistmangz{$i}) {
				&perror("WARN: MAN\U$i\E will help you ".
					"uncompressing manual page in chapter ".
					"\"$i\".");
			}
		}
	}
	if ($tmp !~ /MANLANG/ && scalar(keys %manlangs)) {
		$i = (keys %manlangs)[0];
		&perror("WARN: how about using MANLANG for ".
			"designating manual language, such as \"$i\"?");
	}

	# check USE_X11 and USE_IMAKE
	if ($tmp =~ /\nUSE_IMAKE[?+]?=/
	 && $tmp =~ /\n(USE_X11)[?+]?=/) {
		&perror("WARN: since you already have USE_IMAKE, ".
			"you don't need $1.");
	}
	# check USE_X11 and USE_IMAKE
	if ($newxdef && $tmp =~ /\nUSE_IMAKE[?+]?=/
	 && $tmp =~ /\n(USE_X_PREFIX)[?+]?=/) {
		&perror("WARN: since you already have USE_IMAKE, ".
			"you don't need $1.");
	}

	# check USE_X11 and USE_X_PREFIX
	if ($newxdef && $tmp =~ /\nUSE_X11[?+]?=/
	 && $tmp !~ /\nUSE_X_PREFIX[?+]?=/) {
		&perror("FATAL: meaning of USE_X11 is changed in Aug 1998. ".
			"use USE_X_PREFIX instead.");
	}

	# check direct use of important make targets.
	if ($tmp =~ /\n(fetch|extract|patch|configure|build|install):/) {
		&perror("FATAL: direct redefinition of make target \"$1\" ".
			"discouraged. redefine \"do-$1\" instead.");
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
	my($str, $section) = @_;

	$str = "\n" . $str if ($str !~ /^\n/);
	$str =~ s/\n#[^\n]*/\n/g;
	$str =~ s/\n\n+/\n/g;
	$str =~ s/^\s+//;
	$str =~ s/\s+$//;
	return if ($str eq '');

	if ($str =~ /^([\w\d]+)/) {
		&perror("WARN: extra item placed in the ".
			"$section section, ".
			"for example, \"$1\".");
	} else {
		&perror("WARN: extra item placed in the ".
			"$section section.");
	}
}

sub checkorder {
	my($section, $str, @order) = @_;
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
				&perror("FATAL: $i appears out-of-order.");
				$invalidorder++;
			} else {
				print "OK: seen $i, in order.\n" if ($verbose);
			}
			$j = $k;
		# This if condition tests for .if, .else (in all forms),
		# .for and .endfor and .include
		} elsif ($i !~ m/^\.(if|el|endif|for|endfor|include)/) {
			&perror("FATAL: extra item \"$i\" placed in the ".
				"$section section.");
		}
	}
	if ($invalidorder) {
		&perror("FATAL: order must be " . join('/', @order) . '.');
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
		if ($str =~ /\n$i[?+]?=/) {
			&perror("WARN: \"$i\" has to appear earlier in $file.");
		}
	}
}

sub abspathname {
	my($str, $file) = @_;
	my($s, $i, %cmdnames);
	my($pre);

	# ignore parameter string to echo command
	$str =~ s/[ \t][\@-]?(echo|\$[\{\(]ECHO[\}\)]|\$[\{\(]ECHO_MSG[\}\)])[ \t]+("(\\'|\\"|[^"])*"|'(\\'|\\"|[^"])*')[ \t]*[;\n]//; #'

	print "OK: checking direct use of full pathnames in $file.\n"
		if ($verbose);
	foreach my $s (split(/\n+/, $str)) {
		$i = '';
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
			&perror("WARN: possible use of absolute pathname ".
				"\"$i\", in $file.") unless ($i =~ m,^/compat/,);
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
			&perror("WARN: possible direct use of \"$&\" ".
				"found in $file. if so, use $cmdnames{$i}.");
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
			&perror("WARN: possible direct use of \"$i\" ".
				"found in $file. if so, use $cmdnames{$i}.");
		}
	}
}

sub is_predefined {
	my($url) = @_;
	my($site, $site_re);
	my $subdir_re = quotemeta quotemeta '/%SUBDIR%/';
	for my $site (keys %predefined) {
		$site_re = quotemeta $site;
		$site_re =~ s,$subdir_re,/(.*)/,;

		if ($url =~ /$site_re/) {
			&perror("WARN: how about using ".
				"\"\${MASTER_SITE_$predefined{$site}}\" with ".
				"\"MASTER_SITE_SUBDIR=$1\", instead of \"$url\"?");
			return &TRUE;
		}
	}
	undef;
}

sub urlcheck {
	my ($url) = @_;
	if ($url !~ m#^\w+://#) {
		&perror("WARN: \"$url\" doesn't appear to be a URL to me.");
	}
	if ($url !~ m#/$#) {
		&perror("FATAL: URL \"$url\" should ".
			"end with \"/\".");
	}
	if ($url =~ m#://[^/]*:/#) {
	&perror("FATAL: URL \"$url\" contains ".
				"extra \":\".");
	}
	if ($osname == 'FreeBSD' && $url =~ m#(www\.freebsd\.org)/~.+/#i) {
		&perror("WARN: URL \"$url\", ".
			"$1 should be ".
			"people.FreeBSD.org");
	}
}
sub TRUE {1;}

# Local variables:
# tab-width: 4
# End:
