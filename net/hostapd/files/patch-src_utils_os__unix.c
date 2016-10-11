--- src/utils/os_unix.c.orig	2015-09-27 19:02:05 UTC
+++ src/utils/os_unix.c
@@ -442,6 +442,7 @@ int os_file_exists(const char *fname)
 }
 
 
+#if !defined __FreeBSD__ && !defined __DragonFly__
 int os_fdatasync(FILE *stream)
 {
 	if (!fflush(stream)) {
@@ -459,6 +460,7 @@ int os_fdatasync(FILE *stream)
 
 	return -1;
 }
+#endif
 
 
 #ifndef WPA_TRACE
