#! /usr/bin/perl
#
# portlint - lint for port directory
# implemented by:
#	Jun-ichiro itojun Itoh <itojun@itojun.org>
#	Yoshishige Arai <ryo2@on.rim.or.jp>
#
# Copyright(c) 1997 by Jun-ichiro Itoh <itojun@itojun.org>.
# All rights reserved.
# Freely redistributable.  Absolutely no warranty.
#
# Pleae note that this perl code MUST be able to handle (Open|Net|Free)BSD
# bsd.port.mk.  There are significant differences in those so you'll have
# hard time upgrading this...
#
# $Id: portlint.pl,v 1.2 1999/01/05 12:26:08 itojun Exp $
#

$err = $warn = 0;
$extrafile = $parenwarn = $committer = $verbose = $newport = 0;
$contblank = 1;
$portdir = '.';

# default setting - for FreeBSD
$portsdir = '/usr/ports';
$rcsidstr = '(Id|FreeBSD)';
$multiplist = 0;
$ldconfigwithtrue = 0;
$rcsidinplist = 0;
$mancompress = 1;
$manstrict = 0;
$newxdef = 1;
$automan = 1;
$manchapters = '123456789ln';
$localbase = '/usr/local';

#select(STDERR);
while (@ARGV > 0) {
	$_ = shift;
	/^-h/ && do {
		($prog) = ($0 =~ /([^\/]+)$/);
		print STDERR <<EOF;
usage: $prog [-abcvN] [-B#] [port_directory]
	-a	additional check for scripts/* and pkg/*
	-b	warn \$(VARIABLE)
	-c	committer mode
	-v	verbose mode
	-N	writing a new port
	-B#	allow # contiguous blank lines (default: $contblank line)
EOF
		exit 0;
	};
	/^-a/ && do {$extrafile = 1; next;};
	/^-b/ && do {$parenwarn = 1; next;};
	/^-c/ && do {$committer = 1; next;};
	/^-v/ && do {$verbose = 1; next;};
	/^-N/ && do {$newport = 1; next;};
	/^-B(\d+)$/ && do { $contblank = $1; next; };
	@ARGV > 0 && /^-B$/ && do {
		$contblank = shift;
		if ($contblank !~ /^\d+$/) {
			print STDERR "FATAL: -B must come with number.\n";
			exit 1;
		}
		next;
	};
	$portdir = $_;
}

# OS dependent configs
# os	portsdir	rcsid		mplist	ldcfg	plist-rcsid mancompresss strict	localbase	newxdef	automan
@osdep = split(/\n/, <<EOF);
FreeBSD	/usr/ports	(Id|FreeBSD)	0	0	0		1	0	/usr/local	1	1
NetBSD	/usr/pkgsrc	NetBSD		1	1	1		0	1	/usr/pkg	0	0
EOF
$osname = `uname -s`;
$osname =~ s/\n$//;
foreach $i (@osdep) {
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

#
# variables for global checks.
#
$sharedocused = 0;
%plistmanall = ();
%plistmangz = ();
%plistman = ();
%manlangs = ();

%predefined = ();
foreach $i (split("\n", <<EOF)) {
XCONTRIB	ftp://ftp.x.org/contrib/
XCONTRIB	ftp://crl.dec.com/pub/X11/contrib/
GNU		ftp://prep.ai.mit.edu/pub/gnu/
GNU		ftp://wuarchive.wustl.edu/systems/gnu/
PERL_CPAN	ftp://ftp.digital.com/pub/plan/perl/CPAN/modules/by-module/
PERL_CPAN	ftp://ftp.cdrom.com/pub/perl/CPAN/modules/by-module/
TEX_CTAN	ftp://ftp.cdrom.com/pub/tex/ctan/
TEX_CTAN	ftp://wuarchive.wustl.edu/packages/TeX/
TEX_CTAN	ftp://ftp.funet.fi/pub/TeX/CTAN/
TEX_CTAN	ftp://ftp.tex.ac.uk/public/ctan/tex-archive/
TEX_CTAN	ftp://ftp.dante.de/tex-archive/
SUNSITE		ftp://sunsite.unc.edu/pub/Linux/
SUNSITE		ftp://ftp.infomagic.com/pub/mirrors/linux/sunsite/
SUNSITE		ftp://ftp.funet.fi/pub/mirrors/sunsite.unc.edu/pub/Linux/
EOF
	($j, $k) = split(/\t+/, $i);
	$predefined{$k} = $j;
}

#
# check for files.
#
@checker = ('pkg/COMMENT', 'pkg/DESCR', 'Makefile', 'files/md5');
%checker = ('pkg/COMMENT', 'checkdescr', 'pkg/DESCR', 'checkdescr',
		'Makefile', 'checkmakefile', 'files/md5', 'TRUE');
if ($extrafile) {
	foreach $i ((<$portdir/scripts/*>, <$portdir/pkg/*>)) {
		next if (! -T $i);
		$i =~ s/^$portdir\///;
		next if (defined $checker{$i});
		if ($i =~ /pkg\/PLIST$/
		 || ($multiplist && $i =~ /pkg\/PLIST/)) {
			unshift(@checker, $i);
			$checker{$i} = 'checkplist';
		} else {
			push(@checker, $i);
			$checker{$i} = 'checkpathname';
		}
	}
}
foreach $i (<$portdir/patches/patch-??>) {
	next if (! -T $i);
	$i =~ s/^$portdir\///;
	next if (defined $checker{$i});
	push(@checker, $i);
	$checker{$i} = 'checkpatch';
}
foreach $i (@checker) {
	print "OK: checking $i.\n";
	if (! -f "$portdir/$i") {
		&perror("FATAL: no $i in \"$portdir\".");
	} else {
		$proc = $checker{$i};
		&$proc($i) || &perror("Cannot open the file $i\n");
		if ($i !~ /^patches\//) {
			&checklastline($i)
				|| &perror("Cannot open the file $i\n");
		}
	}
}
if ($committer) {
	if (scalar(@_ = <$portdir/work/*>) || -d "$portdir/work") {
		&perror("WARN: be sure to cleanup $portdir/work ".
			"before committing the port.");
	}
	if (scalar(@_ = <$portdir/*/*~>) || scalar(@_ = <$portdir/*~>)) {
		&perror("WARN: for safety, be sure to cleanup ".
			"emacs backup files before committing the port.");
	}
	if (scalar(@_ = <$portdir/*/*.orig>) || scalar(@_ = <$portdir/*.orig>)
	 || scalar(@_ = <$portdir/*/*.rej>) || scalar(@_ = <$portdir/*.rej>)) {
		&perror("WARN: for safety, be sure to cleanup ".
			"patch backup files before committing the port.");
	}
}
if ($err || $warn) {
	print "$err fatal errors and $warn warnings found.\n"
} else {
	print "looks fine.\n";
}
exit $err;

#
# pkg/COMMENT, pkg/DESCR
#
sub checkdescr {
	local($file) = @_;
	local(%maxchars) = ('pkg/COMMENT', 70, 'pkg/DESCR', 80);
	local(%maxlines) = ('pkg/COMMENT', 1, 'pkg/DESCR', 24);
	local(%errmsg) = ('pkg/COMMENT', "must be one-liner.",
			  'pkg/DESCR',	"exceeds $maxlines{'pkg/DESCR'} ".
					"lines, make it shorter if possible.");
	local($longlines, $linecnt, $tmp) = (0, 0, "");

	open(IN, "< $portdir/$file") || return 0;
	while (<IN>) {
		$linecnt++;
		$longlines++ if ($maxchars{$file} < length($_));
		$tmp .= $_;
	}
	if ($linecnt > $maxlines{$file}) {
		&perror("WARN: $file $errmsg{$file}".
			"(currently $linecnt lines)");
	} else {
		print "OK: $file has $linecnt lines.\n" if ($verbose);
	}
	if ($longlines > 0) {
		&perror("WARN: $i includes lines that exceed $maxchars{$file} ".
			"charactors.");
	}
	if ($tmp =~ /[\033\200-\377]/) {
		&perror("WARN: pkg/DESCR includes iso-8859-1, or ".
			"other local characters.  $file should be".
			"plain ascii file.");
	}
	close(IN);
}

#
# pkg/PLIST
#
sub checkplist {
	local($file) = @_;
	local($curdir) = ($localbase);
	local($inforemoveseen, $infoinstallseen, $infoseen) = (0, 0, 0);
	local($infobeforeremove, $infoafterinstall) = (0, 0);
	local($infooverwrite) = (0);
	local($rcsidseen) = (0);

	open(IN, "< $portdir/$file") || return 0;
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
				&perror("WARN: use \"\@dirrm\" ".
					"instead of \"\@unexec rmdir\".");
			} elsif ($_ =~ /^\@exec[ \t]+install-info/) {
				$infoinstallseen = $.;
			} elsif ($_ =~ /^\@unexec[ \t]+install-info[ \t]+--delete/) {
				$inforemoveseen = $.;
			} elsif ($_ =~ /^\@(exec|unexec)/) {
				if ($ldconfigwithtrue
				 && /ldconfig/
				 && !/\/usr\/bin\/true/) {
					&perror("FATAL: $file $.: ldconfig ".
						"must be used with ".
						"\"||/usr/bin/true\".");
				}
			} elsif ($_ =~ /^\@(comment)/) {
				$rcsidseen++ if (/\$$rcsidstr[:\$]/);
			} elsif ($_ =~ /^\@(dirrm|option)/) {
				; # no check made
			} else {
				&perror("WARN: $file $.: ".
					"unknown PLIST directive \"$_\"");
			}
			next;
		}

		if ($_ =~ /^\//) {
			&perror("FATAL: $file $.: use of full pathname ".
				"disallowed.");
		}

		if ($_ =~ /^info\/.*info(-[0-9]+)?$/) {
			$infoseen = $.;
			$infoafterinstall++ if ($infoinstallseen);
			$infobeforeremove++ if (!$inforemoveseen);
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
		&perror("FATAL: \"\@exec install-info\" must be placed ".
			"after all the info files.");
	} elsif ($infoafterinstall) {
		&perror("FATAL: move \"\@exec install-info\" line to make ".
			"sure that it is placed after all the info files. ".
			"(currently on line $infoinstallseen in $file)");
	}
	if (!$inforemoveseen) {
		&perror("FATAL: \"\@unexec install-info --delete\" must ".
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
	local($file) = @_;
	local($whole);

	open(IN, "< $portdir/$file") || return 0;
	$whole = '';
	while (<IN>) {
		$whole .= $_;
	}
	&abspathname($whole, $file);
	close(IN);
}

sub checklastline {
	local($file) = @_;
	local($whole);

	open(IN, "< $portdir/$file") || return 0;
	$whole = '';
	while (<IN>) {
		$whole .= $_;
	}
	if ($whole !~ /\n$/) {
		&perror("FATAL: the last line of $file has to be ".
			"terminated by \\n.");
	}
	if ($whole =~ /\n([ \t]*\n)+$/) {
		&perror("WARN: $file seems to have unnecessery blank lines ".
			"at the last part.");
	}

	close(IN);
}

sub checkpatch {
	local($file) = @_;
	local($whole);

	if (-z "$portdir/$file") {
		&perror("FATAL: $file has no content. should be removed ".
			"from repository.");
		return;
	}

	open(IN, "< $portdir/$file") || return 0;
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
	local($file) = @_;
	local($rawwhole, $whole, $idx, @sections);
	local($tmp);
	local($i, $j, $k, $l);
	local(@varnames) = ();
	local($distfiles, $pkgname, $distname, $extractsufx) = ('', '', '', '');
	local($bogusdistfiles) = (0);
	local($realwrksrc, $wrksrc, $nowrksubdir) = ('', '', '');
	local(@mman, @pman);

	open(IN, "< $portdir/$file") || return 0;
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
		&perror("FATAL: contiguous blank lines (> $contblank lines) found ".
			"in $file at line " . int(split(/\n/, $`)) . ".");
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
	# whole file: IS_INTERACTIVE/NOPORTDOCS
	#
	$whole =~ s/\n#[^\n]*/\n/g;
	$whole =~ s/\n\n+/\n/g;
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
	print "OK: checking direct use of command names.\n" if ($verbose);
	foreach $i (split(/\s+/, <<EOF)) {
awk basename cat cp echo false gmake grep gzcat
ldconfig md5 mkdir mv patch rm rmdir sed setenv touch tr xmkmf
EOF
		$cmdnames{$i} = "\$\{\U$i\E\}";
	}
	$cmdnames{'gunzip'} = '${GUNZIP_CMD}';
	$cmdnames{'gzip'} = '${GZIP_CMD}';
	$cmdnames{'install'} = '${INSTALL_foobaa}';
	#
	# ignore parameter string to echo command.
	# note that we leave the command as is, since we need to check the
	# use of echo itself.
	$j = $whole;
	$j =~ s/([ \t][\@-]?)(echo|\$[\{\(]ECHO[\}\)]|\$[\{\(]ECHO_MSG[\}\)])[ \t]+("(\\'|\\"|[^"])*"|'(\\'|\\"|[^'])*')[ \t]*[;\n]/$1$2;/;
	foreach $i (keys %cmdnames) {
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
	# break the makefile into sections.
	#
	@sections = split(/\n\n+/, $rawwhole);
	for ($i = 0; $i < scalar(@sections); $i++) {
		if ($sections[$i] !~ /\n$/) {
			$sections[$i] .= "\n";
		}
	}
	$idx = 0;

	#
	# section 1: comment lines.
	#
	print "OK: checking comment section of $file.\n" if ($verbose);
	@linestocheck = split("\n", <<EOF);
Whom
Version [rR]equired
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
	foreach $i (@linestocheck) {
		$j = $i;
		$j =~ s/\(.*\)\?//g;
		$j =~ s/\[(.)[^\]]*\]/$1/g;
		if ($tmp !~ /# $i:[ \t]+\S+/) {
			&perror("FATAL: no \"$j\" line in ".
				"comment section of $file.");
		} else {
			print "OK: \"$j\" seen in $file.\n" if ($verbose);
		}
	}
	if ($tmp !~ /#\n#(\s+)\$$rcsidstr([^\$]*)\$\n/) {
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
		$sections[$i] =~ s/\n#[^\n]*//g;
		$sections[$i] =~ s/\n\n+/\n/g;
		$sections[$i] =~ s/\\\n/ /g;
	}

	#
	#
	# section 2: DISTNAME/PKGNAME/...
	#
	print "OK: checking first section of $file. (DISTNAME/...)\n"
		if ($verbose);
	$tmp = $sections[$idx++];

	# check the order of items.
	&checkorder('DISTNAME', $tmp, split(/\s+/, <<EOF));
DISTNAME PKGNAME CATEGORIES MASTER_SITES MASTER_SITE_SUBDIR
EXTRACT_SUFX DISTFILES
EOF

	# check the items that has to be there.
	$tmp = "\n" . $tmp;
	foreach $i ('DISTNAME', 'CATEGORIES') {
		print "OK: checking $i.\n" if ($verbose);
		if ($tmp !~ /\n$i=/) {
			&perror("FATAL: $i has to be there.");
		}
		if ($tmp =~ /\n$i(\?=)/) {
			&perror("FATAL: $i has to be set by \"=\", ".
				"not by \"$1\".");
		}
	}

	# check x11 in CATEGORIES
	if ($newxdef
	 && $tmp =~ /\nCATEGORIES[+?]?=[ \t]*([^\n]*)\n/
	 && ($foo = $1) =~ /x11/) {
		print "OK: checking x11 in CATEGORIES.\n" if ($verbose);
		@i = split(/\s+/, $foo);
		if ($i[0] =~ /^x11\-?/) {
			; # okay
		} elsif ($i[0] =~ /(chinese|japanese|korean|german|russian)/) {
			; # okay
		} else {
			&perror("WARN: only specific kind of apps should ".
				"specify \"x11\" in CATEGORIES. ".
				"Do you mean just USE_XLIB? ".
				"Then remove \"x11\" from CATEGORIES.");
		}
	}

	# check the URL
	if ($tmp =~ /\nMASTER_SITES[+?]?=[ \t]*([^\n]*)\n/
	 && $1 !~ /^[ \t]*$/) {
		print "OK: seen MASTER_SITES, sanity checking URLs.\n"
			if ($verbose);
		@sites = split(/\s+/, $1);
		foreach $i (@sites) {
			if ($i =~ m#^\w+://#) {
				if ($i !~ m#/$#) {
					&perror("FATAL: URL \"$i\" should ".
						"end with \"/\".");
				}
				if ($i =~ m#://[^/]*:/#) {
					&perror("FATAL: URL \"$i\" contains ".
						"extra \":\".");
				}
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
	$pkgname = $1 if ($tmp =~ /\nPKGNAME[+?]?=[ \t]*([^\n]+)\n/);
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

	print "OK: sanity checking PKGNAME.\n" if ($verbose);
	if ($pkgname ne '' && $pkgname eq $distname) {
		&perror("WARN: PKGNAME is \${DISTNAME} by default, ".
			"you don't need to define PKGNAME.");
	}
	$i = ($pkgname eq '') ? $distname : $pkgname;
	if ($i =~ /-([^-]+)$/) {
		$j = $`;
		$k = $1;
		if ($j =~ /[0-9]$/) {
			&perror("WARN: is \"$j\" sane as package name ".
				"WITHOUT version number? ".
				"if not, avoid \"-\" in version number ".
				"part of ".
				(($pkgname eq '') ? "DISTNAME." : "PKGNAME."));
		}
		if ($k =~ /^pl[0-9]*$/
		 || $k =~ /^[0-9]*[A-Za-z]?[0-9]*(\.[0-9]*[A-Za-z]?[0-9]*)*$/) {
			print "OK: trailing part of PKGNAME\"-$k\" ".
				"looks fine.\n" if ($verbose);
		} else {
			&perror("FATAL: version number part of PKGNAME".
				(($pkgname eq '')
					? ', which is derived from DISTNAME, '
					: ' ').
				"looks illegal. should modify \"-$k\".");
		}
	} else {
		&perror("FATAL: PKGNAME".
			(($pkgname eq '')
				? ', which is derived from DISTNAME, '
				: ' ').
			"must come with version number, like \"foobaa-1.0\".");
		if ($i =~ /_pl[0-9]*$/
		 || $i =~ /_[0-9]*[A-Za-z]?[0-9]*(\.[0-9]*[A-Za-z]?[0-9]*)*$/) {
			&perror("FATAL: you seem to using underline ".
				"before version number in PKGNAME. ".
				"it has to be hyphen.");
		}
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
		if ($distfiles eq $distname . $extractsufx) {
			&perror("WARN: definition of DISTFILES not necessery. ".
				"DISTFILES is \${DISTNAME}/\${EXTRACT_SUFX} ".
				"by default.");
		}

		# make an advice only in certain cases.
		if ($pkgname ne '' && $distfiles =~ /^$pkgname([-\.].+)$/) {
			&perror("WARN: how about \"DISTNAME=$pkgname\"".
				(($1 eq '.tar.gz')
					? ""
					: " and \"EXTRACT_SUFX=$1\"").
				", instead of DISTFILES?");
		}
	}

	# additional checks for committer.
	$i = ($pkgname eq '') ? $distname : $pkgname;
	if ($committer && $i =~ /^(de|ja|ko|ru|vi|zh)-/) {
		&perror("WARN: be sure to include country code \"$1-\" ".
			"in the module alias name.");
	}
	if ($committer && -f "$portdir/$i.tgz") {
		&perror("WARN: be sure to remove $portdir/$i.tgz ".
			"before committing the port.");
	}

	push(@varnames, split(/\s+/, <<EOF));
DISTNAME PKGNAME CATEGORIES MASTER_SITES MASTER_SITE_SUBDIR
EXTRACT_SUFX DISTFILES
EOF

	#
	# section 3: PATCH_SITES/PATCHFILES(optional)
	#
	print "OK: checking second section of $file, (PATCH*: optinal).\n"
		if ($verbose);
	$tmp = $sections[$idx];

	if ($tmp =~ /(PATCH_SITES|PATCH_SITE_SUBDIR|PATCHFILES|PATCH_DIST_STRIP)/) {
		&checkearlier($tmp, @varnames);

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

	push(@varnames, split(/\s+/, <<EOF));
PATCH_SITES PATCHFILES PATCH_DIST_STRIP
EOF

	#
	# section 4: MAINTAINER
	#
	print "OK: checking third section of $file (MAINTAINER).\n"
		if ($verbose);
	$tmp = $sections[$idx++];

	&checkearlier($tmp, @varnames);
	$tmp = "\n" . $tmp;
	if ($tmp =~ /\nMAINTAINER=[^\n]+/) {
		$tmp =~ s/\nMAINTAINER=[^\n]+//;
	} else {
		&perror("FATAL: no MAINTAINER listed in $file.");
	}
	$tmp =~ s/\n\n+/\n/g;

	&checkextra($tmp, 'MAINTAINER');

	push(@varnames, 'MAINTAINER');

	#
	# section 5: *_DEPENDS (may not be there)
	#
	print "OK: checking fourth section of $file(*_DEPENDS).\n"
		if ($verbose);
	$tmp = $sections[$idx];

	# NOTE: EXEC_DEPENDS is obsolete, so it should not be listed.
	@linestocheck = split(/\s+/, <<EOF);
LIB_DEPENDS BUILD_DEPENDS RUN_DEPENDS FETCH_DEPENDS DEPENDS DEPENDS_TARGET
EOF
	if ($tmp =~ /(LIB_|BUILD_|RUN_|FETCH_)?DEPENDS/) {
		&checkearlier($tmp, @varnames);

		if (!defined $ENV{'PORTSDIR'}) {
			$ENV{'PORTSDIR'} = $portsdir;
		}
		foreach $i (grep(/^[A-Z_]*DEPENDS[?+]?=/, split(/\n/, $tmp))) {
			$i =~ s/^([A-Z_]*DEPENDS)[?+]?=[ \t]*//;
			$j = $1;
			print "OK: checking ports listed in $j.\n"
				if ($verbose);
			foreach $k (split(/\s+/, $i)) {
				@l = split(':', $k);

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
				%m = ();
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

				# check port dir existence
				$k = $m{'dir'};
				$k =~ s/\${PORTSDIR}/$ENV{'PORTSDIR'}/;
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
		foreach $i (@linestocheck) {
			$tmp =~ s/$i[?+]?=[^\n]+\n//g;
		}

		&checkextra($tmp, '*_DEPENDS');

		$idx++;
	}

	push(@varnames, @linestocheck);
	&checkearlier($tmp, @varnames);

	#
	# Makefile 6: check the rest of file
	#
	print "OK: checking the rest of the $file.\n" if ($verbose);
	$tmp = join("\n\n", @sections[$idx .. scalar(@sections)-1]);

	$tmp = "\n" . $tmp;	# to make the begin-of-line check easier

	&checkearlier($tmp, @varnames);

	# check WRKSRC/NO_WRKSUBDIR
	#
	# do not use DISTFILES/DISTNAME to control over WRKSRC.
	# DISTNAME is for controlling distribution filename.
	# example:
	#	DISTNAME= package
	#	PKGNAME=  package-1.0
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
			&perror("WARN: definition of WRKSRC not necessery. ".
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
	foreach $i (keys %plistmanall) {
		print "OK: PLIST MAN$i=$plistmanall{$i}\n" if ($verbose);
	}
	foreach $i (split(//, $manchapters)) {
		if ($tmp =~ /MAN\U$i\E=\s*([^\n]*)\n/) {
			print "OK: Makefile MAN$i=$1\n" if ($verbose);
		}
	}
	foreach $i (split(//, $manchapters)) {
		next if ($i eq '');
		if ($tmp =~ /MAN\U$i\E=\s*([^\n]*)\n/) {
			@mman = grep($_ !~ /^\s*$/, split(/\s+/, $1));
			@pman = grep($_ !~ /^\s*$/,
				split(/\s+/, $plistmanall{$i}));
			foreach $j (@mman) {
				print "OK: checking $j (Makefile)\n"
					if ($verbose);
				if ($automan && grep($_ eq $j, @pman)) {
					&perror("FATAL: duplicated manpage ".
						"entry $j: content of ".
						"MAN$i will be automatically ".
						"added to PLIST.");
				} elsif (!$automan && !grep($_ eq $j, @pman)) {
					&perror("WARN: manpage $j in $file ".
						"MAN$i but not in PLIST.");
				}
			}
			foreach $j (@pman) {
				print "OK: checking $j (PLIST)\n" if ($verbose);
				if (!grep($_ eq $j, @mman)) {
					&perror("WARN: manpage $j in PLIST ".
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
						"not necessery.");
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
	local(@msg) = @_;
	if ($msg[0] =~ /^FATAL/) {
		$err++;
	} else {
		$warn++;
	}
	print join("\n", @msg) . "\n";
}

sub checkextra {
	local($str, $section) = @_;

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
	local($section, $str, @order) = @_;
	local(@items, $i, $j, $k, $invalidorder);

	print "OK: checking the order of $section section.\n" if ($verbose);

	@items = ();
	foreach $i (split("\n", $tmp)) {
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
		if (@order[$k] eq $i) {
			if ($k < $j) {
				&perror("FATAL: $i appears out-of-order.");
				$invalidorder++;
			} else {
				print "OK: seen $i, in order.\n" if ($verbose);
			}
			$j = $k;
		} else {
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
	local($str, @varnames) = @_;
	local($i);

	print "OK: checking items that has to appear earlier.\n" if ($verbose);
	foreach $i (@varnames) {
		if ($str =~ /\n$i[?+]?=/) {
			&perror("WARN: \"$i\" has to appear earlier in $file.");
		}
	}
}

sub abspathname {
	local($str, $file) = @_;
	local($s, $i, %cmdnames);
	local($pre);

	# ignore parameter string to echo command
	$str =~ s/[ \t][\@-]?(echo|\$[\{\(]ECHO[\}\)]|\$[\{\(]ECHO_MSG[\}\)])[ \t]+("(\\'|\\"|[^"])*"|'(\\'|\\"|[^"])*')[ \t]*[;\n]//;

	print "OK: checking direct use of full pathnames in $file.\n"
		if ($verbose);
	foreach $s (split(/\n+/, $str)) {
		$i = '';
		if ($s =~ /(^|[ \t\@'"-])(\/[\w\d])/) {
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
			$i =~ s/['"].*$//;
			$i = substr($i, 0, 20) . '...' if (20 < length($i));
			&perror("WARN: possible use of absolute pathname ".
				"\"$i\", in $file.");
		}
	}

	print "OK: checking direct use of pathnames, phase 1.\n" if ($verbose);
%cmdnames = split(/\n|\t+/, <<EOF);
/usr/opt	\${PORTSDIR} instead
$portsdir	\${PORTSDIR} instead
$localbase	\${PREFIX} or \${LOCALBASE}, as appropriate
/usr/X11	\${PREFIX} or \${X11BASE}, as appropriate
EOF
	foreach $i (keys %cmdnames) {
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
	foreach $i (keys %cmdnames) {
		if ($str =~ /(\.\/|\$[\{\(]\.CURDIR[\}\)]\/|[ \t])(\b$i)\//) {
			&perror("WARN: possible direct use of \"$i\" ".
				"found in $file. if so, use $cmdnames{$i}.");
		}
	}
}

sub is_predefined {
	local($url) = @_;
	local($site);
	local($subdir);
	if ($site = (grep($url =~ $_, keys %predefined))[0]) {
		$url =~ /$site/;
		$subdir = $';
		$subdir =~ s/\/$//;
		&perror("WARN: how about using ".
			"\${MASTER_SITE_$predefined{$site}} with ".
			"\"MASTER_SITE_SUBDIR=$subdir\", instead of \"$url\?");
		return &TRUE;
	}
	undef;
}

sub TRUE {1;}
