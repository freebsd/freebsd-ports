--- src/main.c.orig	Wed Oct  5 19:12:04 2005
+++ src/main.c	Wed Oct  5 19:17:36 2005
@@ -143,7 +143,7 @@
   char *password, *p;
   size_t passsize = 128;
   struct termios orig, new;
-  int nread;
+  char* nread;
 
   /* Turn echoing off and fail if we can't. */
   if (tcgetattr(fileno(stdin), &orig) != 0) return;
@@ -152,15 +152,15 @@
   if (tcsetattr(fileno(stdin), TCSAFLUSH, &new) != 0) return;
 
   /* Read the password. */
-  password = NULL;
+  password = (char *)malloc(passsize);
   printf("Please enter password: ");
-  nread = getline(&password, &passsize, stdin);
+  nread = fgets(password, passsize, stdin);
 
   /* Restore terminal. */
   tcsetattr(fileno(stdin), TCSAFLUSH, &orig);
   printf("\n");
 
-  if (nread == -1 || !password) return;
+  if (nread == NULL || !password) return;
 
   for (p = (char*)password; *p; p++)
     ;
