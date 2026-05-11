--- components/user_education/views/help_bubble_view.h.orig	2026-05-09 18:09:27 UTC
+++ components/user_education/views/help_bubble_view.h
@@ -173,7 +173,7 @@ class HelpBubbleView : public views::BubbleDialogDeleg
 // work around this problem by closing the bubble if the widget is minimized.
 // When the underlying issue is fixed at the framework level, this can be
 // removed.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   class PrimaryWidgetObserver;
   std::unique_ptr<PrimaryWidgetObserver> primary_widget_observer_;
 #endif
