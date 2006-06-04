--- socket.c.orig	Mon Feb  6 14:44:52 2006
+++ socket.c	Tue May  9 16:33:19 2006
@@ -134,6 +134,7 @@
 {
     struct sockaddr_un addr;
     int len = 0;
+    int sa_len;
 
     /* used in fcron.c:main_loop():select() */
     FD_ZERO(&read_set);
@@ -145,15 +146,19 @@
     }
 
     addr.sun_family = AF_UNIX;
-    if ( (len = strlen(fifofile)) > sizeof(addr.sun_path) ) {
-	error("Error : fifo file path too long (max is %d)", sizeof(addr.sun_path));
+    if ( (len = strlen(fifofile)) > sizeof(addr.sun_path) - 1) {
+	error("Error : fifo file path too long (max is %d)", sizeof(addr.sun_path) - 1);
 	goto err;
     }
-    strncpy(addr.sun_path, fifofile, sizeof(addr.sun_path) - 1);
+    strncpy(addr.sun_path, fifofile, sizeof(addr.sun_path));
     addr.sun_path[sizeof(addr.sun_path) -1 ] = '\0';
+    sa_len = (addr.sun_path - (char *)&addr) + len;
+#if HAVE_SA_LEN
+    addr.sun_len = sa_len;
+#endif
 
     unlink(fifofile);
-    if (bind(listen_fd, (struct sockaddr*) &addr, sizeof(addr.sun_family)+len+1) != 0){
+    if (bind(listen_fd, (struct sockaddr*) &addr, sa_len) != 0){
 	error_e("Cannot bind socket to '%s'", fifofile);
 	goto err;
     }
