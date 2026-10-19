--- chrome/browser/web_applications/isolated_web_apps/isolated_web_app_url_info.cc.orig	2026-10-18 13:29:39 UTC
+++ chrome/browser/web_applications/isolated_web_apps/isolated_web_app_url_info.cc
@@ -64,6 +64,8 @@ void IsolatedWebAppUrlInfo::CreateFromIsolatedWebAppSo
     const IwaSource& source,
     base::OnceCallback<void(base::expected<IsolatedWebAppUrlInfo, std::string>)>
         callback) {
+// XXX crubit
+#if 0
   std::visit(
       absl::Overload{
           [&](const IwaSourceBundle& bundle) {
@@ -86,6 +88,7 @@ void IsolatedWebAppUrlInfo::CreateFromIsolatedWebAppSo
                 IsolatedWebAppUrlInfo::CreateFromSignedWebBundleId(bundle_id));
           }},
       source.variant());
+#endif
 }
 
 IsolatedWebAppUrlInfo::IsolatedWebAppUrlInfo(const IwaOrigin& iwa_origin)
