--- chrome/services/file_util/public/mojom/safe_document_analyzer_mojom_traits.h.orig	2022-02-07 13:39:41 UTC
+++ chrome/services/file_util/public/mojom/safe_document_analyzer_mojom_traits.h
@@ -14,7 +14,7 @@
 #include "mojo/public/cpp/bindings/enum_traits.h"
 #include "mojo/public/cpp/bindings/struct_traits.h"
 
-#if !BUILDFLAG(FULL_SAFE_BROWSING) || (!defined(OS_LINUX) && !defined(OS_WIN))
+#if !BUILDFLAG(FULL_SAFE_BROWSING) || (!defined(OS_LINUX) && !defined(OS_WIN) && !defined(OS_BSD))
 #error BUILDFLAG(FULL_SAFE_BROWSING) should be set and either OS_LINUX or OS_WIN defined.
 #endif
 
