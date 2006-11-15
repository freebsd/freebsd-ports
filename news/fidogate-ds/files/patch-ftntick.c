Index: src/tick/ftntick.c
===================================================================
RCS file: /cvsroot/rusfidogate/fidogate-sta/src/tick/ftntick.c,v
retrieving revision 5.2
retrieving revision 5.3
diff -u -r5.2 -r5.3
--- src/tick/ftntick.c	23 Nov 2005 23:12:22 -0000	5.2
+++ src/tick/ftntick.c	15 Nov 2006 08:59:25 -0000	5.3
@@ -370,7 +370,7 @@
 	    }
 	    
 	    a = uplinks_line_get(FALSE, &tic->from);
-	    if(a->options)
+	    if(a != NULL && a->options != NULL)
 	    {
 	    	tmp = (char*) xmalloc(strlen(tic->area)
 				      + strlen(autocreate_line)
