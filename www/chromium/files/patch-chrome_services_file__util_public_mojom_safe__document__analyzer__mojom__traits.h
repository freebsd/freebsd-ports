--- chrome/services/file_util/public/mojom/safe_document_analyzer_mojom_traits.h.orig	2021-12-16 14:56:45 UTC
+++ chrome/services/file_util/public/mojom/safe_document_analyzer_mojom_traits.h
@@ -14,8 +14,8 @@
 #include "mojo/public/cpp/bindings/enum_traits.h"
 #include "mojo/public/cpp/bindings/struct_traits.h"
 
-#if !BUILDFLAG(FULL_SAFE_BROWSING) || (!defined(OS_LINUX) && !defined(OS_WIN))
-#error BUILDFLAG(FULL_SAFE_BROWSING) should be set and either OS_LINUX or OS_WIN defined.
+#if !BUILDFLAG(FULL_SAFE_BROWSING) || (!defined(OS_LINUX) && !defined(OS_WIN) && !defined(OS_BSD))
+#error BUILDFLAG(FULL_SAFE_BROWSING) should be set and either OS_LINUX, OS_BSD or OS_WIN defined.
 #endif
 
 namespace mojo {
