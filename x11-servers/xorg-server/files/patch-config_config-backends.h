--- config/config-backends.h.orig	2014-12-09 22:02:34.000000000 +0100
+++ config/config-backends.h	2014-12-21 23:08:34.268311262 +0100
@@ -44,3 +44,8 @@
 int config_wscons_init(void);
 void config_wscons_fini(void);
 #endif
+
+#ifdef CONFIG_DEVD
+int config_devd_init(void);
+void config_devd_fini(void);
+#endif
