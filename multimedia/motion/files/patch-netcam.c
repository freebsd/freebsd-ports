Fix netcam getaddrinfo/connect usage (Fixed upstream in be2328a)

--- netcam.c.orig	2016-10-25 01:39:24 UTC
+++ netcam.c
@@ -840,8 +840,7 @@ static void netcam_disconnect(netcam_con
  */
 static int netcam_connect(netcam_context_ptr netcam, int err_flag)
 {
-    struct sockaddr_in6 server;      /* For connect */
-    struct addrinfo *ai;           /* For getaddrinfo */
+    struct addrinfo *ai;
     int ret;
     int saveflags;
     int back_err;
@@ -851,8 +850,11 @@ static int netcam_connect(netcam_context
     fd_set fd_w;
     struct timeval selecttime;
 
+    char port[15];
+    sprintf(port,"%u",netcam->connect_port);
+
     /* Lookup the hostname given in the netcam URL. */
-    if ((ret = getaddrinfo(netcam->connect_host, NULL, NULL, &ai)) != 0) {
+    if ((ret = getaddrinfo(netcam->connect_host, port, NULL, &ai)) != 0) {
         if (!err_flag)
             MOTION_LOG(ERR, TYPE_NETCAM, NO_ERRNO, "%s: getaddrinfo() failed (%s): %s",
                        netcam->connect_host, gai_strerror(ret));
@@ -920,16 +922,6 @@ static int netcam_connect(netcam_context
                netcam->sock);
 
     /*
-     * Fill the hostname details into the 'server' structure and
-     * attempt to connect to the remote server.
-     */
-    memset(&server, 0, sizeof(server));
-    memcpy(&server, ai->ai_addr, sizeof(server));
-    server.sin6_family = ai->ai_family;
-    server.sin6_port = htons(netcam->connect_port);
-    freeaddrinfo(ai);
-
-    /*
      * We set the socket non-blocking and then use a 'select'
      * system call to control the timeout.
      */
@@ -948,9 +940,11 @@ static int netcam_connect(netcam_context
     }
 
     /* Now the connect call will return immediately. */
-    ret = connect(netcam->sock, &server, sizeof(server));
+    ret = connect(netcam->sock, ai->ai_addr, ai->ai_addrlen);
     back_err = errno;           /* Save the errno from connect */
 
+    freeaddrinfo(ai);
+
     /* If the connect failed with anything except EINPROGRESS, error. */
     if ((ret < 0) && (back_err != EINPROGRESS)) {
         if (!err_flag)
