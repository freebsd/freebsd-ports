--- sgmlfmt/sgmlfmt.pl.orig	1998-09-15 23:05:47.000000000 +0200
+++ sgmlfmt/sgmlfmt.pl	2013-10-22 12:52:49.000000000 +0200
@@ -32,7 +32,7 @@
 # project.  
 
 
-require 'newgetopt.pl';
+use Getopt::Long;
 
 #
 # Where to find DTDs and related files
@@ -151,19 +151,15 @@
     open (outfile, ">$fileroot.trf");
     &sgmlparse(infile, "roff");
     while (<infile>) {
+	s,\\\(ru,_,g if /^\.GET[HP]N/;
+	s,tmac\.m,m\.tmac,g;
 	print outfile;
     }
     close(infile);
     close(outfile);
+    system("groff -z -rRef=1 -T ${driver} -t ${fileroot}.trf 2>&1 | egrep '^\\.' > ${fileroot}.qrf");
     system("groff -T ${driver} -t ${fileroot}.trf ${postproc} > ${fileroot}.${driver}");
-
-    # If foo.tmp has been created, then there are cross references
-    # in the file and we need a second pass to resolve them correctly.
-
-    if (stat("${fileroot}.tmp")) {
-        system("groff -T ${driver} -t ${fileroot}.trf ${postproc} > ${fileroot}.${driver}");
-    	unlink("${fileroot}.qrf");
-    }
+    unlink("${fileroot}.qrf");
     unlink("${fileroot}.trf");
 }
 
@@ -655,7 +651,7 @@
 
 sub main {
     # Check arguments
-    if (!&NGetOpt('d=s', 'f=s', 'links', 'i:s@', 'hdr=s', 'ftr=s', 'e=s')) {
+    if (!GetOptions('d=s', 'f=s', 'links', 'i:s@', 'hdr=s', 'ftr=s', 'e=s')) {
 	&usage;
 	exit 1;
     }
