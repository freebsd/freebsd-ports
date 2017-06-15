--- src/libcharon/plugins/smp/smp.c.orig	2016-04-22 20:01:35 UTC
+++ src/libcharon/plugins/smp/smp.c
@@ -737,7 +737,7 @@ METHOD(plugin_t, destroy, void,
  */
 plugin_t *smp_plugin_create()
 {
-	struct sockaddr_un unix_addr = { AF_UNIX, IPSEC_PIDDIR "/charon.xml"};
+	struct sockaddr_un unix_addr;
 	private_smp_t *this;
 	mode_t old;
 
@@ -766,6 +766,11 @@ plugin_t *smp_plugin_create()
 		return NULL;
 	}
 
+	strlcpy(unix_addr.sun_path, IPSEC_PIDDIR "/charon.xml",
+	    sizeof(unix_addr.sun_path));
+	unix_addr.sun_len = sizeof(unix_addr);
+	unix_addr.sun_family = PF_LOCAL;
+
 	unlink(unix_addr.sun_path);
 	old = umask(S_IRWXO);
 	if (bind(this->socket, (struct sockaddr *)&unix_addr, sizeof(unix_addr)) < 0)
