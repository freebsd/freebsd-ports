--- xsysstats.h.orig	2000-05-30 06:46:20 UTC
+++ xsysstats.h
@@ -15,12 +15,9 @@
 #include <stdio.h>
 #include <sys/param.h>
 
-#include <stdio.h>
-#include <sys/param.h>
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
-#include <malloc.h>
 #include <netdb.h>
 #include <rpcsvc/rstat.h>
 
@@ -115,8 +112,10 @@ struct graph_info {
 	short	host_offset;
 	short	window;		/* What window to put this graph in */
 	int	max_val;	/* maximum value this graph ever reached */
-} *graphs;
+};
 
+extern struct graph_info *graphs;
+
 struct Xss_Window {
 	short	x, y;		/* Upper left corner of window */
 	short	width,height;	/* width and height of the window.  height
@@ -138,7 +137,7 @@ struct Host_Info {
     char    *name;	/*Name of the host */
 #ifdef USE_NEW_RSTAT
     CLIENT  *client;	/* client connection for rstat */
-#endif USE_NEW_RSTAT
+#endif /* USE_NEW_RSTAT */
 };
 
 extern struct Xss_Window **windows;
