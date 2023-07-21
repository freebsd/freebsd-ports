--- content/browser/service_worker/service_worker_context_wrapper.cc.orig	2023-07-21 09:49:17 UTC
+++ content/browser/service_worker/service_worker_context_wrapper.cc
@@ -1396,9 +1396,11 @@ void ServiceWorkerContextWrapper::MaybeProcessPendingW
   auto [document_url, key, callback] = std::move(*request);
 
   DCHECK(document_url.is_valid());
+#if defined(__clang__) && (__clang_major__ >= 16)
   TRACE_EVENT1("ServiceWorker",
                "ServiceWorkerContextWrapper::MaybeProcessPendingWarmUpRequest",
                "document_url", document_url.spec());
+#endif
 
   context_core_->registry()->FindRegistrationForClientUrl(
       ServiceWorkerRegistry::Purpose::kNotForNavigation,
