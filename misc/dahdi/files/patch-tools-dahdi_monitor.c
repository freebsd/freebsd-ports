--- tools/dahdi_monitor.c.orig	2016-10-04 19:57:19.085982000 +0000
+++ tools/dahdi_monitor.c	2016-10-04 19:57:34.349843000 +0000
@@ -368,6 +368,7 @@
 
 	chan = atoi(argv[1]);
 
+	optind = 2;
 	while ((opt = getopt(argc, argv, "vmol:f:r:t:s:F:R:T:S:")) != -1) {
 		switch (opt) {
 		case '?':
