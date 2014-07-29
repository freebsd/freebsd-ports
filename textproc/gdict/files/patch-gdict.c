--- gdict.c	Mon Mar 29 17:35:54 1999
+++ gdict.c~	Thu Jul 22 22:25:19 1999
@@ -13,12 +13,13 @@
  * Window resizing and cleanup by Iain (Nodatadj, EFNet) 23-Mar-1999
  */
 
+#include <sys/types.h>
 #include <gtk/gtk.h>
 #include <stdio.h>
 #include <sys/socket.h>
 #include <unistd.h>
-#include <arpa/inet.h>
 #include <netinet/in.h>
+#include <arpa/inet.h>
 #include <string.h>
 
 /* globals */
@@ -154,7 +155,7 @@
 	Sockaddr.sin_port          = htons(2627);
 	Sockaddr.sin_addr.s_addr   = inet_addr ("128.52.39.7");     
 
-	err = connect (sd, &Sockaddr, sizeof(Sockaddr));
+	err = connect (sd, (struct sockaddr *) &Sockaddr, sizeof(Sockaddr));
 
 	if (err != 0) {
 		sprintf (buffer, "Could not connect to dictionary server!");
