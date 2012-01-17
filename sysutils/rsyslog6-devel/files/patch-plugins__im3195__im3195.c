--- ./plugins/im3195/im3195.c.orig	2011-09-15 06:01:15.000000000 +0000
+++ ./plugins/im3195/im3195.c	2012-01-17 01:17:22.083763800 +0000
@@ -195,8 +195,8 @@
 CODEmodInit_QueryRegCFSLineHdlr
 	CHKiRet(objUse(errmsg, CORE_COMPONENT));
 
-	CHKiRet(omsdRegCFSLineHdlr((uchar *)"input3195listenport", 0, eCmdHdlrInt, NULL, &listenPort, STD_LOADABLE_MODULE_ID));
-	CHKiRet(omsdRegCFSLineHdlr((uchar *)"resetconfigvariables", 1, eCmdHdlrCustomHandler, resetConfigVariables, NULL, STD_LOADABLE_MODULE_ID));
+	CHKiRet(omsdRegCFSLineHdlr((uchar *)"input3195listenport", 0, eCmdHdlrInt, NULL, &listenPort, STD_LOADABLE_MODULE_ID, eConfObjAction));
+	CHKiRet(omsdRegCFSLineHdlr((uchar *)"resetconfigvariables", 1, eCmdHdlrCustomHandler, resetConfigVariables, NULL, STD_LOADABLE_MODULE_ID, eConfObjAction));
 ENDmodInit
 /* vim:set ai:
  */
