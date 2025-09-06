--- src/slurmd/slurmstepd/req.c.orig	2024-05-21 17:19:51 UTC
+++ src/slurmd/slurmstepd/req.c
@@ -176,7 +176,11 @@ _create_socket(const char *name)
 	memset(&addr, 0, sizeof(addr));
 	addr.sun_family = AF_UNIX;
 	strlcpy(addr.sun_path, name, sizeof(addr.sun_path));
-	len = strlen(addr.sun_path)+1 + sizeof(addr.sun_family);
+/* AF_UNIX length handling */
+	len = SUN_LEN(&addr);
+#if defined(__FreeBSD__)
+	addr.sun_len = (uint8_t)len;
+#endif
 
 	/* bind the name to the descriptor */
 	if (bind(fd, (struct sockaddr *) &addr, len) < 0) {
