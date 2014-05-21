--- libgupnp/gupnp-acl.h.orig	2014-05-04 20:49:23.000000000 +0800
+++ libgupnp/gupnp-acl.h	2014-05-09 01:00:57.105329801 +0800
@@ -50,8 +50,12 @@
 typedef struct _GUPnPAclInterface GUPnPAclInterface;
 
 /* Forward declarations to avoid recursive includes */
+#if !defined(GUPnPDevice)
 typedef struct _GUPnPDevice GUPnPDevice;
+#endif
+#if !defined(GUPnPService)
 typedef struct _GUPnPService GUPnPService;
+#endif
 
 struct _GUPnPAclInterface {
     GTypeInterface parent;
