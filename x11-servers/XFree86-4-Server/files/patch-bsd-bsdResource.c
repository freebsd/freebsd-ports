--- programs/Xserver/hw/xfree86/os-support/bsd/bsdResource.c	Wed May 22 14:38:29 2002
+++ programs/Xserver/hw/xfree86/os-support/bsd/bsdResource.c	Wed Jun  4 19:00:15 2003
@@ -19,5 +19,5 @@
 #ifdef INCLUDE_XF86_NO_DOMAIN
 
-#if defined(__alpha__) || defined(__sparc64__)
+#if defined(__alpha__) || defined(__sparc64__) || defined(__amd64__)
 
 resPtr