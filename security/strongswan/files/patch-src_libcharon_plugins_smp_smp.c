--- src/libcharon/plugins/smp/smp.c.orig	2024-03-19 10:25:55 UTC
+++ src/libcharon/plugins/smp/smp.c
@@ -745,7 +745,7 @@ plugin_t *smp_plugin_create()
  */
 plugin_t *smp_plugin_create()
 {
-	struct sockaddr_un unix_addr = { AF_UNIX, IPSEC_PIDDIR "/charon.xml"};
+	struct sockaddr_un unix_addr;
 	private_smp_t *this;
 	mode_t old;
 
@@ -773,6 +773,11 @@ plugin_t *smp_plugin_create()
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
