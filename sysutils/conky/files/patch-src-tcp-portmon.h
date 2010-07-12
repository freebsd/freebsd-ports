--- src/tcp-portmon.h.orig
+++ src/tcp-portmon.h
@@ -40,7 +40,7 @@ struct text_object;
 
 int tcp_portmon_init(struct text_object *, const char *);
 int tcp_portmon_action(struct text_object *, char *, int);
-void tcp_portmon_update(void);
+int tcp_portmon_update(void);
 int tcp_portmon_clear(void);
 int tcp_portmon_set_max_connections(int);
 void tcp_portmon_free(struct text_object *);
