--- lib/ephy-node.c.orig	Mon Jun  9 19:02:09 2003
+++ lib/ephy-node.c	Sun Jun 29 02:01:59 2003
@@ -115,12 +115,16 @@
 static void
 callback (long id, EphyNodeSignalData *data, gpointer *user_data)
 {
-        va_list valist;
+	va_list valist;
 	EphyNodeSignalType type = GPOINTER_TO_INT (user_data[1]);
 
 	if (data->type != type) return;
 
-        va_copy(valist, user_data[0]);
+#if __FreeBSD_version >= 500040
+	va_copy(valist, user_data[0]);
+#else
+	valist = (va_list) user_data[0];
+#endif
 
 	switch (data->type)
 	{
