--- ../nginx-otel-3a655df/src/ngx_otel_module.cpp.orig	2024-12-19 17:07:23.000000000 -0500
+++ ../nginx-otel-3a655df/src/ngx_otel_module.cpp	2025-10-31 11:50:12.604868000 -0400
@@ -512,7 +512,11 @@
     try {
         BatchExporter::SpanInfo info{
             getSpanName(r), ctx->current, ctx->parent.spanId,
+#if defined freenginx
+            (toNanoSec(now->sec, now->msec) - ((ngx_current_msec - r->start_time) * 1000000)),
+#else
             toNanoSec(r->start_sec, r->start_msec),
+#endif
             toNanoSec(now->sec, now->msec)};
 
         bool ok = gExporter->add(info, [r](BatchExporter::Span& span) {
