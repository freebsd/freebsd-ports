--- components/user_education/views/help_bubble_views.cc.orig	2026-08-13 16:48:13 UTC
+++ components/user_education/views/help_bubble_views.cc
@@ -127,7 +127,7 @@ bool HelpBubbleViews::ToggleFocusForAccessibility() {
 
   if (auto* const anchor = GetAnchorView()) {
     if (anchor->GetViewAccessibility().IsAccessibilityFocusable()) {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // Mac and Linux do not automatically pass activation on focus, so we have
       // to do it manually.
       anchor->GetWidget()->Activate();
@@ -143,7 +143,7 @@ bool HelpBubbleViews::ToggleFocusForAccessibility() {
       // An AccessiblePaneView can receive focus, but is not necessarily itself
       // accessibility focusable. Use the built-in functionality for focusing
       // elements of AccessiblePaneView instead.
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // Mac and Linux do not automatically pass activation on focus, so we have
       // to do it manually.
       anchor->GetWidget()->Activate();
