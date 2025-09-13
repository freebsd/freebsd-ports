--- chrome/browser/background/glic/glic_status_icon.cc.orig	2025-09-11 13:19:19 UTC
+++ chrome/browser/background/glic/glic_status_icon.cc
@@ -93,7 +93,7 @@ GlicStatusIcon::GlicStatusIcon(GlicController* control
   if (!status_icon_) {
     return;
   }
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   //  Set a vector icon for proper themeing on Linux.
   status_icon_->SetIcon(
       GlicVectorIconManager::GetVectorIcon(IDR_GLIC_BUTTON_VECTOR_ICON));
@@ -135,7 +135,7 @@ GlicStatusIcon::~GlicStatusIcon() {
 
   context_menu_ = nullptr;
   if (status_icon_) {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
     status_icon_->RemoveObserver(this);
 #endif
     std::unique_ptr<StatusIcon> removed_icon =
@@ -243,7 +243,7 @@ void GlicStatusIcon::UpdateHotkey(const ui::Accelerato
 }
 
 void GlicStatusIcon::UpdateVisibilityOfExitInContextMenu() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (context_menu_) {
     const bool is_visible = BrowserList::GetInstance()->empty();
     const std::optional<size_t> index =
@@ -293,7 +293,7 @@ std::unique_ptr<StatusIconMenuModel> GlicStatusIcon::C
   menu->AddItem(IDC_GLIC_STATUS_ICON_MENU_SETTINGS,
                 l10n_util::GetStringUTF16(IDS_GLIC_STATUS_ICON_MENU_SETTINGS));
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   menu->AddSeparator(ui::NORMAL_SEPARATOR);
   menu->AddItem(IDC_GLIC_STATUS_ICON_MENU_EXIT,
                 l10n_util::GetStringUTF16(IDS_GLIC_STATUS_ICON_MENU_EXIT));
