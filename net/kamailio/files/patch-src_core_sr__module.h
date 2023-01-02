--- src/core/sr_module.h.orig	(revision 43f764cae870b15a96b8ca88f1eb195d4ceb8455)
+++ src/core/sr_module.h
@@ -336,8 +336,8 @@
 extern int mod_response_cbk_no; /**< size of reponse callbacks array */
 
 int register_builtin_modules(void);
-int load_module(char* path);
-int load_modulex(char* path);
+int ksr_load_module(char* path, char* opts);
+int ksr_load_modulex(char* path, char* opts);
 ksr_cmd_export_t* find_export_record(char* name, int param_no, int flags);
 cmd_function find_export(char* name, int param_no, int flags);
 cmd_function find_mod_export(char* mod, char* name, int param_no, int flags);
