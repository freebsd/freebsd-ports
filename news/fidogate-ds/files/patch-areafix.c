Index: src/areafix/areafix.c
===================================================================
RCS file: /cvsroot/rusfidogate/fidogate-sta/src/areafix/areafix.c,v
retrieving revision 5.5
retrieving revision 5.6
diff -u -r5.5 -r5.6
--- src/areafix/areafix.c	26 Feb 2006 15:48:31 -0000	5.5
+++ src/areafix/areafix.c	15 Nov 2006 09:15:36 -0000	5.6
@@ -1946,7 +1946,7 @@
 	for (a=uplinks_lookup (areafix, area); a; a=a->next)
 	{
 		/* Create area */
-		if (a->options)
+		if (a != NULL && a->options != NULL)
 		    BUF_COPY3( buf, a->areas, " ", a->options );
 		else
 		    BUF_COPY( buf,  a->areas );
