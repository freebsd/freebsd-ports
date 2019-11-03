--- src/nss/nss_oslogin.cc.orig	2019-10-23 06:43:42 UTC
+++ src/nss/nss_oslogin.cc
@@ -225,7 +225,7 @@ enum nss_status _nss_oslogin_initgroups_dyn(const char
   if (p_file == NULL)
     return NSS_STATUS_NOTFOUND;
   struct passwd *userp;
-  while ((userp = fgetpwent(p_file)) != NULL)
+  while ((userp = getpwent()) != NULL)
     if (strcmp(userp->pw_name, user) == 0)
       return NSS_STATUS_NOTFOUND;
   fclose(p_file);
