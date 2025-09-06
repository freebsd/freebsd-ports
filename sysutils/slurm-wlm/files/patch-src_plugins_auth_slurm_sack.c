--- src/plugins/auth/slurm/sack.c.orig	2024-05-21 17:19:51 UTC
+++ src/plugins/auth/slurm/sack.c
@@ -278,8 +278,12 @@ extern void init_sack_conmgr(void)
 
 	/* set value of socket path */
 	mask = umask(0);
-	if ((rc = bind(fd, (const struct sockaddr *) &addr,
-		       sizeof(addr))))
+/* AF_UNIX length handling */
+	socklen_t len = SUN_LEN(&addr);
+#if defined(__FreeBSD__)
+	addr.sun_len = (uint8_t)len;
+#endif
+	if ((rc = bind(fd, (const struct sockaddr *)&addr, len)))
 		fatal("%s: [%s] Unable to bind UNIX socket: %m",
 		      __func__, addr.sun_path);
 	umask(mask);
