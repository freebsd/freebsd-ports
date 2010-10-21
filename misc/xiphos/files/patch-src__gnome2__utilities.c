--- ./src/gnome2/utilities.c.orig	2010-10-21 11:08:39.000000000 -0400
+++ ./src/gnome2/utilities.c	2010-10-21 11:10:46.000000000 -0400
@@ -1934,7 +1934,9 @@
 
 #define	IMGSRC_STRING	"<img src=\""
 #define	IMGSRC_LENGTH	10		// strlen(IMGSRC_STRING)
+#ifndef HAVE_STRCASESTR
 const char *strcasestr(const char *haystack, const char *needle);
+#endif
 
 const char *
 AnalyzeForImageSize(const char *origtext,
