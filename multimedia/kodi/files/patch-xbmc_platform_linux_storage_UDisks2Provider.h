--- xbmc/platform/linux/storage/UDisks2Provider.h.orig	2022-07-08 10:04:52 UTC
+++ xbmc/platform/linux/storage/UDisks2Provider.h
@@ -46,7 +46,7 @@ class CUDisks2Provider : public IStorageProvider
     std::string m_label;
     std::string m_device;
     bool m_isSystem = false;
-    u_int64_t m_size = 0;
+    uint64_t m_size = 0;
 
     explicit Block(const char *object);
     ~Block() = default;
