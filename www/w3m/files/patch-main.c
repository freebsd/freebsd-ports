--- main.c.orig	Wed Jul 17 21:54:51 2002
+++ main.c	Wed Jul 17 21:57:26 2002
@@ -3307,7 +3307,7 @@
     HmarkerList *hl = Currentbuf->hmarklist;
     BufferPoint *po;
     Anchor *an;
-    int hseq = hl->nmark - 1;
+    int hseq;
 
     if (Currentbuf->firstLine == NULL)
 	return;
@@ -3318,6 +3318,8 @@
 	hseq = 0;
     else if (prec_num > 0)
 	hseq = hl->nmark - prec_num;
+    else
+	hseq = hl->nmark - 1;
     do {
 	if (hseq < 0)
 	    return;
