--- vfs/samba/lib/util.c.orig	Fri Nov 15 23:02:44 2002
+++ vfs/samba/lib/util.c	Tue Jun 15 03:15:09 2004
@@ -114,7 +114,7 @@
 char *tmpdir(void)
 {
   char *p;
-  if ((p = getenv("TMPDIR"))) {
+  if ((p = getenv("MC_TMPDIR")) || (p = getenv("TMPDIR"))) {
     return p;
   }
   return "/tmp";
@@ -1885,20 +1885,17 @@
  
   char *nis_map = (char *)lp_nis_home_map_name();
  
-  char nis_domain[NIS_MAXNAMELEN + 1];
   char buffer[NIS_MAXATTRVAL + 1];
   nis_result *result;
   nis_object *object;
   entry_obj  *entry;
  
-  strncpy(nis_domain, (char *)nis_local_directory(), NIS_MAXNAMELEN);
-  nis_domain[NIS_MAXNAMELEN] = '\0';
- 
-  DEBUG(5, ("NIS+ Domain: %s\n", nis_domain));
+  DEBUG(5, ("NIS+ Domain: %s\n", (char *)nis_local_directory()));
  
   if (strcmp(user_name, last_key))
   {
-    slprintf(buffer, sizeof(buffer)-1, "[%s=%s]%s.%s", "key", user_name, nis_map, nis_domain);
+    slprintf(buffer, sizeof(buffer)-1, "[%s=%s]%s.%s", "key", user_name, nis_map,
+	     (char *)nis_local_directory());
     DEBUG(5, ("NIS+ querystring: %s\n", buffer));
  
     if (result = nis_list(buffer, RETURN_RESULT, NULL, NULL))
