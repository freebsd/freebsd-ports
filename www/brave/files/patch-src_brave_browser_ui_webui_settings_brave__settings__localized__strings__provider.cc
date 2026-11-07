--- src/brave/browser/ui/webui/settings/brave_settings_localized_strings_provider.cc.orig	2026-06-01 00:00:00 UTC
+++ src/brave/browser/ui/webui/settings/brave_settings_localized_strings_provider.cc
@@ -244,7 +244,12 @@
        IDS_SETTINGS_BRAVE_ORIGIN_ONBOARDING_RESTORE_PURCHASE},
       {"braveOriginOnboardingLearnMore",
        IDS_SETTINGS_BRAVE_ORIGIN_ONBOARDING_LEARN_MORE},
-#if BUILDFLAG(IS_LINUX)
+// brave_origin_onboarding.html guards the button that uses this string with
+// <if expr="is_linux">, and grit counts BSD as Linux -- see the is_linux case
+// in tools/grit/grit/node/base.py.  The button therefore reaches FreeBSD, and
+// leaving the string behind makes $i18n substitution fail a CHECK in
+// ui/base/template_expressions.cc and kill the renderer.
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       {"braveOriginOnboardingProceedFree",
        IDS_BRAVE_ORIGIN_STARTUP_LINUX_FREE_BUTTON},
 #endif
