--- mal-conduit/mal/client/unix/malsync.c.orig	Tue Sep 17 18:43:28 2002
+++ mal-conduit/mal/client/unix/malsync.c	Tue Sep 17 18:43:45 2002
@@ -1409,12 +1409,12 @@
     signal(SIGSEGV, SigHandler);
 #endif
     
-    if (!(sd = pi_socket(PI_AF_SLP, PI_SOCK_STREAM, PI_PF_PADP))) {
+    if (!(sd = pi_socket(PI_PF_SLP, PI_SOCK_STREAM, PI_PF_PADP))) {
         perror("pi_socket");
         exit(1);
     }
     
-    addr.pi_family = PI_AF_SLP;
+    addr.pi_family = PI_PF_SLP;
     strcpy(addr.pi_device, device);
     
     ret = pi_bind(sd, (struct sockaddr*)&addr, sizeof(addr));
