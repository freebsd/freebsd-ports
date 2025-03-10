--- components/user_education/views/help_bubble_view.cc.orig	2025-02-19 07:43:18 UTC
+++ components/user_education/views/help_bubble_view.cc
@@ -299,7 +299,7 @@ DEFINE_CLASS_ELEMENT_IDENTIFIER_VALUE(HelpBubbleView, 
 // TODO(https://crbug.com/382611284): Temporarily handle the case when the
 // primary window is minimized by closing the help bubble. Remove this code when
 // the issue is solved at the Views framework level.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 class HelpBubbleView::PrimaryWidgetObserver : public views::WidgetObserver {
  public:
   explicit PrimaryWidgetObserver(HelpBubbleView& help_bubble)
@@ -772,7 +772,7 @@ HelpBubbleView::HelpBubbleView(
     event_relay_->Init(this);
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   primary_widget_observer_ = std::make_unique<PrimaryWidgetObserver>(*this);
 #endif
 
@@ -886,7 +886,7 @@ gfx::Rect HelpBubbleView::GetAnchorRect() const {
 void HelpBubbleView::OnBeforeBubbleWidgetInit(views::Widget::InitParams* params,
                                               views::Widget* widget) const {
   BubbleDialogDelegateView::OnBeforeBubbleWidgetInit(params, widget);
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) || BUILDFLAG(IS_BSD)
   // Help bubbles anchored to menus may be clipped to their anchors' bounds,
   // resulting in visual errors, unless they use accelerated rendering. See
   // crbug.com/1445770 for details. This also applies to bubbles anchored to
