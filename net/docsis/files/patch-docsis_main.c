
$FreeBSD$

--- docsis_main.c.orig	Thu Feb 13 17:21:40 2003
+++ docsis_main.c	Sat Apr  5 10:18:46 2003
@@ -180,10 +180,10 @@
    	if (! netsnmp_ds_get_boolean (NETSNMP_DS_LIBRARY_ID,  NETSNMP_DS_LIB_PRINT_UCD_STYLE_OID)) {
         	netsnmp_ds_toggle_boolean(NETSNMP_DS_LIBRARY_ID, NETSNMP_DS_LIB_PRINT_UCD_STYLE_OID);
    	}   */
-
+/*
    	if (! netsnmp_ds_get_boolean (NETSNMP_DS_LIBRARY_ID,  NETSNMP_DS_LIB_DONT_PRINT_UNITS)) {
         	netsnmp_ds_toggle_boolean(NETSNMP_DS_LIBRARY_ID, NETSNMP_DS_LIB_DONT_PRINT_UNITS);
-   	} 
+   	} */
 
         netsnmp_ds_set_int(NETSNMP_DS_LIBRARY_ID, NETSNMP_DS_LIB_OID_OUTPUT_FORMAT,
                                                       NETSNMP_OID_OUTPUT_SUFFIX); 
