--- programs/Xserver/hw/xfree86/loader/elfloader.c	Fri Jan 24 09:26:35 2003
+++ programs/Xserver/hw/xfree86/loader/elfloader.c	Wed Jun  4 19:12:09 2003
@@ -74,5 +74,5 @@
 #  error    No MAP_ANON?
 # endif
-# if !defined (__x86_64__)
+# if !defined (__x86_64__) || !defined(__linux__)
 # define MMAP_FLAGS     (MAP_PRIVATE | MAP_ANON)
 # else