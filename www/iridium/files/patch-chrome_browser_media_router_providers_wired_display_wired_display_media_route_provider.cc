--- chrome/browser/media/router/providers/wired_display/wired_display_media_route_provider.cc.orig	2018-07-21 15:25:50.187627000 +0200
+++ chrome/browser/media/router/providers/wired_display/wired_display_media_route_provider.cc	2018-07-21 15:28:47.631030000 +0200
@@ -111,6 +111,11 @@
     bool incognito,
     CreateRouteCallback callback) {
   DCHECK(!base::ContainsKey(presentations_, presentation_id));
+#if defined(OS_BSD) // XXX
+   std::move(callback).Run(base::nullopt, std::string("Not implemented"),
+                           RouteRequestResult::UNKNOWN_ERROR);
+   return;
+#else
   base::Optional<Display> display = GetDisplayBySinkId(sink_id);
   if (!display) {
     std::move(callback).Run(base::nullopt, std::string("Display not found"),
@@ -135,6 +140,7 @@
   presentation.receiver()->Start(presentation_id, GURL(media_source));
   std::move(callback).Run(route, base::nullopt, RouteRequestResult::OK);
   NotifyRouteObservers();
+#endif
 }
 
 void WiredDisplayMediaRouteProvider::JoinRoute(
