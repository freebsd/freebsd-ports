$OpenBSD: patch-engine_c,v 1.1 2008/06/13 00:38:12 canacar Exp $
--- engine.c.orig	Tue Nov  6 23:35:44 2007
+++ engine.c	Thu Jun 12 17:49:32 2008
@@ -809,6 +809,9 @@ next_order(void)
 {
 	order_type *o, *oc;
 
+	if (curr_view->mgr->order_list == NULL)
+		return;
+
 	oc = curr_view->mgr->order_curr;
 
 	for (o = curr_view->mgr->order_list; o->name != NULL; o++) {
