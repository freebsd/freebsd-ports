--- plugins/check_radius.c.orig	Fri Aug 22 08:22:38 2003
+++ plugins/check_radius.c	Sat Nov 27 13:25:35 2004
@@ -102,6 +102,7 @@
 	int result;
 	UINT4 client_id;
 	char *str;
+	rc_handle *rh;
 
 	setlocale (LC_ALL, "");
 	bindtextdomain (PACKAGE, LOCALEDIR);
@@ -111,31 +112,34 @@
 		usage (_("Could not parse arguments\n"));
 
 	str = strdup ("dictionary");
-	if ((config_file && rc_read_config (config_file)) ||
-			rc_read_dictionary (rc_conf_str (str)))
+	if (config_file)
+		rh = rc_read_config (config_file);
+	else
+		rh = NULL;
+	if (!rh || rc_read_dictionary (rh, rc_conf_str (rh, str)))
 		die (STATE_UNKNOWN, _("Config file error"));
 
 	service = PW_AUTHENTICATE_ONLY;
 
-	if (!(rc_avpair_add (&data.send_pairs, PW_SERVICE_TYPE, &service, 0) &&
-				rc_avpair_add (&data.send_pairs, PW_USER_NAME, username, 0) &&
-				rc_avpair_add (&data.send_pairs, PW_USER_PASSWORD, password, 0)))
+	if (!(rc_avpair_add (rh, &data.send_pairs, PW_SERVICE_TYPE, &service, -1, 0) &&
+				rc_avpair_add (rh, &data.send_pairs, PW_USER_NAME, username, -1, 0) &&
+				rc_avpair_add (rh, &data.send_pairs, PW_USER_PASSWORD, password, -1, 0)))
 		die (STATE_UNKNOWN, _("Out of Memory?"));
 
 	/* 
 	 * Fill in NAS-IP-Address 
 	 */
 
-	if ((client_id = rc_own_ipaddress ()) == 0)
+	if ((client_id = rc_own_ipaddress (rh)) == 0)
 		return (ERROR_RC);
 
-	if (rc_avpair_add (&(data.send_pairs), PW_NAS_IP_ADDRESS, &client_id, 0) ==
+	if (rc_avpair_add (rh, &(data.send_pairs), PW_NAS_IP_ADDRESS, &client_id, -1, 0) ==
 			NULL) return (ERROR_RC);
 
-	rc_buildreq (&data, PW_ACCESS_REQUEST, server, port, (int)timeout_interval,
+	rc_buildreq (rh, &data, PW_ACCESS_REQUEST, server, port, (int)timeout_interval,
 	             retries);
 
-	result = rc_send_server (&data, msg);
+	result = rc_send_server (rh, &data, msg);
 	rc_avpair_free (data.send_pairs);
 	if (data.receive_pairs)
 		rc_avpair_free (data.receive_pairs);
