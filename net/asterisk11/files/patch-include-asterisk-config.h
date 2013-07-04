--- include/asterisk/config.h.orig	2013-07-02 12:26:35.000000000 +0200
+++ include/asterisk/config.h	2013-07-02 12:29:07.000000000 +0200
@@ -481,6 +481,8 @@
  * This function frees a list of variables.
  */
 void ast_variables_destroy(struct ast_variable *var);
+static inline void ast_variables_destroy_cleanup(struct ast_variable **var)
+    { ast_variables_destroy(*var); }
 
 /*!
  * \brief Register config engine
