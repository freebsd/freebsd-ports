--- src/chrome/updater/configurator.cc.orig	2026-10-18 18:43:23 UTC
+++ src/chrome/updater/configurator.cc
@@ -94,7 +94,7 @@ Configurator::Configurator(scoped_refptr
         return std::nullopt;
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
       }()) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Linux creating the NetworkFetcherFactory requires performing blocking IO
   // to load an external library. This should be done when the configurator is
   // created.
