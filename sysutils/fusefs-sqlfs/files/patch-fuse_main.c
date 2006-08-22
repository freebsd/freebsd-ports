--- fuse_main.c.orig	Sat Aug 12 01:46:18 2006
+++ fuse_main.c	Sat Aug 19 16:18:02 2006
@@ -17,12 +17,52 @@
 
 *****************************************************************************/
 
+#include <stdlib.h>
+#include <stdio.h>
+#include <sysexits.h>
 #include "sqlfs.h"
 
+void usage() __dead2;
+
+void usage()
+{
+	fprintf(stderr, "Usage: %s -o dbname [-h]\n", getprogname());
+
+	exit(EX_USAGE);
+}
 
 int main(int argc, char **argv)
 {
-    sqlfs_init("/tmp/fsdata");
+	char c;
+	int ret;
+	char *dbname = NULL;
+	
+	while ((c = getopt(argc, argv, "o:h")) != -1)
+		switch (c) {
+		case 'o':
+			dbname = optarg;
+			break;
+		case 'h':
+			/* FALLTHROUGH */
+		default:
+			usage();
+			/* NOTREACHED */
+		}
+		argc -= optind;
+		argv += optind;
+
+	if (dbname == NULL)
+		dbname = getenv("SQLFS_DBNAME");
+
+	if (dbname == NULL)
+		usage();
+	/* NOTREACHED */
+
+	ret = sqlfs_init(dbname);
+	if (ret != 0)
+		return ret;
    
-    return sqlfs_fuse_main(argc, argv);
+	ret = sqlfs_fuse_main(argc, argv);
+	
+	return ret;
 }
