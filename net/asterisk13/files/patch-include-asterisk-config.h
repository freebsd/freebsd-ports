--- include/asterisk/config.h.orig	2014-10-16 17:30:39 UTC
+++ include/asterisk/config.h
@@ -674,6 +674,8 @@ struct ast_variable *ast_variables_rever
  * This function frees a list of variables.
  */
 void ast_variables_destroy(struct ast_variable *var);
+static inline void ast_variables_destroy_cleanup(struct ast_variable **var)
+    { ast_variables_destroy(*var); }
 
 /*!
  * \brief Register config engine
