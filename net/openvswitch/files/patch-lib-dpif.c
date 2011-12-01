--- lib/dpif.c.orig	2011-11-02 07:36:34.000000000 +0100
+++ lib/dpif.c	2011-11-02 07:36:56.000000000 +0100
@@ -247,7 +247,11 @@
     dp_initialize();
 
     if (!type || *type == '\0') {
+#ifdef HAVE_NETLINK
         type = "system";
+#else
+        type = "netdev";
+#endif
     }
 
     registered_class = shash_find_data(&dpif_classes, type);
