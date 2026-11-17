--- src/chrome/browser/ui/webui/side_panel/customize_chrome/customize_chrome_page_handler.cc.orig	2026-10-18 18:43:23 UTC
+++ src/chrome/browser/ui/webui/side_panel/customize_chrome/customize_chrome_page_handler.cc
@@ -572,7 +572,7 @@ void CustomizeChromePageHandler::UpdateF
       side_panel::mojom::ManagementNoticeState::New();
   management_notice_state->can_be_shown = false;
   management_notice_state->enabled_by_policy = false;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   enterprise_util::BrowserManagementNoticeState state =
       enterprise_util::GetManagementNoticeStateForNTPFooter(profile_);
   switch (state) {
