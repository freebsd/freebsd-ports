--- fcrondyn.c.orig	Mon Feb  6 14:44:52 2006
+++ fcrondyn.c	Tue May  9 15:24:22 2006
@@ -399,17 +399,21 @@
     int fd = -1;
     struct sockaddr_un addr;
     int len = 0;
+    int sa_len;
 
     if ( (fd = socket(PF_UNIX, SOCK_STREAM, 0)) == -1 )
 	die_e("could not create socket");
 
     addr.sun_family = AF_UNIX;
-    if ( (len = strlen(fifofile)) > sizeof(addr.sun_path) )
-	die("Error : fifo file path too long (max is %d)", sizeof(addr.sun_path));
-    strncpy(addr.sun_path, fifofile, sizeof(addr.sun_path) - 1);
-    addr.sun_path[sizeof(addr.sun_path)-1] = '\0';
+    if ( (len = strlen(fifofile)) > sizeof(addr.sun_path) - 1 )
+	die("Error : fifo file path too long (max is %d)", sizeof(addr.sun_path) - 1);
+    strncpy(addr.sun_path, fifofile, sizeof(addr.sun_path));
+    sa_len = (addr.sun_path - (char *)&addr) + len;
+#if HAVE_SA_LEN
+    addr.sun_len = sa_len;
+#endif
 
-    if ( connect(fd, (struct sockaddr *) &addr, sizeof(addr.sun_family) + len) < 0 )
+    if ( connect(fd, (struct sockaddr *) &addr, sa_len) < 0 )
 	die_e("Cannot connect() to fcron (check if fcron is running)");
 
     if ( authenticate_user(fd) == ERR ) {
