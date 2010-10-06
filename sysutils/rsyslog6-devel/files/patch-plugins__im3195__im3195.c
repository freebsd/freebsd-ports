--- ./plugins/im3195/im3195.c.orig	2010-10-05 05:17:31.289999990 +0000
+++ ./plugins/im3195/im3195.c	2010-10-05 05:18:22.651270169 +0000
@@ -161,8 +161,8 @@
 CODEmodInit_QueryRegCFSLineHdlr
 	CHKiRet(objUse(errmsg, CORE_COMPONENT));
 
-	CHKiRet(omsdRegCFSLineHdlr((uchar *)"input3195listenport", 0, eCmdHdlrInt, NULL, &listenPort, STD_LOADABLE_MODULE_ID));
-	CHKiRet(omsdRegCFSLineHdlr((uchar *)"resetconfigvariables", 1, eCmdHdlrCustomHandler, resetConfigVariables, NULL, STD_LOADABLE_MODULE_ID));
+	CHKiRet(omsdRegCFSLineHdlr((uchar *)"input3195listenport", 0, eCmdHdlrInt, NULL, &listenPort, STD_LOADABLE_MODULE_ID, eConfObjAction));
+	CHKiRet(omsdRegCFSLineHdlr((uchar *)"resetconfigvariables", 1, eCmdHdlrCustomHandler, resetConfigVariables, NULL, STD_LOADABLE_MODULE_ID, eConfObjAction));
 ENDmodInit
 /* vim:set ai:
  */
