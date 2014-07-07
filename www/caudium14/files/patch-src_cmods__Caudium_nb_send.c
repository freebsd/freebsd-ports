--- src/cmods/_Caudium/nb_send.c.orig	2014-07-06 17:29:43.000000000 +0200
+++ src/cmods/_Caudium/nb_send.c	2014-07-06 17:29:21.000000000 +0200
@@ -92,7 +92,7 @@ static int sbuffers;  /* size of allocat
 static void push_callback(int no)
 {
   add_ref(Pike_sp->u.object = THISOBJ);
-  Pike_sp->subtype = no + Pike_fp->context.identifier_level;
+  Pike_sp->subtype = no + Pike_fp->context->identifier_level;
   Pike_sp->type = T_FUNCTION;
   Pike_sp++;
 }
