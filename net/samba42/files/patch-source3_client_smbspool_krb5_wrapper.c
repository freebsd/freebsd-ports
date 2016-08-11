--- source3/client/smbspool_krb5_wrapper.c.orig	2016-04-21 00:26:35.874203000 +0000
+++ source3/client/smbspool_krb5_wrapper.c	2016-04-21 00:47:23.148722000 +0000
@@ -195,7 +195,7 @@
 	 * Make sure we do not have LD_PRELOAD or other security relevant
 	 * environment variables set.
 	 */
-	clearenv();
+	environ = NULL;
 
 	CUPS_SMB_DEBUG("Setting KRB5CCNAME to '%s'", gen_cc);
 	setenv("KRB5CCNAME", gen_cc, 1);
