Index: main.c
===================================================================
--- main.c	(revision 1793)
+++ main.c	(revision 1796)
@@ -133,6 +133,7 @@
 		trace(TRACE_ERROR, "%s,%s: error reading message",
 		      __FILE__, __func__);
 		dm_free(tmpmessage);
+		tmpmessage=NULL;
 		return -1;
 	}
 	
@@ -371,6 +372,7 @@
 		trace(TRACE_ERROR, "%s,%s splitmessage failed",
 		      __FILE__, __func__);
 		dm_free(whole_message);
+		whole_message=NULL;
 		exitcode = EX_TEMPFAIL;
 		goto freeall;
 	}
