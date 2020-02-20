* Define required functions for devd config backend
*
--- config/config-backends.h.orig	2017-03-15 18:05:25 UTC
+++ config/config-backends.h
@@ -43,4 +43,7 @@ void config_hal_fini(void);
 #elif defined(CONFIG_WSCONS)
 int config_wscons_init(void);
 void config_wscons_fini(void);
+#elif defined(CONFIG_DEVD)
+int config_devd_init(void);
+void config_devd_fini(void);
 #endif
