--- src/tcp-portmon.c.orig
+++ src/tcp-portmon.c
@@ -139,9 +139,10 @@ int tcp_portmon_action(struct text_object *obj, char *p, int p_max_size)
 	return 0;
 }
 
-void tcp_portmon_update(void)
+int tcp_portmon_update(void)
 {
 	update_tcp_port_monitor_collection(pmc);
+	return 0;
 }
 
 int tcp_portmon_clear(void)
