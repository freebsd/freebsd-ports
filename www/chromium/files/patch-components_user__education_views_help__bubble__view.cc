--- components/user_education/views/help_bubble_view.cc.orig	2024-08-26 12:06:38 UTC
+++ components/user_education/views/help_bubble_view.cc
@@ -856,7 +856,7 @@ gfx::Rect HelpBubbleView::GetAnchorRect() const {
 void HelpBubbleView::OnBeforeBubbleWidgetInit(views::Widget::InitParams* params,
                                               views::Widget* widget) const {
   BubbleDialogDelegateView::OnBeforeBubbleWidgetInit(params, widget);
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Help bubbles anchored to menus may be clipped to their anchors' bounds,
   // resulting in visual errors, unless they use accelerated rendering. See
   // crbug.com/1445770 for details. This also applies to bubbles anchored to
