--- source4/libcli/ldap/ldap_client.c.orig	2026-01-20 15:42:54 UTC
+++ source4/libcli/ldap/ldap_client.c
@@ -407,8 +407,20 @@ static int ldap_parse_basic_url(
 		*pport = port;
 		return 0;
 	}
+#ifdef FREEBSD
+	int s0, s1; s0 = s1 = 0;
+	ret = sscanf(url, "%n%*[^:/]%n:%d", &s0, &s1, &port);
 
+	if(ret >= 0) {
+		host = calloc(sizeof(char), s1 - s0 + 1);
+		if (host == NULL) {
+			return ENOMEM;
+		}
+		ret = sscanf(url, "%[^:/]:%d", host, &port);
+	}
+#else
 	ret = sscanf(url, "%m[^:/]:%d", &host, &port);
+#endif
 	if (ret < 1) {
 		return EINVAL;
 	}
