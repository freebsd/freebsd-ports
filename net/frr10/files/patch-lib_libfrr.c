--- lib/libfrr.c.orig	2024-09-12 07:46:05 UTC
+++ lib/libfrr.c
@@ -1463,3 +1463,11 @@ const char *frr_vers2str(uint32_t version, char *buf, 
 
 	return buf;
 }
+
+bool frr_is_daemon(void)
+{
+	if (di)
+		return true;
+
+	return false;
+}
