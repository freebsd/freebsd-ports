--- leif/sun_le_asia/th_TH/leif/thai_le.c	Fri Mar 26 18:13:39 2004
+++ leif/sun_le_asia/th_TH/leif/thai_le.c	Wed Feb 16 20:45:29 2005
@@ -173,7 +173,7 @@
 /* Open the IF interface */
 Bool if_le_OpenIF(iml_if_t * If)
 {
-	char *keymap_config_file = "/usr/lib/im/locale/th_TH/thai_keymap.cfg";
+	char *keymap_config_file = IMDIR "/locale/th_TH/thai_keymap.cfg";
 	TThaiKeymapList *pThaiKeymapList = &gThaiKeymapList;
 
     	DEBUG_printf("if_le_OpenIF ====\n");
