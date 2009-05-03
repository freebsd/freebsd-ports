--- libs/gcu/cmd-context.cc.orig	2009-05-02 23:59:39.000000000 -0400
+++ libs/gcu/cmd-context.cc	2009-05-02 23:59:52.000000000 -0400
@@ -78,7 +78,7 @@ gcu_cc_cmd_context_init (GOCmdContextCla
 GSF_CLASS_FULL (GcuCmdContext, gcu_cmd_context,
 		NULL, NULL, NULL, NULL,
 		NULL, G_TYPE_OBJECT, 0,
-		GSF_INTERFACE (gcu_cc_cmd_context_init, GO_CMD_CONTEXT_TYPE))
+		GSF_INTERFACE (gcu_cc_cmd_context_init, GO_TYPE_CMD_CONTEXT))
 
 static GOCmdContext *cc = NULL;
 
