--- src/summary_search.c.orig	Wed Jun 12 07:49:20 2002
+++ src/summary_search.c	Tue Jul 23 19:14:41 2002
@@ -224,10 +224,6 @@
 	gboolean backward;
 	gboolean search_all;
 	gboolean all_searched = FALSE;
-	gboolean from_matched;
-	gboolean   to_matched;
-	gboolean subj_matched;
-	gboolean body_matched;
 	gchar *body_str;
 	wchar_t *wcs_hs, *fromwcs, *towcs, *subjwcs;
 	wchar_t *(* WCSFindFunc) (const wchar_t *haystack,
@@ -260,6 +256,7 @@
 	towcs   = (wchar_t *)GTK_ENTRY(to_entry)->text;
 	subjwcs = (wchar_t *)GTK_ENTRY(subject_entry)->text;
 	body_str = gtk_entry_get_text(GTK_ENTRY(body_entry));
+	wcs_hs = NULL;
 
 	if (search_all) {
 		gtk_clist_freeze(GTK_CLIST(ctree));
@@ -285,7 +282,13 @@
 	if (*body_str)
 		main_window_cursor_wait(summaryview->mainwin);
 
-	for (;;) {
+	for (;; node = backward ? GTK_CTREE_NODE_PREV(node)
+				: GTK_CTREE_NODE_NEXT(node)) {
+		if (wcs_hs) {
+		    g_free(wcs_hs);
+		    wcs_hs = NULL;
+		}
+		
 		if (!node) {
 			gchar *str;
 			AlertValue val;
@@ -324,58 +327,49 @@
 				break;
 		}
 
-		from_matched = to_matched = subj_matched = body_matched = FALSE;
-
 		msginfo = gtk_ctree_node_get_row_data(ctree, node);
 
-		if (*fromwcs && msginfo->from) {
+		if (*fromwcs) {
+			if (msginfo->from == NULL)
+				continue;
 			wcs_hs = strdup_mbstowcs(msginfo->from);
-			if (wcs_hs && WCSFindFunc(wcs_hs, fromwcs) != NULL)
-				from_matched = TRUE;
-			g_free(wcs_hs);
+			if (!(wcs_hs && WCSFindFunc(wcs_hs, fromwcs) != NULL))
+				continue;
 		}
-		if (*towcs && msginfo->to) {
+		if (*towcs) {
+			if (msginfo->to == NULL)
+				continue;
 			wcs_hs = strdup_mbstowcs(msginfo->to);
-			if (wcs_hs && WCSFindFunc(wcs_hs, towcs) != NULL)
-				to_matched = TRUE;
-			g_free(wcs_hs);
+			if (!(wcs_hs && WCSFindFunc(wcs_hs, towcs) != NULL))
+				continue;
 		}
-		if (*subjwcs && msginfo->subject) {
+		if (*subjwcs) {
+			if (msginfo->subject == NULL)
+				continue;
 			wcs_hs = strdup_mbstowcs(msginfo->subject);
-			if (wcs_hs && WCSFindFunc(wcs_hs, subjwcs) != NULL)
-				subj_matched = TRUE;
-			g_free(wcs_hs);
+			if (!(wcs_hs && WCSFindFunc(wcs_hs, subjwcs) != NULL))
+				continue;
 		}
 		if (*body_str) {
-			if (procmime_find_string(msginfo, body_str, case_sens))
-				body_matched = TRUE;
+			if (!procmime_find_string(msginfo, body_str, case_sens))
+				continue;
 		}
 
-		if (from_matched || to_matched || subj_matched || body_matched) {
-			if (search_all)
-				gtk_ctree_select(ctree, node);
-			else {
-				if (messageview_is_visible
-					(summaryview->messageview)) {
-					summary_unlock(summaryview);
-					summary_select_node
-						(summaryview, node, TRUE, TRUE);
-					summary_lock(summaryview);
-					if (body_matched) {
-						messageview_search_string
-							(summaryview->messageview,
-							 body_str, case_sens);
-					}
-				} else {
-					summary_select_node
-						(summaryview, node, FALSE, TRUE);
-				}
-				break;
-			}
+		if (search_all)
+			gtk_ctree_select(ctree, node);
+		else {
+			if (messageview_is_visible(summaryview->messageview)) {
+				summary_unlock(summaryview);
+				summary_select_node(summaryview, node, TRUE, TRUE);
+				summary_lock(summaryview);
+				if (*body_str)
+					messageview_search_string(
+						summaryview->messageview,
+						body_str, case_sens);
+			} else
+				summary_select_node(summaryview, node, FALSE, TRUE);
+			break;
 		}
-
-		node = backward ? GTK_CTREE_NODE_PREV(node)
-				: GTK_CTREE_NODE_NEXT(node);
 	}
 
 	if (*body_str)
