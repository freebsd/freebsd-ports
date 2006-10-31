Index: src/common/msgid.c
===================================================================
RCS file: /cvsroot/rusfidogate/fidogate-sta/src/common/msgid.c,v
retrieving revision 5.1
retrieving revision 5.2
diff -u -r5.1 -r5.2
--- src/common/msgid.c	10 Dec 2004 19:09:58 -0000	5.1
+++ src/common/msgid.c	31 Oct 2006 15:12:10 -0000	5.2
@@ -265,9 +265,9 @@
      * Compute CRC for strings from, to, subject
      */
     crc32_init();
-    crc32_compute(msg->name_from, strlen(msg->name_from));
-    crc32_compute(msg->name_to  , strlen(msg->name_to  ));
-    crc32_compute(msg->subject  , strlen(msg->subject  ));
+    crc32_compute((unsigned char *)msg->name_from, strlen(msg->name_from));
+    crc32_compute((unsigned char *)msg->name_to  , strlen(msg->name_to  ));
+    crc32_compute((unsigned char *)msg->subject  , strlen(msg->subject  ));
 
     return s_printf("<NOMSGID_%d=3A%d=2F%d.%d_%s_%08lx@%s>",
 		    msg->node_orig.zone, msg->node_orig.net,
