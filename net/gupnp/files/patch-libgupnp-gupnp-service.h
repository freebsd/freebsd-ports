--- libgupnp/gupnp-service.h.orig	2013-12-01 19:32:50.000000000 +0800
+++ libgupnp/gupnp-service.h	2014-05-28 13:01:03.041207000 +0800
@@ -65,7 +65,10 @@
 #define GUPNP_TYPE_SERVICE_ACTION (gupnp_service_action_get_type ())
 
 typedef struct _GUPnPServicePrivate GUPnPServicePrivate;
+#if !defined(__typedef_GUPnPService__)
+#define __typedef_GUPnPService__
 typedef struct _GUPnPService GUPnPService;
+#endif
 typedef struct _GUPnPServiceClass GUPnPServiceClass;
 
 /**
