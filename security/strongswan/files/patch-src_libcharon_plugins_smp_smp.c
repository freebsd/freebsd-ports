--- src/libcharon/plugins/smp/smp.c.orig	2018-10-23 17:03:28 UTC
+++ src/libcharon/plugins/smp/smp.c
@@ -740,7 +740,7 @@ METHOD(plugin_t, destroy, void,
  */
 plugin_t *smp_plugin_create()
 {
-	struct sockaddr_un unix_addr = { AF_UNIX, IPSEC_PIDDIR "/charon.xml"};
+	struct sockaddr_un unix_addr;
 	private_smp_t *this;
 	mode_t old;
 
@@ -768,6 +768,11 @@ plugin_t *smp_plugin_create()
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
