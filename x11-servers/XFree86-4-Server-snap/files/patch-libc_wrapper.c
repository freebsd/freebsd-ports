--- programs/Xserver/hw/xfree86/os-support/shared/libc_wrapper.c.orig	Wed Sep 10 04:05:22 2003
+++ programs/Xserver/hw/xfree86/os-support/shared/libc_wrapper.c	Wed Sep 17 19:18:01 2003
@@ -484,7 +484,7 @@
     if (flags & XF86_MAP_FIXED)		f |= MAP_FIXED;
     if (flags & XF86_MAP_SHARED)	f |= MAP_SHARED;
     if (flags & XF86_MAP_PRIVATE)	f |= MAP_PRIVATE;
-#ifdef __AMD64__
+#ifdef __AMD64__ && defined(linux)
     if (flags & XF86_MAP_32BIT)	        f |= MAP_32BIT;
 #endif
     if (prot  & XF86_PROT_EXEC)		p |= PROT_EXEC;
