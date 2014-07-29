--- dict.c	Mon Mar 29 08:10:35 1999
+++ dict.c~	Thu Jul 22 22:25:16 1999
@@ -4,11 +4,12 @@
  * Thanks goes out to #linuxos also.  :)
  */
 
+#include <sys/types.h>
 #include <stdio.h>
 #include <sys/socket.h>
 #include <unistd.h>
-#include <arpa/inet.h>
 #include <netinet/in.h>
+#include <arpa/inet.h>
 #include <string.h>
 
 int main (int argc, char *argv[]) {
@@ -40,7 +41,7 @@
 	Sockaddr.sin_port		= htons(2627);
 	Sockaddr.sin_addr.s_addr	= inet_addr("128.52.39.7");
 
-	err = connect (sd, &Sockaddr, sizeof(Sockaddr) );
+	err = connect (sd, (struct sockaddr *) &Sockaddr, sizeof(Sockaddr) );
 	
 	if (err != 0) {
 		printf("Could not connect to dictionary server!\n");
