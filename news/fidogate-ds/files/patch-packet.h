Index: src/include/packet.h
===================================================================
RCS file: /cvsroot/rusfidogate/fidogate-sta/src/include/packet.h,v
retrieving revision 5.2
retrieving revision 5.3
diff -u -r5.2 -r5.3
--- src/include/packet.h	14 Oct 2006 08:52:55 -0000	5.2
+++ src/include/packet.h	31 Oct 2006 15:12:10 -0000	5.3
@@ -95,9 +95,9 @@
     int attr;					/* Attribute flags */
     int cost;					/* Cost */
     time_t date;				/* Date */
-    unsigned char name_to[MSG_MAXNAME];		/* To name */
-    unsigned char name_from[MSG_MAXNAME];	/* From name */
-    unsigned char subject[MSG_MAXSUBJ];		/* Subject */
+    char name_to[MSG_MAXNAME];			/* To name */
+    char name_from[MSG_MAXNAME];		/* From name */
+    char subject[MSG_MAXSUBJ];			/* Subject */
 
     char *area;					/* EchoMail area or NULL */
 }
