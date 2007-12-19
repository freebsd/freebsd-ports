--- ClamAV.pm.orig	2007-02-20 11:42:16.000000000 -0200
+++ ClamAV.pm	2007-12-18 14:31:54.000000000 -0200
@@ -73,10 +73,6 @@
     CL_ESUPPORT
     CL_ELOCKDB
 
-    CL_ENCINIT
-    CL_ENCLOAD
-    CL_ENCIO
-
     CL_SCAN_RAW
     CL_SCAN_ARCHIVE
     CL_SCAN_MAIL
@@ -169,12 +165,9 @@
     VERSION  => $VERSION,
     PREFIX   => 'clamav_perl_',
     NAME     => "Mail::ClamAV",
-    LIBS     => "-lclamav";
-# removed on install
-BEGIN {
-require "./config.pl";
-}
-# end removed on install
+    OPTIMIZE => '-g',
+    LIBS     => " -lclamav";
+
 use Inline C => <<'END_OF_C';
 #include <stdio.h>
 #include <string.h>
@@ -496,13 +489,7 @@
     if (strEQ("CL_ESUPPORT", name)) return CL_ESUPPORT;
     if (strEQ("CL_ELOCKDB", name)) return CL_ELOCKDB;
 
-    /* NodalCore */
-    if (strEQ("CL_ENCINIT", name)) return CL_ENCINIT;
-    if (strEQ("CL_ENCLOAD", name)) return CL_ENCLOAD;
-    if (strEQ("CL_ENCIO", name)) return CL_ENCIO;
-
     /* db options */
-    if (strEQ("CL_DB_NCORE", name)) return CL_DB_NCORE;
     if (strEQ("CL_DB_PHISHING", name)) return CL_DB_PHISHING;
     if (strEQ("CL_DB_ACONLY", name)) return CL_DB_ACONLY;
     if (strEQ("CL_DB_PHISHING_URLS", name)) return CL_DB_PHISHING_URLS;
