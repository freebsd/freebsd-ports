--- servers/slapd/daemon.c.orig	Sat May 24 21:12:20 2003
+++ servers/slapd/daemon.c	Sun Jun 22 19:26:22 2003
@@ -858,7 +858,7 @@
 #ifdef LDAP_PF_LOCAL
 	case AF_LOCAL: {
 		char *addr = ((struct sockaddr_un *)*sal)->sun_path;
-#if 0 /* don't muck with socket perms */
+#if 1
 		if ( chmod( addr, l.sl_perms ) < 0 && crit ) {
 			int err = sock_errno();
 #ifdef NEW_LOGGING
