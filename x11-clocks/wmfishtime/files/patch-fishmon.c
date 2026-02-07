--- fishmon.c.orig	2004-05-12 23:55:59 UTC
+++ fishmon.c
@@ -152,6 +152,10 @@ static char month[12][4] = { "JAN", "FEB
 
 int main(int argc, char **argv)
 {
+#if (GTK_MAJOR_VERSION >= 2)
+    /* This is needed to proper dockapp work on >=GTK+=2.18 */
+    setenv("GDK_NATIVE_WINDOWS", "1", 0);
+#endif
     int ch;
     GdkEvent *event;
 #ifdef PRO
@@ -648,6 +652,9 @@ static void make_new_fishmon_dockapp(voi
 
     /* make a copy for the iconwin - parameters are the same */
     memcpy(&attri, &attr, sizeof(GdkWindowAttr));
+#if (GTK_MAJOR_VERSION >= 2)
+    attri.window_type = GTK_WINDOW_CHILD;
+#endif
 
     sizehints.flags = USSize;
     sizehints.width = 64;
@@ -679,7 +686,11 @@ static void make_new_fishmon_dockapp(voi
     wmhints.window_group = win;
     wmhints.flags =
 	StateHint | IconWindowHint | IconPositionHint | WindowGroupHint;
+#if (GTK_MAJOR_VERSION >= 2)
+    gdk_window_show(bm.iconwin);
+#else
     XSetWMHints(GDK_WINDOW_XDISPLAY(bm.win), win, &wmhints);
+#endif
 
     bm.gc = gdk_gc_new(bm.win);
 
@@ -1020,27 +1031,29 @@ static void parse_options(int argc, char
 {
     static int ch = 0;
     static struct option long_opts[] = {
-	{ "h",		no_argument, NULL, 1 },
-	{ "help",	no_argument, NULL, 1 },
-	{ "v",		no_argument, NULL, 2 },
-	{ "version",	no_argument, NULL, 2 },
-	{ "c",		no_argument, &enable_check_mail, 1 },
-	{ "check-mail", no_argument, &enable_check_mail, 1 },
-	{ "b",		no_argument, &broken_wm, 1 },
-	{ "broken",	no_argument, &broken_wm, 1 },
+	{ "help",	no_argument, NULL, 'h' },
+	{ "version",	no_argument, NULL, 'v' },
+	{ "check-mail", no_argument, &enable_check_mail, 'c' },
+	{ "broken",	no_argument, &broken_wm, 'b' },
 	{ 0, 0, 0, 0 }
     };
 
-    while ((ch = getopt_long_only(argc, argv, "", long_opts, NULL)) != -1) {
+    while ((ch = getopt_long(argc, argv, "hvcb", long_opts, NULL)) != -1) {
 	switch (ch) {
-	    case 1:
+	    case 'h':
 		do_help();
 		exit(0);
 		break;
-	    case 2:
+	    case 'v':
 		do_version();
 		exit(0);
 		break;
+	    case 'c':
+		enable_check_mail = 1;
+		break;
+	    case 'b':
+		broken_wm = 1;
+		break;
 	}
     }
 }
