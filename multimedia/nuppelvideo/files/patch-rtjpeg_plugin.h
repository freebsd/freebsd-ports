--- rtjpeg_plugin.h.orig	Tue Jul  3 15:01:32 2001
+++ rtjpeg_plugin.h	Thu Oct 28 02:28:45 2004
@@ -56,3 +56,6 @@
 int            rtjpeg_end_of_video();
 int            rtjpeg_check_sig(char *fname);
 
+/* Stolen from glibc */
+void *memmem(const void *haystack, size_t haystacklen,
+	     const void *needle, size_t needlelen);
