--- ./server/core.c.orig	2010-10-21 05:40:35.805621104 +0000
+++ ./server/core.c	2010-10-21 05:40:53.651624122 +0000
@@ -1624,7 +1624,7 @@
  */
 
 #ifdef WIN32
-#define USE_ICASE REG_ICASE
+#define USE_ICASE AP_REG_ICASE
 #else
 #define USE_ICASE 0
 #endif
@@ -1646,7 +1646,7 @@
     char *old_path = cmd->path;
     core_dir_config *conf;
     ap_conf_vector_t *new_dir_conf = ap_create_per_dir_config(cmd->pool);
-    regex_t *r = NULL;
+    ap_regex_t *r = NULL;
     const command_rec *thiscmd = cmd->cmd;
 
     const char *err = ap_check_cmd_context(cmd,
@@ -1675,13 +1675,13 @@
         cmd->path = ap_getword_conf(cmd->pool, &arg);
         if (!cmd->path)
             return "<Directory ~ > block must specify a path";
-        r = ap_pregcomp(cmd->pool, cmd->path, REG_EXTENDED|USE_ICASE);
+        r = ap_pregcomp(cmd->pool, cmd->path, AP_REG_EXTENDED|USE_ICASE);
         if (!r) {
             return "Regex could not be compiled";
         }
     }
     else if (thiscmd->cmd_data) { /* <DirectoryMatch> */
-        r = ap_pregcomp(cmd->pool, cmd->path, REG_EXTENDED|USE_ICASE);
+        r = ap_pregcomp(cmd->pool, cmd->path, AP_REG_EXTENDED|USE_ICASE);
         if (!r) {
             return "Regex could not be compiled";
         }
@@ -1746,7 +1746,7 @@
     int old_overrides = cmd->override;
     char *old_path = cmd->path;
     core_dir_config *conf;
-    regex_t *r = NULL;
+    ap_regex_t *r = NULL;
     const command_rec *thiscmd = cmd->cmd;
     ap_conf_vector_t *new_url_conf = ap_create_per_dir_config(cmd->pool);
     const char *err = ap_check_cmd_context(cmd,
@@ -1765,14 +1765,14 @@
     cmd->override = OR_ALL|ACCESS_CONF;
 
     if (thiscmd->cmd_data) { /* <LocationMatch> */
-        r = ap_pregcomp(cmd->pool, cmd->path, REG_EXTENDED);
+        r = ap_pregcomp(cmd->pool, cmd->path, AP_REG_EXTENDED);
         if (!r) {
             return "Regex could not be compiled";
         }
     }
     else if (!strcmp(cmd->path, "~")) {
         cmd->path = ap_getword_conf(cmd->pool, &arg);
-        r = ap_pregcomp(cmd->pool, cmd->path, REG_EXTENDED);
+        r = ap_pregcomp(cmd->pool, cmd->path, AP_REG_EXTENDED);
         if (!r) {
             return "Regex could not be compiled";
         }
@@ -1810,7 +1810,7 @@
     int old_overrides = cmd->override;
     char *old_path = cmd->path;
     core_dir_config *conf;
-    regex_t *r = NULL;
+    ap_regex_t *r = NULL;
     const command_rec *thiscmd = cmd->cmd;
     core_dir_config *c = mconfig;
     ap_conf_vector_t *new_file_conf = ap_create_per_dir_config(cmd->pool);
@@ -1833,14 +1833,14 @@
     }
 
     if (thiscmd->cmd_data) { /* <FilesMatch> */
-        r = ap_pregcomp(cmd->pool, cmd->path, REG_EXTENDED|USE_ICASE);
+        r = ap_pregcomp(cmd->pool, cmd->path, AP_REG_EXTENDED|USE_ICASE);
         if (!r) {
             return "Regex could not be compiled";
         }
     }
     else if (!strcmp(cmd->path, "~")) {
         cmd->path = ap_getword_conf(cmd->pool, &arg);
-        r = ap_pregcomp(cmd->pool, cmd->path, REG_EXTENDED|USE_ICASE);
+        r = ap_pregcomp(cmd->pool, cmd->path, AP_REG_EXTENDED|USE_ICASE);
         if (!r) {
             return "Regex could not be compiled";
         }
