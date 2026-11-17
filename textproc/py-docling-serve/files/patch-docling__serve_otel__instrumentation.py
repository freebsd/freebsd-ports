-- Import RayCollector lazily, only when Ray metrics are enabled.
-- Importing it at module level imports docling_jobkit.orchestrators.ray, which requires ray; ray is not available in the ports tree for python 3.12, so the app could not be imported at all.
--- docling_serve/otel_instrumentation.py.orig	2026-11-16 09:48:36 UTC
+++ docling_serve/otel_instrumentation.py
@@ -18,7 +18,6 @@ from redis import Redis
 from prometheus_client import REGISTRY, start_http_server
 from redis import Redis
 
-from docling_serve.ray_metrics_collector import RayCollector
 from docling_serve.rq_metrics_collector import RQCollector
 
 logger = logging.getLogger(__name__)
@@ -150,6 +149,8 @@ def setup_otel_instrumentation(
 
     # Register Ray metrics if RedisStateManager is provided
     if ray_redis_manager and enable_prometheus:
+        from docling_serve.ray_metrics_collector import RayCollector
+
         logger.info("Registering Ray metrics collector")
         REGISTRY.register(
             RayCollector(
