--- components/webapps/isolated_web_apps/reading/response_reader_factory.cc.orig	2026-10-18 13:29:39 UTC
+++ components/webapps/isolated_web_apps/reading/response_reader_factory.cc
@@ -45,6 +45,8 @@ void IsolatedWebAppResponseReaderFactory::CreateRespon
   DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
   DCHECK(!web_bundle_id.is_for_proxy_mode());
 
+  // XXX crubit
+#if 0
   auto create_reader = base::BindOnce(
       &SignedWebBundleReader::Create, web_bundle_path,
       IwaOrigin(web_bundle_id).origin().GetURL(), verify_signatures,
@@ -58,6 +60,7 @@ void IsolatedWebAppResponseReaderFactory::CreateRespon
   } else {
     std::move(create_reader).Run();
   }
+#endif
 }
 
 void IsolatedWebAppResponseReaderFactory::OnReaderCreated(
