--- components/autofill/core/common/autofill_features.cc.orig	2024-07-31 14:19:23 UTC
+++ components/autofill/core/common/autofill_features.cc
@@ -661,7 +661,7 @@ BASE_FEATURE(kAutofillTextAreaChangeEvents,
 // Enabled by default for Mac and Windows platforms.
 BASE_FEATURE(kAutofillContentEditableChangeEvents,
              "AutofillContentEditableChangeEvents",
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
