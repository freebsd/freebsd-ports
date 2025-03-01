--- posix/posix.c.orig	2025-03-01 15:14:20 UTC
+++ posix/posix.c
@@ -849,12 +849,18 @@ static ptr c_get_hostname(void) {
 
 /** return Scheme string, or Scheme integer on error */
 static ptr c_get_hostname(void) {
+#ifdef __FreeBSD__
+  int len = sysconf(_SC_HOST_NAME_MAX) + 1;
+  char* buf = alloca(len);
+  if (gethostname(buf, len) != 0) {
+#else
 #ifdef HOST_NAME_MAX
   char buf[HOST_NAME_MAX + 1];
 #else
   char buf[256];
 #endif
   if (gethostname(buf, sizeof(buf)) != 0) {
+#endif
     return Sinteger(c_errno());
   }
   return schemesh_Sstring_utf8b(buf, -1);
