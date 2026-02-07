--- hw/xfree86/os-support/bsd/ppc_video.c.orig	2022-01-02 23:41:56.000000000 +0100
+++ hw/xfree86/os-support/bsd/ppc_video.c	2022-06-29 11:57:25.691481000 +0200
@@ -79,7 +79,11 @@ xf86DisableIO()
 {
 
     if (ioBase != MAP_FAILED) {
+#if defined(__FreeBSD__)
+        munmap(__DEVOLATILE(unsigned char *, ioBase), 0x10000);
+#else
         munmap(__UNVOLATILE(ioBase), 0x10000);
+#endif
         ioBase = MAP_FAILED;
     }
 }
