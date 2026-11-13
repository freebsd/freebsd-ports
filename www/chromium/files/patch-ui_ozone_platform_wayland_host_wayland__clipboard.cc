--- ui/ozone/platform/wayland/host/wayland_clipboard.cc.orig	2026-11-11 14:44:17 UTC
+++ ui/ozone/platform/wayland/host/wayland_clipboard.cc
@@ -35,7 +35,7 @@
 #include "ui/ozone/platform/wayland/host/zwp_primary_selection_device_manager.h"
 #include "ui/ozone/public/platform_clipboard.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/strings/string_util.h"
 #include "ui/base/clipboard/clipboard_util_linux.h"
 #include "ui/ozone/platform/wayland/host/wayland_exchange_data_provider.h"
@@ -107,7 +107,7 @@ class ClipboardImpl final : public Clipboard, public D
 
   void ReadFileTransfer(
       ui::PlatformClipboard::RequestDataClosure callback) final {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Prefer portal types
     std::string mime_type;
     auto available_types = GetDevice()->GetAvailableMimeTypes();
@@ -186,7 +186,7 @@ class ClipboardImpl final : public Clipboard, public D
       }
     }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     if (offered_data_.contains(ui::kMimeTypeUriList)) {
       if (!offered_data_.contains(ui::kMimeTypePortalFileTransfer)) {
         mime_types.push_back(ui::kMimeTypePortalFileTransfer);
@@ -221,7 +221,7 @@ class ClipboardImpl final : public Clipboard, public D
     NotifyClipboardChanged();
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void OnPortalKeyRead(ui::PlatformClipboard::RequestDataClosure callback,
                        const ui::PlatformClipboard::Data& data) {
     if (!data) {
@@ -283,7 +283,7 @@ class ClipboardImpl final : public Clipboard, public D
       DataSource* source,
       const std::string& mime_type,
       typename DataSource::Delegate::ContentCallback callback) override {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     if (mime_type == ui::kMimeTypePortalFileTransfer ||
         mime_type == ui::kMimeTypePortalFiles) {
       auto it = offered_data_.find(ui::kMimeTypeUriList);
