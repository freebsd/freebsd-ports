--- chrome/updater/configurator.cc.orig	2025-12-05 10:12:50 UTC
+++ chrome/updater/configurator.cc
@@ -90,7 +90,7 @@ Configurator::Configurator(scoped_refptr<UpdaterPrefs>
         return std::nullopt;
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
       }()) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Linux creating the NetworkFetcherFactory requires performing blocking IO
   // to load an external library. This should be done when the configurator is
   // created.
