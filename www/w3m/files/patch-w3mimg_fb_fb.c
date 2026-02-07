--- w3mimg/fb/fb.c.orig	2026-01-23 06:10:55 UTC
+++ w3mimg/fb/fb.c
@@ -1020,7 +1020,7 @@ fb_munmap(void *buf, video_adapter_info_t *video_adapt
     mmap_offset = (size_t)(video_adapter_info->va_window) & (PAGE_MASK);
     mmap_length = (size_t)(video_adapter_info->va_window_size +
 			   mmap_offset + PAGE_MASK) & (~PAGE_MASK);
-    return munmap(((u_long)buf & (~PAGE_MASK)), mmap_length);
+    return munmap((void *)((u_long)buf & (~PAGE_MASK)), mmap_length);
 #endif
 }
 
