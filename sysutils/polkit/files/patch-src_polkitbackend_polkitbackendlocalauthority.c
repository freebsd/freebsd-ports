--- src/polkitbackend/polkitbackendlocalauthority.c.orig	2012-05-15 21:52:35.000000000 +0200
+++ src/polkitbackend/polkitbackendlocalauthority.c	2012-05-15 21:53:07.000000000 +0200
@@ -700,11 +700,7 @@
   ret = NULL;
   name = polkit_unix_netgroup_get_name (POLKIT_UNIX_NETGROUP (group));
 
-  if (setnetgrent (name) == 0)
-    {
-      g_warning ("Error looking up net group with name %s: %s", name, g_strerror (errno));
-      goto out;
-    }
+  setnetgrent (name);
 
   for (;;)
     {
@@ -737,7 +733,6 @@
 
   ret = g_list_reverse (ret);
 
- out:
   endnetgrent ();
   return ret;
 }
