--- utils/make-password.c.orig	Tue Sep 17 13:46:08 2002
+++ utils/make-password.c	Tue Sep 17 13:54:13 2002
@@ -34,15 +34,15 @@
   char salt[3];
 
   if (argc < 2) {
-    fprintf(stderr,"usage:%s %s\n",argv[0],TTYPrompt);
+    fprintf(stderr,"usage:%s %s\n",argv[0],"/dev/cua[<0..n>]");
     exit(2);
   }
-  if (!(sd = pi_socket(PI_AF_SLP, PI_SOCK_STREAM, PI_PF_PADP))) {
+  if (!(sd = pi_socket(PI_PF_SLP, PI_SOCK_STREAM, PI_PF_PADP))) {
     perror("pi_socket");
     exit(1);
   }
     
-  addr.pi_family = PI_AF_SLP;
+  addr.pi_family = PI_PF_SLP;
   strcpy(addr.pi_device,argv[1]);
   
   ret = pi_bind(sd, (struct sockaddr*)&addr, sizeof(addr));
