--- ipc.c.orig
+++ ipc.c
@@ -35,8 +35,7 @@
 #endif /* FD_ZERO */
 
 extern char *get_now_date_string();
-
-extern int errno;
+extern void telnet_protocol();
 
 static struct in_addr host_address;
 static struct sockaddr_in socket_address;
@@ -360,7 +359,7 @@
 /*  This function takes the three bytes from a telnet command,
  *  and implements a very limited telnet protocol.
  */
-telnet_protocol(one, two, three)
+void telnet_protocol(one, two, three)
 unsigned int one, two, three;
 {
     unsigned char reply[3];
