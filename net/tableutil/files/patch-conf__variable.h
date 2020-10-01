--- conf_variable.h.orig	2005-08-01 08:39:48 UTC
+++ conf_variable.h
@@ -46,6 +46,5 @@ struct variable *variable_invert(struct variable *rhs)
 void variable_save_cidr(char *file, struct variable *rhs);
 void variable_save_range(char *file, struct variable *rhs);
 void variable_save_single(char *file, struct variable *rhs);
-variable_list_t variable_list;
 
 #endif /*_CONF_VARIABLE_H_*/
