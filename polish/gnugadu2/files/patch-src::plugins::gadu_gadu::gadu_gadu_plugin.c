--- src/plugins/gadu_gadu/gadu_gadu_plugin.c.orig	Sat Jun 12 09:04:53 2004
+++ src/plugins/gadu_gadu/gadu_gadu_plugin.c	Wed Jul 21 23:11:11 2004
@@ -385,6 +385,10 @@
 	GGaduMsg *msg = NULL;
 	gchar *hist_line = NULL;
 	gint i, j;
+	GSList *list;
+	GSList *us;
+	gchar *line2 = NULL;
+		
 
 	/* w przypadku bledu/utraty polaczenia postap tak jak w przypadku disconnect */
 	if (!(e = gg_watch_fd(session)) || (condition & G_IO_ERR) ||
@@ -524,9 +528,8 @@
 
 		}
 		
-		GSList *list = ggadu_repo_get_as_slist("gadu-gadu", REPO_VALUE_CONTACT);
-		GSList *us = list;
-		gchar *line2 = NULL;
+		list = ggadu_repo_get_as_slist("gadu-gadu", REPO_VALUE_CONTACT);
+		us = list;
 		
 		while(us)
 		{
@@ -560,6 +563,8 @@
 				gchar *strIP = NULL;
 				gchar *id = g_strdup_printf("%d", e->event.notify60[i].uin);
 				struct in_addr ip_addr;
+				gchar *status = NULL;
+				gchar *line;
 				GGaduContact *k = ggadu_repo_find_value("gadu-gadu", ggadu_repo_key_from_string(id));
 
 				if (k)
@@ -581,7 +586,7 @@
 					
 					/* Zapiszmy sobie zmiane opisu do pliku historii */
 					
-					gchar *status = NULL;
+					status = NULL;
 					if((k->status == GG_STATUS_AVAIL)||(k->status == GG_STATUS_AVAIL_DESCR))		status = g_strdup_printf("avail");
 					else if((k->status == GG_STATUS_BUSY)||(k->status == GG_STATUS_BUSY_DESCR))		status = g_strdup_printf("busy");
 					else if((k->status == GG_STATUS_INVISIBLE)||(k->status == GG_STATUS_INVISIBLE_DESCR))	status = g_strdup_printf("notavail");
@@ -592,7 +597,7 @@
 					/* Format kompatybilny z histori± Kadu ;) 			*/
 					/* Jednak pierw nale¿y skasowaæ [numerek].idx aby uaktualniæ ;)	*/
 
-					gchar *line = g_strdup_printf("status,%s,%s,%s,%d,%s%s\n", k->id, k->nick, 
+					line = g_strdup_printf("status,%s,%s,%s,%d,%s%s\n", k->id, k->nick, 
 							    ((k->ip == NULL) ? "0.0.0.0" : k->ip), (int)time(0), status,
 							    ((k->status_descr == NULL) ? "" : g_strdup_printf(",%s",k->status_descr)));
 					ggadu_gg_save_history((gchar *) k->id, line);
@@ -623,6 +628,8 @@
 
 			while (n->uin)
 			{
+				gchar *status;
+				gchar *line;
 				gchar *id = g_strdup_printf("%d", n->uin);
 				GGaduContact *k = ggadu_repo_find_value("gadu-gadu", ggadu_repo_key_from_string(id));
 				struct in_addr ip_addr;
@@ -647,7 +654,7 @@
 					
 					/* Zapiszmy sobie zmiane opisu do pliku historii */
 					
-					gchar *status = NULL;
+					status = NULL;
 					if((k->status == GG_STATUS_AVAIL)||(k->status == GG_STATUS_AVAIL_DESCR))		status = g_strdup_printf("avail");
 					else if((k->status == GG_STATUS_BUSY)||(k->status == GG_STATUS_BUSY_DESCR))		status = g_strdup_printf("busy");
 					else if((k->status == GG_STATUS_INVISIBLE)||(k->status == GG_STATUS_INVISIBLE_DESCR))	status = g_strdup_printf("notavail");
@@ -658,7 +665,7 @@
 					/* Format kompatybilny z histori± Kadu ;) 			*/
 					/* Jednak pierw nale¿y skasowaæ [numerek].idx aby uaktualniæ ;)	*/
 					
-					gchar *line = g_strdup_printf("status,%s,%s,%s,%d,%s%s\n", k->id, k->nick, 
+					line = g_strdup_printf("status,%s,%s,%s,%d,%s%s\n", k->id, k->nick, 
 							    ((k->ip == NULL) ? "0.0.0.0" : k->ip), (gint)time(0), status,
 							    ((k->status_descr == NULL) ? "" : g_strdup_printf(",%s",k->status_descr)));
 					ggadu_gg_save_history((gchar *) k->id, line);
@@ -674,6 +681,8 @@
 	case GG_EVENT_STATUS60:
 	case GG_EVENT_STATUS:
 		{
+			gchar *status;
+			gchar *line;
 			gchar *id =
 				g_strdup_printf("%d",
 						(e->type ==
@@ -698,7 +707,7 @@
 			
 			/* Zapiszmy sobie zmiane opisu do pliku historii */
 
-			gchar *status = NULL;
+			status = NULL;
 			if((k->status == GG_STATUS_AVAIL)||(k->status == GG_STATUS_AVAIL_DESCR))		status = g_strdup_printf("avail");
 			else if((k->status == GG_STATUS_BUSY)||(k->status == GG_STATUS_BUSY_DESCR))		status = g_strdup_printf("busy");
 			else if((k->status == GG_STATUS_INVISIBLE)||(k->status == GG_STATUS_INVISIBLE_DESCR))	status = g_strdup_printf("notavail");
@@ -709,7 +718,7 @@
 			/* Format kompatybilny z histori± Kadu ;) 			*/
 			/* Jednak pierw nale¿y skasowaæ [numerek].idx aby uaktualniæ ;)	*/
 
-			gchar *line = g_strdup_printf("status,%s,%s,%s,%d,%s%s\n", k->id, k->nick, 
+			line = g_strdup_printf("status,%s,%s,%s,%d,%s%s\n", k->id, k->nick, 
 				    ((k->ip == NULL) ? "0.0.0.0" : k->ip), (gint)time(0), status,
 				    ((k->status_descr == NULL) ? "" : g_strdup_printf(",%s",k->status_descr)));
 			ggadu_gg_save_history((gchar *) k->id, line);
@@ -2275,6 +2284,7 @@
 					GSList *tmp = msg->recipients;
 					while (tmp)
 					{	
+						gchar *line;
 						GSList *list = ggadu_repo_get_as_slist("gadu-gadu", REPO_VALUE_CONTACT);
 						GSList *us = list;
 						gchar *line2 = NULL;
@@ -2288,7 +2298,7 @@
 						}
 						
 						
-						gchar *line =
+						line =
 							g_strdup_printf("chatsend,%s,%s,%d,%s\n", msg->id, line2, (gint)time(0), msg->message);
 						ggadu_gg_save_history((gchar *) tmp->data, line);
 						g_free(line2);
@@ -2312,6 +2322,7 @@
 				}
 				else if (ggadu_config_var_get(handler, "log"))
 				{
+					gchar *line;
 					GSList *list = ggadu_repo_get_as_slist("gadu-gadu", REPO_VALUE_CONTACT);
 					GSList *us = list;
 					gchar *line2 = NULL;
@@ -2324,7 +2335,7 @@
 						us = us->next;
 					}
 						
-					gchar *line =
+					line =
 						g_strdup_printf("chatsend,%s,%s,%d,%s\n", msg->id, line2, (gint)time(0), msg->message);
 					ggadu_gg_save_history(msg->id, line);
 
