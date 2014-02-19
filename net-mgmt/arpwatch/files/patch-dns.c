--- dns.c.orig	Fri Oct 13 21:50:52 2000
+++ dns.c	Tue Apr 13 17:35:07 2004
@@ -137,7 +137,7 @@
 	return (0);
 }

-/* Return the cannonical name of the host */
+/* Return the canonical name of the host (NULL if not found) */
 char *
 gethname(u_int32_t a)
 {
@@ -150,18 +150,18 @@
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
