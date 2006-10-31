Index: src/common/areas.c
===================================================================
RCS file: /cvsroot/rusfidogate/fidogate-sta/src/common/areas.c,v
retrieving revision 5.2
retrieving revision 5.3
diff -u -r5.2 -r5.3
--- src/common/areas.c	14 Oct 2006 08:52:55 -0000	5.2
+++ src/common/areas.c	20 Oct 2006 12:13:18 -0000	5.3
@@ -67,9 +67,9 @@
 	debug(8, "config: AreasXlate %s", cf);
 	
 	/* Chars in area name */
-	x_a = xstrtok(cf  , " \t");
+	x_a = (unsigned char *)xstrtok(cf  , " \t");
 	/* Chars in newsgroup name */
-	x_g = xstrtok(NULL, " \t");
+	x_g = (unsigned char *)xstrtok(NULL, " \t");
 	if(!x_a || !x_g)
 	    return;
 
