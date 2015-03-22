--- include/linux/module.h.orig	2015-03-22 00:59:45.757428000 +0600
+++ include/linux/module.h	2015-03-22 01:00:08.597762000 +0600
@@ -47,7 +47,7 @@
 #define _module_ptr_args	__CONCAT(_module_ptr_args_, __LINE__)
 #define _module_ptr_init(field, val)					\
 	static struct module_ptr_args _module_ptr_args = {		\
-		(const void **) &(THIS_MODULE->field), val		\
+		(const void **) (uintptr_t) &(THIS_MODULE->field), val	\
 	};								\
 	SYSINIT(__CONCAT(_module_ptr_args, _init),			\
 		SI_SUB_KLD, SI_ORDER_FIRST,				\
