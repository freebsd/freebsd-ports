--- src/brave/common/importer/chrome_importer_utils.cc.orig	2026-06-01 00:00:00 UTC
+++ src/brave/common/importer/chrome_importer_utils.cc
@@ -142,8 +142,9 @@
   }
 
   // We can import password from Whale only on macOS. Decryption fails on
-  // Windows and Linux.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+  // Windows and Linux -- and on FreeBSD, which decrypts the same way Linux
+  // does.
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (type == user_data_importer::TYPE_WHALE) {
     return false;
   }
