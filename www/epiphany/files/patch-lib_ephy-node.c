--- lib/ephy-node.c.orig	Sat Jun 28 11:03:58 2003
+++ lib/ephy-node.c	Sat Jun 28 11:04:22 2003
@@ -115,12 +115,12 @@
 static void
 callback (long id, EphyNodeSignalData *data, gpointer *user_data)
 {
-        va_list valist;
+        _BSD_VA_LIST_ valist;
 	EphyNodeSignalType type = GPOINTER_TO_INT (user_data[1]);
 
 	if (data->type != type) return;
 
-        va_copy(valist, user_data[0]);
+        valist = user_data[0];
 
 	switch (data->type)
 	{
