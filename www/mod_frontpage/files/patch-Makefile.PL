--- Makefile.PL.orig	Tue Mar 12 22:07:07 2002
+++ Makefile.PL	Sun Feb 22 10:26:40 2004
@@ -9,14 +9,39 @@
 # FP extensions 5.0 from Martin Blapp <mbr@freebsd.org>
 #
 
-$flavor=`uname`;
-if (-e "/etc/mandrake-release") {$flavor="Mandrake";}
+use Symbol;
+use POSIX qw(:errno_h);
+use Cwd;
+
+$prefix= $ENV{PREFIX};
+if (!$prefix) {
+	$prefix = "/usr/local/";
+} else {
+	if ($prefix =~ /^(.*?)[\/]{1,}$/) {
+		$prefix = $1;
+	}
+}
 
-if ($flavor eq "FreeBSD") { $thechoice="/usr/local/sbin/httpd"; 
-} elsif ($flavor eq "Mandrake") { $thechoice="/usr/sbin/httpd"; 
+$worksrc= $ENV{WRKSRC};
+if (!$worksrc) {
+	$worksrc = "./";
+} elsif ($worksrc eq "\.") {
+	$worksrc = "./";
+}
+
+$ostype=`uname`;
+chop $ostype;
+if (-e "/etc/mandrake-release") {
+    $flavor="Mandrake";
+}
+
+if ($ostype eq "FreeBSD" && -e "$prefix/sbin/httpd") {
+    $thechoice="$prefix/sbin/httpd"; 
+} elsif ($ostype eq "Linux" && -e "/usr/sbin/httpd") {
+    $thechoice="/usr/sbin/httpd"; 
 } else {
     print "Enter the path of your httpd binary.\n";
-    print "It should be something like /usr/local/apache/bin).\n";
+    print "It should be something like $prefix/apache/bin).\n";
     print "If you don't know, enter the word 'findit'. I will try to look\n";
     print "for you... but it will take a few minutes.\n";
     print "Your choice: ";
@@ -66,7 +91,7 @@
 print "Libexecdir: $libexecdir\n";
 print "\n";
 
-$tmpfile="/tmp/frontpage.$$";
+$tmpfile="$worksrc/../tmpfrontpage.$$";
 #Mandrake now has two config files, one main and one included
 #if we build on another distro, it ignores it
 `cat $confdir/httpd.conf $confdir/commonhttpd.conf > $tmpfile 2>/dev/null`;
@@ -95,7 +120,6 @@
     }
 }
 close(FILE);
-`rm -f $tmpfile`;
 
 print "Apache user: $user, group: $group\n";
 print "Userdir: $userdir\n";
@@ -109,20 +133,33 @@
     $errorlog="$serverroot/$errorlog";
     print "$errorlog\n";
 }
-print "DocumentRoot: $documentroot\n";
-
-$_=`ls -dln $documentroot|cut -c 17-30`;
-if (/^(\d*)(\s*)(\d*)/) {
-    $uid=$1; $gid=$3;
-    print "Content uid $uid, gid $gid\n";
+$documentroot =~ s/"$//;
+$documentroot =~ s/^"//;
+print "DocumentRoot_unresolved: ($documentroot)\n";
+$documentroot_resolved = realpath($documentroot);
+if (-d $documentroot_resolved) {
+	$documentroot = $documentroot_resolved;
+	($dev,$ino,$mode,$nlink,$uid,$gid,$rdev,$size,$atime,$mtime,
+	$ctime,$blksize,$blocks) = stat $documentroot;
+
+	if ($dev != 0 && $ino != 0) {
+	} else {
+		print "Could not get UID and GID of DocumentRoot\n";
+		exit;
+	}
+} else {
+	$uid = 80;
+	$gid = 80;
 }
+print "DocumentRoot: ($documentroot)\n";
+print "Content uid $uid, gid $gid\n";
 
 #
 # Check the user for sanity
 # Should be 48 for Mandrake, 80 for BSD
 
-if ($flavor eq "FreeBSD") { $defaultid=80;
-} elsif ($flavor eq "Mandrake") { $defaultid=48;
+if ($ostype eq "FreeBSD") { $defaultid=80;
+} elsif ($ostype eq "Mandrake") { $defaultid=48;
 } else { $defaultid=99; }
 
 if ($uid < $defaultid) {
@@ -138,8 +175,8 @@
 ### Create Makefile
 $install=`which install`;
 chop $install;
-open(MTMP,"Makefile.in") or die "Can't find Makefile.tmpl\n";
-open(MAKF,"> Makefile") or die "Can't create Makefile\n";
+open(MTMP,"$worksrc/Makefile.in") or die "Can't find $worksrc/Makefile.in\n";
+open(MAKF,"> $worksrc/Makefile") or die "Can't create $worksrc/Makefile\n";
 print "Creating Makefile\n";
 while(<MTMP>) {
 $_=~ s|\$\(apxs\)|$apxs|;
@@ -158,11 +195,40 @@
 $_=~ s|\$\(fpexec_logexec\)|$errorlog|;
 $_=~ s|\$\(fpexec_userdir\)|$userdir|;
 $_=~ s|\$\(fpexec_docroot\)|$documentroot|;
-$_=~ s|"\$\(fpexec_bin\)|\\\\\"$sbindir\/fpexec\\\\|;
-$_=~ s|"\$\(fpstatic_bin\)|\\\\\"$sbindir\/fpstatic\\\\|;
+$_=~ s|"\$\(fpexec_bin\)|\\\\\"$prefix\/sbin\/fpexec\\\\|;
+$_=~ s|"\$\(fpstatic_bin\)|\\\\\"$prefix\/sbin\/fpstatic\\\\|;
 $_=~ s|\$\(httpdconf\)|$httpdconf|;
 $_=~ s|\$\(libexecdir\)|$libexecdir|;
-if ($flavor eq "FreeBSD") { $_=~ s|root.root|root:wheel|;}
+$_=~ s|\$\(prefix\)|$prefix|;
+if ($ostype eq "FreeBSD") { $_=~ s|root.root|root:wheel|;}
 print MAKF $_;
 }
 
+sub realpath($) {
+	my $dir = shift;
+	unless (-d $dir) {
+		if (-e $dir) {
+			$! = ENOTDIR;
+		} else {
+			$! = ENOENT;
+		}
+		return;
+	}
+	my $realpath;
+	my $pipe = gensym();
+	my $pid = open($pipe, "-|");
+	defined $pid or return;
+	if ($pid) {
+		$realpath = <$pipe>;
+		if (length $realpath) {
+			return $realpath;
+		} else {
+			$! = EINVAL;
+			return;
+		}
+	} else {
+		chdir $dir or die $!;
+		print cwd();
+		exit;
+	}
+}
