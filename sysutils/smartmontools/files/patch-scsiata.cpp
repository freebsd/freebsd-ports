--- scsiata.cpp.orig	2007-12-02 19:14:20.000000000 -0700
+++ scsiata.cpp	2009-09-04 14:27:48.000000000 -0600
@@ -380,14 +380,14 @@
    return 1, else 0 */
 int has_sat_pass_through(int device, int packet_interface)
 {
-    char data[512];
+    int ret;
+    char *data = (char *)malloc(512);	// (alignment)
     smart_command_set command;
 
     command = packet_interface ? PIDENTIFY : IDENTIFY;
-    if (0 == sat_command_interface(device, command, 0, data))
-        return 1;
-    else
-        return 0;
+    ret = ( 0 == sat_command_interface(device, command, 0, data) ? 1 : 0 );
+    free(data);
+    return ret;
 }
 
 /* Next two functions are borrowed from sg_lib.c in the sg3_utils
