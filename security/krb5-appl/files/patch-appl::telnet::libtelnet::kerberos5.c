diff -ur krb5-1.2.7/src/appl/telnet/libtelnet/kerberos5.c krb5-1.2.7/src/appl/telnet/libtelnet/kerberos5.c
--- appl/telnet/libtelnet/kerberos5.c	2002-03-29 00:07:09.000000000-0500
+++ appl/telnet/libtelnet/kerberos5.c	2003-02-03 17:30:18.000000000-0500
@@ -441,6 +441,10 @@
 		 * first component of a service name especially since
 		 * the default is of length 4.
 		 */
+		if (krb5_princ_size(telnet_context,ticket->server) < 1) {
+		    (void) strcpy(errbuf, "malformed service name");
+		    goto errout;
+		}
 		if (krb5_princ_component(telnet_context,ticket->server,0)->length < 256) {
 		    char princ[256];
 		    strncpy(princ,
