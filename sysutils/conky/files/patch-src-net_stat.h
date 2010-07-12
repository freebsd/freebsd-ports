--- src/net_stat.h.orig
+++ src/net_stat.h
@@ -94,7 +94,7 @@ int interface_up(struct text_object *);
 void free_if_up(struct text_object *);
 
 void free_dns_data(void);
-void update_dns_data(void);
+int update_dns_data(void);
 void parse_nameserver_arg(struct text_object *, const char *);
 void print_nameserver(struct text_object *, char *, int);
 
