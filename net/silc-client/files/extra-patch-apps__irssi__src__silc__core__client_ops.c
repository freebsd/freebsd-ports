--- ./apps/irssi/src/silc/core/client_ops.c.orig	2008-12-13 15:30:25.000000000 -0500
+++ ./apps/irssi/src/silc/core/client_ops.c	2010-08-16 08:16:57.000000000 -0400
@@ -2790,6 +2790,15 @@
   silc_free(a);
 }
 
+/* helper function to emulate server_setup_find_port */
+static SERVER_SETUP_REC *silc_server_setup_find_port(const char *address,
+						     int port) {
+  SERVER_SETUP_REC *rec;
+
+  rec = server_setup_find(address, port, NULL);
+  return (rec == NULL || rec->port != port) ? NULL : rec;
+}
+
 /* Find authentication data by hostname and port. The hostname may be IP
    address as well.*/
 
@@ -2811,7 +2820,7 @@
 
   /* Check whether we find the password for this server in our
      configuration.  If it's set, always send it server. */
-  setup = server_setup_find_port(hostname, port);
+  setup = silc_server_setup_find_port(hostname, port);
   if (setup && setup->password) {
     completion(SILC_AUTH_PASSWORD, setup->password, strlen(setup->password),
 	       context);
