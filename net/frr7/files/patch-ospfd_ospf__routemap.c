--- ospfd/ospf_routemap.c.orig	2020-11-30 11:26:58 UTC
+++ ospfd/ospf_routemap.c
@@ -445,7 +445,7 @@ static void *route_set_metric_compile(const char *arg)
 {
 	struct ospf_metric *metric;
 
-	metric = XCALLOC(MTYPE_ROUTE_MAP_COMPILED, sizeof(uint32_t));
+	metric = XCALLOC(MTYPE_ROUTE_MAP_COMPILED, sizeof(*metric));
 	metric->used = false;
 
 	if (all_digit(arg))
