--- src/HTInit.c.orig	Thu Jan  8 00:03:09 2004
+++ src/HTInit.c	Tue Nov  8 17:55:15 2005
@@ -149,6 +149,11 @@
  HTSetConversion("text/html", "text/plain",  HTMLToPlain,    0.5, 0.0, 0.0, 0);
  HTSetConversion("text/html", "www/present", HTMLPresent,    1.0, 0.0, 0.0, 0);
 
+ HTSetConversion("application/xhtml+xml", "www/source",  HTPlainPresent, 1.0, 0.0, 0.0, 0);
+ HTSetConversion("application/xhtml+xml", "text/x-c",    HTMLToC,        0.5, 0.0, 0.0, 0);
+ HTSetConversion("application/xhtml+xml", "text/plain",  HTMLToPlain,    0.5, 0.0, 0.0, 0);
+ HTSetConversion("application/xhtml+xml", "www/present", HTMLPresent,    1.0, 0.0, 0.0, 0);
+
  /*
   *  These should override the default types as necessary.
   */
@@ -1021,6 +1026,8 @@
     HTSetSuffix(".htmlx",	"text/html", "8bit", 1.0);
     HTSetSuffix(".htm",		"text/html", "8bit", 1.0);
     HTSetSuffix(".html",	"text/html", "8bit", 1.0);
+    HTSetSuffix(".xht",		"application/xhtml+xml", "8bit", 1.0);
+    HTSetSuffix(".xhtml",	"application/xhtml+xml", "8bit", 1.0);
 
     } else { /* LYSuffixRules */
     /*
@@ -1044,6 +1051,8 @@
      */
     HTSetSuffix(".htm",		"text/html", "8bit", 1.0);
     HTSetSuffix(".html",	"text/html", "8bit", 1.0);
+    HTSetSuffix(".xht",		"application/xhtml+xml", "8bit", 1.0);
+    HTSetSuffix(".xhtml",	"application/xhtml+xml", "8bit", 1.0);
 #endif /* BUILTIN_SUFFIX_MAPS */
 
 
