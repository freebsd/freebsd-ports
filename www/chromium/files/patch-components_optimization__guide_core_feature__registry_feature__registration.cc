--- components/optimization_guide/core/feature_registry/feature_registration.cc.orig	2025-12-05 10:12:50 UTC
+++ components/optimization_guide/core/feature_registry/feature_registration.cc
@@ -67,7 +67,7 @@ BASE_FEATURE(kProductSpecificationsMqlsLogging,
 
 BASE_FEATURE(kFormsClassificationsMqlsLogging,
              BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) ||
-                     BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+                     BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
                  ? base::FEATURE_ENABLED_BY_DEFAULT
                  : base::FEATURE_DISABLED_BY_DEFAULT);
 
