--- sgmlfmt/sgmlfmt.pl.orig	Tue Sep 15 21:05:47 1998
+++ sgmlfmt/sgmlfmt.pl	Tue Sep  4 15:27:32 2001
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
 
