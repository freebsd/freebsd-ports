--- lib/rc_str.c-	Mon Jul 11 11:59:42 2005
+++ lib/rc_str.c	Mon Jul 11 11:59:45 2005
@@ -63,7 +63,7 @@
 	extern struct rcf_setval *rcf_setval_head;
 	struct rcf_setval *n;
 	char *buf;
-	int buflen = 0;
+	size_t buflen = 0;
 
 	for (n = rcf_setval_head; n; n = n->next) {
 		if (strncmp(n->sym->v, str, len) == 0 && n->sym->l == len) {
@@ -81,7 +81,7 @@
 {
 	char *res;
 	char *buf;
-	int buflen = 0;
+	size_t buflen = 0;
 
 	if (rc_strzcat(&buf, &buflen, str, len))
 		return NULL;
