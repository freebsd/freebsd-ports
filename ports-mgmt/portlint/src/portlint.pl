#! /usr/bin/perl -w
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
# $MCom: portlint/portlint.pl,v 1.297 2013/10/26 14:41:47 marcus Exp $
#

use strict;
use warnings;

use Getopt::Std;
use File::Find;
use IPC::Open2;
use POSIX qw(strftime);

sub perror($$$$);
our ($opt_a, $opt_A, $opt_b, $opt_C, $opt_c, $opt_g, $opt_h, $opt_m, $opt_t, $opt_v, $opt_M, $opt_N, $opt_B, $opt_V, @ALLOWED_FULL_PATHS, @MASTERSITES_WHITELIST);

my ($err, $warn);
my ($extrafile, $parenwarn, $committer, $verbose, $usetabs, $newport,
	$grouperrs, $checkmfiles);
my $contblank;
my $portdir;
my $makeenv = "";
my @errlst = ();
my %errcache = ();

$err = $warn = 0;
$extrafile = $parenwarn = $committer = $verbose = $usetabs = $newport = 0;
$checkmfiles = 0;
$contblank = 1;
$portdir = '.';

@ALLOWED_FULL_PATHS = qw(/boot/loader.conf /compat/ /dev/null /etc/inetd.conf);
@MASTERSITES_WHITELIST = qw(googlecode.com nodeload.github.com);

# version variables
my $major = 2;
my $minor = 14;
my $micro = 7;

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
my $numpitems = 6;

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
usage: $prog [-AabCcghmvtN] [-M ENV] [-B#] [port_directory]
	-a	additional check for scripts/* and pkg-*
	-A	turn on all additional checks (equivalent to -abcmNt)
	-b	warn \$(VARIABLE)
	-c	committer mode (implies -m)
	-C	pedantic committer mode (equivalent to -abcmt)
	-g  group errors together to avoid duplication (disabled if -v is specified)
	-h	show summary of command line options
	-v	verbose mode
	-t	nit pick about use of spaces
	-m	check \${PORTSDIR}/MOVED, UIDs, and GIDs files
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

getopts('AabCcghmtvB:M:NV');

&usage if $opt_h;
&version if $opt_V;
$extrafile = 1 if $opt_a || $opt_A || $opt_C;
$parenwarn = 1 if $opt_b || $opt_A || $opt_C;
$committer = 1 if $opt_c || $opt_A || $opt_C;
$verbose = 1 if $opt_v;
$grouperrs = 1 if $opt_g && !$opt_v;
$checkmfiles = 1 if $opt_m || $opt_c || $opt_A || $opt_C;
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
$ENV{'PL_SVN_IGNORE'} //= '';
my $mfile_moved = "${portsdir}/MOVED";
my $mfile_uids = "${portsdir}/UIDs";
my $mfile_gids = "${portsdir}/GIDs";

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
	WRKDIR WRKSRC NO_WRKSUBDIR SCRIPTDIR FILESDIR
	PKGDIR COMMENT DESCR PLIST PKGCATEGORY PKGINSTALL PKGDEINSTALL
	PKGREQ PKGMESSAGE DISTINFO_FILE .CURDIR USE_LDCONFIG USE_AUTOTOOLS
	USE_GNOME INDEXFILE PKGORIGIN CONFLICTS PKG_VERSION PKGINSTALLVER
	PLIST_FILES PLIST_DIRS PORTDOCS PORTEXAMPLES OPTIONS_DEFINE
	OPTIONS_RADIO OPTIONS_SINGLE OPTIONS_MULTI OPTIONS_GROUP OPTIONS_SUB
	INSTALLS_OMF USE_RC_SUBR USES DIST_SUBDIR ALLFILES IGNOREFILES
	CHECKSUM_ALGORITHMS INSTALLS_ICONS GNU_CONFIGURE CONFIGURE_ARGS
	MASTER_SITE_SUBDIR LICENSE LICENSE_COMB NO_STAGE
);

my %makevar;
my $i = 0;
for (split(/\n/, get_makevar(@varlist))) {
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

my @popt = ();

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

my $cmd = join(' -V MASTER_SITE_', "make $makeenv ", @site_groups);

$i = 0;

open2(\*IN, \*OUT, $cmd);

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
my @checker = ($makevar{DESCR}, 'Makefile', $makevar{DISTINFO_FILE});
my %checker = (
	$makevar{DESCR} => \&checkdescr,
	'Makefile' => \&checkmakefile,
	$makevar{DISTINFO_FILE} => \&checkdistinfo
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
if ($checkmfiles) {
    foreach my $i ($mfile_moved, $mfile_uids, $mfile_gids) {
		next if (! -T $i);
		next if (defined $checker{$i});
		push(@checker, $i);
		$checker{$i} = \&checkmfile;
	}
}
foreach my $i (<$makevar{FILESDIR}/patch-*>) {
	next if (! -T $i);
	next if (defined $checker{$i});
	push(@checker, $i);
	$checker{$i} = \&checkpatch;
}
foreach my $i (@checker) {
	print "OK: checking $i.\n" if ($verbose);
	if (! -f "$i") {
		&perror("FATAL", "", -1, "no $i in \"$portdir\".") unless $i eq $makevar{DISTINFO_FILE} && $makevar{DISTFILES} eq "";
	} else {
		my $proc = $checker{$i};
		&$proc($i) || &perror("", "", -1, "Cannot open the file $i\n");
		if ($proc ne \&checkpatch) {
			&checklastline($i)
				|| &perror("", "", -1, "Cannot open the file $i\n");
		}
	}
}

# Check to make sure there is no pkg-comment file anymore.
if (-f 'pkg-comment') {
	&perror("FATAL", "", -1, "Use of pkg-comment is obsolete.  Use the COMMENT macro within the port's Makefile instead.");
}

if ($committer) {
	sub find_proc {
		return if /^\.\.?$/;

		(my $fullname = $File::Find::name) =~ s#^\./##;

		print "OK: checking the file name of $fullname.\n" if ($verbose);

		if ($fullname eq 'work') {
			&perror("FATAL", $fullname, -1, "be sure to cleanup the working directory ".
					"before committing the port.");

			$File::Find::prune = 1;
		} elsif (-l) {
			&perror("WARN", $fullname, -1, "this is a symlink. ".
					"Please remove it.");
		} elsif (-z) {
			&perror("FATAL", $fullname, -1, "empty file and should be removed. ".
				    "If it still needs to be there, put a dummy comment ".
					"to state that the file is intentionally left empty.");
		} elsif (-d && scalar(my @x = <$_/{*,.?*}>) <= 1) {
			&perror("FATAL", $fullname, -1, "empty directory should be removed.") unless ($fullname =~ /^\.svn/);
		} elsif (/^\./) {
			&perror("WARN", $fullname, -1, "dotfiles are not preferred. ".
					"If this file is a dotfile to be installed as an example, ".
					"consider importing it as \"dot$_\".") unless
					(-d && $_ eq '.svn');
		} elsif (/[^-.a-zA-Z0-9_\+]/) {
			&perror("WARN", $fullname, -1, "only use characters ".
					"[-_.a-zA-Z0-9+] for patch or script names.");
		} elsif (/\.(orig|rej|bak)$/ || /~$/ || /^\#/) {
			&perror("FATAL", $fullname, -1, "for safety, be sure to cleanup ".
					"backup files before committing the port.");
		} elsif (/(^|\.)core$/) {
			&perror("FATAL", $fullname, -1, "for safety, be sure to cleanup ".
					"core files before committing the port.");
		} elsif (/README.html/) {
			&perror("FATAL", $fullname, -1, "for safety, be sure to cleanup ".
					"README.html files before committing the port.");
		} elsif ($_ eq '.svn' && -d) {
			&perror("FATAL", $fullname, -1, "for safety, be sure to cleanup ".
				"Subversion files before committing the port.");

			$File::Find::prune = 1;
		} elsif ($_ eq 'CVS' && -d) {
			if ($newport) {
				&perror("FATAL", $fullname, -1, "for safety, be sure to cleanup ".
						"CVS directories before importing the new port.");
			}

			$File::Find::prune = 1;
		} elsif (-f) {
			my $fullpath = $makevar{'.CURDIR'}.'/'.$fullname;
			my $result = `svn -q status $fullpath`;

			chomp $result;
			if (substr($result, 0, 1) eq '?') {
				&perror("FATAL", "", -1, "$fullname not under SVN.")
					unless (eval { /$ENV{'PL_SVN_IGNORE'}/, 1 } &&
						/$ENV{'PL_SVN_IGNORE'}/);
			}
		}
	}

	find(\&find_proc, '.');

	# Check for ports that may break INDEX
	my $indexerr = `env LOCALBASE=/nonexistentlocal make $makeenv describe 2>&1 >/dev/null`;
	chomp $indexerr;
	$indexerr =~ tr/\n/ /s;
	&perror("FATAL", "", -1, "breaks INDEX ($indexerr).")
		if ($indexerr);
}
if ($err || $warn) {
	my($errtext, $warntext) = ("error", "warning");
	$errtext .= "s" unless ($err == 1);
	$warntext .= "s" unless ($warn == 1);
	if ($grouperrs) {
		foreach my $msg (@errlst) {
			my $lines;
			if ($errcache{$msg} && scalar(@{$errcache{$msg}})) {
				$lines = "[" . (join(",", @{$errcache{$msg}})) . "]: ";
			} else {
				$lines = "";
			}
			$msg =~ s/%%LINES%%/$lines/;
			print $msg, "\n";
		}
	}
	printf("%d fatal %s and %d %s found.\n", $err, $errtext, $warn, $warntext);
} else {
	print "looks fine.\n";
}
exit $err;

#
# distinfo
#
sub checkdistinfo {
	my($file) = @_;
	my($dist_subdir) = $makevar{DIST_SUBDIR};
	my(@allfiles) = split (/\s+/, $makevar{ALLFILES});
	my %ignorefiles = ();
	my %algorithms = ();
	my %records = ();

	foreach my $i (split (/\s+/, $makevar{IGNOREFILES})) {
		$ignorefiles{$i} = 1;
	}
	foreach my $i (split (/\s+/, uc ($makevar{CHECKSUM_ALGORITHMS}))) {
		$algorithms{$i} = 1;
	}

	if (scalar (%ignorefiles)) {
		&perror("WARN", "", -1, "Found IGNOREFILES. It is not recomended.");
	}

	open(IN, "< $file") || return 0;
	while (<IN>) {
		if (/^\s*$/) {
			&perror("FATAL", $file, $., "found blank line.");
		}
		m/(\S+)\s+\((\S+)\)\s+=\s+(\S+)/;

		if ($1 ne "" && $2 ne "" && $3 ne "") {
			my ($tag, $path, $value) = ($1, $2, $3);
			$records{$path}{$tag} = $value;

			if (!$algorithms{$tag} && $tag ne "SIZE") {
				&perror("FATAL", $file, $., "unsupported checksum algorithm ".
					"found: $tag.");
			}
		} else {
			&perror("FATAL", $file, $., "line format error.");
		}
	}
	close(IN);

	# For all files check SIZE and checksums
	foreach my $f (@allfiles) {
		# Remove hindering chars from DISTNAME
		$f =~ s/['\\]//g;

		my $path = $f;
		$path = "$dist_subdir/$f" if $dist_subdir;
		if (!defined($records{$path}{SIZE}) && !$ignorefiles{$f}) {
			&perror("FATAL", $file, -1, "has no SIZE record for $path.");
		}
		my $n = 0;
		foreach my $alg (keys %algorithms) {
			$n++ if exists($records{$path}{$alg});
		}
		if ($n == 0) {
			&perror("FATAL", $file, -1, "no checksum record for $path.");
		}
		if ($n < scalar(keys %algorithms)) {
			&perror("WARN", $file, -1, "no checksum records for all ".
				"supported algorithms (".join(" ",keys %algorithms).") for ".
				"$path.");
		}
	}
	return 1;
}

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
		chomp || &perror("WARN", $file, -1, "lines should terminate with a ".
			"newline (i.e. '\\n').");
		if (/$/) {
			&perror("WARN", $file, -1, "lines should not contain carriage ".
				"returns.  Strip all carriage returns (e.g. run dos2unix) ".
				"in $file.");
		}
		if (/^WWW:(\s+)(\S*)/) {
			my $wwwurl = $2;
			if ($1 ne ' ') {
				&perror("WARN", $file, -1, "use WWW: with a single space, ".
					"then $wwwurl");
			}
			if ($wwwurl !~ m|^https?://|) {
				&perror("WARN", $file, -1, "WWW URL, $wwwurl should begin ".
					"with \"http://\" or \"https://\".");
			}
			if ($wwwurl =~ m|^http://search.cpan.org/~|) {
				&perror("WARN", $file, -1, "consider changing WWW URL to ".
					"http://search.cpan.org/dist/$makevar{PORTNAME}/");
			}
		}
		$linecnt++;
		$longlines++ if ($maxchars{$file} < length);
	}
	if ($linecnt > $maxlines{$file}) {
		&perror("WARN", $file, -1, "$errmsg{$file}".
			"(currently $linecnt lines)");
	} else {
		print "OK: $file: has $linecnt lines.\n" if ($verbose);
	}
	if ($longlines > 0) {
		&perror("WARN", $file, -1, "includes lines that exceed $maxchars{$file} ".
			"characters.");
	}
	if ($tmp =~ /[\033\200-\377]/) {
		&perror("WARN", $file, -1, "includes iso-8859-1, or ".
			"other local characters.  files should be in ".
			"plain 7-bit ASCII");
	}
	if ($file =~ /\bpkg-descr/ && $tmp =~ m,http://,) {
		my $has_url = 0;
		my $has_www = 0;
		my $cpan_url = 0;
		my $has_endslash = 0;
		foreach my $line (grep($_ =~ "http://", split(/\n+/, $tmp))) {
			$has_url = 1;
			if ($line =~ m,WWW:[ \t]+http://,) {
				$has_www = 1;
				if ($line =~ m,search.cpan.org,) {
					$cpan_url = 1;
					if ($line =~ m,/$,) {
						$has_endslash = 1;
					}
				}
			}
		}

		if (!$has_url) {
			&perror("WARN", $file, -1, "add \"WWW: UR:\" for this port if possible");
		}

		if ($cpan_url && !$has_endslash) {
			&perror("WARN", $file, -1, "end WWW CPAN URL with a \"/\"");
		}

		if ($has_url && ! $has_www) {
			&perror("FATAL", $file, -1, "contains a URL but no \"WWW:\"");
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

	my $seen_dirrm_docsdir = 0;
	my $seen_special = 0;
	my $item_count = 0;

	# Variables that are allowed to be out-of-sync in the XXXDIR check.
	# E.g., %%PORTDOCS%%%%RUBY_MODDOCDIR%% will be OK because there is
	# no %%PORTRUBY_MODDOC%% substitution.
	my %check_xxxdir_ok = (
		"DOCS"				=> "DOCS",
		"EXAMPLES"			=> "EXAMPLES",
		"DATA"				=> "DATA",
		"RUBY_DOC"			=> "DOCS",
		"RUBY_EXAMPLES"		=> "EXAMPLES",
		"RUBY_MODDOC" 		=> "DOCS",
		"RUBY_MODEXAMPLES"	=> "EXAMPLES",
	);

	open(IN, "< $file") || return 0;
	while (<IN>) {
		$item_count++;
		if ($_ =~ /[ \t]+\n?$/) {
			&perror("WARN", $file, $., "whitespace before end ".
				"of line.");
		}

		# make it easier to handle.
		$_ =~ s/\s+$//;
		$_ =~ s/\n$//;

		# store possible OPTIONS knobs for OPTIONS_SUB
		if ($makevar{OPTIONS_SUB}) {
			if ($_ =~ /^\%\%([^%]+)\%\%/) {
				if ($1 =~ /PORTDOCS/) {
					push @popt, "DOCS";
				} elsif ($1 =~ /PORTEXAMPLES/) {
					push @popt, "EXAMPLES";
				} else {
					push @popt, $1;
				}
			}
		}

		if ($_ =~ /\.DS_Store/) {
			&perror("WARN", $file, $., ".DS_Store meta data files must not ".
				"be installed.");
		}

		if ($osname eq 'NetBSD' && $_ =~ /<\$ARCH>/) {
			&perror("WARN", $file, $., "use of <\$ARCH> deprecated, ".
				"use \${MACHINE_ARCH} instead.");
		}
		if (m'lib/perl5/site_perl/%%PERL_VER%%') {
			&perror("WARN", $file, $., "use \%\%SITE_PERL\%\% ".
					"instead of lib/perl5/site_perl/\%\%PERL_VER\%\%.");
		}
		if ($osname ne 'NetBSD' && m'([\w\d]+-portbld-freebsd\d+\.\d+)') {
			&perror("WARN", $file, $., "possible direct use of the ".
				"CONFIGURE_TARGET value ($1).  Consider using the plist ".
				"substitution %%CONFIGURE_TARGET%% instead.");
		}
		$seen_special++ if /[\%\@]/;
		$seen_dirrm_docsdir++ if /^(\%\%PORTDOCS\%\%)?\@dirrm\s+\%\%DOCSDIR\%\%/ || /^(\%\%PORTDOCS\%\%)?\@unexec\s+(\/bin\/)?rmdir\s+\%D\/\%\%DOCSDIR\%\%\s+2\>\s*\/dev\/null\s+\|\|\s+(\/usr\/bin\/)?true/;
		if ($_ =~ /^\@/) {
			if ($_ =~ /^\@(cwd|cd)[ \t]+(\S+)/) {
				$curdir = $2;
			} elsif ($_ =~ /^\@unexec[ \t]+rm[ \t]/) {
				if ($_ !~ /%[DB]/) {
					&perror("WARN", $file, $., "use \"%D\" or \"%B\" to ".
						"specify prefix.");
				}
				if ($_ !~ /true$/ && $_ !~ /rm -f/) {
					&perror("WARN", $file, $., "add \"2>&1 ".
						">/dev/null || true\" ".
						"to \"\@unexec rm\".");
				}
			} elsif ($_ =~ /^\@unexec[ \t]+rmdir/) {
				if ($_ !~ /%[DB]/) {
					&perror("WARN", $file, $., "use \"%D\" or \"%B\" to ".
						"specify prefix.");
				}
				&perror("WARN", $file, $., "use \"\@dirrmtry\" ".
					"instead of \"\@unexec rmdir\".");
			} elsif (!$autoinfo && $_ =~ /^\@exec[ \t]+install-info\s+(.+)\s+(.+)$/) {
				$infoinstallseen = $.;
				push(@exec_info, $1);
			} elsif (!$autoinfo && $_ =~ /^\@unexec[ \t]+install-info[ \t]+--delete\s+(.+)\s+(.+)$/) {
				$inforemoveseen = $.;
				push(@unexec_info, $1);
			} elsif ($autoinfo && $_ =~ /^\@unexec[ \t]+install-info[ \t]+--delete\s+(.+)\s+(.+)$/) {
				&perror("WARN", $file, $., "\@unexec install-info is deprecated in favor of adding info files into the Makefile using the INFO macro.");
			} elsif ($_ =~ /^\@(exec|unexec)/) {
				if (/ldconfig/) {
					if ($ldconfigwithtrue
					 && !/\/usr\/bin\/true/) {
						&perror("FATAL", $file, $., "ldconfig ".
							"must be used with ".
							"\"||/usr/bin/true\".");
					}
				&perror("WARN", $file, $., "possible ".
					"direct use of ldconfig ".
					"in PLIST found. use ".
					"USE_LDCONFIG instead.");
				}
				if (/scrollkeeper/) {
					&perror("WARN", $file, $., "possible ".
						"direct use of scrollkeeper commands ".
						"in PLIST found.  Use ".
						"INSTALLS_OMF instead ".
						"(see http://www.FreeBSD.org/gnome/docs/porting.html ".
						"for more details).");
				}
			} elsif ($_ =~ /^\@(comment)/) {
				$rcsidseen++ if (/\$$rcsidstr[:\$]/);
			} elsif ($_ =~ /^\@(owner|group|mode)\s/) {
				&perror("WARN", $file, $., "\@$1 should not be needed");
			} elsif ($_ =~ m!^\@(dirrm|dirrmtry)\s+/!) {
				&perror("WARN", $file, $., "Using \@$1 with absolute path ".
					"will not work as you expected in most cases.  Use ".
					"pkg-deinstall or \@unexec rmdir ... if you want to ".
					"remove a directory such as /var/\${PORTNAME}");
			} elsif ($_ =~ /^\@(dirrm|option|stopdaemon|rmtry)/) {
				; # no check made
			} elsif ($_ eq "\@cwd") {
				; # @cwd by itself means change directory back to the original
				  # PREFIX.
			} else {
				&perror("WARN", $file, $.,
					"unknown pkg-plist directive \"$_\"");
			}
			next;
		}

		if ($_ =~ /^\//) {
			&perror("FATAL", $file, $., "use of full pathname ".
				"disallowed.");
		}

		if ($_ =~ /charset\.alias$/ || $_ =~ /locale\.alias$/) {
			&perror("WARN", $file, $., "installing charset.alias or locale.alias, ".
				"please add USES[+]=gettext and use libintl from devel/gettext ".
				"instead of from outdated bundled one if possible. ".
				"See http://www.freebsd.org/cgi/query-pr.cgi?pr=ports/71531 ".
				"for more details.");
		}

		if ($_ =~ /\%gconf.*\.xml/ || $_ =~ /gconf.*\.schemas?/) {
			&perror("FATAL", $file, $., "explicitly listing \%gconf key files ".
				"or GConf schema files in the plist is not supported. ".
				"Use GCONF_SCHEMAS in the Makefile instead. ".
				"See http://www.FreeBSD.org/gnome/docs/porting.html ".
				"for more details.");
		}

		if ($_ =~ m|lib/pkgconfig/[^\/]+.pc$|) {
			&perror("FATAL", $file, $., "installing pkg-config files into ".
				"lib/pkgconfig.  All pkg-config files must be installed ".
				"into libdata/pkgconfig for them to be found by pkg-config.");
		}

		if ($_ =~ m|lib[^\/]+\.so(\.\d+)?$| &&
			$makevar{USE_LDCONFIG} eq '') {
			&perror("WARN", $file, $., "installing shared libraries, ".
				"please define USE_LDCONFIG as appropriate");
		}

		if ($_ =~ m|^share/icons/.*/| &&
			$makevar{INSTALLS_ICONS} eq '') {
			&perror("WARN", $file, $., "installing icons, ".
				"please define INSTALLS_ICONS as appropriate");
		}

		if ($_ =~ m|\.omf$| && $makevar{INSTALLS_OMF} eq '') {
			&perror("WARN", $file, $., "installing OMF files, ".
				"please define INSTALLS_OMF (see the FreeBSD GNOME ".
				"porting guide at ".
				"http://www.FreeBSD.org/gnome/docs/porting.html ".
				"for more details)");
		}

		if ($_ =~ m|\.mo$| && $makevar{USES} !~ /\bgettext\b/) {
			&perror("WARN", $file, $., "installing gettext translation files, ".
				"please define USES[+]=gettext as appropriate");
		}

		if ($_ =~ m|\.core$| && $_ !~ /^\@/) {
			&perror("WARN", $file, $., "this port installs a file which ends ".
				"in \".core\".  This file may be deleted if ".
				"daily_clean_disks_enable=\"YES\" in /etc/periodic.conf.  ".
				"If possible, install this file with a different name.");
		}

		if ($_ =~ m|/a\.out$| && $_ !~ /^\@/) {
			&perror("WARN", $file, $., "this port installs a file named ".
				"\"a.out\".  This file may be deleted if ".
				"daily_clean_disks_enable=\"YES\" in /etc/periodic.conf.  ".
				"If possible, install this file with a different name.");
		}

		if ($autoinfo && $_ =~ /\.info$/) {
			&perror("WARN", $file, $., "enumerating info files in the plist is deprecated in favor of adding info files into the Makefile using the INFO macro.");
		}

		if ($autoinfo && $_ =~ /\.info-\d+$/) {
			&perror("FATAL", $file, $., "numbered info files are obsolete and not portable; add info files using the INFO macro in the Makefile.");
		}

		if (!$autoinfo) {
			if ($_ =~ /^info\/.*info(-[0-9]+)?$/) {
				$infoseen = $.;
				$infoafterinstall++ if ($infoinstallseen);
				$infobeforeremove++ if (!$inforemoveseen);
				push(@infofile, $_);
			}

			if ($_ =~ /^info\/dir$/) {
				&perror("FATAL", $file, $., "\"info/dir\" should not be listed.".
					"Use install-info to add/remove ".
					"an entry.");
				$infooverwrite++;
			}
		}

		if ($_ =~ /^(\%\%PORTDOCS\%\%)?share\/doc\//) {
			&perror("WARN", $file, $., "If and only if your port is ".
					"DOCSDIR-safe (that is, a user can override DOCSDIR ".
					"when building this port and the port will still work ".
					"correctly) consider using DOCSDIR macro; if you are ".
					"unsure if this this port is DOCSDIR-safe, then ignore ".
					"this warning");
			$sharedocused++;
		} elsif ($_ =~ /^(\%\%PORTDOCS\%\%)?\%\%DOCSDIR\%\%/) {
			$sharedocused++;
		}

		if ($_ =~ /^share\/examples\//) {
			&perror("WARN", $file, $., "If and only if your port is ".
				"EXAMPLESDIR-safe (that is, a user can override EXAMPLESDIR ".
				"when building this port and the port will still work ".
				"correctly) consider using EXAMPLESDIR macro; if you are ".
				"unsure if this port is EXAMPLESDIR-safe, then ignore this ".
				"warning");
		}

		{
			my $tmpportname = quotemeta($makevar{PORTNAME});
			if ($_ =~ /^share\/$tmpportname\//) {
				&perror("WARN", $file, $., "If and only if your port is ".
					"DATADIR-safe (that is, a user can override DATADIR when ".
					"building this port and the port will still work ".
					"correctly) consider using DATADIR macro; if you are ".
					"unsure if this port is DATADIR-safe, then ignore this ".
					"warning");
			}
		}

		if ($_ =~ m{^%%PORT(\w+)%%(.*?)%%(\w+)DIR%%(.*)$} and $1 ne $3) {
			&perror("WARN", $file, $., "Do not mix %%PORT$1%% with %%$3DIR%%. ".
				"Use '%%PORT$check_xxxdir_ok{$3}%%$2%%$3DIR%%$4' instead and update Makefile ".
				"accordingly.") unless (defined($check_xxxdir_ok{$3}) and
					$check_xxxdir_ok{$3} eq $1);
		}

		if ($_ =~ m#man/([^/]+/)?man([$manchapters])/([^\.]+\.[$manchapters])(\.gz)?$#) {
			if (!$4) {
				$plistman{$2} .= ' ' . $3;
				if ($mancompress) {
					&perror("FATAL", $file, $.,
						"unpacked man file $3 ".
						"listed. must be gzipped.");
				}
			} else {
				$plistmangz{$2} .= ' ' . $3;
				if (!$mancompress) {
					&perror("FATAL", $file, $.,
						"gzipped man file $3$4 ".
						"listed. unpacked one should ".
						"be installed.");
				}
			}
			$plistmanall{$2} .= ' ' . $3;
			if ($1) {
				$manlangs{substr($1, 0, length($1) - 1)}++;
			}
		}

		if ($curdir !~ m#^$localbase#
		 && $curdir !~ m#^/usr/X11R6#) {
			&perror("WARN", $file, $., "installing to ".
				"directory $curdir discouraged. ".
				"could you please avoid it?");
		}

		if ("$curdir/$_" =~ m#^$localbase/share/doc#) {
			print "OK: $file [$.]: seen installation to share/doc. ".
				"($curdir/$_)\n" if ($verbose);
			$sharedocused++;
		}
	}

	if (!$seen_special && $item_count < $numpitems) {
		&perror("WARN", $file, -1, "There are only $item_count items in the plist.  Consider using PLIST_FILES instead of pkg-plist when installing less than $numpitems items.");
}

	if ($sharedocused && !$seen_dirrm_docsdir) {
		&perror("WARN", $file, -1, "Both ``\%\%PORTDOCS\%\%\@dirrm \%\%DOCSDIR\%\%'' and ``\%\%PORTDOCS\%\%\@unexec \%D/\%\%DOCSDIR\%\% 2>/dev/null || true'' are missing.  At least one should be used.");
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
				&perror("FATAL", $file, -1, "you need an '\@exec install-info \%D/$if \%D/info/dir' line");
			}
			if ($unexec_install !~ m/\%D\/$if/) {
				&perror("FATAL", $file, -1, "you need an '\@unexec install-info --delete \%D/$if \%D/info/dir' line");
			}
		}
	}

	if ($rcsidinplist && !$rcsidseen) {
		&perror("FATAL", $file, -1, "RCS tag \"\$$rcsidstr\$\" must be present ".
			"as \@comment.")
	}

	if (((!$autoinfo && !$infoseen) || $autoinfo)) {
		close(IN);
		return 1;
	}

	if (!$autoinfo && $infoseen) {
		if (!$infoinstallseen) {
			if ($infooverwrite) {
				&perror("FATAL", $file, -1, "install-info must be used to ".
					"add/delete entries into \"info/dir\".");
			}
			&perror("FATAL", $file, -1, "\"\@exec install-info \%D/...  \%D/info/dir\" must be placed ".
				"after all the info files.");
		} elsif ($infoafterinstall) {
			&perror("FATAL", $file, $infoinstallseen, "move ".
				"\"\@exec install-info\" line to make ".
				"sure that it is placed after all the info files.");
		}
		if (!$inforemoveseen) {
			&perror("FATAL", $file, -1, "\"\@unexec install-info --delete \%D/... \%D/info/dir\" must ".
				"be placed before any of the info files listed.");
		} elsif ($infobeforeremove) {
			&perror("FATAL", $file, $inforemoveseen, "move ".
				"\"\@exec install-info --delete\" ".
				"line to make sure ".
				"that it is placed before any of the info files. ");
		}
	}

	close(IN);
}
#
# ${PORTSDIR}/MOVED, UIDs, GIDs files
#
sub checkmfile {
	my ($file) = @_;
	my $line = 0;
    my $format;
    my @entries;
    my @sorted;
	my $dosort;

	if ($file =~ m/MOVED$/) {
		$format = '^[^|]*\|[^|]*\|[^|]*\|[^|]*$';
		$dosort = 0;
    } elsif ($file =~ m/UIDs$/) {
		$format = '^[^:]+:\*:[0-9]+:[0-9]+:[^:]*:0:0:[^:]+:[^:]+:[^:]+$';
		$dosort = 1;
    } elsif ($file =~ m/GIDs$/) {
		$format = '^[^:]+:\*:[0-9]+:[^:]*$';
		$dosort = 1;
	} else {
		&perror("FATAL", $file, -1, "Internal error. ".
			"Invalid name for mfiles.");
    }

	open(IN, "<$file") || return 0;
	while (<IN>) {
		chomp;
		$line++;
		next if (m,^\s*#,);

		if (!m,${format},) {
			&perror("FATAL", $file, -1,
					"malformed line at ".
					"${line}.\n => $_");
		} else {
			push @entries, "$line:$_";
			next;
		}
	}
    if ($dosort) {
		my $errline;
		@sorted = sort {(split /:/, $a)[3] <=> (split /:/, $b)[3] } @entries;

		for (my $n = 0; $n < @entries; $n++) {
			if (!defined($sorted[$n]) or
				$entries[$n] ne $sorted[$n]) {
					($line, $errline) = ($entries[$n] =~ m/([0-9]+):(.*)/);
					&perror("WARN", $file, -1,
							"malformed sorting order at " .
							"${line}.\n => $errline");
			}
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
		&perror("FATAL", $file, -1, "the last line has to be ".
			"terminated by \\n.");
	}
	if ($whole =~ /\n([ \t]*\n)+$/) {
		&perror("WARN", $file, -1, "seems to have unnecessary blank lines ".
			"at the last part.");
	}

	close(IN);
}

sub checkpatch {
	my($file) = @_;
	my($whole);

	if (-z "$file") {
		&perror("FATAL", $file, -1, "has no content. should be removed ".
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
		&perror("WARN", $file, $lineno, "includes possible RCS tag \"\$$1\$\". ".
			"use binary mode (-ko) on commit/import.") unless
			$1 eq $rcsidstr;
	}

	if ($committer && $whole =~ /\wjavavm\w/) {
		my $lineno = &linenumber($`);
		&perror("WARN", $file, $lineno, "since javavmwrapper 2.0, the ".
			"``javavm'' command to invoke a JVM is deprecated.  Use ".
			"``java'' instead");
	}

	if ($whole =~ //) {
		my $lineno = &linenumber($`);
		&perror("WARN", $file, $lineno, "patch contains ^M characters. ".
			"Consider defining USE_DOS2UNIX to remove DOS line endings ".
			"from source files.");
	}

	close(IN);
}

sub check_depends_syntax {
	my $tmp = shift;
	my $file = shift;
	my (%seen_depends, $j);

	$ENV{'PORTSDIR'} //= $portsdir;

	foreach my $i (grep(/^(PATCH_|EXTRACT_|LIB_|BUILD_|RUN_|TEST_|FETCH_)*DEPENDS[?+]?=/, split(/\n/, $tmp))) {
		$i =~ s/^((PATCH_|EXTRACT_|LIB_|BUILD_|RUN_|TEST_|FETCH_)*DEPENDS)[?+]?=[ \t]*//;
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
		print "OK: checking ports listed in $j.\n" if ($verbose);
		foreach my $k (split(/\s+/, $i)) {
			if ($k =~ /^#/) {
				last;
			}
			if ($k =~ /^\$\{(\w+)\}$/) {
				$k = get_makevar($1);
			}
			my @l = split(':', $k);

			print "OK: checking dependency value for $j.\n"
				if ($verbose);
			if ($k =~ /\${((PATCH_|EXTRACT_|LIB_|BUILD_|RUN_|TEST_|FETCH_)*DEPENDS)}/) {
				&perror("WARN", $file, -1, "do not set $j to $k. ".
					"Instead, explicity list out required $j dependencies.");
			}

			if (($j ne 'DEPENDS'
			  && scalar(@l) != 2 && scalar(@l) != 3)) {
				&perror("WARN", $file, -1, "wrong dependency value ".
					"for $j. $j requires ".
						"2 or 3 ".
					"colon-separated tuples.");
				next;
			}
			my %m = ();
			$m{'dep'} = $l[0];
			$m{'dir'} = $l[1];
			$m{'tgt'} = $l[2];
			print "OK: dep=\"$m{'dep'}\", ".
				"dir=\"$m{'dir'}\", tgt=\"$m{'tgt'}\"\n"
				if ($verbose);

			# check USE_PERL5
			if ($m{'dep'} =~ /^perl5(\.\d+)?$/) {
				&perror("WARN", $file, -1, "dependency to perl5 ".
					"listed in $j. consider using ".
					"USE_PERL5.");
			}

			# Check for ${SITE_PERL} in depends
			if ($m{'dep'} =~ m|^(\${SITE_PERL}/.*)$|) {
				&perror("WARN", $file, -1, "dependency to $1 ".
					"listed in $j. consider using p5-Example-Package-Name>=0.  See ".
					"http://www.freebsd.org/doc/en/books/porters-handbook/using-perl.html".
					" for more details.");
			}

			# check USE_ICONV
			if ($m{'dep'} =~ /^(iconv\.\d+)$/) {
				&perror("WARN", $file, -1, "dependency to $1 ".
					"listed in $j.  consider using ".
					"USE_ICONV.");
			}

			# check USES=gettext
			if ($m{'dep'} =~ /^(intl\.\d+)$/) {
				&perror("WARN", $file, -1, "dependency to $1 ".
					"listed in $j.  consider using ".
					"USES[+]=gettext.");
			}

			# check USES=gmake
			if ($m{'dep'} =~ /^(gmake|\${GMAKE})$/) {
				&perror("WARN", $file, -1, "dependency to $1 ".
					"listed in $j. consider using ".
					"USES[+]=gmake.");
			}

			# check USE_QT
			if ($m{'dep'} =~ /^(qt\d)+$/) {
				&perror("WARN", $file, -1, "dependency to $1 ".
					"listed in $j. consider using ".
					"USE_QT.");
			}

			# check LIBLTDL
			if ($m{'dep'} =~ /^(ltdl\.\d)+$/) {
				&perror("WARN", $file, -1, "dependency to $1 ".
					"listed in $j.  consider using ".
					"USE_LIBLTDL.");
			}

			# check GHOSTSCRIPT
			if ($m{'dep'} eq "gs") {
				&perror("WARN", $file, -1, "dependency to gs ".
					"listed in $j.  consider using ".
					"USE_GHOSTSCRIPT(_BUILD|_RUN).");
			}

			# check JAVALIBDIR
			if ($m{'dep'} =~ m|share/java/classes|) {
				&perror("FATAL", $file, -1, "you should use \${JAVALIBDIR} ".
					"in BUILD_DEPENDS/RUN_DEPENDS to define ".
					"dependencies on JAR files installed in ".
					"\${JAVAJARDIR}");
			}

			# check backslash in LIB_DEPENDS
			if ($osname eq 'NetBSD' && $j eq 'LIB_DEPENDS'
			 && $m{'dep'} =~ /\\\\./) {
				&perror("WARN", $file, -1, "use of backslashes in ".
					"$j is deprecated.");
			}

			# check for PREFIX
			if ($m{'dep'} =~ /\${PREFIX}/) {
				&perror("FATAL", $file, -1, "\${PREFIX} must not be ".
					"contained in *_DEPENDS. ".
					"use \${LOCALBASE} instead.");
			}

			# Check for direct dependency on apache.
			if ($m{'dep'} =~ /\/www\/apache\d*\//) {
				&perror("FATAL", $file, -1, "do not depend on any apache ".
					"port in *_DEPENDS directly.  ".
					"Instead use USE_APACHE=VERSION, where VERSION can be ".
					"found in \${PORTSDIR}/Mk/bsd.apache.mk.");
			}

			# Check for over-specific shared library dependencies
			if ($j eq 'LIB_DEPENDS' && $m{'dep'} =~ m/(\.\d+$)/) {
				&perror("WARN", $file, -1, "$j don't specify the " .
					"ABI version number $1 in $m{'dep'} unless it is " .
					"really necessary.");
			}

			# check port dir existence
			$k = $m{'dir'};
			$k =~ s/\${PORTSDIR}/$ENV{'PORTSDIR'}/;
			$k =~ s/\$[\({]PORTSDIR[\)}]/$ENV{'PORTSDIR'}/;
			if (! -d $k) {
				&perror("WARN", $file, -1, "no port directory $k ".
					"found, even though it is ".
					"listed in $j.");
			} else {
				print "OK: port directory $k found.\n"
					if ($verbose);
			}
		}
	}
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
	my($portname, $portversion, $distfiles, $distversionprefix, $distversion, $distversionsuffix, $distname, $extractsufx) = ('') x 8;
	my $masterport = 0;
	my $slaveport = 0;
	my $use_gnome_hack = 0;
	my $use_java = 0;
	my $use_ant = 0;
	my($realwrksrc, $wrksrc, $nowrksubdir) = ('', '', '');
	my(@mman, @pman);
	my(@aopt, @mopt, @opt);
	my($pkg_version, $versiondir, $versionfile) = ('', '', '');
	my $useindex = 0;
	my %deprecated = ();
	my @deplist = ();
	my %autocmdnames = ();
	my $pre_mk_line = 0;
	my $options_mk_line = 0;
	my $docsused = 0;
	my $optused = 0;
	my $desktop_entries = '';

	open(IN, "< $file") || return 0;
	$rawwhole = '';
	$tmp = 0;
	while (<IN>) {
		if ($_ =~ /[ \t]+\n?$/) {
			&perror("WARN", $file, $., "whitespace before ".
				"end of line.");
		}
		if ($_ =~ /^        /) {	# 8 spaces here!
			&perror("WARN", $file, $., "use tab (not space) to make ".
				"indentation");
		}
		if ($usetabs) {
			if (m/^[A-Za-z0-9_-]+.?= /) {
				if (m/[?+]=/) {
					&perror("WARN", $file, $., "use a tab (not space) after a ".
						"variable name");
				} else {
					&perror("FATAL", $file, $., "use a tab (not space) after a ".
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
		&perror("FATAL", $file, $lineno, "contiguous blank lines ".
			"(> $contblank lines) found.");
	}

	#
	# whole file: header
	#
	my @lines = split("\n", $whole);
	print "OK: checking header in $file.\n" if ($verbose);
	if ($lines[1] =~ /^# (?:New )?[Pp]orts collection [mM]akefile/) {
		&perror("FATAL", $file, 1, "old style headers found.");
	} elsif ($lines[1] =~ /^# Created by: \S/) {
		if ($lines[2] !~ /^# \$$rcsidstr[:\$]/) {
			&perror("FATAL", $file, 2, "header should be ".
				"followed by \$$rcsidstr\$.");
		} elsif ($lines[3] !~ /^$/) {
		#&perror("FATAL", $file, 3, "do not add extra ".
		#		"empty comments after header.");
		}
	# special case for $rcsidsrt\nMCom:
	} elsif ($lines[1] =~ /^# \$$rcsidstr[:\$]/ and $lines[2] =~ /^#\s+\$MCom[:\$]/ and $lines[3] =~ /^$/) {
		# DO NOTHING
	} elsif ($lines[1] !~ /^# \$$rcsidstr[:\$]/ or $lines[2] !~ /^$/) {
		&perror("FATAL", $file, 1, "incorrect header; ".
			"use Created by: with a single space, then \$$rcsidstr\$.");
	}

	#
	# whole file: $(VARIABLE)
	#
	if ($parenwarn) {
		print "OK: checking for \$(VARIABLE).\n" if ($verbose);
		if ($whole =~ /\$\([\w\d]+\)/) {
			my $lineno = &linenumber($`);
			&perror("WARN", $file, $lineno, "use \${VARIABLE}, instead of ".
				"\$(VARIABLE).");
		}
	}

	#
	# whole file: empty(${VARIABLE})
	#
	if ($parenwarn) {
		print "OK: checking for empty(\${VARIABLE}).\n" if ($verbose);
		if ($whole =~ /empty\(\${[\w\d]+/) {
			my $lineno = &linenumber($`);
			&perror("WARN", $file, $lineno, "use empty(VARIABLE), instead of ".
				"empty(\${VARIABLE}).");
		}
	}

	#
	# whole file: use of !=
	#
	print "OK: checking for use of !=.\n" if ($verbose);
	if ($whole =~ /^[\w\d_]+\!=/m) {
		my $lineno = &linenumber($`);
		&perror("WARN", $file, $lineno, "use of != in assignments is almost ".
			"never a good thing to do.  Try to avoid using them.  See ".
			"http://lists.freebsd.org/pipermail/freebsd-ports/2008-July/049777.html ".
			"for some helpful hints on what to do instead.");
	}

	#
	# whole file: use of .elseif
	#
	print "OK: checking for use of .elseif.\n" if ($verbose);
	if ($whole =~ /^\.\s*else\s*if/m) {
		my $lineno = &linenumber($`);
		&perror("FATAL", $file, $lineno, "use of .elseif (or .else if) is not
			supported in all versions of FreeBSD.  Use .elif instead.");
	}

	#
	# whole file: PLIST_FILES and PLIST_DIRS
	#
	print "OK: checking PLIST_FILES and PLIST_DIRS.\n" if ($verbose);
	if ($whole =~ /\nPLIST_FILES.?=/ || $whole =~ /\nPLIST_DIRS.?=/) {
		if (-f 'pkg-plist') {
			my $lineno = &linenumber($`);
			&perror("WARN", $file, $lineno, "You may remove pkg-plist ".
					"if you use PLIST_FILES and/or PLIST_DIRS.");
		}
		my @plist_files = split(/\s+/, $makevar{PLIST_FILES});
		foreach my $plist_file (@plist_files) {
			if ($plist_file =~ m|lib[^\/]+\.so(\.\d+)?$| &&
				$makevar{USE_LDCONFIG} eq '') {
				&perror("WARN", "", -1, "PLIST_FILES: installing shared libraries, ".
					"please define USE_LDCONFIG as appropriate");
			}
			if ($plist_file =~ m|\.omf$| && $makevar{INSTALLS_OMF} eq '') {
				&perror("WARN", "", -1, "PLIST_FILES: installing OMF files, ".
					"please define INSTALLS_OMF (see the FreeBSD GNOME ".
					"porting guide at ".
					"http://www.FreeBSD.org/gnome/docs/porting.html ".
					"for more details)");
			}
			if ($plist_file =~ m|\.core$| && $plist_file !~ /^\@/) {
				&perror("WARN", "", -1, "this port installs a file which ".
					"ends in \".core\".  This file may be deleted if ".
					"daily_clean_disks_enable=\"YES\" in /etc/periodic.conf.  ".
					"If possible, install this file with a different name.");
			}
		}
	}

	#
	# whole file: USE_* and others variables used too late
	#
	my @options_early = qw(
		OPTIONS_DEFAULT
		OPTIONS_DEFINE
		OPTIONS_EXCLUDE
		OPTIONS_GROUP.*?
		OPTIONS_MULTI.*?
		OPTIONS_RADIO.*?
		OPTIONS_SINGLE.*?
	);

	pos($whole) = 0;
	if ($whole =~ /^\.include\s+<bsd\.port\.pre\.mk>$/gm) {
		# Remember position
		$pre_mk_line = &linenumber($`) + 1;
		print "OK: checking for USE_* used too late.\n" if ($verbose);
		my @use_early = qw(
			BZIP2
			GNUSTEP
			IMAKE
			KDE(?:BASE|LIBS)_VER
			(?:LIB)?RUBY
			LINUX_PREFIX
			OPENSSL
			PYTHON
			QT2?
			QT_VER
			X_PREFIX
			ZIP
		);

		my @other_early = qw(
			EMACS_PORT_NAME
		);

		my $earlypattern = join('|', 'USE_(?:'.join('|', @use_early).')',
			@other_early, @options_early);

		while ($whole =~ /^($earlypattern)[+?:!]?=/gmo) {
			my $lineno = &linenumber($`);
			&perror("FATAL", $file, $lineno, "$1 is set after ".
				"including bsd.port.pre.mk.");
		}
	}

	#
	# whole file: check OPTIONS
	#
	print "OK: checking OPTIONS.\n" if ($verbose);
	pos($whole) = 0;
	if ($whole =~ /^\.include\s+<bsd\.port\.options\.mk>$/gm) {
		# Remember position
		$options_mk_line = &linenumber($`) + 1;
	}

	pos($whole) = 0;
	if ($whole =~ /^\.include\s+<bsd\.port\.options\.mk>$/gm) {
		my $earlypattern = join('|', @options_early);
		while ($whole =~ /^($earlypattern)[+?]?=/gmo) {
			my $lineno = &linenumber($`);
			&perror("FATAL", $file, $lineno, "$1 is set after ".
				"including bsd.port.options.mk.");
		}
	}

	pos($whole) = 0;
	foreach my $i ("OPTIONS_RADIO","OPTIONS_SINGLE",
		"OPTIONS_MULTI","OPTIONS_GROUP") {
		foreach my $j (split(/\s+/, $makevar{$i})) {
			if ($j) {
				my @ocount = split(/\s+/, get_makevar("${i}_${j}"));
				if (!scalar(@ocount)) {
					&perror("FATAL", $file, -1,
						"Description for ${i}_${j} does not exist");
				} else {
					push @aopt, @ocount;
				}
			}
		}
	}

	@opt = split(/\s+/, $makevar{OPTIONS_DEFINE});
	pos($whole) = 0;
	while ($whole =~ /PORT_OPTIONS:M(\w+)/mg) {
		push @mopt, $1;
		my $lineno = &linenumber($`) + 1;
		&perror("FATAL", $file, $lineno, "option WITH(OUT)_$1 is used before ".
			"including bsd.port.pre.mk or bsd.port.options.mk.")
			if ($optused && $lineno < $pre_mk_line &&
				$lineno < $options_mk_line);
	}
	my @options_helpers = qw(
		__DUMMY__
		_ALL_TARGET
		_BUILD_DEPENDS
		_EXTRACT_DEPENDS
		_FETCH_DEPENDS
		_LIB_DEPENDS
		_PKG_DEPENDS
		_RUN_DEPENDS
		_CATEGORIES
		_CFLAGS
		_CMAKE_OFF
		_CMAKE_ON
		_CONFIGURE_ENABLE
		_CONFIGURE_ENV
		_CONFIGURE_OFF
		_CONFIGURE_ON
		_CONFIGURE_WITH
		_CPPFLAGS
		_CXXFLAGS
		_DISTFILES
		_INSTALL_TARGET
		_LDFLAGS
		_MAKE_ARGS
		_MAKE_ENV
		_EXTRA_PATCHES
		_PATCHFILES
		_PATCH_DEPENDS
		_PATCH_SITES
		_PLIST_DIRS
		_PLIST_DIRSTRY
		_PLIST_FILES
		_USE
		_USES
	);

	my $m = join("|", @options_helpers);

	if ($makevar{OPTIONS_SUB}) {
		if ($makevar{PLIST_FILES}) {
			foreach my $i (split(/\s+/, $makevar{PLIST_FILES})) {
				push @popt, $1 if $i =~ /^\%\%([^%]+)\%\%/;
			}
		}
		if ($makevar{PLIST_DIRS}) {
			foreach my $i (split(/\s+/, $makevar{PLIST_DIRS})) {
				push @popt, $1 if $i =~ /^\%\%([^%]+)\%\%/;
			}
		}
		# special cases for PORTDOCS/PORTEXAMPLES
		push @popt, "DOCS" if $makevar{PORTDOCS};
		push @popt, "EXAMPLES" if $makevar{PORTEXAMPLES};

		# uniq(@popt)
		my %seen = ();
		@popt = grep { !$seen{$_}++ } @popt;
	}
	foreach my $i ((@opt, @aopt)) {
		if (!grep(/^$i$/, (@mopt, @popt))) {
			if ($whole !~ /\n${i}($m)(.)?=[^\n]+/) {
				&perror("WARN", $file, -1, "$i is listed in ".
						"OPTIONS_DEFINE, but no PORT_OPTIONS:M$i appears.");
			}
		}
	}

	foreach my $i (@mopt) {
		if (!grep(/^$i$/, @opt, @aopt)) {
			# skip global options
			next if ($i eq 'DOCS' or $i eq 'NLS' or $i eq 'EXAMPLES' or $i eq 'IPV6' or $i eq 'X11');
			&perror("WARN", $file, -1, "$i is appears in PORT_OPTIONS:M, ".
				"but not listed in OPTIONS_DEFINE.");
		}
	}

	#
	# whole file: check DESKTOP_ENTRIES for ${TRUE}/${FALSE}
	#
	print "OK: checking DESKTOP_ENTRIES for \${TRUE}/\${FALSE}.\n" if ($verbose);
	$desktop_entries = &get_makevar_raw('DESKTOP_ENTRIES');
	if ($desktop_entries =~ /\${TRUE}/ or $desktop_entries =~ /\${FALSE}/) {
		&perror("FATAL", $file, -1, "Use true/false instead of \${TRUE}/\${FALSE} in DESKTOP_ENTRIES.");
	}

	#
	# whole file: USE_* as a user-settable option
	#
	print "OK: checking for USE_* as a user-settable option.\n" if ($verbose);
	while ($whole =~ /\n\s*\.\s*(?:el)?if[^\n]*?\b(\w*USE_)(\w+)(?![^\n]*\n#?\.error)/g) {
		my $lineno = &linenumber($`);
		&perror("WARN", $file, $lineno, "is $1$2 a user-settable option? ".
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
		&perror("FATAL", $file, $lineno, "NO_CHECKSUM is a user ".
			"variable and is not to be set in a port's Makefile.");
	}

	#
	# whole file: USE_SIZE
	#
	print "OK: checking USE_SIZE.\n" if ($verbose);
	if ($whole =~ /\nUSE_SIZE/) {
			my $lineno = &linenumber($`);
			&perror("WARN", $file, $lineno, "use of USE_SIZE is no longer ".
					"required.");
	}

	#
	# whole file: MACHINE_ARCH
	#
	print "OK: checking MACHINE_ARCH.\n" if ($verbose);
	if ($whole =~ /\nMACHINE_ARCH/) {
		my $lineno = &linenumber($`);
		&perror("FATAL", $file, $lineno, "MACHINE_ARCH should never be ".
		    "overridden.");
	}

	#
	# whole file: DEPRECATED
	#
	print "OK: checking DEPRECATED.\n" if ($verbose);
	if ($whole =~ /\nDEPRECATED[+?]?=[ \t]*"/ &&
		$whole !~ /\nDEPRECATED[+?]?=[ \t]*"\$\{BROKEN\}"/) {
		my $lineno = &linenumber($`);
		&perror("WARN", $file, $lineno, "DEPRECATED messages should not ".
			"be quoted unless they are exactly \"\${BROKEN}\".");
	}
	if ($whole =~ /\nDEPRECATED[+?]?=[^"]*\$\{BROKEN\}/) {
		my $lineno = &linenumber($`);
		&perror("WARN", $file, $lineno, "\"\${BROKEN}\" must be quoted ".
			"when it is the source of DEPRECATED.");
	}

	#
	# whole file: BROKEN et al.
	#
	my ($var);
	foreach $var (qw(IGNORE BROKEN COMMENT FORBIDDEN MANUAL_PACKAGE_BUILD NO_CDROM NO_PACKAGE RESTRICTED)) {
		print "OK: checking ${var}.\n" if ($verbose);
		if ($whole =~ /\n${var}[+?]?=[ \t]+"/) {
			my $lineno = &linenumber($`);
			&perror("WARN", $file, $lineno, "${var} messages should not ".
				"be quoted.");
		}
	}

	if ($whole =~ /\nIGNORE[+?]?=[ \t]+[^a-z \t]/ ||
		$whole =~ /^IGNORE[+?]?=[ \t]+.*\.$/m) {
		my $lineno = &linenumber($`);
		&perror("WARN", $file, $lineno, "IGNORE messages should begin ".
			"with a lowercase letter and end without a period.");
	}

	#
	# whole file: PKGNAME
	#
	print "OK: checking PKGNAME.\n" if ($verbose);
	if ($whole =~ /\nPKGNAME.?=/) {
		my $lineno = &linenumber($`);
		&perror("FATAL", $file, $lineno, "PKGNAME is obsoleted by PORTNAME, ".
			"PORTVERSION, PKGNAMEPREFIX and PKGNAMESUFFIX.");
	}

	#
	# whole file: MAKE_JOBS_UNSAFE
	#
	print "OK: checking for MAKE_JOBS_UNSAFE in combination with NO_BUILD.\n" if ($verbose);
	if ($whole =~ /\nMAKE_JOBS_UNSAFE.?=/) {
		my $matched = $1;
		if ($whole =~ /\nNO_BUILD.?=/) {
			my $lineno = &linenumber($`);
			&perror("WARN", $file, $lineno, "MAKE_JOBS_UNSAFE should not ".
				"be used in combination with NO_BUILD.  You ".
				"should remove MAKE_JOBS_UNSAFE from your Makefile.");
	    	}
	}

	#
	# whole file: USE_GNOME=pkgconfig
	#
	print "OK: checking for USE_GNOME=pkgconfig.\n" if ($verbose);
	if ($makevar{USE_GNOME} =~ /pkgconfig/) {
		&perror("WARN", $file, -1, "USE_GNOME=pkgconfig is now obsolete. ".
			"Use USES[+]=pkgconfig instead.");
	}

	#
	# whole file: EXPIRATION_DATE
	#
	print "OK: checking for valid EXPIRATION_DATE.\n" if ($verbose);
	my $edate;
	if (($edate) = ($whole =~ m/\nEXPIRATION_DATE\??=[ \t]*([^\n]*)\n/)) {
		my $lineno = &linenumber($`);
		if ($edate ne strftime("%Y-%m-%d", 0, 0, 0,
					substr($edate, 8, 2),
					substr($edate, 5, 2) - 1,
					substr($edate, 0, 4) - 1900)) {
			&perror("FATAL", $file, $lineno, "EXPIRATION_DATE ($edate) is ".
				"either not in YYYY-MM-DD format or it is not a valid ".
				"date.");
		}
	}

	#
	# whole file: IS_INTERACTIVE/NOPORTDOCS|PORT_OPTIONS:MDOCS
	#
	print "OK: checking IS_INTERACTIVE.\n" if ($verbose);
	if ($whole =~ /\nIS_INTERACTIVE/) {
		if ($whole !~ /defined\((BATCH|FOR_CDROM)\)/) {
			my $lineno = &linenumber($`);
			&perror("WARN", $file, $lineno, "use of IS_INTERACTIVE ".
				"discouraged. provide batch mode by using BATCH and/or ".
				"FOR_CDROM.");
		}
	}
	print "OK: checking for use of PORT_OPTIONS:MDOCS.\n" if ($verbose);
	if ($sharedocused && $whole =~ /PORT_OPTIONS:MDOCS/) {
		$docsused++;
	}
	print "OK: checking for use of NOPORTDOCS.\n" if ($verbose);
	if ($whole =~ /NOPORTSDOC/) {
		my $lineno = &linenumber($`);
		&perror("WARN", $file, $lineno, "NOPORTSDOC found.  Do you ".
			"mean NOPORTDOCS?");
	}
	if ($sharedocused && $whole !~ /defined\s*\(?NOPORTDOCS\)?/
		&& $whole !~ /def\s*\(?NOPORTDOCS\)?/) {
		if ($docsused == 0 && $whole !~ m#(\$[\{\(]PREFIX[\}\)]|$localbase)/share/doc#) {
			&perror("WARN", $file, -1, "use \".if \${PORT_OPTIONS:MDOCS}\" to wrap ".
				"installation of files into $localbase/share/doc.");
		}
	} else {
		$docsused++;
	}
	if ($docsused > 1) {
		&perror("FATAL", $file, -1, "Both NOPORTDOCS and PORT_OPTIONS:MDOCS are found. ".
			"Remove one or another.");
	}
	print "OK: checking for use of NOPORTDOCS.\n" if ($verbose);
	if ($whole =~ /NOPORTDOCS/) {
		my $lineno = &linenumber($`);
		&perror("WARN", $file, $lineno, "NOPORTDOCS found.  Consider ".
			"using PORT_OPTIONS:MDOCS.");
	}

	#
	# whole file: check for USES[+]=gettext
	#
	print "OK: checking for USES=gettext without PORT_OPTIONS:MNLS.\n" if ($verbose);
	if ($makevar{USES} =~ /\bgettext\b/ && $whole !~ /PORT_OPTIONS:MNLS/) {
		&perror("WARN", $file, -1, "Consider adding support for a NLS ".
			"knob to conditionally disable gettext support.");
	}

	#
	# whole file: check for deprecated commands
	#
	print "OK: checking for deprecated macros.\n" if $verbose;

	%deprecated = (
			USE_MESA		=> 'USE_GL',
			USE_RCORDER		=> 'USE_RC_SUBR',
			INSTALLS_SHLIB  => 'USE_LDCONFIG',
			APACHE_COMPAT   => 'USE_APACHE',
			USE_XPM         => 'USE_X11=xpm',
	);

	@deplist = (\%deprecated);

	for my $dlst (@deplist) {
		my $hurl = $dlst->{'__HELP__'};
		foreach my $depmacro (keys %{$dlst}) {
		    if ($whole =~ /\n($depmacro)[+?:!]?=/) {
				my $derror = "$depmacro is ".
					"deprecated, use $dlst->{$1} instead";
				if (defined($hurl)) {
					$derror .= " (see $hurl for more details)";
				}
				&perror("FATAL", $file, -1, $derror);
			}
		}
	}

	#
	# whole file: DOS line endings
	#
	print "OK: checking for DOS line ending removal.\n" if ($verbose);
	if ($whole =~ // || $whole =~ /:cntrl:/) {
		my $lineno = &linenumber($`);
		&perror("WARN", $file, $lineno, "Possible manual removal of DOS ".
			"line endings found.  Consider defining USE_DOS2UNIX instead.");
	}

	#
	# whole file: direct use of command names
	#
	my %cmdnames = ();
	print "OK: checking direct use of command names.\n" if ($verbose);
	foreach my $i (qw(
awk basename brandelf cat chmod chown cp cpio dialog dirname egrep expr
false file find gmake grep gzcat ldconfig ln md5 mkdir mv objcopy paste patch
pax perl printf rm rmdir pkg_add pkg_delete pkg_info pkg_version
ruby sed sh sort sysctl touch tr which xargs xmkmf
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
	$cmdnames{'pkg_create'} = '${PKG_CMD}';
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
				&& $curline !~ /^USES(.)?=[^\n]+$i/m
				&& $curline !~ /^WX_COMPS(.)?=[^\n]+$i/m
				&& $curline !~ /^\s*#.+$/m
				&& $curline !~ /\-\-$i/m
				&& $curline !~ /^COMMENT(.)?=[^\n]+$i/m) {
					&perror("WARN", $file, $lineno, "possible direct use of ".
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
				&& $lm !~ /^USE_AUTOTOOLS(.)?=[^\n]+($i\d*)/m
				&& $lm !~ /^\s*#.+$/m
				&& $lm !~ /^COMMENT(.)?=[^\n]+($i\d*)/m) {
					&perror("WARN", $file, $lineno, "possible direct use of ".
						"command \"$sm\" found. Use $autocmdnames{$i} ".
						"instead and set according USE_AUTOTOOLS=<tool> macro");
			}
		}
	}

	#
	# whole file: check for use of paths that have macro replacements
	#
	my %pathnames = ();
	print "OK: checking for paths that have macro replacements.\n"
		if ($verbose);
	$pathnames{'${PREFIX}/share/java/classes'} = 'JAVADIR';
	$pathnames{'${PREFIX}/share/java'} = 'JAVASHAREDIR';
	foreach my $i (keys %pathnames) {
		my $lineno = &linenumber($`);
		if ($j =~ m|$i|gm) {
			&perror("FATAL", $file, $lineno, "you should use ".
				"$pathnames{$i} rather than $i");
		}
	}

	#
	# whole file: ldconfig must come with "true" command
	#
	print "OK: checking that ldconfig is properly checked.\n"
		if ($verbose);
	if ($ldconfigwithtrue
	 && $j =~ /(ldconfig|\$[{(]LDCONFIG[)}])/
	 && $j !~ /(\/usr\/bin\/true|\$[{(]TRUE[)}])/) {
	 	my $lineno = &linenumber($`);
		&perror("FATAL", $file, $lineno, "ldconfig must be used with ".
			"\"||\${TRUE}\".");
	}

	#
	# whole file: ${GZIP_CMD} -9 (or any other number)
	#
	print "OK: checking for compression arguments passed to \${GZIP_CMD}.\n"
		if ($verbose);
	if ($j =~ /\${GZIP_CMD}\s+-(\w+(\s+-)?)*(\d)/) {
		my $lineno = &linenumber($`);
		&perror("WARN", $file, $lineno, "possible use of \"\${GZIP_CMD} -$3\" ".
			"found. \${GZIP_CMD} includes \"-\${GZIP}\" which ".
			"sets the compression level.");
	}

	#
	# whole file: ${MKDIR} -p
	#
	print "OK: checking for \${MKDIR} -p.\n"
		if ($verbose);
	if ($j =~ /\${MKDIR}\s+-p/) {
		my $lineno = &linenumber($`);
		&perror("WARN", $file, $lineno, "possible use of \"\${MKDIR} -p\" ".
			"found. \${MKDIR} includes ".
			"\"-p\" by default.");
	}

	#
	# check for use of ${FIND} ... ${XARGS} ${RM}
	#
	print "OK: checking for instances of \${FIND} ... \${XARGS} \${RM}.\n"
		if ($verbose);
	if ($j =~ /\$\{FIND\}.*\|.*\$\{XARGS\}.*\$\{RM\}/) {
			my $lineno = &linenumber($`);
			&perror("WARN", $file, $lineno, "possible use of ".
				"\"\${FIND} ... \${XARGS} \${RM}\" when ".
				"\"\${FIND} ... -delete\" will work.");
	}

	#
	# whole file: ${MACHINE_ARCH}
	#
	print "OK: checking for instances of \${MACHINE_ARCH} being test.\n"
		if ($verbose);
	if ($j =~ /\${MACHINE_ARCH}\s*[!=]=/) {
		my $lineno = &linenumber($`);
		&perror("FATAL", $file, $lineno, "MACHINE_ARCH should never be tested ".
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
		&perror("FATAL", $file, $lineno, "use of SITE_PERL discouraged. ".
				"it is set in bsd.port.mk.");
	}

	#
	# whole file: ${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
	#
	if ($j =~ m'\${(?:LOCALBASE|PREFIX)}/lib/perl5/site_perl/\${PERL_VER}') {
		my $lineno = &linenumber($`);
		&perror("WARN", $file, $lineno, "possible use of \"\${LOCALBASE}/lib/perl5/site_perl/\${PERL_VER}\" ".
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
	# whole file: USE_GCC checks
	#
	if ($whole =~ /^USE_GCC[?:]?=\s*(.*)$/m) {
		my $lineno = &linenumber($`);
		my $gcc_val = $1;
		if ($gcc_val eq 'any' || $gcc_val eq 'yes') {
			# Just accept these two.
		} elsif ($gcc_val =~ /3\.[234]\+/) {
			&perror("WARN", $file, $lineno, "USE_GCC=3.2+, USE_GCC=3.3+, ".
				"and USE_GCC=3.4+ are noops on all currently (and future) ".
				"supported versions of FreeBSD.  Do not use them.");
		} elsif ($gcc_val eq "4.1+") {
			&perror("WARN", $file, $lineno, "USE_GCC=4.2+ is recommended ".
				"over USE_GCC=4.1+ since the former is the system compiler ".
				"for FreeBSD 7.X.");
		} elsif ($gcc_val !~ /\+/ && $gcc_val ne 'any') {
			&perror("WARN", $file, $lineno, "Setting a specific version for ".
				"USE_GCC should only be done as a last resort.  Unless you ".
				"have confirmed this port does not build with later ".
				"versions of GCC, please use USE_GCC=$gcc_val+.");
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
		$whole =~ /^JAVA_BUILD[?:]?=\s*(.*)$/m)) {
		&perror("FATAL", $file, -1, "the port uses Java features, but USE_JAVA ".
			"is not defined");
	}

	#
	# whole file: check for USE_ANT and USE_GMAKE both defined
	#
	if ($use_ant && $whole =~ /^USE_GMAKE[?:]?=\s*(.*)$/m) {
		&perror("WARN", $file, -1, "a port shall not define both USE_ANT ".
			"and USE_GMAKE");
	}

	#
	# whole file: check for USE_APACHE=yes
	#
	if ($whole =~ /^USE_APACHE[?:]?=\s*(yes)$/m) {
		&perror("FATAL", $file, -1, "Use USE_APACHE=VERSION ".
			"(where version can be found in \${PORTSDIR}/Mk/bsd.apache.mk) ".
			"instead of yes");
	}

	#
	# whole file: check for WITH_APACHE\d+
	#
	if ($whole =~ /WITH_APACHE\d+/) {
		&perror("FATAL", $file, -1, "Use WITH_APACHE=yes and .if ".
			"\${APACHE_VERSION} [==|<|>] 13|20|22|24");
	}

	#
	# whole file: check for JAVA_BUILD and NO_BUILD
	#
	if ($whole =~ /^NO_BUILD[?:]?=\s*(.*)$/m &&
		$whole =~ /^JAVA_BUILD[?:]?=\s*(.*)$/m) {
		&perror("FATAL", $file, -1, "JAVA_BUILD and NO_BUILD cannot be set ".
			"at the same time");
	}

	#
	# whole file: check for reassignment of ECHO_MSG
	#
	if ($whole =~ /^ECHO_MSG[?:]?=\s*(.*)$/m) {
		&perror("FATAL", $file, -1, "Re-assigning ECHO_MSG can break ".
			"``make readme''.  Consider using \${PRINTF} directly instead ".
			"for custom message output.");
	}

	#
	# whole file: check for --build, --mandir, and --infodir
	# when GNU_CONFIGURE
	#
	if (exists $makevar{GNU_CONFIGURE} &&
		$makevar{GNU_CONFIGURE} ne '' &&
		$makevar{CONFIGURE_ARGS} =~ /--(build|(man|info)dir)/) {
		&perror("WARN", $file, -1, "--build, --mandir, and --infodir ".
			"are not needed in CONFIGURE_ARGS as they are already set in ".
			"bsd.port.mk.");
	}

	#
	# whole file: CONFIGURE_ENV
	#
	if ($whole =~ /\nCONFIGURE_ENV[?:+]?=\s*([^\\\n]+(\\\n[^\\\n]+)*)/) {
		my $configure_env = $1;
		my $cflags = undef;
		my $cxxflags = undef;
		if ($configure_env =~ /\bCFLAGS="([^"]+)"/ ||
			$configure_env =~ /\bCFLAGS='([^']+)'/ ||
			$configure_env =~ /\bCFLAGS=(\S+)/) {
			$cflags = $1;
		}
		if ($configure_env =~ /\bCXXFLAGS="([^"]+)"/ ||
			$configure_env =~ /\bCXXFLAGS='([^']+)'/ ||
			$configure_env =~ /\bCXXFLAGS=(\S+)/) {
			$cxxflags = $1;
		}

		if (defined($cflags) || defined($cxxflags)) {
			&perror("WARN", $file, -1, "CFLAGS/CXXFLAGS are not needed in ".
				"CONFIGURE_ENV as they are already added there in bsd.port.mk.");
		}

		if ($makevar{GNU_CONFIGURE} ne '') {
			if ((defined($cflags) && $cflags =~ /-I/) ||
				(defined($cxxflags) && $cxxflags =~ /-I/)) {
				&perror("WARN", $file, -1, "Consider passing include paths ".
					"to configure via the CPPFLAGS macro ".
					"(i.e. CPPFLAGS+=-I...)");
			}
		}

		if (defined($cflags) && $cflags !~ /\$\{CFLAGS/) {
			&perror("FATAL", $file, -1, "CFLAGS are clobbered in ".
				"CONFIGURE_ENV.  Alter CFLAGS in the Makefile with ".
				"CFLAGS+=... instead");
		}

		if (defined($cxxflags) && $cflags !~ /\$\{CXXFLAGS/) {
			&perror("FATAL", $file, -1, "CXXFLAGS are clobbered in ".
				"CONFIGURE_ENV.  Alter CXXFLAGS in the Makefile with ".
				"CXXFLAGS+=... instead");
		}

		if ($configure_env =~ /(FC)=/ ||
			$configure_env =~ /(F77)=/ ||
			$configure_env =~ /(FFLAGS)=/) {
				&perror("FATAL", $file, -1, "$1 is already ".
					"passed in CONFIGURE_ENV via bsd.gcc.mk.  If you need to ".
					"override the default value, alter $1 in the Makefile ".
					"instead with $1=...");
		}

		if ($configure_env =~ /(\bCPPFLAGS)=/) {
			&perror("FATAL", $file, -1, "$1 is already ".
				"passed in CONFIGURE_ENV via bsd.port.mk.  If you need to ".
				"override the default value, alter $1 in the Makefile ".
				"instead with $1+=...");
		}

		if ($configure_env =~ /(\bLDFLAGS)=/) {
			&perror("FATAL", $file, -1, "$1 is already passed in ".
				"CONFIGURE_ENV via bsd.port.mk.  If you need to ".
				"override the default value, alter $1 in the Makefile ".
				"instead with $1+=...");
		}
	}

	#
	# whole file: *FLAGS
	#
	foreach my $f (qw(CFLAGS CXXFLAGS CPPFLAGS LDFLAGS)) {
		if ($whole =~ /^$f=/m) {
			&perror("WARN", $file, -1, "$f is overridden in the Makefile ".
				"clobbering a value possibly set by a user.  Consider ".
				"using $f+=... if you want to add or $f:=\${$f:C/...//} ".
				"if you want to remove specific flags");
		}
	}

	#
	# whole file: MAKE_ENV
	#
	if ($whole =~ /\nMAKE_ENV[?:+]?=\s*([^\\\n]+(\\\n[^\\\n]+)*)/) {
		my $make_env = $1;

		if ($make_env =~ /(CPPFLAGS)=/) {
			&perror("FATAL", $file, -1, "$1 is already ".
				"passed in MAKE_ENV via bsd.port.mk.  If you need to ".
				"override the default value, alter $1 in the Makefile ".
				"instead with $1=...");
		}
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
			&perror("FATAL", $file, -1, "supposedly non-slave port with".
				" .CURDIR != MASTERDIR");
		} elsif ($whole =~ /^\.\s*include\s*[<"]bsd\.port\.pre\.mk[">]/m) {
			&perror("FATAL", $file, -1, "slave ports may not include".
				" bsd.port.pre.mk");
		}
		if ($whole !~ /\n\.include\s+"\$\{MASTERDIR\}\/Makefile"\s*$/s) {
			&perror("FATAL", $file, -1, "the last line of a slave port's Makefile has to be".
				' .include "${MASTERDIR}/Makefile"');
		}
		print "OK: checking master port in $masterdir.\n" if ($verbose);
		if (! -e "$masterdir/Makefile") {
			&perror("WARN", "", -1, "unable to locate master port in $masterdir");
		}
		if ($whole !~ /^MASTERDIR=\s*\$\{\.CURDIR\}(?:\/\.\.){1,2}(?:\/[\w\@.+-]+){1,2}\s*$/m) {
			&perror("WARN", $file, -1, "slave ports must define MASTERDIR=".
				'${.CURDIR}/..(/../<category>)/<port>');
		}
	} else {
		#$slaveport = 0;
		print "OK: non-slave port detected, checking for anything after bsd.port(.post).mk.\n"
			if ($verbose);
		if ($whole !~ /\n\.include\s+<bsd\.port(?:\.post)?\.mk>\s*$/s) {
			&perror("FATAL", $file, -1, "the last line of Makefile has to be".
				' .include <bsd.port(.post).mk>');
		}
		if ($whole =~ /^MASTERDIR\s*[+?:!]?\s*=/m) {
			&perror("WARN", $file, -1, "non-slave ports may not define MASTERDIR");
		}
	}

	#
	# break the makefile into sections.
	#
	$tmp = $rawwhole;
	$tmp =~ s/\\\n/ /g;
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
	}
	$tmp = $sections[$idx++];
	$tmp = "\n" . $tmp;	# to make the begin-of-line check easier

	if ($tmp =~ /\n[^#]/) {
		&perror("FATAL", $file, -1, "non-comment line in comment section.");
	}
	if ($osname eq 'NetBSD') {
		foreach my $i (@linestocheck) {
			$j = $i;
			$j =~ s/\(.*\)\?//g;
			$j =~ s/\[(.)[^\]]*\]/$1/g;
			if ($tmp !~ /# $i:[ \t]+\S+/) {
				&perror("FATAL", $file, -1, "no \"$j\" line in comment section.");
			} else {
				print "OK: \"$j\" seen in $file.\n" if ($verbose);
			}
		}
	}
	if ($tmp =~ m/Version [rR]equired/) {
		&perror("WARN", $file, -1, "Version required is no longer needed in the comment section.");
	}
	my $tmp2 = "";
	for (split(/\n/, $tmp)) {
		$tmp2 .= $_ if (m/\$$rcsidstr/);
	}
	if ($tmp2 !~ /#(\s+)\$$rcsidstr([^\$]*)\$$/) {

		&perror("FATAL", $file, -1, "no \$$rcsidstr\$ line in comment ".
			"section.");
	} else {
		print "OK: \$$rcsidstr\$ seen in $file.\n" if ($verbose);
		if ($1 ne ' ') {
			&perror("WARN", $file, -1, "please use single whitespace ".
				"right before \$$rcsidstr\$ tag.");
		}
		if ($2 ne '') {
			if ($verbose || $newport) {	# XXX
				&perror("WARN", $file, -1,
				    ($newport ? 'for new port, '
					      : 'is it a new port? if so, ').
				    "make \$$rcsidstr\$ tag in comment ".
				    "section empty, to make SVN happy.");
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
		$sections[$i] =~ s/^\n//;
	}

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
PROJECTHOST PKGNAMEPREFIX PKGNAMESUFFIX DISTNAME EXTRACT_SUFX DISTFILES
DIST_SUBDIR EXTRACT_ONLY
	));

	# check the items that has to be there.
	$tmp = "\n" . $tmp;
	print "OK: checking PORTNAME/PORTVERSION/DISTVERSION.\n" if ($verbose);
	if ($tmp !~ /\nPORTNAME(.)?=/) {
		&perror("FATAL", $file, -1, "PORTNAME has to be there.") unless ($slaveport && $makevar{PORTNAME} ne '');
	} elsif (defined $1 && $1 ne '') {
		&perror("WARN", $file, -1, "unless this is a master port, PORTNAME has to be set by \"=\", ".
			"not by \"$1=\".") unless ($masterport);
	}
	if ($tmp !~ /\n(PORTVERSION|DISTVERSION)(.)?=/) {
		&perror("FATAL", $file, -1, "PORTVERSION or DISTVERSION has to be there.") unless (($makevar{PORTVERSION} ne '' || $makevar{DISTVERSION} ne ''));
		if (!$slaveport && ($makevar{PORTVERSION} ne '' || $makevar{DISTVERSION} ne '')) {
			&perror("WARN", $file, -1, "PORTVERSION/DISTVERSION is set externally to this port's Makefile, but this port is not configured as a slave port.");
		}
	} elsif (defined $2 && $2 ne '') {
		&perror("WARN", $file, -1, "unless this is a master port, PORTVERSION has to be set by \"=\", ".
			"not by \"$2=\".") unless ($masterport);
	}
	if ($tmp =~ /\nPORTVERSION.?=/ && $tmp =~ /\nDISTVERSION.?=/) {
		&perror("FATAL", $file, -1, "either PORTVERSION or DISTVERSION must be ".
			"specified, not both.");
	}
	if ($newport) {
		print "OK: checking for existence of PORTREVISION in new port.\n"
			if ($verbose);
		if ($tmp =~ /^PORTREVISION(.)?=/m) {
			&perror("WARN", $file, -1, "new ports should not set PORTREVISION.");
		}
	} elsif (!$slaveport) {
		print "OK: checking for PORTREVISION=0.\n" if ($verbose);
		if ($tmp =~ /^PORTREVISION=\s*0/m) {
			&perror("WARN", $file, -1, "Setting PORTREVISION to 0 is not ".
				"necessary.");
		}
	}
	if ($newport) {
		print "OK: checking for existence of PORTEPOCH in new port.\n"
			if ($verbose);
		if ($tmp =~ /^PORTEPOCH(.)?=/m) {
			&perror("WARN", $file, -1, "new ports should not set PORTEPOCH.");
		}
	}
	print "OK: checking CATEGORIES.\n" if ($verbose);
	if ($tmp !~ /\nCATEGORIES(.)?=/) {
		&perror("FATAL", $file, -1, "CATEGORIES has to be there.") unless ($makevar{CATEGORIES} ne '');
		if (!$slaveport && $makevar{CATEGORIES} ne '') {
			&perror("WARN", $file, -1, "CATEGORIES is set externally to this port's Makefile, but this port is not configured as a slave port.");
		}
	} elsif (defined $1 && ($i = $1) ne '' && $i =~ /[^?+]/) {
		&perror("WARN", $file, -1, "unless this is a master port, CATEGORIES should be set by \"=\", \"?=\", or \"+=\", ".
			"not by \"$i=\".") unless ($masterport);
	}

	@cat = split(/\s+/, $makevar{CATEGORIES});
	if (@cat == 0) {
		&perror("FATAL", $file, -1, "CATEGORIES left blank. set it to \"misc\"".
		" if nothing seems apropriate.");
	} else {
		my %seencat = ();
		foreach my $cat (@cat) {
			if ($seencat{$cat}) {
				&perror("WARN", $file, -1, "Duplicate category, $cat specified".
					" in CATEGORIES.");
			} else {
				$seencat{$cat} = 1;
			}
		}
	}

	if ($use_java && !grep /^java$/, @cat) {
		&perror("WARN", $file, -1, "the port uses Java but is not part of the ".
			"``java'' category");
	}

	if (scalar(@cat) == 1 && $cat[0] eq "java") {
		&perror("FATAL", $file, -1, "the ``java'' category shall not be the only ".
			"one for a port");
	}

	if ($newport && scalar(@cat) > 0 && $cat[0] eq "java") {
		&perror("WARN", $file, -1, "save for ports directly related to the Java ".
			"language, porters are encouraged not to use ``java'' as ".
			"the main category for a port");
	}

	if ($committer && $makevar{'.CURDIR'} =~ m'${portsdir}/([^/]+)/[^/]+/?$') {
		if ($cat[0] ne $1 && $makevar{PKGCATEGORY} ne $1 ) {
			&perror("FATAL", $file, -1, "category \"$1\" must be listed first");
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
		&perror("WARN", $file, -1, "multiple language specific categories detected. ".
		"are you sure?");
		do {
			shift @cat;
		} while (@cat && grep($_ eq $cat[0], @lang_cat));
	}

	# check x11 in CATEGORIES
	if ($newxdef) {
#MICHAEL: I don't understand this line
		if (2 <= @cat && $cat[1] eq "x11") {
			&perror("WARN", $file, -1, "only specific kind of apps should ".
				"specify \"x11\" in CATEGORIES. ".
				"Do you mean just USE_XORG? ".
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
				&perror("WARN", $file, -1, "when you specify multiple categories, ".
				"language specific category should come first.");
			}
		}
	}

	# check number of MASTER_SITES
	if ($makevar{MASTER_SITES} ne '' &&
		! grep {$makevar{MASTER_SITES} =~ m|$_|} @MASTERSITES_WHITELIST) {
		my @sites = split(/\s+/, $makevar{MASTER_SITES});
		if (scalar(@sites) == 1) {
			&perror("WARN", $file, -1, "only one MASTER_SITE configured.  ".
				"Consider adding additional mirrors.");
		}
	}

	# check the URL
	if (($tmp =~ /\nMASTER_SITES[+?]?=[ \t]*([^\n]*)\n/
	 && $1 !~ /^[ \t]*$/) || ($makevar{MASTER_SITES} ne '')) {
		print "OK: seen MASTER_SITES, sanity checking URLs.\n"
			if ($verbose);
		my $urlseen = 0;
		my @sites = split(/\s+/, $1 // '');
		my $ftphttp = 0;
		foreach my $i (@sites) {
			last if ($i =~ /^#/);
			if ($i =~ m#^\w+://#) {
				$urlseen = 1;
				$ftphttp = 1 if ($i =~ /^(ftp|http):/);
				&urlcheck($i, $file);
				unless (&is_predefined($i, $file)) {
					print "OK: URL \"$i\" ok.\n"
						if ($verbose);
				}
			} else {
				print "OK: non-URL \"$i\" ok.\n"
					if ($verbose);
				# Assume variables contain an ftp/http site.
				$ftphttp = 1;
			}
		}
		&perror("WARN", $file, -1, "no ftp/http mirror in MASTER_SITES ".
			"for users behind a proxy.") if ($urlseen && ! $ftphttp);
	} else {
		&perror("WARN", $file, -1, "no MASTER_SITES found. is it ok?");
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
			&perror("WARN", $file, -1, "no need to define EXTRACT_SUFX if ".
				"DISTFILES is defined.");
		}
		if ($extractsufx eq '.tar.gz') {
			&perror("WARN", $file, -1, "EXTRACT_SUFX is \".tar.gz.\" ".
				"by default. you don't need to specify it.");
		}
		if ($extractsufx eq '.tar.bz2') {
			&perror("WARN", $file, -1, "EXTRACT_SUFX is \".tar.bz2.\" ".
				"You should use USE_BZIP2 instead.");
		}
		if ($extractsufx eq '.zip') {
			 &perror("WARN", $file, -1, "EXTRACT_SUFX is \".zip\" ".
				"You should use USE_ZIP instead.");
		}
	} else {
		print "OK: no EXTRACT_SUFX seen, using default value.\n"
			if ($verbose);
		$extractsufx = '.tar.gz';
	}

	print "OK: sanity checking PORTNAME/PORTVERSION/DISTVERSIONPREFIX/DISTVERSION/DISTVERSIONSUFFIX.\n" if ($verbose);
	if ($distname ne '') {
		my $exp_distname = $makevar{DISTNAME};
		if ($exp_distname eq "$portname-$portversion") {
			&perror("WARN", $file, -1, "DISTNAME is \${PORTNAME}-\${PORTVERSION} by ".
				"default, you don't need to define DISTNAME.");
		} else {
			if ($exp_distname eq "$portname-$distversionprefix$distversion$distversionsuffix") {
				&perror("WARN", $file, -1, "DISTNAME is \${PORTNAME}-\${DISTVERSIONPREFIX}\${DISTVERSION}\${DISTVERSIONSUFFIX} by ".
					"default, you don't need to define DISTNAME.");
			}
		}
		if ($distname =~ /PORTREVISION/) {
			&perror("FATAL", $file, -1, "DISTNAME contains a reference to ".
				"PORTREVISION.  You should only be using PORTVERSION");
		}
		if ($distname =~ /PORTEPOCH/) {
			&perror("FATAL", $file, -1, "DISTNAME contains a reference to ".
				"PORTEPOCH.  You should only be using PORTVERSION");
		}
	}
	if ($portname =~ /^$re_lang_short/) {
		&perror("FATAL", $file, -1, "language prefix is automatically".
			" set by PKGNAMEPREFIX.".
			" you must remove it from PORTNAME.");
	}
	if ($portname =~ /([|<>=! ])/) {
		&perror("FATAL", $file, -1, "PORTNAME contains the illegal character \"$1\".".
			" You should modify \"$portname\".");
	} elsif ($portname =~ /\$[\{\(].+[\}\)]/) {
		&perror("WARN", $file, -1, "using variable in PORTNAME.".
			" consider using PKGNAMEPREFIX and/or PKGNAMESUFFIX.");
	} elsif ($portname =~ /([^\w._@+-])/) {
		&perror("WARN", $file, -1, "using \"$1\" in PORTNAME.".
			" You should modify \"$portname\".");
	} elsif ($portname =~ /-/ && $distname ne '') {
		&perror("WARN", $file, -1, "using hyphen in PORTNAME.".
			" consider using PKGNAMEPREFIX and/or PKGNAMESUFFIX.");
	}
	if ($portversion eq '' && $distversion eq '') {
		&perror("FATAL", $file, -1, "either PORTVERSION or DISTVERSION must be specified");
	}
	if ($portversion =~ /^pl[0-9]*$/
	|| $portversion =~ /^[0-9]*[A-Za-z]?[0-9]*(\.[0-9]*[A-Za-z]?[0-9+]*)*$/) {
		print "OK: PORTVERSION \"$portversion\" looks fine.\n" if ($verbose);
	} elsif ($portversion =~ /^[^\-]*\$[{\(].+[\)}][^\-]*$/) {
		&perror("WARN", $file, -1, "using variable, \"$portversion\", as version ".
			"number");
	} elsif ($portversion =~ /([-,_<>=! #*])/) {
		&perror("FATAL", $file, -1, "PORTVERSION must not contain \"$1\". ".
			"You should modify \"$portversion\".");
	} else {
		&perror("FATAL", $file, -1, "PORTVERSION looks illegal. ".
			"You should modify \"$portversion\".");

	}

	$pkg_version = $makevar{PKG_VERSION};

	if ($makevar{CONFLICTS}) {
		print "OK: checking CONFLICTS.\n" if ($verbose);
		foreach my $conflict (split ' ', $makevar{CONFLICTS}) {
			my $selfconflict;
			if ($makevar{PKGINSTALLVER} ne "" &&
				$makevar{PKGINSTALLVER} >= 20040125) {
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
				&perror("WARN", "", -1, "Conflict \"$conflict\" specified too narrow. ".
					"You should end it with a wildcard (-[0-9]*).");
			} elsif ($conflict !~ /[<>=-][^-]*[0-9][^-]*$/) {
				&perror("WARN", "", -1, "Conflict \"$conflict\" specified too broad. ".
					"You should end it with a version number fragment (-[0-9]*).");
			}
			if ($selfconflict) {
				&perror("FATAL", "", -1, "Package conflicts with itself. ".
					"You should remove \"$conflict\" from CONFLICTS.");
			}
		}
	}

	$versiondir = $ENV{VERSIONDIR} // '/var/db/chkversion';

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
					&perror("FATAL", $file, -1, "$makevar{PKGNAME} < $version. ".
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
		&perror("WARN", $file, -1, "use of DISTFILES with single file ".
			"discouraged. distribution filename should be set by ".
			"DISTNAME and EXTRACT_SUFX.");
		if ($distfiles eq (($distname ne '') ? $distname : "$portname-$portversion") . $extractsufx) {
			&perror("WARN", $file, -1, "definition of DISTFILES not necessary. ".
				"DISTFILES is \${DISTNAME}/\${EXTRACT_SUFX} ".
				"by default.");
		}

		# display advice only in certain cases.
#MICHAEL: will this work with multiple distfiles in this list?  what about
#         doing the same sort of thing for DISTNAME, is it needed?
		if ($distfiles =~ /^\Q$i\E([\-.].+)$/) {
			&perror("WARN", $file, -1, "how about \"EXTRACT_SUFX=$1\"".
				", instead of DISTFILES?");
		}
	}

	# additional checks for committer.
	if ($committer && $has_lang_cat) {
		&perror("WARN", $file, -1, "be sure to include language code ".
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

				&perror("WARN", "", -1, "be sure to remove $portdir/$tgz ".
				"before committing the port.");
			}
		}
	}

	push(@varnames, qw(
PORTNAME PORTVERSION PORTREVISION PORTEPOCH CATEGORIES MASTER_SITES
PKGNAMEPREFIX PKGNAMESUFFIX DISTNAME EXTRACT_SUFX
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

		if ($tmp =~ /PATCH_SITES[?+]?=[^\n]+\n/) {
			print "OK: seen PATCH_SITES.\n" if ($verbose);
			$tmp =~ s/PATCH_SITES[?+]?=[^\n]+\n//;
		}
		if ($tmp =~ /PATCH_SITE_SUBDIR[?+]?=[^\n]+\n/) {
			print "OK: seen PATCH_SITE_SUBDIR.\n" if ($verbose);
			$tmp =~ s/PATCH_SITE_SUBDIR[?+]?=[^\n]+\n//;
		}
		if ($tmp =~ /PATCHFILES[?+]?=[^\n]+\n/) {
			print "OK: seen PATCHFILES.\n" if ($verbose);
			$tmp =~ s/PATCHFILES[?+]?=[^\n]+\n//;
		}
		if ($tmp =~ /PATCH_DIST_STRIP[?+]?=[^\n]+\n/) {
			print "OK: seen PATCH_DIST_STRIP.\n" if ($verbose);
			$tmp =~ s/PATCH_DIST_STRIP[?+]?=[^\n]+\n//;
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
	$tmp = $sections[$idx];

	&checkearlier($file, $tmp, @varnames);
	&checkorder('MAINTAINER', $tmp, $file, qw(
MAINTAINER COMMENT
	));

	$tmp = "\n" . $tmp;
	if ($tmp =~ /\nMAINTAINER(\?)?=([^\n]+)/) {
		my $addr = $2;
		if (defined $1 && $1 ne '') {
			&perror("WARN", $file, -1, "unless this is a master port, ".
				"MAINTAINER has to be set by \"=\", ".
				"not by \"$1=\".") unless ($masterport);
		}
		$addr =~ s/^\s*//;
		$addr =~ s/\s*$//;
		if ($addr =~ /[\s,<>()]/) {
			&perror("FATAL", $file, -1, "MAINTAINER should be a single address without comment.");
		}
		if ($addr !~ /^[^\@]+\@[\w\d\-\.]+$/) {
			&perror("FATAL", $file, -1, "MAINTAINER address, $addr, does not appear to be a valid email address.");
		}
		if ($newport && $addr =~ /ports\@freebsd.org/i) {
			&perror("WARN", $file, -1, "new ports should not be maintained by ".
				"ports\@FreeBSD.org.");
		}
		$tmp =~ s/\nMAINTAINER\??=[^\n]+//;
	} elsif ($whole !~ /\nMAINTAINER[?]?=/) {
		&perror("FATAL", $file, -1, "no MAINTAINER listed.") unless ($makevar{MAINTAINER} ne '');
		if (!$slaveport && $makevar{MAINTAINER} ne '') {
			&perror("WARN", $file, -1, "MAINTAINER is set externally to this port's Makefile, but this port is not configured as a slave port.");
		}
	}
	$tmp =~ s/\n\n+/\n/g;

	# check COMMENT
	if ($tmp !~ /\nCOMMENT(.)?=/) {
		&perror("FATAL", $file, -1, "COMMENT has to be there.") unless ($makevar{COMMENT} ne '');
		if (!$slaveport && $makevar{COMMENT} ne '') {
			&perror("WARN", $file, -1, "COMMENT is set externally to this port's Makefile, but this port is not configured as a slave port.");
		}
	} elsif (defined $1 && $1 ne '') {
		&perror("WARN", $file, -1, "unless this is a master port, COMMENT has to be set by \"=\", ".
			"not by \"$1=\".") unless ($masterport);
	} else { # check for correctness
		if (($makevar{COMMENT} !~ /^["\[0-9A-Z]/) || ($makevar{COMMENT} =~ m/\.$/)) { #"
			&perror("WARN", $file, -1, "COMMENT should begin with a capital, and end without a period");
		}
		if (length($makevar{COMMENT}) > 70) {
			&perror("WARN", $file, -1, "COMMENT exceeds 70 characters limit.");
		}
	}

	$idx++;

	push(@varnames, qw(
MAINTAINER COMMENT
	));

	#
	# section 5: LICENSE
	#
	print "OK: checking fourth section of $file (LICENSE).\n"
		if ($verbose);
	$tmp = $sections[$idx];

	if ($makevar{LICENSE}) {
		&checkorder('LICENSE', $tmp, $file, qw(
			LICENSE LICENSE_COMB LICENSE_GROUPS(_\w+)? LICENSE_NAME(_\w+)?
			LICENSE_TEXT(_\w+)? LICENSE_FILE(_\w+)? LICENSE_PERMS(_\w+)?
			LICENSE_DISTFILES(_\w+)?
		));

		# check LICENSE
		if ($makevar{LICENSE} && $makevar{LICENSE} ne '') {
			my $comb = $makevar{LICENSE_COMB} // 'single';

			my @tokens = split(/ /, $makevar{LICENSE});
			if ($comb eq 'single' && scalar(@tokens) > 1) {
				&perror("FATAL", $file, -1, "LICENSE contains multiple licenses but LICENSE_COMB is not set to 'dual' or 'multi'");
			}
		}

		# check value of LICENSE_COMB
		if ($makevar{LICENSE_COMB} && $makevar{LICENSE_COMB} !~ /^(single|dual|multi$)/) {
			&perror("FATAL", $file, -1, "LICENSE_COMB contains invalid value '$1' - must be one of 'single', 'dual', 'multi'");
		}

		$idx++;

		push(@varnames, qw(
			LICENSE LICENSE_COMB LICENSE_GROUPS LICENSE_NAME
			LICENSE_TEXT LICENSE_FILE LICENSE_PERMS
		));
	} else {
		&perror("WARN", $file, -1, "Consider defining LICENSE.");
	}

	#
	# section 6: *_DEPENDS (may not be there)
	#
	print "OK: checking fifth section of $file (*_DEPENDS).\n"
		if ($verbose);
	$tmp = $sections[$idx];

	# Check for direct assignment of BUILD_DEPENDS to RUN_DEPENDS.
	if ($tmp =~ /\nRUN_DEPENDS=[ \t]*\${BUILD_DEPENDS}/) {
		&perror("FATAL", $file, -1, "RUN_DEPENDS should not be set to ".
			"\${BUILD_DEPENDS} as \${BUILD_DEPENDS} includes other ".
			"implicit dependencies.  Instead, copy the explicit dependencies ".
			"from BUILD_DEPENDS to RUN_DEPENDS.  See ".
			"http://www.freebsd.org/doc/en_US.ISO8859-1/books/porters-handbook/makefile-depend.html#AEN2154 ".
			"for more details.");
	}

	# NOTE: EXEC_DEPENDS is obsolete, so it should not be listed.
	@linestocheck = qw(
EXTRACT_DEPENDS LIB_DEPENDS PATCH_DEPENDS BUILD_DEPENDS RUN_DEPENDS
TEST_DEPENDS FETCH_DEPENDS DEPENDS_TARGET
	);

	if ($tmp =~ /^(PATCH_|EXTRACT_|LIB_|BUILD_|RUN_|TEST_|FETCH_)DEPENDS/m) {
		&checkearlier($file, $tmp, @varnames);

		check_depends_syntax($tmp, $file);

		foreach my $i (@linestocheck) {
			$tmp =~ s/$i[?+:]?=[^\n]+\n//g;
		}

		&checkextra($tmp, '*_DEPENDS', $file);

		$idx++;
	}

	push(@varnames, @linestocheck);
	&checkearlier($file, $tmp, @varnames);

	#
	# Makefile 7: check the rest of file
	#
	print "OK: checking the rest of the $file.\n" if ($verbose);
	$tmp = join("\n\n", @sections[$idx .. scalar(@sections)-1]);

	$tmp = "\n" . $tmp;	# to make the begin-of-line check easier

	&checkearlier($file, $tmp, @varnames);

	# Check depends that might be specified based on the WITH_/WITHOUT_
	# arguments and other external variables.
	check_depends_syntax($tmp, $file);

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
			&perror("WARN", $file, -1, "WRKSRC is set to meaningless value ".
				"\"$1\".".
				($nowrksubdir eq ''
					? " use \"NO_WRKSUBDIR=yes\" instead."
					: ""));
		}
		if ($bogusdistfiles) {
			if ($distname ne '' && $wrksrc eq '') {
			    &perror("WARN", $file, -1, "do not use DISTFILES and DISTNAME ".
				"to control WRKSRC. how about ".
				"\"WRKSRC=\${WRKDIR}/$distname\"?");
			} else {
			    &perror("WARN", $file, -1, "DISTFILES/DISTNAME affects WRKSRC. ".
				"take caution when changing them.");
			}
		}
	} else {
		print "OK: seen NO_WRKSUBDIR, checking value of WRKSRC.\n"
			if ($verbose);
		if ($wrksrc eq 'work' || $wrksrc =~ /^$[\{\(]WRKDIR[\}\)]/) {
			&perror("WARN", $file, -1, "definition of WRKSRC not necessary. ".
				"WRKSRC is \${WRKDIR} by default.");
		}
	}

	# check RESTRICTED/NO_CDROM/NO_PACKAGE
	print "OK: checking RESTRICTED/NO_CDROM/NO_PACKAGE.\n" if ($verbose);
	if ($committer && $tmp =~ /\n(RESTRICTED|NO_CDROM|NO_PACKAGE)[+?]?=/) {
		&perror("WARN", $file, -1, "\"$1\" found. do not forget to update ".
			"ports/LEGAL.");
	}

	# check NO_CONFIGURE/NO_PATCH
	print "OK: checking NO_CONFIGURE/NO_PATCH.\n" if ($verbose);
	if ($tmp =~ /\n(NO_CONFIGURE|NO_PATCH)[+?]?=/) {
		&perror("FATAL", $file, -1, "\"$1\" was obsoleted. remove this.");
	}

	# check NO_STAGE
	if ($makevar{NO_STAGE}) {
		&perror("WARN", $file, -1, "Consider adding STAGE support.");
	}

	# check MAN[1-9LN]
	print "OK: checking MAN[0-9LN].\n" if ($verbose);
	foreach my $i (keys %plistmanall) {
		print "OK: pkg-plist MAN$i=$plistmanall{$i}\n" if ($verbose);
	}
	if ($tmp =~ /PERL_CONFIGURE=\s*/
		&& $tmp =~ /^MAN3PREFIX=\s*\${PREFIX}\/lib\/perl5\/\${PERL_VERSION}/) {
		&perror("WARN", $file, -1, "MAN3PREFIX is ".
			"\"\${PREFIX}/lib/perl5/\${PERL_VERSION}\" ".
			"when PERL_CONFIGURE is set.  You do not need to specify it.");
	}
	foreach my $i (split(//, $manchapters)) {
		if ($tmp =~ /\nMAN\U$i\E[+?]=\s*([^\n]*)\n/ &&
			(!$makevar{NO_STAGE} || $makevar{NO_STAGE} eq '')) {
			&perror("FATAL", $file, -1, "when STAGE support is enabled ".
				"you must add your man pages directly to the plist ".
				"with a .gz extension.");
		} elsif ($tmp =~ /\nMAN\U$i\E[+?]=\s*([^\n]*)\n/) {
			print "OK: Makefile MAN\U$i\E=$1\n" if ($verbose);
		}
	}
	if ($tmp =~ /\nMANCOMPRESSED=\s*/ &&
		(!$makevar{NO_STAGE} || $makevar{NO_STAGE} eq '')) {
		&perror("WARN", $file, -1, "when STAGE support is enable, the ".
			"MANCOMPRESSED macro is not supported.  The compress-man ".
			"target is able to only compress when it is needed.");
	}
	foreach my $i (split(//, $manchapters)) {
		next if ($i eq '');
		my @mansecs = grep(/^MAN\U$i\E=\s*(.*)/, split(/\n/, $tmp));
		if (scalar @mansecs > 1) {
			&perror("FATAL", $file, -1, "duplicate MAN$i macro.  ".
				"Only the last MAN$i macro will be processed.  Use ".
				"MAN$i+=... instead to append man pages.");
		}
		if ($tmp =~ /^MAN\U$i\E=\s*([^\n]*)\n/) {
			@mman = grep($_ !~ /^\s*$/, split(/\s+/, $1));
			@pman = grep($_ !~ /^\s*$/,
				split(/\s+/, $plistmanall{$i} // ''));
			foreach my $j (@mman) {
				print "OK: checking $j (Makefile)\n"
					if ($verbose);
				if ($automan && grep($_ eq $j, @pman)) {
					&perror("FATAL", $file, -1, "duplicated manpage ".
						"entry $j: content of ".
						"MAN\U$i\E will be automatically ".
						"added to pkg-plist.");
				} elsif (!$automan && !grep($_ eq $j, @pman)) {
					&perror("WARN", $file, -1, "manpage $j ".
						"MAN\U$i\E but not in pkg-plist.");
				}
			}
			foreach my $j (@pman) {
				print "OK: checking $j (pkg-plist)\n" if ($verbose);
				if (!grep($_ eq $j, @mman)) {
					&perror("WARN", $file, -1, "manpage $j in pkg-plist ".
						"but not in MAN\U$i\E.");
				}
			}
		} else {
			if ($plistmanall{$i} && $makevar{NO_STAGE} &&
				$makevar{NO_STAGE} ne '') {
				if ($manstrict) {
					&perror("FATAL", $file, -1, "manpage for chapter ".
						"$i must be listed in ".
						"MAN\U$i\E. ");
				} else {
					&perror("WARN", $file, -1, "manpage for chapter ".
						"$i should be listed in ".
						"MAN\U$i\E, ".
						"even if compression is ".
						"not necessary.");
				}
			}
			if ($mancompress && $plistman{$i}) {
				&perror("WARN", $file, -1, "MAN\U$i\E will help you ".
					"compressing manual page in chapter ".
					"\"$i\".");
			} elsif (!$mancompress && $plistmangz{$i}) {
				&perror("WARN", $file, -1, "MAN\U$i\E will help you ".
					"uncompressing manual page in chapter ".
					"\"$i\".");
			}
		}
	}
	if ($tmp !~ /MANLANG/ && scalar(keys %manlangs)) {
		$i = (keys %manlangs)[0];
		&perror("WARN", $file, -1, "how about using MANLANG for ".
			"designating manual language, such as \"$i\"?");
	}

	# check INFO
	print "OK: checking INFO.\n" if ($verbose);
	if ($autoinfo && $tmp =~ /\nINFO=\s*([^\n]*)\n/) {
		my @minfo = grep($_ !~ /^\s*$/, split(/\s+/, $1));
		if ($tmp =~ /[\/|\s]install-info\s/) {
			&perror("FATAL", $file, -1, "install-info is automatically run ".
				"when INFO is defined.");
		}
		foreach $i (@minfo) {
			if ($i =~ /\.info(-\d+)?$/) {
				&perror("FATAL", $file, -1, "do not include the .info extension ".
					"on files listed in the INFO macro.");
			}
		}
	} elsif ($autoinfo && $tmp =~ /[\/|\s]install-info\s/) {
		&perror("WARN", $file, -1, "do not call install-info directly.  Use the ".
			"INFO macro instead.");
	}

	# check for HAS_CONFIGURE or GNU_CONFIGURE
	if ($tmp =~ /\nGNU_CONFIGURE[?+]?=/
		&& $tmp =~ /\n(HAS_CONFIGURE)[?+]?=/) {
		&perror("WARN", $file, -1, "since you already have GNU_CONFIGURE, ".
			"you do not need $1.");
	}

	# check direct use of important make targets.
	if ($tmp =~ /\n(fetch|extract|patch|configure|build|install):/) {
		&perror("FATAL", $file, -1, "direct redefinition of make target \"$1\" ".
			"discouraged. redefine \"do-$1\" instead.");
	}

	# check for incorrect use of the pre-everything target.
	if ($tmp =~ /\npre-everything:[^:]/) {
		&perror("FATAL", $file, -1, "use pre-everything:: instead of pre-everything:");
	}

	if ($tmp =~ /^pre-patch:/m && $use_gnome_hack) {
		&perror("FATAL", $file, -1, "pre-patch target overwrites gnomehack component. ".
			"use post-patch instead.");
	}

	if ($tmp =~ /^do-build:/m && $use_ant) {
		&perror("WARN", $file, -1, "USE_ANT is intended only for ports that ".
			"build with Ant.  It is recommended not to override the default ".
			"'do-build:' target when defining USE_ANT");
	}

	#
	# check for deprecated use of USE_RC_SUBR, and current syntax
	#
	if ($tmp =~ /\nUSE_RC_SUBR=([\s]*)(.*)/) {
		my $subr_value = $makevar{USE_RC_SUBR};
		if ($subr_value eq '') {
			$subr_value = $2;
		}

		if (($subr_value =~ /^yes$/i) ||
			($subr_value =~ /^true$/i) ||
			($subr_value =~ /^1$/)) {
			&perror("FATAL", $file, -1, "The value of the USE_RC_SUBR variable ".
				"should be the name of the intended rc.d script, and there ".
				"should be a corresponding file in the files/ directory.");
		} else {
			foreach my $i (split(/\s/, $subr_value)) {
				my $mvar;
				if ($i =~ /\$\{([^}]+)\}/) {
					$mvar = $1;
					if (defined($makevar{$mvar})) {
						$i = $makevar{$mvar};
					} else {
						$i = &getMakevar($mvar);
					}
				}
				if ($i ne '' && ! -f "files/$i.in") {
					&perror("FATAL", $file, -1, "$i listed in USE_RC_SUBR, ".
						"but files/$i.in is missing.");
				} elsif ($i eq '' && $mvar ne '') {
					&perror("WARN", $file, -1, "possible undefined make variable ".
						"$mvar used as the value for USE_RC_SUBR.");
				}
			}
		}
	}

	1;
}

sub perror($$$$) {
	my($type, $file, $line, $msg) = @_;

	if ($type eq 'FATAL') {
		$err++;
	} else {
		$warn++;
	}
	if ($grouperrs) {
		$msg = '%%LINES%%' . $msg;
		if ($file ne "") {
			$msg = $file . ": " . $msg;
		}
		$msg = $type . ": " . $msg;
		if (!$errcache{$msg}) {
			push @errlst, $msg;
		}
		if ($line > -1) {
			push @{$errcache{$msg}}, $line;
		}
	} else {
		if ($line > -1) {
			$msg = "[$line]: " . $msg;
		}
		if ($file ne "") {
			$msg = $file . ": " . $msg;
		}
		$msg = $type . ": " . $msg;
		print $msg . "\n";
	}
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
		&perror("WARN", $file, -1, "extra item placed in the ".
			"$section section, ".
			"for example, \"$1\".");
	} else {
		&perror("WARN", $file, -1, "extra item placed in the ".
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
			if (defined $order[$k] &&
			$order[$k] =~ /[\.\*\+\?\{\}\[\]\^\$\|]/ &&
			$i =~ /$order[$k]/) {
				last;
			}
			$k++;
		}
		if (defined $order[$k] && $order[$k] =~ /[\.\*\+\?\{\}\[\]\^\$\|]/ &&
			$i =~ /$order[$k]/) {
			if ($k < $j) {
				&perror("FATAL", $file, -1, "$i appears out-of-order.");
				$invalidorder++;
			} else {
				print "OK: seen $i, in order.\n" if ($verbose);
			}
			$j = $k;
		} elsif (defined $order[$k] && $order[$k] eq $i) {
			if ($k < $j) {
				&perror("FATAL", $file, -1, "$i appears out-of-order.");
				$invalidorder++;
			} else {
				print "OK: seen $i, in order.\n" if ($verbose);
			}
			$j = $k;
		# This if condition tests for .if, .else (in all forms),
		# .for and .endfor and .include
		} elsif ($i !~ m/^\.(if|el|endif|for|endfor|include)/) {
			&perror("FATAL", $file, -1, "extra item \"$i\" placed in the ".
				"$section section.");
		}
	}
	if ($invalidorder) {
		&perror("FATAL", $file, -1, "order must be " . join('/', @order) . '.');
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
			&perror("WARN", $file, -1, "\"$i\" has to appear earlier.");
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
	# XXX: This next pattern crashes Perl 5.8.7.
	#$str =~ s/[ \t][\@-]?(echo|\$[\{\(]ECHO[\}\)]|\$[\{\(]ECHO_MSG[\}\)])[ \t]+("(\\'|\\"|[^"])*"|'(\\'|\\"|[^"])*')[ \t]*[;\n]//; #'
	$str =~ s/[ \t][\@-]?(echo|\$[\{\(]ECHO[\}\)]|\$[\{\(]ECHO_MSG[\}\)])[ \t]+.*(;|$)//m; #'

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
		if ($i ne '' && ! grep {$i =~ m|^$_|} @ALLOWED_FULL_PATHS) {
			$i =~ s/\s.*$//;
			$i =~ s/['"].*$//; #'
			$i = substr($i, 0, 20) . '...' if (20 < length($i));
			&perror("WARN", $file, -1, "possible use of absolute pathname ".
				"\"$i\".");
		}
	}

	print "OK: checking direct use of pathnames, phase 1.\n" if ($verbose);
%cmdnames = split(/\n|\t+/, <<EOF);
/usr/opt	\${PORTSDIR} instead
$portsdir	\${PORTSDIR} instead
$localbase	\${PREFIX} or \${LOCALBASE}, as appropriate
EOF
	foreach my $i (keys %cmdnames) {
		if ($str =~ /$i/) {
			&perror("WARN", $file, -1, "possible direct use of \"$&\" ".
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
			&perror("WARN", $file, -1, "possible direct use of \"$i\" ".
				"found. if so, use $cmdnames{$i}.");
		}
	}
}

sub get_makevar {
	my($cmd, $result);

	$cmd = join(' -V ', "make $makeenv MASTER_SITE_BACKUP=''", @_);
	$result = `$cmd`;
	chomp $result;

	return $result;
}

sub get_makevar_raw {
	my($cmd, $result);

	$cmd = join(' -XV ', "make $makeenv MASTER_SITE_BACKUP=''", @_);
	$result = `$cmd`;
	chomp $result;

	return $result;
}

sub is_predefined {
	my($url, $file) = @_;
	my($site, $site_re);
	my $subdir_re = quotemeta quotemeta '/%SUBDIR%/';
	for my $site (keys %predefined) {
		$site_re = quotemeta $site;
		$site_re =~ s,$subdir_re,/(.*)/,;

		if ($url =~ /$site_re/) {
			&perror("WARN", $file, -1, "how about using ".
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
		&perror("WARN", $file, -1, "\"$url\" doesn't appear to be a URL to me.");
	}
	if ($url !~ m#/(:[^/:]+)?$#) {
		&perror("FATAL", $file, -1, "URL \"$url\" should ".
			"end with \"/\" or a group name (e.g. :something).");
	}
	if ($url =~ m#://[^/]*:/#) {
	&perror("FATAL", $file, -1, "URL \"$url\" contains ".
				"extra \":\".");
	}
	if ($osname eq 'FreeBSD' && $url =~ m#(www\.freebsd\.org)/~.+/#i) {
		&perror("WARN", $file, -1, "URL \"$url\", ".
			"$1 should be ".
			"people.FreeBSD.org");
	}
}
sub TRUE {1;}

# Local variables:
# tab-width: 4
# End:
