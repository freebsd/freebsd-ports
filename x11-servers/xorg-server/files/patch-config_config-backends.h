--- config/config-backends.h.orig	2014-04-12 15:29:14 UTC
+++ config/config-backends.h
@@ -75,3 +75,8 @@ void config_hal_fini(void);
 int config_wscons_init(void);
 void config_wscons_fini(void);
 #endif
+
+#ifdef CONFIG_DEVD
+int config_devd_init(void);
+void config_devd_fini(void);
+#endif
