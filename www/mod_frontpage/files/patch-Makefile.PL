--- Makefile.PL.orig	Tue Mar 12 22:07:07 2002
+++ Makefile.PL	Thu May 16 12:21:00 2002
@@ -9,14 +9,28 @@
 # FP extensions 5.0 from Martin Blapp <mbr@freebsd.org>
 #
 
-$flavor=`uname`;
-if (-e "/etc/mandrake-release") {$flavor="Mandrake";}
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
@@ -121,8 +135,8 @@
 # Check the user for sanity
 # Should be 48 for Mandrake, 80 for BSD
 
-if ($flavor eq "FreeBSD") { $defaultid=80;
-} elsif ($flavor eq "Mandrake") { $defaultid=48;
+if ($ostype eq "FreeBSD") { $defaultid=80;
+} elsif ($ostype eq "Mandrake") { $defaultid=48;
 } else { $defaultid=99; }
 
 if ($uid < $defaultid) {
@@ -158,11 +172,12 @@
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
 
