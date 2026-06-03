--- src/libcharon/plugins/smp/smp.c.orig	2025-11-07 19:05:36 UTC
+++ src/libcharon/plugins/smp/smp.c
@@ -743,7 +743,7 @@ PLUGIN_DEFINE(smp)
  */
 PLUGIN_DEFINE(smp)
 {
-	struct sockaddr_un unix_addr = { AF_UNIX, IPSEC_PIDDIR "/charon.xml"};
+	struct sockaddr_un unix_addr;
 	private_smp_t *this;
 	mode_t old;
 
@@ -771,6 +771,11 @@ PLUGIN_DEFINE(smp)
 		free(this);
 		return NULL;
 	}
+
+	strlcpy(unix_addr.sun_path, IPSEC_PIDDIR "/charon.xml",
+	    sizeof(unix_addr.sun_path));
+	unix_addr.sun_len = sizeof(unix_addr);
+	unix_addr.sun_family = PF_LOCAL;
 
 	unlink(unix_addr.sun_path);
 	old = umask(S_IRWXO);
