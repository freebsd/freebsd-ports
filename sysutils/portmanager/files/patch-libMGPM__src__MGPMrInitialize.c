--- ./libMGPM/src/MGPMrInitialize.c.orig	Mon Dec 12 15:32:34 2005
+++ ./libMGPM/src/MGPMrInitialize.c	Fri Dec  8 17:13:00 2006
@@ -47,7 +47,7 @@
 	 */
 	property->configConfFileName		= calloc( stringSize + 1, 1 );
 	MGmStrcpy(property->configConfFileName, ETCDIR);
-	MGmStrcat(property->configConfFileName, "/portmanager/" );
+	MGmStrcat(property->configConfFileName, "/portmanager" );
 	MGmStrcat(property->configConfFileName, CONFIGURE_CONF);
 
 	/*
