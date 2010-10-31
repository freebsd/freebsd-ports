--- kdc/config.c.orig	2010-10-16 15:50:27.000000000 +0200
+++ kdc/config.c	2010-10-16 15:51:28.000000000 +0200
@@ -333,6 +333,7 @@
 
     krb5_kdc_windc_init(context);
 
+#ifdef PKINIT
 #ifdef __APPLE__
     config->enable_pkinit = 1;
 
@@ -345,7 +346,7 @@
     if (config->pkinit_kdc_anchors == NULL)
 	config->pkinit_kdc_anchors = strdup("KEYCHAIN:");
 
-#endif
+#endif /* __APPLE__ */
 
     if (config->enable_pkinit) {
 	if (config->pkinit_kdc_identity == NULL)
@@ -361,6 +362,8 @@
 			       config->pkinit_kdc_revoke);
 
     }
+
+#endif /* PKINIT */
     
     return config;
 }
