--- programs/Xserver/hw/xfree86/os-support/shared/libc_wrapper.c	Fri Feb 21 22:00:39 2003
+++ programs/Xserver/hw/xfree86/os-support/shared/libc_wrapper.c	Wed Jun  4 18:55:45 2003
@@ -481,5 +481,5 @@
     if (flags & XF86_MAP_SHARED)	f |= MAP_SHARED;
     if (flags & XF86_MAP_PRIVATE)	f |= MAP_PRIVATE;
-#ifdef __x86_64__
+#if defined(__x86_64__) && defined(linux)
     if (flags & XF86_MAP_32BIT)	        f |= MAP_32BIT;
 #endif
