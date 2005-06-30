===================================================================
RCS file: /cvsroot/tcl/tcl/unix/tclUnixNotfy.c,v
retrieving revision 1.11.2.11
retrieving revision 1.11.2.12
diff -u -r1.11.2.11 -r1.11.2.12
--- tclUnixNotfy.c	2005/05/31 08:29:10	1.11.2.11
+++ tclUnixNotfy.c	2005/06/07 10:26:58	1.11.2.12
@@ -275,7 +275,7 @@
      */
 
     if (notifierCount == 0) {
-	int result;
+	int result, dummy;
 	if (triggerPipe < 0) {
 	    panic("Tcl_FinalizeNotifier: notifier pipe not initialized");
 	}
@@ -294,7 +294,7 @@
 	close(triggerPipe);
 
 	Tcl_ConditionWait(&notifierCV, &notifierMutex, NULL);
-	result = Tcl_JoinThread(notifierThread);
+	result = Tcl_JoinThread(notifierThread, &dummy);
 	if (result) {
 	    Tcl_Panic("Tcl_FinalizeNotifier: unable to join notifier thread");
 	}
