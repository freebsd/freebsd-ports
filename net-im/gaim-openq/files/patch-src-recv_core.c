--- src/recv_core.c.orig	Sat Oct  2 17:48:12 2004
+++ src/recv_core.c	Sat Oct 16 18:17:35 2004
@@ -290,7 +290,7 @@
 void qq_input_pending(gpointer data, gint source, GaimInputCondition cond)
 {
 	GaimConnection *gc;
-	qq_data *qd;;
+	qq_data *qd;
 	guint8 *buf;
 	gint len;
 
