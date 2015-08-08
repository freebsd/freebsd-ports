--- include/asterisk/config.h.orig	2015-07-24 22:20:17 UTC
+++ include/asterisk/config.h
@@ -714,6 +714,8 @@ struct ast_variable *ast_variables_rever
  * This function frees a list of variables.
  */
 void ast_variables_destroy(struct ast_variable *var);
+static inline void ast_variables_destroy_cleanup(struct ast_variable **var)
+    { ast_variables_destroy(*var); }
 
 /*!
  * \brief Register config engine
