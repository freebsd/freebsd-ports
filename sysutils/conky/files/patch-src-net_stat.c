--- src/net_stat.c.orig
+++ src/net_stat.c
@@ -400,7 +400,7 @@ void free_dns_data(void)
 	memset(&dns_data, 0, sizeof(dns_data));
 }
 
-void update_dns_data(void)
+int update_dns_data(void)
 {
 	FILE *fp;
 	char line[256];
@@ -416,7 +416,7 @@ void update_dns_data(void)
 	free_dns_data();
 
 	if ((fp = fopen("/etc/resolv.conf", "r")) == NULL)
-		return;
+		return 0;
 	while(!feof(fp)) {
 		if (fgets(line, 255, fp) == NULL) {
 			break;
@@ -429,6 +429,7 @@ void update_dns_data(void)
 		}
 	}
 	fclose(fp);
+	return 0;
 }
 
 void parse_nameserver_arg(struct text_object *obj, const char *arg)
