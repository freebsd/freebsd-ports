--- netrc.c	(Revision 4683)
+++ netrc.c	(Revision 4684)
@@ -314,8 +314,10 @@
 free_netrc(netrc_entry *a) {
     while(a) {
 	netrc_entry *n = a->next;
-	memset(a->password, 0x55, strlen(a->password));
-	xfree(a->password);
+	if (a->password != NULL) {
+		memset(a->password, 0x55, strlen(a->password));
+		free(a->password);
+	}
 	xfree(a->login);
 	xfree(a->host);
 	xfree(a);
