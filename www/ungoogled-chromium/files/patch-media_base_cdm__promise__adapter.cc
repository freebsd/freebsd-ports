--- media/base/cdm_promise_adapter.cc.orig	2023-06-05 19:39:05 UTC
+++ media/base/cdm_promise_adapter.cc
@@ -95,9 +95,11 @@ void CdmPromiseAdapter::Clear(ClearReason reason) {
   // Reject all outstanding promises.
   DCHECK(thread_checker_.CalledOnValidThread());
   for (auto& [promise_id, promise] : promises_) {
+#if defined(__clang__) && (__clang_major__ >= 16)
     TRACE_EVENT_NESTABLE_ASYNC_END1(
         "media", "CdmPromise", TRACE_ID_WITH_SCOPE("CdmPromise", promise_id),
         "status", "cleared");
+#endif
     promise->reject(CdmPromise::Exception::INVALID_STATE_ERROR,
                     ToSystemCode(reason), "Operation aborted.");
   }
