--- Makefile.PL.orig	Tue Mar 12 22:07:07 2002
+++ Makefile.PL	Mon Sep  9 21:28:36 2002
@@ -9,14 +9,32 @@
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
+
+$ostype=`uname`;
+chop $ostype;
+if (-e "/etc/mandrake-release") {
+    $flavor="Mandrake";
+}
 
-if ($flavor eq "FreeBSD") { $thechoice="/usr/local/sbin/httpd"; 
-} elsif ($flavor eq "Mandrake") { $thechoice="/usr/sbin/httpd"; 
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
@@ -109,20 +127,27 @@
     $errorlog="$serverroot/$errorlog";
     print "$errorlog\n";
 }
-print "DocumentRoot: $documentroot\n";
+$documentroot =~ s/"$//;
+$documentroot =~ s/^"//;
+$documentroot = realpath($documentroot);
+print "DocumentRoot: ($documentroot)\n";
 
-$_=`ls -dln $documentroot|cut -c 17-30`;
-if (/^(\d*)(\s*)(\d*)/) {
-    $uid=$1; $gid=$3;
-    print "Content uid $uid, gid $gid\n";
+($dev,$ino,$mode,$nlink,$uid,$gid,$rdev,$size,$atime,$mtime,
+$ctime,$blksize,$blocks) = stat $documentroot;
+
+if ($dev != 0 && $ino != 0) {
+	print "Content uid $uid, gid $gid\n";
+} else {
+	print "Could not get UID and GID of DocumentRoot\n";
+	exit;
 }
 
 #
 # Check the user for sanity
 # Should be 48 for Mandrake, 80 for BSD
 
-if ($flavor eq "FreeBSD") { $defaultid=80;
-} elsif ($flavor eq "Mandrake") { $defaultid=48;
+if ($ostype eq "FreeBSD") { $defaultid=80;
+} elsif ($ostype eq "Mandrake") { $defaultid=48;
 } else { $defaultid=99; }
 
 if ($uid < $defaultid) {
@@ -158,11 +183,40 @@
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
