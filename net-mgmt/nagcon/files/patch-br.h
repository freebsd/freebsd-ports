--- ./br.h.orig	Tue Mar 28 20:54:02 2006
+++ ./br.h	Tue Mar 28 20:56:02 2006
@@ -8,6 +8,12 @@
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
