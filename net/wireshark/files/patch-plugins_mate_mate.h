--- plugins/mate/mate.h.orig	Fri Jan 28 20:21:03 2005
+++ plugins/mate/mate.h	Fri Jan 28 20:29:36 2005
@@ -324,7 +324,7 @@
 extern void initialize_mate_runtime(void);
 extern mate_pdu* mate_get_pdus(guint32 framenum);
 extern void mate_analyze_frame(packet_info *pinfo, proto_tree* tree);
-extern int mate_packet(void* _U_, packet_info* _U_, epan_dissect_t* _U_,const void* _U_);
+extern int mate_packet(void *prs _U_, packet_info* tree _U_, epan_dissect_t *edt _U_,const void *dummy _U_);
 
 /* from mate_setup.c */
 extern mate_config* mate_make_config(guint8* filename);
