--- chrome/browser/browser_features.cc.orig	2023-12-10 06:10:27 UTC
+++ chrome/browser/browser_features.cc
@@ -28,7 +28,7 @@ BASE_FEATURE(kClosedTabCache,
 BASE_FEATURE(kDestroyProfileOnBrowserClose,
              "DestroyProfileOnBrowserClose",
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS_LACROS)
+    BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -292,7 +292,7 @@ BASE_FEATURE(kOmniboxTriggerForNoStatePrefetch,
              "OmniboxTriggerForNoStatePrefetch",
              base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kPayloadTestComponent,
              "PayloadTestComponent",
              base::FEATURE_DISABLED_BY_DEFAULT);
