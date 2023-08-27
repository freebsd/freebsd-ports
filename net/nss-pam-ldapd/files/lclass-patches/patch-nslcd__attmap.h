--- nslcd/attmap.h.orig	2021-11-15 20:40:49.000000000 +0100
+++ nslcd/attmap.h	2023-05-29 19:22:02.233912000 +0200
@@ -67,6 +67,7 @@
 extern const char *attmap_shadow_shadowInactive;
 extern const char *attmap_shadow_shadowExpire;
 extern const char *attmap_shadow_shadowFlag;
+extern const char *attmap_passwd_loginClass;
 
 /* return a reference to the map specific base variable */
 const char **base_get_var(enum ldap_map_selector map);
