--- zip/unzip/extract.c.orig	2012-04-09 13:58:50.000000000 +0300
+++ zip/unzip/extract.c		2012-09-12 14:05:07.000000000 +0300
@@ -218,7 +218,7 @@
 static ZCONST char Far InvalidComprData[] = "invalid compressed data to ";
 static ZCONST char Far Inflate[] = "inflate_boinc";
 
-extern int inflate_boinc(__G__ is_defl64);
+extern int inflate_boinc(__GPRO__ int is_defl64);
 
 #ifndef SFX
    static ZCONST char Far Explode[] = "explode";
