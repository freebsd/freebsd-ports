--- src/main-ctl-unix.c.orig	2015-08-28 19:13:38 UTC
+++ src/main-ctl-unix.c
@@ -110,12 +110,15 @@ int ctl_handler_init(main_server_st * s)
 	struct sockaddr_un sa;
 	int sd, e;
 
-	if (s->config->use_occtl == 0 || s->perm_config->occtl_socket_file == NULL) {
-		mslog(s, NULL, LOG_INFO, "not using control unix socket");
-		return 0;
+       mslog(s, NULL, LOG_INFO, "using control unix socket: %s", s->perm_config->occtl_socket_file);
+
+       if (s->config->use_occtl == 0 ||
+               s->perm_config->occtl_socket_file == NULL) {
+               mslog(s, NULL, LOG_INFO, "not using control unix socket");
+	       return 0;
 	}
 
-	mslog(s, NULL, LOG_DEBUG, "initializing control unix socket: %s", s->perm_config->occtl_socket_file);
+	mslog(s, NULL, LOG_INFO, "initializing control unix socket: %s", s->perm_config->occtl_socket_file);
 	memset(&sa, 0, sizeof(sa));
 	sa.sun_family = AF_UNIX;
 	strlcpy(sa.sun_path, s->perm_config->occtl_socket_file, sizeof(sa.sun_path));
@@ -124,7 +127,7 @@ int ctl_handler_init(main_server_st * s)
 	sd = socket(AF_UNIX, SOCK_STREAM, 0);
 	if (sd == -1) {
 		e = errno;
-		mslog(s, NULL, LOG_ERR, "could not create socket '%s': %s",
+		mslog(s, NULL, LOG_INFO, "could not create socket '%s': %s",
 		      s->perm_config->occtl_socket_file, strerror(e));
 		return -1;
 	}
@@ -133,7 +136,7 @@ int ctl_handler_init(main_server_st * s)
 	ret = bind(sd, (struct sockaddr *)&sa, SUN_LEN(&sa));
 	if (ret == -1) {
 		e = errno;
-		mslog(s, NULL, LOG_ERR, "could not bind socket '%s': %s",
+		mslog(s, NULL, LOG_INFO, "could not bind socket '%s': %s",
 		      s->perm_config->occtl_socket_file, strerror(e));
 		return -1;
 	}
@@ -141,14 +144,14 @@ int ctl_handler_init(main_server_st * s)
 	ret = chown(s->perm_config->occtl_socket_file, s->perm_config->uid, s->perm_config->gid);
 	if (ret == -1) {
 		e = errno;
-		mslog(s, NULL, LOG_ERR, "could not chown socket '%s': %s",
+		mslog(s, NULL, LOG_INFO, "could not chown socket '%s': %s",
 		      s->perm_config->occtl_socket_file, strerror(e));
 	}
 
 	ret = listen(sd, 1024);
 	if (ret == -1) {
 		e = errno;
-		mslog(s, NULL, LOG_ERR, "could not listen to socket '%s': %s",
+		mslog(s, NULL, LOG_INFO, "could not listen to socket '%s': %s",
 		      s->perm_config->occtl_socket_file, strerror(e));
 		return -1;
 	}
