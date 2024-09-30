--- copytape.c.orig
+++ copytape.c
@@ -28,15 +28,18 @@
  */
 
 
-#include <stdio.h>
 #include <sys/types.h>
 #include <sys/ioctl.h>
 #include <sys/mtio.h>
 #include <sys/file.h>
 
-extern int      errno;
+#include <errno.h>
+#include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+#include <unistd.h>
 
-#define BUFLEN		262144	/* max tape block size */
+#define BUFLEN		(1024*1024)	/* max tape block size */
 #define TAPE_MARK	-100	/* return record length if we read a
 				 * tape mark */
 #define END_OF_TAPE	-101	/* 2 consecutive tape marks */
@@ -149,7 +152,7 @@
 	    len = input(from);
 	} while (len > 0);
 	if (len == FORMAT_ERROR) {
-	    perror(stderr, "copytape: format error on skip");
+	    perror("copytape: format error on skip");
 	    exit(-1);
 	};
 	if (len == END_OF_TAPE) {
