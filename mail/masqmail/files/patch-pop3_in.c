--- src/pop3_in.c.old	Mon Apr  5 01:13:51 2004
+++ src/pop3_in.c	Mon Apr  5 01:15:27 2004
@@ -372,7 +372,7 @@
     DEBUG(5){
       struct sockaddr_in name;
       int len;
-      getsockname(sock, &name, &len);
+      getsockname(sock, (struct sockaddr *)(&name), &len);
       debugf("socket: name.sin_addr = %s\n", inet_ntoa(name.sin_addr));
     }
     return popb;
