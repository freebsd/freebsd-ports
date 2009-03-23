--- fur_utils.c.orig	2008-11-24 01:14:49.000000000 +0900
+++ fur_utils.c	2009-03-13 17:42:56.000000000 +0900
@@ -476,7 +476,6 @@
   return attrib & FILE_ATTRIBUTE_DIRECTORY?1:0;
 }
 
-extern long int timezone;
 extern int daylight;
 extern char * tzname [2];
 
