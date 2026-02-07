--- nslcd/attmap.c.orig	2025-02-09 14:17:17 UTC
+++ nslcd/attmap.c
@@ -176,6 +176,7 @@ const char **attmap_get_var(enum ldap_map_selector map
     if (strcasecmp(name, "gecos") == 0)             return &attmap_passwd_gecos;
     if (strcasecmp(name, "homeDirectory") == 0)     return &attmap_passwd_homeDirectory;
     if (strcasecmp(name, "loginShell") == 0)        return &attmap_passwd_loginShell;
+    if (strcasecmp(name, "loginClass") ==0)         return &attmap_passwd_loginClass;
   }
   else if (map == LM_PROTOCOLS)
   {
@@ -230,6 +231,7 @@ const char *attmap_set_mapping(const char **var, const
         (var != &attmap_shadow_shadowWarning) &&
         (var != &attmap_shadow_shadowInactive) &&
         (var != &attmap_shadow_shadowExpire) &&
+	 (var != &attmap_passwd_loginClass) &&
         (var != &attmap_shadow_shadowFlag))
       return NULL;
     /* the member attribute may only be set to an empty string */
