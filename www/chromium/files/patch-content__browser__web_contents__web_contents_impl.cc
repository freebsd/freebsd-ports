--- content/browser/web_contents/web_contents_impl.cc.orig	2012-01-18 11:11:38.000000000 +0200
+++ content/browser/web_contents/web_contents_impl.cc	2012-01-29 16:23:41.000000000 +0200
@@ -2021,7 +2021,7 @@
   if (!render_view_host->CreateRenderView(string16(), max_page_id))
     return false;
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Force a ViewMsg_Resize to be sent, needed to make plugins show up on
   // linux. See crbug.com/83941.
   if (rwh_view) {
