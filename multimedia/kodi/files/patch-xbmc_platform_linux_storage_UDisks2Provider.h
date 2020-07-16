--- xbmc/platform/linux/storage/UDisks2Provider.h.orig	2020-07-16 09:15:42 UTC
+++ xbmc/platform/linux/storage/UDisks2Provider.h
@@ -40,7 +40,7 @@ class CUDisks2Provider : public IStorageProvider
     std::string m_label;
     std::string m_device;
     bool m_isSystem = false;
-    u_int64_t m_size = 0;
+    uint64_t m_size = 0;
 
     explicit Block(const char *object);
     ~Block() = default;
