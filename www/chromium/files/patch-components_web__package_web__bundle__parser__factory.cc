--- components/web_package/web_bundle_parser_factory.cc.orig	2026-10-18 13:29:39 UTC
+++ components/web_package/web_bundle_parser_factory.cc
@@ -72,10 +72,13 @@ void WebBundleParserFactory::GetParserForDataSource(
     mojo::PendingRemote<mojom::BundleDataSource> data_source) {
   // TODO(crbug.com/40197063): WebBundleParserFactory doesn't support
   // |base_url|. For features::kWebBundlesFromNetwork should support |base_url|.
+  // XXX crubit
+#if !BUILDFLAG(IS_BSD) 
   mojo::MakeSelfOwnedReceiver(
       std::make_unique<WebBundleParser>(std::move(data_source),
                                         base_url.value_or(GURL())),
       std::move(receiver));
+#endif
 }
 
 void WebBundleParserFactory::BindFileDataSource(
