--- main.c.orig	Fri May  7 13:50:04 2004
+++ main.c	Fri May  7 13:50:10 2004
@@ -1215,15 +1215,14 @@
   {
     float tmpquat[4];
     float vect[3] = {0.0, 1.0, 0.0};
-    struct utsname  un;
-    struct hostent* he;
+    char namebuf[256];
+    struct hostent* he = NULL;
     struct in_addr  in;
 
     memset(&local, 0, sizeof(site));
 
-    uname(&un);
-    strcpy(local.name, un.nodename);
-    he = gethostbyname(un.nodename);
+    if (gethostname(namebuf,256) == 0)
+      he = gethostbyname(namebuf);
     if(!he)
       { 
         printf("Error gethostbynaming local hostname");
