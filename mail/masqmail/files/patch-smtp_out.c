--- src/smtp_out.c.old	Mon Apr  5 01:07:18 2004
+++ src/smtp_out.c	Mon Apr  5 01:08:18 2004
@@ -60,7 +60,7 @@
   struct hostent *host_entry;
 
   if(do_correct){
-    getsockname(psb->sock, &sname, &len);
+    getsockname(psb->sock, (struct sockaddr *)(&sname), &len);
     DEBUG(5) debugf("socket: name.sin_addr = %s\n", inet_ntoa(sname.sin_addr));
     host_entry =
       gethostbyaddr((const char *)&(sname.sin_addr),
@@ -455,7 +455,7 @@
     DEBUG(5){
       struct sockaddr_in name;
       int len = sizeof(struct sockaddr);
-      getsockname(sock, &name, &len);
+      getsockname(sock, (struct sockaddr *)(&name), &len);
       debugf("socket: name.sin_addr = %s\n", inet_ntoa(name.sin_addr));
     }
     return psb;
