--- w3mimg/fb/fb.c.orig	2025-03-05 08:43:34.000000000 +0100
+++ w3mimg/fb/fb.c	2025-03-06 11:05:52.577162000 +0100
@@ -1020,7 +1020,7 @@
     mmap_offset = (size_t)(video_adapter_info->va_window) & (PAGE_MASK);
     mmap_length = (size_t)(video_adapter_info->va_window_size +
 			   mmap_offset + PAGE_MASK) & (~PAGE_MASK);
-    return munmap(((u_long)buf & (~PAGE_MASK)), mmap_length);
+    return munmap((void *)((u_long)buf & (~PAGE_MASK)), mmap_length);
 #endif
 }
 
