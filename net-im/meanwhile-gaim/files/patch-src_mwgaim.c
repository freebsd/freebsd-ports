--- src/mwgaim.c.orig	Thu Mar 24 12:49:15 2005
+++ src/mwgaim.c	Thu Mar 24 12:49:50 2005
@@ -1651,6 +1651,7 @@ static void im_recv_mime(struct mwConver
 	GString *atstr;
 	gsize len = (end - start);
 	char *tt;
+	gsize mov;
 
 	atstr = g_string_new("");
 	if(alt) g_string_append_printf(atstr, " alt=\"%s\"", alt);
@@ -1661,7 +1662,7 @@ static void im_recv_mime(struct mwConver
 	DEBUG_INFO("rewriting IMG\n{%s}\n", tt);
 	g_free(tt);
 
-	gsize mov = g_snprintf(start, len, "<img%s id=\"%i\"",
+	mov = g_snprintf(start, len, "<img%s id=\"%i\"",
 			       atstr->str, img);
 	while(mov < len) start[mov++] = ' ';
 
