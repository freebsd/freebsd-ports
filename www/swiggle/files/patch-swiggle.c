--- swiggle.c.orig	Sat Oct 23 22:58:37 2004
+++ swiggle.c	Wed Nov  1 16:34:10 2006
@@ -66,12 +66,14 @@
 char generated[1024];
 char *progname = "";
 int cols = 5;
+int exif_display = 1; /* By default, display the exif data */
 int rows = 3;
 int scaleheight = 480;
 int thumbheight = 96;
 int force = 0;
 int bilinear = 0;
 int rm_orphans = 1;
+int show_descr = 0;
 int (*sort_func)();
 
 #define	MAX_PER_PAGE	(cols*rows)
@@ -113,7 +115,7 @@
 	progname = argv[0];
 	sort_func = sort_by_filename;
 
-	while ((i = getopt(argc, argv, "c:d:h:H:r:s:flov")) != -1) {
+	while ((i = getopt(argc, argv, "c:d:h:H:r:s:DeEflov")) != -1) {
 		switch (i) {
 		case 'c':
 			cols = (int) strtol(optarg, &eptr, 10);
@@ -163,6 +165,12 @@
 				usage();
 			}
 			break;
+		case 'e':
+			exif_display = 2;
+			break;
+		case 'E':
+			exif_display = 0;
+			break;
 		case 'f':
 			force = 1;
 			break;
@@ -172,6 +180,9 @@
 		case 'o':
 			rm_orphans = 0;
 			break;
+		case 'D':
+			show_descr = 1;
+			break;
 		case 'v':
 			version();
 			break;
@@ -353,7 +364,7 @@
 		qsort(imglist, imgcount, sizeof(struct imginfo), sort_func);
 		
 		create_html(dir, imglist, imgcount);
-		x = create_thumbindex(dir, imglist, imgcount);
+		x = create_thumbindex(dir, imglist, imgcount, show_descr);
 		printf("%d thumbnail index pages created.\n", x);
 	}
 	
@@ -1040,6 +1051,11 @@
 	    "(default: %d)\n", thumbheight);
 	fprintf(stderr, "   -H <j> ... height of the scaled images in pixel "
 	    "(default: %d)\n", scaleheight);
+	fprintf(stderr, "   -e     ... don't display exif data on the page, "
+	    "insert it in html comments\n");
+	fprintf(stderr, "   -E     ... don't display exif data at all\n");
+	fprintf(stderr, "   -D     ... display filename instead of size on "
+	     "index page\n");
 	fprintf(stderr, "   -f     ... force rebuild of everything; ignore "
 	    "cache\n");
 	fprintf(stderr, "   -o     ... don't remove orphaned files\n");
