--- chrome/browser/media/router/providers/wired_display/wired_display_media_route_provider.cc.orig	2019-09-09 21:55:09 UTC
+++ chrome/browser/media/router/providers/wired_display/wired_display_media_route_provider.cc
@@ -112,6 +112,12 @@ void WiredDisplayMediaRouteProvider::CreateRoute(
     bool incognito,
     CreateRouteCallback callback) {
   DCHECK(!base::Contains(presentations_, presentation_id));
+#if defined(OS_BSD)
+  std::move(callback).Run(base::nullopt, nullptr,
+		          std::string("Not implemented"),
+			  RouteRequestResult::UNKNOWN_ERROR);
+  return;
+#else
   base::Optional<Display> display = GetDisplayBySinkId(sink_id);
   if (!display) {
     std::move(callback).Run(base::nullopt, nullptr,
@@ -138,6 +144,7 @@ void WiredDisplayMediaRouteProvider::CreateRoute(
   std::move(callback).Run(route, nullptr, base::nullopt,
                           RouteRequestResult::OK);
   NotifyRouteObservers();
+#endif
 }
 
 void WiredDisplayMediaRouteProvider::JoinRoute(
