--- include/cfg_param.h.orig	2014-11-21 23:04:39.814559345 +0100
+++ include/cfg_param.h	2014-11-21 23:05:10.489615374 +0100
@@ -126,7 +126,7 @@
 #define ALIAS_TABLE 2
 
 #ifndef CI_BUILD_LIB
-extern struct ci_server_conf CONF;
+extern struct ci_server_conf CI_CONF;
 
 struct cfg_default_value * cfg_default_value_store(void *param, void *value,int size);
 struct cfg_default_value * cfg_default_value_replace(void *param, void *value);
