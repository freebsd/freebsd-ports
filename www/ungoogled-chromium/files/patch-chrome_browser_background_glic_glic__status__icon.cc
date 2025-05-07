--- chrome/browser/background/glic/glic_status_icon.cc.orig	2025-05-06 12:23:00 UTC
+++ chrome/browser/background/glic/glic_status_icon.cc
@@ -86,7 +86,7 @@ GlicStatusIcon::GlicStatusIcon(GlicController* control
   if (!status_icon_) {
     return;
   }
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   //  Set a vector icon for proper themeing on Linux.
   status_icon_->SetIcon(
       GlicVectorIconManager::GetVectorIcon(IDR_GLIC_BUTTON_VECTOR_ICON));
@@ -128,7 +128,7 @@ GlicStatusIcon::~GlicStatusIcon() {
 
   context_menu_ = nullptr;
   if (status_icon_) {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
     status_icon_->RemoveObserver(this);
 #endif
     std::unique_ptr<StatusIcon> removed_icon =
@@ -234,7 +234,7 @@ void GlicStatusIcon::UpdateHotkey(const ui::Accelerato
 }
 
 void GlicStatusIcon::UpdateVisibilityOfExitInContextMenu() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (context_menu_) {
     context_menu_->SetCommandIdVisible(IDC_GLIC_STATUS_ICON_MENU_EXIT,
                                        BrowserList::GetInstance()->empty());
@@ -272,7 +272,7 @@ std::unique_ptr<StatusIconMenuModel> GlicStatusIcon::C
   menu->AddItem(
       IDC_GLIC_STATUS_ICON_MENU_REMOVE_ICON,
       l10n_util::GetStringUTF16(IDS_GLIC_STATUS_ICON_MENU_REMOVE_ICON));
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   menu->AddItem(IDC_GLIC_STATUS_ICON_MENU_EXIT,
                 l10n_util::GetStringUTF16(IDS_GLIC_STATUS_ICON_MENU_EXIT));
 #endif
