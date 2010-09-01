--- freebsd/drivers/dahdi/wctdm.c.orig	2010-09-01 22:06:31.000000000 +0700
+++ freebsd/drivers/dahdi/wctdm.c	2010-09-01 22:17:48.000000000 +0700
@@ -341,7 +341,11 @@
 static int boostringer = 0;
 static int fastringer = 0;
 static int _opermode = 0;
+#if defined(__FreeBSD__)
+static char opermode[16] = "FCC";
+#else
 static char *opermode = "FCC";
+#endif
 static int fxshonormode = 0;
 static int alawoverride = 0;
 static int fastpickup = 0;
@@ -3141,6 +3145,7 @@
 {
 	pci_unregister_driver(&wctdm_driver);
 }
+#endif /* !__FreeBSD__ */
 
 module_param(debug, int, 0600);
 module_param(fxovoltage, int, 0600);
@@ -3166,6 +3171,7 @@
 module_param(fxstxgain, int, 0600);
 module_param(fxsrxgain, int, 0600);
 
+#if !defined(__FreeBSD__)
 MODULE_DESCRIPTION("Wildcard TDM400P Driver");
 MODULE_AUTHOR("Mark Spencer <markster@digium.com>");
 MODULE_ALIAS("wcfxs");
@@ -3173,4 +3179,4 @@
 
 module_init(wctdm_init);
 module_exit(wctdm_cleanup);
-#endif /* !__FreeBSD__ */
+#endif
