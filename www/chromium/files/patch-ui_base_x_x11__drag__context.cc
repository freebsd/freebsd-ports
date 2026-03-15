--- ui/base/x/x11_drag_context.cc.orig	2026-03-13 06:02:14 UTC
+++ ui/base/x/x11_drag_context.cc
@@ -15,7 +15,7 @@
 #include "ui/gfx/x/connection.h"
 #include "ui/gfx/x/xproto.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/base/clipboard/clipboard_constants.h"
 #include "ui/base/clipboard/clipboard_util_linux.h"
 #include "ui/base/x/selection_utils.h"
@@ -150,7 +150,7 @@ void XDragContext::OnSelectionNotify(const x11::Select
     scoped_refptr<base::RefCountedMemory> data;
     x11::Atom type = x11::Atom::None;
     if (GetRawBytesOfProperty(local_window_, property, &data, &type)) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // If the source provided a portal key, retrieve the files now.
       if (target == x11::GetAtom(kMimeTypePortalFileTransfer) ||
           target == x11::GetAtom(kMimeTypePortalFiles)) {
