--- relayd/relay.c.orig	2014-08-10 20:08:47 UTC
+++ relayd/relay.c
@@ -2716,12 +2716,12 @@ relay_load_certfiles(struct relay *rlay)
 		return (-1);
 
 	if (snprintf(certfile, sizeof(certfile),
-	    "/usr/local/etc/ssl/%s:%u.crt", hbuf, useport) == -1)
+	    "%%PREFIX%%/etc/ssl/%s:%u.crt", hbuf, useport) == -1)
 		return (-1);
 	if ((rlay->rl_ssl_cert = relay_load_file(certfile,
 	    &rlay->rl_conf.ssl_cert_len)) == NULL) {
 		if (snprintf(certfile, sizeof(certfile),
-		    "/usr/local/etc/ssl/%s.crt", hbuf) == -1)
+		    "%%PREFIX%%/etc/ssl/%s.crt", hbuf) == -1)
 			return (-1);
 		if ((rlay->rl_ssl_cert = relay_load_file(certfile,
 		    &rlay->rl_conf.ssl_cert_len)) == NULL)
@@ -2732,11 +2732,11 @@ relay_load_certfiles(struct relay *rlay)
 
 	if (useport) {
 		if (snprintf(certfile, sizeof(certfile),
-		    "/usr/local/etc/ssl/private/%s:%u.key", hbuf, useport) == -1)
+		    "%%PREFIX%%/etc/ssl/private/%s:%u.key", hbuf, useport) == -1)
 			return -1;
 	} else {
 		if (snprintf(certfile, sizeof(certfile),
-		    "/usr/local/etc/ssl/private/%s.key", hbuf) == -1)
+		    "%%PREFIX%%/etc/ssl/private/%s.key", hbuf) == -1)
 			return -1;
 	}
 	if ((rlay->rl_ssl_key = ssl_load_key(env, certfile,
