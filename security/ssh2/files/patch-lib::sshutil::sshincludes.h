--- lib/sshutil/sshincludes.h.orig	Wed Dec  3 14:17:18 2003
+++ lib/sshutil/sshincludes.h	Sun Jul 30 15:27:37 2006
@@ -331,7 +331,7 @@
 #define UID_ROOT 0
 #endif /* UID_ROOT */
 
-#ifdef SSHDIST_ZLIB
+#if defined(SSHDIST_ZLIB) && !defined(__FreeBSD__)
 /* Define zlib to have ssh prefix, so we will not care if there is another zlib
    in the kernel */
 #define deflateInit_            ssh_z_deflateInit_
@@ -367,7 +367,7 @@
 #define uLongf                  ssh_z_uLongf
 #define voidpf                  ssh_z_voidpf
 #define voidp                   ssh_z_voidp
-#endif /* SSHDIST_ZLIB */
+#endif /* SSHDIST_ZLIB && !__FreeBSD__ */
 
 
 
