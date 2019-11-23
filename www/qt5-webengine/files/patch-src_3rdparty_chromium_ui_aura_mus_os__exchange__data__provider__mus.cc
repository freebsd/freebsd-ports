--- src/3rdparty/chromium/ui/aura/mus/os_exchange_data_provider_mus.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/ui/aura/mus/os_exchange_data_provider_mus.cc
@@ -14,6 +14,7 @@
 #include "base/strings/string_split.h"
 #include "base/strings/string_util.h"
 #include "base/strings/utf_string_conversions.h"
+#include "base/sys_byteorder.h"
 #include "net/base/filename_util.h"
 #include "ui/base/clipboard/clipboard_constants.h"
 #include "ui/base/clipboard/clipboard_format_type.h"
@@ -279,8 +280,13 @@ void OSExchangeDataProviderMus::SetHtml(const base::st
   std::vector<unsigned char> bytes;
   // Manually jam a UTF16 BOM into bytes because otherwise, other programs will
   // assume UTF-8.
+#if defined(ARCH_CPU_LITTLE_ENDIAN)
   bytes.push_back(0xFF);
   bytes.push_back(0xFE);
+#else
+  bytes.push_back(0xFE);
+  bytes.push_back(0xFF);
+#endif
   AddString16ToVector(html, &bytes);
   mime_data_[ui::kMimeTypeHTML] = bytes;
 }
