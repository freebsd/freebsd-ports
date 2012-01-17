--- ./plugins/imklog/bsd.c.orig	2012-01-17 01:18:16.381760139 +0000
+++ ./plugins/imklog/bsd.c	2012-01-17 01:20:48.523313199 +0000
@@ -93,7 +93,7 @@
  * entry point. -- rgerhards, 2008-04-09
  */
 rsRetVal
-klogWillRun(void)
+klogWillRun(modConfData_t *pModConf)
 {
 	DEFiRet;
 
@@ -176,7 +176,7 @@
 /* to be called in the module's AfterRun entry point
  * rgerhards, 2008-04-09
  */
-rsRetVal klogAfterRun(void)
+rsRetVal klogAfterRun(modConfData_t *pModConf)
 {
         DEFiRet;
 	if(fklog != -1)
@@ -190,7 +190,7 @@
  * "message pull" mechanism.
  * rgerhards, 2008-04-09
  */
-rsRetVal klogLogKMsg(void)
+rsRetVal klogLogKMsg(modConfData_t *pModConf)
 {
         DEFiRet;
 	readklog();
