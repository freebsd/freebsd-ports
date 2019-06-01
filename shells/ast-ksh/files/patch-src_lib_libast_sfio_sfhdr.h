--- src/lib/libast/sfio/sfhdr.h.orig	2016-02-28 17:09:23 UTC
+++ src/lib/libast/sfio/sfhdr.h
@@ -209,9 +209,6 @@
 
 /* see if we can use memory mapping for io */
 #if _LARGEFILE64_SOURCE && !_lib_mmap64
-#undef _mmap_worthy
-#endif
-#if !_mmap_worthy
 #undef _hdr_mman
 #undef _sys_mman
 #endif
