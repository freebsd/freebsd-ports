--- src/input/vcd/xineplug_inp_vcd.c	2004/04/28 10:41:46	1.108
+++ src/input/vcd/xineplug_inp_vcd.c	2004/07/18 14:47:21	1.109
@@ -48,6 +48,7 @@
 #define SHORT_PLUGIN_NAME "VCDX"
 #define MRL_PREFIX "vcdx://"
 #define MRL_PREFIX_LEN strlen(MRL_PREFIX)
+#define MRL_MAX_LEN 1024
 
 #define xine_config_entry_t xine_cfg_entry_t
 
@@ -465,7 +466,7 @@
     return false;
   }
 
-  count = sscanf (p, "%[^@]@%1[EePpSsTt]%u", 
+  count = sscanf (p, "%1024[^@]@%1[EePpSsTt]%u", 
 		  device_str, type_str, &num);
   itemid->num = num;
   
@@ -489,7 +490,7 @@
     {
       /* No device/file given, so use the default device and try again. */
       if (NULL == default_vcd_device) return false;
-      strcpy(device_str, default_vcd_device);
+      strncpy(device_str, default_vcd_device, MRL_MAX_LEN);
       if (p[0] == '@') p++;
       count = sscanf (p, "%1[EePpSsTt]%u", type_str, &num);
       type_str[0] = toupper(type_str[0]);
@@ -781,7 +782,7 @@
 vcd_class_get_dir (input_class_t *this_gen, const char *filename, 
                     int *num_files) {
 
-  char             intended_vcd_device[1024]="";
+  char             intended_vcd_device[MRL_MAX_LEN+1]="";
   vcdinfo_itemid_t itemid;
 
   vcd_input_class_t *class = (vcd_input_class_t *) this_gen;
@@ -913,7 +914,7 @@
 static char *
 vcd_class_get_identifier (input_class_t *this_gen) {
   dbg_print((INPUT_DBG_CALL|INPUT_DBG_EXT), "called\n");
-  return SHORT_PLUGIN_NAME;
+  return strdup(SHORT_PLUGIN_NAME);
 }
 
 /* 
@@ -1425,7 +1426,7 @@
 {
   vcd_input_class_t  *class = (vcd_input_class_t *) class_gen;
 
-  char intended_vcd_device[1024]="";
+  char intended_vcd_device[MRL_MAX_LEN+1]="";
   vcdinfo_itemid_t itemid;
   char *check_mrl=NULL;
   bool used_default;
