Index: src/toss/ftntoss.c
===================================================================
RCS file: /cvsroot/rusfidogate/fidogate-sta/src/toss/ftntoss.c,v
retrieving revision 5.2
retrieving revision 5.4
diff -u -r5.2 -r5.4
--- src/toss/ftntoss.c	23 Nov 2005 23:12:22 -0000	5.2
+++ src/toss/ftntoss.c	31 Oct 2006 15:12:10 -0000	5.4
@@ -927,7 +927,7 @@
 	}
 
 	a = uplinks_line_get(TRUE, &msg->node_from);
-	if(a->options)
+	if(a != NULL && a->options != NULL)
 	    BUF_COPY5(autocreate_cmd, areaname, " ",
 		      autocreate_line, " ", a->options);
 	else
@@ -1036,9 +1036,9 @@
 
 	    /* Compute CRC for strings from, to, subject */
 	    crc32_init();
-	    crc32_compute(msg->name_from, strlen(msg->name_from));
-	    crc32_compute(msg->name_to  , strlen(msg->name_to  ));
-	    crc32_compute(msg->subject  , strlen(msg->subject  ));
+	    crc32_compute((unsigned char *)msg->name_from, strlen(msg->name_from));
+	    crc32_compute((unsigned char *)msg->name_to  , strlen(msg->name_to  ));
+	    crc32_compute((unsigned char *)msg->subject  , strlen(msg->subject  ));
 
 	    str_printf(buffer, sizeof(buffer), "%s NOMSGID: %s %s %08lx",
 		       area->area, znfp1(&msg->node_orig),
