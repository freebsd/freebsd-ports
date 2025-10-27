--- components/autofill/core/common/autofill_features.cc.orig	2025-10-21 16:57:35 UTC
+++ components/autofill/core/common/autofill_features.cc
@@ -10,7 +10,7 @@ namespace autofill::features {
 
 namespace {
 constexpr bool IS_AUTOFILL_AI_PLATFORM = BUILDFLAG(IS_CHROMEOS) ||
-                                         BUILDFLAG(IS_LINUX) ||
+                                         BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) ||
                                          BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN);
 }
 
