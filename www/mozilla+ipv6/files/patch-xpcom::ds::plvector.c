
$FreeBSD: /tmp/pcvs/ports/www/mozilla+ipv6/files/Attic/patch-xpcom::ds::plvector.c,v 1.1 2001-11-27 17:13:38 sumikawa Exp $

--- xpcom/ds/plvector.c	2001/11/21 12:36:30	1.1
+++ xpcom/ds/plvector.c	2001/11/21 12:43:54
@@ -177,11 +177,12 @@
 PL_VectorCompact(PLVector* v)
 {
     if (v->size != v->maxSize) {
+        void ** newData = NULL;
+
         /* shrink to desired size */
 #ifdef SIZE_T_MAX
         PR_ASSERT(v->size <= SIZE_T_MAX/sizeof(void *)); /* no overflow */
 #endif
-        void ** newData = NULL;
         if (v->size != 0) {
             newData = (void **)PR_Malloc(v->size * sizeof(void *));
             /* copy new data from old */
