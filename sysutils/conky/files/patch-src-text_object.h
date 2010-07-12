--- src/text_object.h.orig
+++ src/text_object.h
@@ -230,6 +230,7 @@ enum text_object_type {
 #endif /* X11 */
 	OBJ_nameserver,
 	OBJ_nodename,
+	OBJ_nodename_short,
 	OBJ_nvidia,
 	OBJ_pre_exec,
 	OBJ_cmdline_to_pid,
