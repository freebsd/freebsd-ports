--- lib/plugins/stonith/ipmilan_command.c.orig	2018-09-02 01:03:28 UTC
+++ lib/plugins/stonith/ipmilan_command.c
@@ -47,6 +47,7 @@ extern const PILPluginImports*  PluginIm
 
 /* #define DUMP_MSG 0 */
 #define OPERATION_TIME_OUT 10
+typedef struct selector_s selector_t;
 
 os_handler_t *os_hnd=NULL;
 selector_t *os_sel;
