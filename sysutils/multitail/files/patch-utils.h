--- utils.h.orig	Thu Jan 20 14:02:33 2005
+++ utils.h	Mon Jan 24 19:31:42 2005
@@ -1,3 +1,6 @@
+#if defined(__FreeBSD__)
+#define off64_t off_t
+#endif
 int myrand(int max);
 void * mymalloc(int size, char *what);
 void * myrealloc(void *oldp, int newsize, char *what);
