Description: Fix a segfault when vpopmaild is not used.
Origin: upstream; http://vpopmail.svn.sourceforge.net/viewvc/vpopmail/tags/v5_4_31/client.c?r1=979&r2=984&view=patch
Last-Update: 2010-01-14

--- a/client.c
+++ b/client.c
@@ -65,13 +65,15 @@
    fd_set wfds;
    client_handle_t *handle = NULL;
 
+   timeout = CLIENT_SERVER_TIMEOUT;
+   memset(socket_file, 0, sizeof(socket_file));
+
    /*
 	  Load configuration file
    */
 
    config = config_begin("vusagec.conf");
-   if (config == NULL)
-	  fprintf(stderr, "client_connect: warning: config_begin failed\n");
+   if (config) {
 
    /*
 	  Disabled?
@@ -89,7 +91,6 @@
 	  Get timeout
    */
 
-   timeout = CLIENT_SERVER_TIMEOUT;
    str = config_fetch_by_name(config, "Server", "Timeout");
    if (str) {
 	  fl = atoi(str);
@@ -103,8 +104,6 @@
 	  Determine connection type
    */
 
-   memset(socket_file, 0, sizeof(socket_file));
-
    str = config_fetch_by_name(config, "Server", "Remote");
    if (str) {
 	  ret = ippp_parse(str, &addr);
@@ -131,6 +130,7 @@
    }
 
    config_kill(config);
+   }
 
    /*
 	  Allocate a socket
