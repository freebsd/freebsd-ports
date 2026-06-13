--- test/gtest/common/test.cc.orig	2026-05-07 20:53:46 UTC
+++ test/gtest/common/test.cc
@@ -481,14 +481,15 @@ static void clear_dontcopy_regions_vma_cb(ucs_sys_vma_
 
 static void clear_dontcopy_regions_vma_cb(ucs_sys_vma_info_t *info, void *ctx) {
     int ret;
-
     if (info->flags & UCS_SYS_VMA_FLAG_DONTCOPY) {
+#ifdef __linux__
         ret = madvise((void*)info->start, info->end - info->start, MADV_DOFORK);
         if (ret != 0) {
             UCS_TEST_MESSAGE << "madvise(DOFORK) failed, errno: " << errno
                              << std::hex << " 0x" << info->start
                              << "-0x" << info->end;
         }
+#endif
     }
 }
 
