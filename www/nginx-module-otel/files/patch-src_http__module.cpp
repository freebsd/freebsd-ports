--- src/http_module.cpp.orig	2026-11-08 17:28:59 UTC
+++ src/http_module.cpp
@@ -518,7 +518,12 @@ ngx_int_t onRequestEnd(ngx_http_request_t* r)
     try {
         BatchExporter::SpanInfo info{
             getSpanName(r), ctx->current, ctx->parent.spanId,
+#if (freenginx)
+            toNanoSec(now->sec, now->msec) -
+                (uint64_t) (ngx_current_msec - r->start_time) * 1000000,
+#else
             toNanoSec(r->start_sec, r->start_msec),
+#endif
             toNanoSec(now->sec, now->msec)};
 
         bool ok = gExporter->add(info, [r](BatchExporter::Span& span) {
