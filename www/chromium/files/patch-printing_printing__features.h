--- printing/printing_features.h.orig	2021-07-19 18:45:19 UTC
+++ printing/printing_features.h
@@ -39,11 +39,11 @@ COMPONENT_EXPORT(PRINTING_BASE)
 bool ShouldPrintUsingXps(bool source_is_pdf);
 #endif  // defined(OS_WIN)
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 COMPONENT_EXPORT(PRINTING_BASE)
 extern const base::Feature kEnableOopPrintDrivers;
-#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
 }  // namespace features
