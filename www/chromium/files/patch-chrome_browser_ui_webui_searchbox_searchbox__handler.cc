--- chrome/browser/ui/webui/searchbox/searchbox_handler.cc.orig	2025-12-12 08:02:48 UTC
+++ chrome/browser/ui/webui/searchbox/searchbox_handler.cc
@@ -160,7 +160,7 @@ const char* kMacShareIconResourceName =
 #elif BUILDFLAG(IS_WIN)
 const char* kWinShareIconResourceName =
     "//resources/cr_components/searchbox/icons/win_share.svg";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const char* kLinuxShareIconResourceName =
     "//resources/cr_components/searchbox/icons/share.svg";
 #else
@@ -220,7 +220,7 @@ static void DefineChromeRefreshRealboxIcons() {
 #elif BUILDFLAG(IS_WIN)
   kWinShareIconResourceName =
       "//resources/cr_components/searchbox/icons/win_share_cr23.svg";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   kLinuxShareIconResourceName =
       "//resources/cr_components/searchbox/icons/share_cr23.svg";
 #else
@@ -314,8 +314,7 @@ void SearchboxHandler::SetupWebUIDataSource(content::W
   source->AddBoolean("enableCsbMotionTweaks", false);
 
   static constexpr webui::LocalizedString kStrings[] = {
-      {"lensSearchButtonLabel",
-       IDS_TOOLTIP_LENS_REINVOKE_VISUAL_SELECTION_A11Y_LABEL},
+      {"lensSearchButtonLabel", IDS_TOOLTIP_LENS_SEARCH},
       {"searchboxSeparator", IDS_AUTOCOMPLETE_MATCH_DESCRIPTION_SEPARATOR},
       {"removeSuggestion", IDS_OMNIBOX_REMOVE_SUGGESTION},
       {"searchBoxHint", IDS_GOOGLE_SEARCH_BOX_EMPTY_HINT_MD},
@@ -539,7 +538,7 @@ std::string SearchboxHandler::AutocompleteIconToResour
   if (icon.name == omnibox::kShareWinChromeRefreshIcon.name) {
     return kWinShareIconResourceName;
   }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (icon.name == omnibox::kShareLinuxChromeRefreshIcon.name) {
     return kLinuxShareIconResourceName;
   }
