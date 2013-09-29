--- hw/xfree86/os-support/bsd/sparc64_video.c.orig	2008-10-02 21:01:25.000000000 +0000
+++ hw/xfree86/os-support/bsd/sparc64_video.c	2009-03-29 19:55:40.000000000 +0000
@@ -52,6 +52,10 @@
 	pVidMem->mapMem = sparc64MapVidMem;
 	pVidMem->unmapMem = sparc64UnmapVidMem;
 	pVidMem->initialised = TRUE;
+
+#if defined(__FreeBSD__)
+	pci_system_init_dev_mem(xf86Info.screenFd);
+#endif
 }
 
 static pointer
