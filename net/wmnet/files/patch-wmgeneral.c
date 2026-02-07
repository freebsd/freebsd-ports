--- wmgeneral.c.orig	Wed Aug 26 18:58:57 1998
+++ wmgeneral.c	Sat Jun  5 13:53:35 2004
@@ -221,7 +221,7 @@
 				 char const* pixmask_bits, int pixmask_width,
 				 int pixmask_height)
 {
-	static char const Geometry[] = "";
+	static char *Geometry = 0;
 
 	unsigned int borderwidth = 1;
 	XClassHint classHint;
@@ -245,6 +245,17 @@
 			display_name = argv[i + 1];
 	}
 
+	/* Look to see if the caller specified the geometry. If so, we will
+	   use it to place window */
+
+	for (i = 1; argv[i]; i++) {
+		if (!strcmp(argv[i], "-geom")) 
+			Geometry = argv[i + 1];
+	}
+	
+	if (!Geometry)
+		Geometry = "";
+
 	if (!(display = XOpenDisplay(display_name))) {
 		fprintf(stderr, "%s: can't open display %s\n", wname,
 				XDisplayName(display_name));
@@ -272,7 +283,7 @@
 				&mysizehints.height, &dummy);
 
 	mysizehints.width = 64;
-	mysizehints.height = 64;
+	mysizehints.height = 90;
 		
 	win = XCreateSimpleWindow(display, Root, mysizehints.x, mysizehints.y,
 							  mysizehints.width, mysizehints.height,
