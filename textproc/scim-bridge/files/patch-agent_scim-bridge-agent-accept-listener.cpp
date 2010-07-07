
$FreeBSD$

--- agent/scim-bridge-agent-accept-listener.cpp.orig
+++ agent/scim-bridge-agent-accept-listener.cpp
@@ -106,12 +106,12 @@
     struct sockaddr_un socket_addr;
     memset (&socket_addr, 0, sizeof (struct sockaddr_un));
     socket_addr.sun_family = AF_UNIX;
-    strcpy (socket_addr.sun_path, socket_path);
+    strncpy (socket_addr.sun_path, socket_path, 104); /* 104 is the maximum length of sun_path in FreeBSD */
     
     const int MAX_TRIAL = 5;
     for (int i = 0; i < MAX_TRIAL; ++i) {
         scim_bridge_pdebugln (8, "Pinging for the another agent process...");
-        if (connect (socket_fd, (struct sockaddr*)&socket_addr, sizeof (socket_addr.sun_family) + strlen (socket_addr.sun_path))) {
+        if (connect (socket_fd, (struct sockaddr*)&socket_addr, SUN_LEN(&socket_addr))) {
             if (i == MAX_TRIAL - 1) {
                 scim_bridge_pdebugln (6, "It seems like there is no other agent for the old socket.");
                 break;
@@ -163,7 +163,7 @@
         return RETVAL_FAILED;
     }
     
-    if (bind (socket_fd, (struct sockaddr*)&socket_addr, strlen (socket_addr.sun_path) + sizeof (socket_addr.sun_family)) != 0) {
+    if (bind (socket_fd, (struct sockaddr*)&socket_addr, SUN_LEN(&socket_addr)) != 0) {
         scim_bridge_perrorln ("Cannot bind the socket: %s", strerror (errno));
         close (socket_fd);
         socket_fd = -1;
