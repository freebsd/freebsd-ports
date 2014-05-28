--- libgupnp/gupnp-acl.h.orig	2014-05-04 20:49:23.000000000 +0800
+++ libgupnp/gupnp-acl.h	2014-05-28 13:01:03.041207000 +0800
@@ -50,8 +50,14 @@
 typedef struct _GUPnPAclInterface GUPnPAclInterface;
 
 /* Forward declarations to avoid recursive includes */
+#if !defined(__typedef_GUPnPDevice__)
+#define __typedef_GUPnPDevice__
 typedef struct _GUPnPDevice GUPnPDevice;
+#endif
+#if !defined(__typedef_GUPnPService__)
+#define __typedef_GUPnPService__
 typedef struct _GUPnPService GUPnPService;
+#endif
 
 struct _GUPnPAclInterface {
     GTypeInterface parent;
