--- video/rtjpeg_plugin.h.orig	Thu Jun 21 23:27:05 2001
+++ video/rtjpeg_plugin.h	Mon Nov  1 09:41:06 2004
@@ -52,3 +52,6 @@
 int            rtjpeg_end_of_video();
 int            rtjpeg_check_sig(char *fname);
 
+/* Stolen from glibc */
+void *memmem(const void *haystack, size_t haystacklen,
+	     const void *needle, size_t needlelen);
