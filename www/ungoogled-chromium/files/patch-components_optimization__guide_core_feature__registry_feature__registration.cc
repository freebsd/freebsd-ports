--- components/optimization_guide/core/feature_registry/feature_registration.cc.orig	2025-10-21 16:57:35 UTC
+++ components/optimization_guide/core/feature_registry/feature_registration.cc
@@ -75,7 +75,7 @@ BASE_FEATURE(kProductSpecificationsMqlsLogging,
 BASE_FEATURE(kFormsClassificationsMqlsLogging,
              "FormsClassificationsMqlsLogging",
              BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) ||
-                     BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+                     BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
                  ? base::FEATURE_ENABLED_BY_DEFAULT
                  : base::FEATURE_DISABLED_BY_DEFAULT);
 
