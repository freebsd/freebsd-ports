--- content/browser/tab_contents/tab_contents.cc.orig	2011-06-24 11:30:32.000000000 +0300
+++ content/browser/tab_contents/tab_contents.cc	2011-06-26 21:18:24.774780173 +0300
@@ -1822,7 +1822,7 @@
   if (!render_view_host->CreateRenderView(string16()))
     return false;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   // Force a ViewMsg_Resize to be sent, needed to make plugins show up on
   // linux. See crbug.com/83941.
   if (RenderWidgetHost* render_widget_host = rwh_view->GetRenderWidgetHost())
