--- src/gmdns-service.c.orig	Sun Jun  6 01:14:54 2004
+++ src/gmdns-service.c	Sun Jun  6 01:15:12 2004
@@ -304,10 +304,12 @@
 gmdns_service_new (const char* name, const char* service_name, 
 		const char* protocol, const char* domain) 
 {
+	GmDNSService *service;
+
 	g_return_val_if_fail (name != NULL, NULL);
 	g_return_val_if_fail (service_name != NULL, NULL);
 
-	GmDNSService *service = 
+	service = 
 		(GmDNSService*) g_object_new (GMDNS_TYPE_SERVICE, NULL);
 
 	if (protocol == NULL) {
