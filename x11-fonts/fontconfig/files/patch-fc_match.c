--- fc-match/fc-match.c.orig	Mon Dec  6 20:25:18 2004
+++ fc-match/fc-match.c	Fri Mar  9 17:26:55 2007
@@ -99,7 +99,7 @@
     int		c;
 
 #if HAVE_GETOPT_LONG
-    while ((c = getopt_long (argc, argv, "Vv?", longopts, NULL)) != -1)
+    while ((c = getopt_long (argc, argv, "sVv?", longopts, NULL)) != -1)
 #else
     while ((c = getopt (argc, argv, "sVv?")) != -1)
 #endif
