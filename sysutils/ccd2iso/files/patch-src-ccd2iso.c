
$FreeBSD$

--- src/ccd2iso.c.orig	Thu Nov 13 06:43:41 2003
+++ src/ccd2iso.c	Thu Jun 24 15:31:04 2004
@@ -22,6 +22,7 @@
 #include <config.h>
 #endif
 
+#include <err.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <sys/stat.h>
@@ -47,7 +48,12 @@
 	}
 
 	src_file = fopen(argv[1], "r");
+	if (src_file == NULL)
+		err(1, "%s", argv[1]);
+
 	dst_file = fopen(argv[2], "w");
+	if (dst_file == NULL)
+		err(1, "%s", argv[2]);
 
 	stat(argv[1], &stat_file);
 	total_bytes = stat_file.st_size;
