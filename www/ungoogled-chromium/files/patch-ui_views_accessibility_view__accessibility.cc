--- ui/views/accessibility/view_accessibility.cc.orig	2026-06-05 13:45:06 UTC
+++ ui/views/accessibility/view_accessibility.cc
@@ -36,7 +36,7 @@
 #include "ui/views/accessibility/view_ax_platform_node_delegate_win.h"
 #elif BUILDFLAG(IS_MAC)
 #include "ui/views/accessibility/view_ax_platform_node_delegate_mac.h"
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/views/accessibility/view_ax_platform_node_delegate_auralinux.h"
 #endif
 
@@ -106,7 +106,7 @@ std::unique_ptr<ViewAccessibility> ViewAccessibility::
   return ViewAXPlatformNodeDelegateWin::CreatePlatformSpecific(view);
 #elif BUILDFLAG(IS_MAC)
   return ViewAXPlatformNodeDelegateMac::CreatePlatformSpecific(view);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return ViewAXPlatformNodeDelegateAuraLinux::CreatePlatformSpecific(view);
 #endif
 }
