--- src/dlglist.c.orig	Tue Aug 24 18:14:12 2004
+++ src/dlglist.c	Wed Jun 29 11:13:07 2005
@@ -71,7 +71,7 @@
 #define mc_list_previous(list)	((list) ? (((MC_DLG_List *)(list))->prev) : NULL)
 #define mc_list_next(list)	((list) ? (((MC_DLG_List *)(list))->next) : NULL)
 
-static MC_DLG_List* mc_list_first (MC_DLG_List *list){ while(list->prev) list=list->prev; return list;}
+static MC_DLG_List* mc_list_first (MC_DLG_List *list){ while(list && list->prev) list=list->prev; return list;}
 static MC_DLG_List* mc_list_last  (MC_DLG_List *list){ while(list->next) list=list->next; return list;}
 
 
