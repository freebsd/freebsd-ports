--- ioping.c.orig	2013-02-02 21:00:59.000000000 +0400
+++ ioping.c	2013-07-23 15:53:52.000000000 +0400
@@ -154,11 +154,6 @@
 	return FlushFileBuffers(h) ? 0 : -1;
 }
 
-int fdatasync(int fd)
-{
-	return fsync(fd);
-}
-
 void srandom(unsigned int seed)
 {
 	srand(seed);
@@ -178,6 +173,13 @@
 
 #endif /* __MINGW32__ */
 
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__MINGW32__)
+int fdatasync(int fd)
+{
+        return fsync(fd);
+}
+#endif /* (__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__MINGW32__) */
+
 #ifndef HAVE_POSIX_MEMALIGN
 /* don't free it */
 int posix_memalign(void **memptr, size_t alignment, size_t size)
@@ -222,7 +224,7 @@
 
 void version(void)
 {
-	fprintf(stderr, "ioping %s\n", VERSION);
+	fprintf(stderr, "ioping %f\n", VERSION);
 }
 
 struct suffix {
