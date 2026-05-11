--- ui/ozone/platform/x11/x11_clipboard_ozone.cc.orig	2026-05-09 18:09:27 UTC
+++ ui/ozone/platform/x11/x11_clipboard_ozone.cc
@@ -14,7 +14,7 @@
 #include "ui/base/clipboard/clipboard_constants.h"
 #include "ui/base/x/x11_clipboard_helper.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/strings/string_view_util.h"
 #include "ui/base/clipboard/clipboard_util_linux.h"
 #include "ui/gfx/x/atom_cache.h"
@@ -47,7 +47,7 @@ void X11ClipboardOzone::RequestClipboardData(
     PlatformClipboard::RequestDataClosure callback) {
   DCHECK(!callback.is_null());
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (mime_type == kMimeTypeUriList) {
     auto uri_list_atoms = helper_->GetAtomsForFormat(
         ClipboardFormatType::CustomPlatformType(kMimeTypeUriList));
@@ -78,7 +78,7 @@ void X11ClipboardOzone::RequestClipboardData(
                          std::move(callback)));
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void X11ClipboardOzone::OnPortalKeyRead(
     PlatformClipboard::RequestDataClosure callback,
     SelectionData selection_data) {
@@ -134,7 +134,7 @@ void X11ClipboardOzone::OnSelectionChanged(ClipboardBu
     clipboard_changed_callback_.Run(buffer);
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void X11ClipboardOzone::OnGetAvailableMimeTypesForPortal(
     ClipboardBuffer buffer,
     std::vector<x11::Atom> uri_list_atoms,
