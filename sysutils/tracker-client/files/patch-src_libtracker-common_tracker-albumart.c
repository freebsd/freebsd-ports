--- src/libtracker-common/tracker-albumart.c.orig	2009-08-08 17:37:48.000000000 +0000
+++ src/libtracker-common/tracker-albumart.c	2009-08-08 17:38:14.000000000 +0000
@@ -81,7 +81,8 @@
 	return retval;
 }
 
-#ifndef HAVE_STRCASESTR
+#if 0
+// #ifndef HAVE_STRCASESTR
 
 static gchar *
 strcasestr (const gchar *haystack, 
