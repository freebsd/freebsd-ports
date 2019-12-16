--- sysdep.c.orig	2019-10-03 14:54:58 UTC
+++ sysdep.c
@@ -91,6 +91,20 @@ typedef enum {
 } search_if_en;
 #endif
 
+#ifdef TUNSIFPID
+void tun_claim(int fd)
+{
+
+	ioctl(fd, TUNSIFPID, 0);
+}
+#else
+/* Nop; no protocol for doing this */
+void tun_claim(int fd)
+{
+
+}
+#endif
+
 /* 
  * Allocate TUN/TAP device, returns opened fd. 
  * Stores dev name in the first arg(must be large enough).
