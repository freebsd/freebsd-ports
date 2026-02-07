--- kpathsea.c.orig	2014-04-08 16:18:57.296160200 +0400
+++ kpathsea.c	2014-04-08 16:19:06.680160318 +0400
@@ -36,7 +36,7 @@ void copyright_findtfm(void)
 
 void version_findtfm(void)
 {
-        extern char * kpathsea_version_string;
+        extern const char * kpathsea_version_string;
         puts(kpathsea_version_string);
 }
 
