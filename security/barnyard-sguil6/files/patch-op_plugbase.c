--- src/output-plugins/op_plugbase.c.orig	Sun Mar 28 18:14:19 2004
+++ src/output-plugins/op_plugbase.c	Sun Jan 15 22:33:35 2006
@@ -27,7 +27,7 @@
 #if defined(ENABLE_MYSQL) || defined(ENABLE_POSTGRES)
 #include "op_acid_db.h"
 #endif
-#ifdef ENABLE_MYSQL
+#ifdef ENABLE_TCL
 #include "op_sguil.h"
 #endif
 #include "op_alert_csv.h"
@@ -47,7 +47,7 @@
 #if defined(ENABLE_MYSQL) || defined(ENABLE_POSTGRES)
     OpAcidDb_Init();
 #endif
-#ifdef ENABLE_MYSQL
+#ifdef ENABLE_TCL
     OpSguil_Init();
 #endif
     OpAlertCSV_Init();
