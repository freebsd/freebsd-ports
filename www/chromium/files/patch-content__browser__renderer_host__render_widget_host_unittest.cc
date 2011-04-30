--- content/browser/renderer_host/render_widget_host_unittest.cc.orig	2010-12-16 02:11:57.000000000 +0100
+++ content/browser/renderer_host/render_widget_host_unittest.cc	2010-12-20 20:15:08.000000000 +0100
@@ -407,7 +407,7 @@
 
 // Tests setting custom background
 TEST_F(RenderWidgetHostTest, Background) {
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_FREEBSD)
   scoped_ptr<RenderWidgetHostView> view(
       RenderWidgetHostView::CreateViewForWidget(host_.get()));
   host_->set_view(view.get());
