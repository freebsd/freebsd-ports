--- src/drivers.h.orig	Sun May 20 10:19:01 2001
+++ src/drivers.h	Thu Nov 29 16:33:19 2001
@@ -32,6 +32,18 @@
 typedef void (*p_term_drv) (struct Devices * dev);
 
 /* driver vars */
+#ifdef USE_FREEBSD_SYSCTL
+
+
+/* functions prototypes */
+int freebsd_dev_list(const char *devname, struct Devices *list);
+int freebsd_dev_init(struct Devices *dev);
+int freebsd_dev_get(struct Devices *dev, unsigned long *ip, unsigned long *op,
+		      unsigned long *ib, unsigned long *ob);
+void freebsd_dev_term(struct Devices *dev);
+
+#endif /*USE_FREESD_SYSCTL*/
+
 #ifdef USE_SOLARIS_FPPPD
 
 #include <sys/stropts.h>
@@ -133,6 +145,9 @@
 #endif
 #ifdef USE_TESTING_DUMMY
     {"testing_dummy", testing_dummy_list, testing_dummy_init, testing_dummy_get, testing_dummy_term},
+#endif
+#ifdef USE_FREEBSD_SYSCTL
+    {"FreeBSD_sysctl", freebsd_dev_list, freebsd_dev_init, freebsd_dev_get, freebsd_dev_term},
 #endif
     {NULL, NULL, NULL, NULL, NULL}
   };
