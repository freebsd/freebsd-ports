--- src/plugins/gadu_gadu/gadu_gadu_plugin.c.orig	Tue Jan  4 09:51:43 2005
+++ src/plugins/gadu_gadu/gadu_gadu_plugin.c	Fri Jan 28 00:39:28 2005
@@ -422,6 +422,9 @@
 	uint32_t *uins;
 	GGaduMsg *msg = NULL;
 	gint i, j;
+	GSList *list;
+	GSList *us;
+	gchar *recipients_line = NULL;
 
 	/* w przypadku bledu/utraty polaczenia postap tak jak w przypadku disconnect */
 	if (!session || !(e = gg_watch_fd(session)) || (condition & G_IO_ERR) ||
@@ -585,9 +588,8 @@
 
 		}
 
-		GSList *list = ggadu_repo_get_as_slist("gadu-gadu", REPO_VALUE_CONTACT);
-		GSList *us = list;
-		gchar *recipients_line = NULL;
+		list = ggadu_repo_get_as_slist("gadu-gadu", REPO_VALUE_CONTACT);
+		us = list;
 
 		while (us)
 		{
@@ -696,6 +698,7 @@
 
 				if (k)
 				{
+					gchar *status = NULL;
 					ip_addr.s_addr = n->remote_ip;
 					if (inet_ntoa(ip_addr) && (ggadu_strcasecmp(inet_ntoa(ip_addr), "0.0.0.0")))
 					{
@@ -714,7 +717,6 @@
 
 					/* Zapiszmy sobie zmiane opisu do pliku historii */
 
-					gchar *status = NULL;
 					if ((k->status == GG_STATUS_AVAIL) || (k->status == GG_STATUS_AVAIL_DESCR))
 						status = g_strdup_printf("avail");
 					else if ((k->status == GG_STATUS_BUSY) || (k->status == GG_STATUS_BUSY_DESCR))
