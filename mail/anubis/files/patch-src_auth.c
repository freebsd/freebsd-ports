
$FreeBSD$

--- src/auth.c.orig	Wed Dec  4 22:43:34 2002
+++ src/auth.c	Sun Mar  7 15:10:48 2004
@@ -42,6 +42,66 @@
  IDENT protocol support
 ************************/
 
+#define USERNAME_C "USERID :"
+
+/* If the reply matches sscanf expression
+   
+      "%*[^:]: USERID :%*[^:]:%s"
+
+   and the length of "%s" part does not exceed size-1 bytes,
+   copies this part to USERNAME and returns 0. Otherwise,
+   returns 1 */
+
+static int
+ident_extract_username(char *reply, char *username, size_t size)
+{
+	char *p;
+
+	p = strchr (reply, ':');
+	if (!p)
+		return 1;
+	if (p[1] != ' '
+	    || strncmp (p + 2, USERNAME_C, sizeof (USERNAME_C) - 1))
+		return 1;
+	p += 2 + sizeof (USERNAME_C) - 1;
+	p = strchr (p, ':');
+	if (!p)
+		return 1;
+	p++;
+	if (strlen (p) >= size)
+		return 1;
+	strcpy(username, p);
+	return 0;
+}
+
+/* If the reply matches sscanf expression
+
+      "%*[^ ] %*[^ ] %*[^ ] %*[^ ] %*[^ ] %s"
+
+   and the length of "%s" part does not exceed size-1 bytes,
+   copies this part to USERNAME and returns 0. Otherwise,
+   returns 1 */
+
+static int
+crypt_extract_username(char *reply, char *username, size_t size)
+{
+	int i;
+	char *p = reply;
+#define skip_word(c) while (*c && (*c) != ' ') c++
+
+	/* Skip five words */
+	for (i = 0; i < 5; i++) {
+		skip_word(p);
+		if (!*p++)
+			return 1;
+	}
+	
+	if (strlen (p) >= size)
+		return 1;
+	strcpy(username, p);
+	return 0;
+}
+
 int
 auth_ident(struct sockaddr_in *addr, char *user, int size)
 {
@@ -51,7 +111,8 @@
 	int sd = 0;
 
 	if ((sd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
-		anubis_error(SOFT, _("IDENT: socket() failed: %s."), strerror(errno));
+		anubis_error(SOFT, _("IDENT: socket() failed: %s."),
+			     strerror(errno));
 		return 0;
 	}
 	memcpy(&ident, addr, sizeof(ident));
@@ -69,11 +130,7 @@
 	info(VERBOSE, _("IDENT: connected to %s:%u"),
 	inet_ntoa(ident.sin_addr), ntohs(ident.sin_port));
 
-	#ifdef HAVE_SNPRINTF
 	snprintf(buf, LINEBUFFER,
-	#else
-	sprintf(buf,
-	#endif /* HAVE_SNPRINTF */
 		"%u , %u"CRLF, ntohs(addr->sin_port), session.tunnel_port);
 
 	if (send(sd, buf, strlen(buf), 0) == -1) {
@@ -89,7 +146,8 @@
 	close_socket(sd);
 	memset(user, 0, size);
 
-	if (sscanf(buf, "%*[^:]: USERID :%*[^:]:%s", user) != 1) {
+	remcrlf (buf);
+	if (ident_extract_username(buf, user, size)) {
 		info(VERBOSE, _("IDENT: incorrect data."));
 		return 0;
 	}
@@ -105,7 +163,8 @@
 		if (rs == -1)
 			return 0;
 
-		if (sscanf(buf, "%*[^ ] %*[^ ] %*[^ ] %*[^ ] %*[^ ] %s", user) != 1) {
+		remcrlf (buf);
+		if (crypt_extract_username(buf, user, size)) {
 			info(VERBOSE, _("IDENT: incorrect data (DES deciphered)."));
 			return 0;
 		}
