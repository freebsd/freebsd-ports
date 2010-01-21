Index: src/privacy.c
===================================================================
RCS file: //claws/src/privacy.c,v
retrieving revision 1.10.2.22
retrieving revision 1.10.2.23
diff -u -r1.10.2.22 -r1.10.2.23
--- src/privacy.c	23 Feb 2009 16:55:45 -0000	1.10.2.22
+++ src/privacy.c	15 Jan 2010 13:42:13 -0000	1.10.2.23
@@ -318,6 +318,8 @@
 	GSList *cur;
 	cm_return_val_if_fail(mimeinfo != NULL, FALSE);
 
+	procmime_decode_content(mimeinfo);
+
 	for(cur = systems; cur != NULL; cur = g_slist_next(cur)) {
 		PrivacySystem *system = (PrivacySystem *) cur->data;
 


