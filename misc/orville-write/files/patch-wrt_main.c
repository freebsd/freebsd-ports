--- wrt_main.c.orig	Sun Sep  7 22:56:27 2003
+++ wrt_main.c	Sun Sep  7 22:56:47 2003
@@ -69,7 +69,7 @@
 
 bool readyn(void);
 void type_help(char *file);
-void log(char *outcome);
+void _log(char *outcome);
 
 
 main(int argc, char **argv)
@@ -145,7 +145,7 @@
     {
 	if (telegram) putchar('\n');
 	printf("Permission denied: %s is not accepting messages\n",hisname);
-	log("FAIL: denied");
+	_log("FAIL: denied");
 	done(1);
     }
 
@@ -176,7 +176,7 @@
 	fflush(stdout);
 	if (!readyn())
 	{
-		log("ABANDON: interupting");
+		_log("ABANDON: interupting");
 		done(1);
 	}
     }
@@ -193,14 +193,14 @@
 	if (!(hiswrt.wrt_telpref & (TELPREF_WRITE|TELPREF_TEL)) )
 	{
 	    if (!no_switch) printf("Try the \042talk\042 command.\n");
-	    log("FAIL: can't switch - talk only");
+	    _log("FAIL: can't switch - talk only");
 	    done(1);
 	}
 	if (no_switch || file_input)
 	{
 	    if (!no_switch) printf("Try the \042write\042 command "
 				   "(with no input redirection).\n");
-	    log("FAIL: can't switch");
+	    _log("FAIL: can't switch");
 	    done(1);
 	}
 	else
@@ -211,7 +211,7 @@
 	    {
 		if (!am_root)
 		{
-		    log("ABANDON: won't switch");
+		    _log("ABANDON: won't switch");
 		    done(1);
 		}
 	    }
@@ -273,7 +273,7 @@
 	open_record();
 
     open_hist();
-    log(rec_only?"POSTPONED":"OK");
+    _log(rec_only?"POSTPONED":"OK");
 
     /* Now that his terminal and the wrttmp file are open, abandon superuser */
     setuid(getuid());
@@ -366,7 +366,7 @@
 /* LOG - This logs a write execution.
  */
 
-void log(char *outcome)
+void _log(char *outcome)
 {
 FILE *fp;
 time_t tock;
