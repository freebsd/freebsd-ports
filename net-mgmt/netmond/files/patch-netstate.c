--- netstate.c.orig	Tue Aug 26 10:54:09 2003
+++ netstate.c	Thu Nov  2 13:35:27 2006
@@ -128,7 +128,7 @@
 		memset(&sin, 0, sizeof(sin));
 		sin.sin_family = AF_INET;
 		sin.sin_port = htons(cf->ns_port);
-		sin.sin_addr.s_addr = INADDR_ANY;
+		sin.sin_addr = cf->ns_ip_addr;
 		if (bind(netstate_sock, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
 			report(LOG_ERR, "bind port %d: %m", ntohs(sin.sin_port));
 			close(netstate_sock);
@@ -405,6 +405,14 @@
 	_exit(1);
 }
 #endif
+int 
+iskoi8(unsigned char ch)
+{
+    if ( ch == 163 ) return 1;
+    if ( ch == 179 ) return 1;
+    if ( ch >= 192 ) return 1;
+    return 0;    
+}
 
 void *
 netstate_serve(arg)
@@ -505,9 +513,9 @@
 			set_timer(0, interrupt);
 #endif
 		if (!cp) break;
-		while (isprint(*cp)) cp++;
+		while ( iskoi8(*cp) || isprint(*cp) ) cp++;
 		*cp = '\0';
-
+	    
 		next = input;
 		if ((cp = my_strsep(&next, " ")) == NULL) {
 			bad_input++;
