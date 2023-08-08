--- prnt/hpcups/ModeDeltaPlus.cpp.orig	2023-06-02 08:02:35 UTC
+++ prnt/hpcups/ModeDeltaPlus.cpp
@@ -241,8 +241,8 @@ bool ModeDeltaPlus::compress (BYTE   *outmem,
                               const     uint32_t    inheight,
                               uint32_t  horz_ht_dist)
 {
-    register    BYTE     *outptr = outmem;
-    register    uint32_t    col;
+    BYTE     *outptr = outmem;
+    uint32_t    col;
     const       BYTE     *seedrow;
     uint32_t                seedrow_count = 0;
     uint32_t                location = 0;
