--- Makefile.PL.orig	Sun Dec  9 23:55:38 2001
+++ Makefile.PL	Sun Jan 20 17:22:36 2002
@@ -41,23 +41,23 @@
 open(FILE,"$httpdconf") or die "Can't find $httpdconf!\n";
 print "Reading httpd.conf...\n";
 while(<FILE>) {
-    if (/^User (\w*)/) {
+    if (!$user && /^User (\w*)/) {
 	$user=$1;
     }
-    if (/^Group (\w*)/) {
+    if (!$group && /^Group (\w*)/) {
 	$group=$1;
     }
-    if (/^UserDir (\w*)/) {
+    if (!$userdir && /^UserDir (\w*)/) {
 	$userdir=$1;
     }
-    if (/^ServerRoot (\S*)/) {
+    if (!$serverroot && /^ServerRoot (\S*)/) {
 	$serverroot=$1;
     }
-    if (/^ErrorLog (\S*)/) {
+    if (!$errorlog && /^ErrorLog (\S*)/) {
 	$errorlog=$1;
 	$errorlog=~ s/error_log/fpexec_log/;
     }
-    if (/^DocumentRoot (\S*)/) {
+    if (!$documentroot && /^DocumentRoot (\S*)/) {
 	$documentroot=$1;
     }
 }
@@ -82,13 +82,13 @@
 print "Content uid, gid: $uid, $gid\n";
 
 #
-# User "apache" in Mandrake has user 48, gid 48
+# User "www" in FreeBSD has user 80, gid 80 
 #
-if ($uid < 48) {
+if ($uid < 80) {
     print "UID too low! Using default value 100\n";
     $uid=100;
 }
-if ($gid < 48) {
+if ($gid < 80) {
     print "GID too low! Using default value 100\n";
     $gid=100;
 }
