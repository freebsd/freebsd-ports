--- components/user_education/views/help_bubble_view.h.orig	2025-02-19 07:43:18 UTC
+++ components/user_education/views/help_bubble_view.h
@@ -162,7 +162,7 @@ class HelpBubbleView : public views::BubbleDialogDeleg
 // work around this problem by closing the bubble if the widget is minimized.
 // When the underlying issue is fixed at the framework level, this can be
 // removed.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   class PrimaryWidgetObserver;
   std::unique_ptr<PrimaryWidgetObserver> primary_widget_observer_;
 #endif
