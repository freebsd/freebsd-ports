--- src/main.c.orig	2017-03-27 16:11:23 UTC
+++ src/main.c
@@ -9,6 +9,8 @@
 #include <stdlib.h>
 #include <string.h>
 #include <libgen.h>
+#include <limits.h>	/* for NAME_MAX, max bytes in a file name */
+#include <assert.h>	/* for assert() macro */
 
 #include "sha1.h"
 
@@ -23,7 +25,9 @@ int main(int argc, char** argv)
 
 	if (argc < 2)
 	{
-		printf("Usage: %s <file>\n", basename(argv[0]));
+assert (sizeof(buffer) >= NAME_MAX); /* reuse buffer[] for newly-POSIX-compliant, thread-safe basename() */
+		(void) strlcpy (buffer, argv[0], sizeof (buffer));
+		printf("Usage: %s <file>\n", basename(buffer));
 		return 1;
 	}
 
