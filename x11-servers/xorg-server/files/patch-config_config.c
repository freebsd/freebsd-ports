--- config/config.c.orig	2014-04-12 15:29:14 UTC
+++ config/config.c
@@ -64,6 +64,9 @@ config_init(void)
 #elif defined(CONFIG_WSCONS)
     if (!config_wscons_init())
         ErrorF("[config] failed to initialise wscons\n");
+#elif defined(CONFIG_DEVD)
+     if (!config_devd_init())
+         ErrorF("[config] failed to initialise devd\n");
 #endif
 }
 
@@ -82,6 +85,8 @@ config_fini(void)
     config_dbus_core_fini();
 #elif defined(CONFIG_WSCONS)
     config_wscons_fini();
+#elif defined(CONFIG_DEVD)
+     config_devd_fini();
 #endif
 }
 
