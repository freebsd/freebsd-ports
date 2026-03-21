--- ui/base/x/selection_utils.cc.orig	2026-03-13 06:02:14 UTC
+++ ui/base/x/selection_utils.cc
@@ -25,7 +25,7 @@
 #include "ui/base/clipboard/clipboard_constants.h"
 #include "ui/gfx/x/atom_cache.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "components/dbus/xdg/file_transfer_portal.h"
 #endif
 
@@ -43,7 +43,7 @@ std::vector<x11::Atom> GetURLAtomsFrom() {
 }
 
 std::vector<x11::Atom> GetURIListAtomsFrom() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (dbus_xdg::FileTransferPortal::IsAvailableSync()) {
     return {x11::GetAtom(kMimeTypePortalFileTransfer),
             x11::GetAtom(kMimeTypePortalFiles), x11::GetAtom(kMimeTypeUriList)};
