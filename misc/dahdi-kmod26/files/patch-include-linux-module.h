--- include/linux/module.h.orig	2012-03-26 17:40:58 UTC
+++ include/linux/module.h
@@ -38,16 +38,22 @@ int _linux_module_modevent(struct module *mod, int typ
 	_LINUX_MODULE(name);						\
 	DEV_MODULE(name, _linux_module_modevent, THIS_MODULE)
 
+#if __FreeBSD_version >= 1400058
 #define LINUX_DRIVER_MODULE(name, busname, driver, devclass)		\
 	_LINUX_MODULE(name);						\
+	DRIVER_MODULE(name, busname, driver, _linux_module_modevent, THIS_MODULE);
+#else
+#define LINUX_DRIVER_MODULE(name, busname, driver, devclass)		\
+	_LINUX_MODULE(name);						\
 	DRIVER_MODULE(name, busname, driver, devclass, _linux_module_modevent, THIS_MODULE);
+#endif
 
 void _linux_module_ptr_sysinit(void *arg);
 
 #define _module_ptr_args	__CONCAT(_module_ptr_args_, __LINE__)
 #define _module_ptr_init(field, val)					\
 	static struct module_ptr_args _module_ptr_args = {		\
-		(const void **) &(THIS_MODULE->field), val		\
+		(const void **) (uintptr_t) &(THIS_MODULE->field), val	\
 	};								\
 	SYSINIT(__CONCAT(_module_ptr_args, _init),			\
 		SI_SUB_KLD, SI_ORDER_FIRST,				\
