--- ../../src/os/darwin/darwin_sigar.c
+++ ../../src/os/darwin/darwin_sigar.c
@@ -23,7 +23,9 @@
 
 #include <sys/param.h>
 #include <sys/mount.h>
+#if !(defined(__FreeBSD__) && (__FreeBSD_version >= 800000))
 #include <nfs/rpcv2.h>
+#endif
 #include <nfs/nfsproto.h>
 
 #ifdef DARWIN
@@ -3146,7 +3148,7 @@
     return SIGAR_OK;
 }
 
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) && /*XXX*/ (__FreeBSD_version < 800000)
 
 #define _KERNEL
 #include <sys/file.h>
