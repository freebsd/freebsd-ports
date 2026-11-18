--- chrome/browser/ui/toolbar/cast/cast_toolbar_button_util.cc.orig	2026-11-17 21:17:00 UTC
+++ chrome/browser/ui/toolbar/cast/cast_toolbar_button_util.cc
@@ -21,7 +21,7 @@
 #include "ui/base/base_window.h"
 #include "ui/base/l10n/l10n_util.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/feedback/feedback_disabled_dialog.h"
 #endif
 
@@ -103,7 +103,7 @@ void CastToolbarButtonUtil::AddCastChildActions(
             base::BindRepeating(
                 [](BrowserWindowInterface* browser, actions::ActionItem* item,
                    actions::ActionInvocationContext context) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
                   // Cast uses its own feedback page (chrome://cast-feedback)
                   // instead of the standard feedback dialog. However, when
                   // feedback submission is disabled, chrome://cast-feedback is
