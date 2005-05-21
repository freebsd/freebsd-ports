--- hydra-teamspeak.c.orig	Thu Jan  6 16:39:55 2005
+++ hydra-teamspeak.c	Sat May 21 20:00:40 2005
@@ -14,11 +14,6 @@
   char *login, *pass; 
   char buf[100]; 
 
-  if (strlen(login = hydra_get_next_login()) == 0)
-    login = empty;
-  if (strlen(pass = hydra_get_next_password()) == 0)
-    pass = empty;
-
   struct team_speak {
     char header[16];
     unsigned long crc;
@@ -35,6 +30,11 @@
     char login[29];
   };
   struct team_speak teamspeak;
+
+  if (strlen(login = hydra_get_next_login()) == 0)
+    login = empty;
+  if (strlen(pass = hydra_get_next_password()) == 0)
+    pass = empty;
 
   memset(&teamspeak, 0, sizeof(struct team_speak));
 
