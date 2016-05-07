--- dns.c.orig	2000-10-14 01:50:52 UTC
+++ dns.c
@@ -137,7 +137,7 @@ gethinfo(register char *hostname, regist
 	return (0);
 }
 
-/* Return the cannonical name of the host */
+/* Return the canonical name of the host (NULL if not found) */
 char *
 gethname(u_int32_t a)
 {
@@ -150,18 +150,18 @@ gethname(u_int32_t a)
 	hp = gethostbyaddr((char *)&a, sizeof(a), AF_INET);
 	_res.options = options;
 	if (hp == NULL)
-		return (intoa(a));
+		return NULL;
 	return (hp->h_name);
 }
 
-/* Return the simple name of the host */
+/* Return the simple name of the host (NULL if not found) */
 char *
 getsname(register u_int32_t a)
 {
 	register char *s, *cp;
 
 	s = gethname(a);
-	if (!isdigit((int)*s)) {
+	if (s != NULL) {
 		cp = strchr(s, '.');
 		if (cp != NULL)
 			*cp = '\0';
