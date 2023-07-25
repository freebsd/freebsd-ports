--- content/browser/service_worker/service_worker_context_wrapper.cc.orig	2023-07-24 14:27:53 UTC
+++ content/browser/service_worker/service_worker_context_wrapper.cc
@@ -1397,9 +1397,11 @@ void ServiceWorkerContextWrapper::MaybeProcessPendingW
   auto document_url = d_u;
 
   DCHECK(document_url.is_valid());
+#if defined(__clang__) && (__clang_major__ >= 16)
   TRACE_EVENT1("ServiceWorker",
                "ServiceWorkerContextWrapper::MaybeProcessPendingWarmUpRequest",
                "document_url", document_url.spec());
+#endif
 
   context_core_->registry()->FindRegistrationForClientUrl(
       ServiceWorkerRegistry::Purpose::kNotForNavigation,
