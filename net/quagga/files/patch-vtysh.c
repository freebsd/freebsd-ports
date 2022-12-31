--- vtysh/vtysh.c.orig	2018-02-20 00:24:55.000000000 +0300
+++ vtysh/vtysh.c	2022-12-31 19:56:32.203501000 +0300
@@ -246,7 +246,7 @@ vtysh_client_execute (struct vtysh_client *vclient, co
 void
 vtysh_pager_init (void)
 {
-  char *pager_defined;
+  char *pager_defined, *s;
 
   pager_defined = getenv ("VTYSH_PAGER");
 
@@ -254,6 +254,17 @@ vtysh_pager_init (void)
     vtysh_pager_name = strdup (pager_defined);
   else
     vtysh_pager_name = strdup ("more");
+
+  s = getenv("MORE");
+  if (s != NULL)
+    return;
+
+  s = strrchr(vtysh_pager_name, '/');
+  s = (s == NULL ? vtysh_pager_name : s++);
+  if (strcmp(s, "more") != 0 && strcmp(s, "less") != 0)
+    return;
+
+  putenv("MORE=-E");
 }
 
 /* Command execution over the vty interface. */
