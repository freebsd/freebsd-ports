
$FreeBSD$

--- src/fstools/fs_tools.h.orig
+++ src/fstools/fs_tools.h
@@ -115,7 +115,7 @@
 #define INO_TO_CG	ino_to_cg
 #endif
 
-#if defined(FREEBSD5)
+#if defined(FREEBSD5) || defined(FREEBSD6) || defined(FREEBSD7)
 #define SUPPORTED
 #include <sys/vnode.h>
 #include <ufs/ufs/quota.h>
