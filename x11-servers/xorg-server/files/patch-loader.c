--- programs/Xserver/hw/xfree86/loader/loader.c.orig	Tue Feb 22 06:58:18 2005
+++ programs/Xserver/hw/xfree86/loader/loader.c	Tue Feb 22 06:59:09 2005
@@ -552,8 +552,8 @@
 	FatalError("\n_LoaderFileToMem() read() failed: %s\n",
 		   strerror(errno));
 
-# if (defined(linux) || defined(__NetBSD__) || defined(__OpenBSD__)) \
-    && defined(__powerpc__)
+# if (defined(linux) || defined(__NetBSD__) || defined(__OpenBSD__) \
+    || defined(__FreeBSD__)) && defined(__powerpc__)
     /*
      * Keep the instruction cache in sync with changes in the
      * main memory.
