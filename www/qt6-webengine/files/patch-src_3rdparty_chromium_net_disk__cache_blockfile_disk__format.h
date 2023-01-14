--- src/3rdparty/chromium/net/disk_cache/blockfile/disk_format.h.orig	2022-06-08 06:40:31 UTC
+++ src/3rdparty/chromium/net/disk_cache/blockfile/disk_format.h
@@ -149,7 +149,9 @@ struct RankingsNode {
 };
 #pragma pack(pop)
 
+#if !defined(OS_BSD)
 static_assert(sizeof(RankingsNode) == 36, "bad RankingsNode");
+#endif
 
 }  // namespace disk_cache
 
