--- window2.c.orig	Fri Mar 30 09:40:02 2001
+++ window2.c	Fri Mar 30 09:40:50 2001
@@ -172,7 +172,7 @@
 	for (i = 0;i<j;i++) {
 		p = (ManPath*) man_paths->get_value(i);
 		if (p) {
-			clist_item[0] = p->active?"o":"";
+			clist_item[0] = (gchar *)(p->active?"o":"");
 			clist_item[1] = man_paths->get_name(i);
 			sprintf(buffer,"%d",p->GetSize(-1));
 			clist_item[2] = buffer;
