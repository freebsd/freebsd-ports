--- br.h.orig	2017-12-27 12:07:16 UTC
+++ br.h
@@ -10,6 +10,12 @@
 #define likely(x)       __builtin_expect((x),1)
 #define unlikely(x)     __builtin_expect((x),0)
 
+/* FreeBSD uses open/stat/lseek/off_t rather than open64/stat64/lseek64/off64_t */
+#define stat64 stat
+#define lseek64 lseek
+#define open64 open
+#define off64_t off_t
+
 class buffered_reader
 {
 private:
