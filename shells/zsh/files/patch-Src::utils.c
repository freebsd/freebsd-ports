--- Src/utils.c.orig	Tue Apr 17 10:57:15 2007
+++ Src/utils.c	Wed Jul 25 15:13:58 2007
@@ -1092,6 +1092,7 @@
 time_t lastmailcheck;
 
 /* the last time we checked the people in the WATCH variable */
+extern char *_mktemp(char *);
 
 /**/
 time_t lastwatch;
@@ -4569,11 +4570,11 @@
     int count;
 #else
     unsigned int wval;
+    size_t count;
 # if defined(HAVE_NL_LANGINFO) && defined(CODESET) && defined(HAVE_ICONV)
     iconv_t cd;
     char inbuf[4];
     size_t inbytes, outbytes;
-    size_t count;
 # endif
 #endif
 
