--- src/liboping.c.orig	2014-09-28 09:21:20 UTC
+++ src/liboping.c
@@ -801,6 +801,11 @@ static ssize_t ping_sendto (pingobj_t *obj, pinghost_t
 		if (errno == ENETUNREACH)
 			return (0);
 #endif
+	/* BSDs return EHOSTDOWN on ARP/ND failure */
+#if defined(EHOSTDOWN)
+		if (errno == EHOSTDOWN)
+			return (0);
+#endif
 		ping_set_errno (obj, errno);
 	}
 
