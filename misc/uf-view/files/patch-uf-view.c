
$FreeBSD$

--- uf-view.c.orig	Sun May 13 21:13:07 2001
+++ uf-view.c	Wed May 30 22:57:40 2001
@@ -98,7 +98,7 @@
 	if (url != NULL)
 	{
 		gchar foo[100] = "/tmp/ufXXXXXX";
-		mktemp(foo);
+		mkstemp(foo);
 
 		appbar_send_msg(_("Fetching %s"), url);
 
@@ -206,6 +206,7 @@
 	const gchar *authors[] = {
 		("Bastien Nocera <hadess@hadess.net>"),
 		("Robert Brady <rwb197@ecs.soton.ac.uk>"),
+		("Drew Ogle <daliegri@wam.umd.edu>"),
 		NULL,
 	};
 
@@ -239,7 +240,7 @@
 void on_today_button_clicked(GtkWidget * button, gpointer user_data)
 {
 	struct tm *time_struct;
-	glong curtime;
+	time_t curtime;
 	gint month, year, day;
 
 	curtime = time(0);
@@ -383,7 +384,7 @@
 	gchar foo[100] = "/tmp/ufXXXXXX";
 
 	/* Initialise */
-	mktemp(foo);
+	mkstemp(foo);
 
 	if (date_error(year, month, day, 1997, 9, 17) == TRUE) {
 		show_error(_("User Friendly did not exist at that time.\nPlease choose a later date."));
@@ -466,7 +467,7 @@
 	gchar foo[100] = "/tmp/ufXXXXXX";
 
 	/* Initialise */
-	mktemp(foo);
+	mkstemp(foo);
 
 	if (date_error(year, month, day, 2000, 3, 17) == TRUE) {
 		show_error(_("This Penny Arcade's stuff's too old.\nPlease choose a later date."));
