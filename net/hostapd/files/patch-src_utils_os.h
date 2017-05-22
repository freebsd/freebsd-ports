--- src/utils/os.h.orig	2016-09-17 20:36:13 UTC
+++ src/utils/os.h
@@ -246,12 +246,14 @@ char * os_readfile(const char *name, siz
  */
 int os_file_exists(const char *fname);
 
+#if !defined __FreeBSD__ && !defined __DragonFly__
 /**
  * os_fdatasync - Sync a file's (for a given stream) state with storage device
  * @stream: the stream to be flushed
  * Returns: 0 if the operation succeeded or -1 on failure
  */
 int os_fdatasync(FILE *stream);
+#endif
 
 /**
  * os_zalloc - Allocate and zero memory
