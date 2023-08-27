--- nslcd/attmap.c.orig	2019-11-02 16:23:45.000000000 +0100
+++ nslcd/attmap.c	2023-05-29 19:22:02.233300000 +0200
@@ -176,6 +176,7 @@
     if (strcasecmp(name, "gecos") == 0)             return &attmap_passwd_gecos;
     if (strcasecmp(name, "homeDirectory") == 0)     return &attmap_passwd_homeDirectory;
     if (strcasecmp(name, "loginShell") == 0)        return &attmap_passwd_loginShell;
+    if (strcasecmp(name, "loginClass") ==0)         return &attmap_passwd_loginClass;
   }
   else if (map == LM_PROTOCOLS)
   {
@@ -230,6 +231,7 @@
         (var != &attmap_shadow_shadowWarning) &&
         (var != &attmap_shadow_shadowInactive) &&
         (var != &attmap_shadow_shadowExpire) &&
+	 (var != &attmap_passwd_loginClass) &&
         (var != &attmap_shadow_shadowFlag))
       return NULL;
     /* the member attribute may only be set to an empty string */
