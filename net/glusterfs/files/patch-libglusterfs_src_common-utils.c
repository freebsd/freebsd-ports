--- libglusterfs/src/common-utils.c.orig	2020-05-18 20:57:54 UTC
+++ libglusterfs/src/common-utils.c
@@ -3067,7 +3067,7 @@ get_mem_size()
     memsize = page_size * num_pages;
 #endif

-#if defined GF_DARWIN_HOST_OS
+#if defined GF_DARWIN_HOST_OS || defined __FreeBSD__

     size_t len = sizeof(memsize);
     int name[] = {CTL_HW, HW_PHYSMEM};
