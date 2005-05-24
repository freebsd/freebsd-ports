--- iiimsf/src/lexmlconf.cpp.orig	Fri Apr 22 16:53:03 2005
+++ iiimsf/src/lexmlconf.cpp	Mon May 16 19:00:55 2005
@@ -114,6 +114,7 @@
 	list = (IIIMLEInfoList *)malloc(sizeof (IIIMLEInfoList) * 1);
 	list->data = leinfo;
 	list->next = NULL;
+	list->prev = NULL;
 
 	return list;
 }
@@ -128,6 +129,7 @@
 	if (list != NULL) {
 		for (ll = list; ll->next != NULL; ll = ll->next);
 		ll->next = l;
+		l->prev = ll;
 		ll = list;
 	} else {
 		ll = l;
@@ -144,7 +146,12 @@
 
 	l = iiim_le_info_list_new(leinfo);
 	if (list != NULL) {
+                if (list->prev != NULL) {
+                        list->prev->next = l;
+                }
 		l->next = list;
+		l->prev = list->prev;
+		list->prev = l;
 	}
 
 	return l;
@@ -154,22 +161,19 @@
 iiim_le_info_list_remove(IIIMLEInfoList *list,
 			 IIIMLEInfo     *leinfo)
 {
-	IIIMLEInfoList *tmp, *prev = NULL;
+	IIIMLEInfoList *prev, *next;
 
-	tmp = list;
-	while (tmp) {
-		if (tmp->data == leinfo) {
-			if (prev)
-				prev->next = tmp->next;
-			else
-				list = tmp->next;
-			iiim_le_info_free(tmp->data);
-			free(tmp);
-
-			break;
-		}
-		prev = tmp;
-		tmp = prev->next;
+	for (; list && list->data != leinfo; list = list->next);
+
+	if (NULL != list) {
+	  prev = list->prev;
+	  next = list->next;
+
+	  if (NULL != prev) prev->next = next;
+	  if (NULL != next) next->prev = prev;
+
+	  if (list->data) iiim_le_info_free(list->data);
+	  free(list);
 	}
 
 	return list;
