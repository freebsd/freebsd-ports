
$FreeBSD$

--- libnautilus-private/nautilus-monitor.c	2001/12/07 22:54:34	1.1
+++ libnautilus-private/nautilus-monitor.c	2001/12/07 23:10:06
@@ -274,7 +274,8 @@
 	}
 	
 	monitor = g_new0 (NautilusMonitor, 1);
-	FAMMonitorFile (connection, path, &monitor->request, NULL);
+	if (FAMMonitorFile (connection, path, &monitor->request, NULL) == -1)
+		return NULL;
 
 	g_free (path);
 
@@ -314,7 +315,8 @@
 	}
 	
 	monitor = g_new0 (NautilusMonitor, 1);
-	FAMMonitorDirectory (connection, path, &monitor->request, NULL);
+	if (FAMMonitorDirectory (connection, path, &monitor->request, NULL) == -1)
+		return NULL;
 
 	g_assert (g_hash_table_lookup (get_request_hash_table (),
 				       GINT_TO_POINTER (FAMREQUEST_GETREQNUM (&monitor->request))) == NULL);
