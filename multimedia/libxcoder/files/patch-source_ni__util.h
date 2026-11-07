--- source/ni_util.h.orig	2026-10-17 00:01:03 UTC
+++ source/ni_util.h
@@ -416,7 +416,7 @@ uint32_t ni_round_up(uint32_t number_to_round, uint32_
     }                                                                          \
 }while(0)
 
-#if __linux__ || __APPLE__
+#if __linux__ || __APPLE__ || __FreeBSD__
 uint32_t ni_get_kernel_max_io_size(const char * p_dev);
 #endif
 
