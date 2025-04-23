--- nslcd/attmap.h.orig	2023-06-17 15:32:13 UTC
+++ nslcd/attmap.h
@@ -67,6 +67,7 @@ extern const char *attmap_shadow_shadowFlag;
 extern const char *attmap_shadow_shadowInactive;
 extern const char *attmap_shadow_shadowExpire;
 extern const char *attmap_shadow_shadowFlag;
+extern const char *attmap_passwd_loginClass;
 
 /* return a reference to the map specific base variable */
 const char **base_get_var(enum ldap_map_selector map);
