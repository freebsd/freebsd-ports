--- programs/Xserver/hw/xfree86/common/compiler.h.orig	Fri Jan 21 03:19:16 2005
+++ programs/Xserver/hw/xfree86/common/compiler.h	Fri Jan 21 03:20:03 2005
@@ -1068,7 +1068,7 @@
 #     define write_mem_barrier()	/* NOP */
 #    endif /* __arm32__ */
 
-#   elif (defined(Lynx) || defined(linux) || defined(__OpenBSD__) || defined(__NetBSD__)) && defined(__powerpc__)
+#   elif (defined(Lynx) || defined(linux) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__FreeBSD__)) && defined(__powerpc__)
 
 #    ifndef MAP_FAILED
 #     define MAP_FAILED ((void *)-1)
