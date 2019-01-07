--- chrome/browser/media/router/providers/wired_display/wired_display_media_route_provider.cc.orig	2018-12-12 22:56:03.000000000 +0100
+++ chrome/browser/media/router/providers/wired_display/wired_display_media_route_provider.cc	2018-12-16 14:00:18.522246000 +0100
@@ -111,6 +111,12 @@
     bool incognito,
     CreateRouteCallback callback) {
   DCHECK(!base::ContainsKey(presentations_, presentation_id));
+#if defined(OS_BSD) // XXX
+   std::move(callback).Run(base::nullopt, nullptr,
+                           std::string("Not implemented"),
+                           RouteRequestResult::UNKNOWN_ERROR);
+   return;
+#else
   base::Optional<Display> display = GetDisplayBySinkId(sink_id);
   if (!display) {
     std::move(callback).Run(base::nullopt, nullptr,
@@ -137,6 +143,7 @@
   std::move(callback).Run(route, nullptr, base::nullopt,
                           RouteRequestResult::OK);
   NotifyRouteObservers();
+#endif
 }
 
 void WiredDisplayMediaRouteProvider::JoinRoute(
