--- iflib/rdconfig.c.orig	1997-04-26 09:46:24 UTC
+++ iflib/rdconfig.c
@@ -5,6 +5,7 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <time.h>
+#include <unistd.h>
 #include "xutil.h"
 #include "lutil.h"
 #include "ftn.h"
@@ -402,8 +403,13 @@ char *arg;
 			verbose=setverbose(arg);
 			break;
 
-	case 'I':	configname=arg;
-			break;
+	case 'I':
+		if (issetugid())
+			fprintf(stderr,
+		    "readconfig: -I option ignored while running as set-user-ID\n");
+		else
+			configname=arg;
+		break;
 
 	default:	return 1; /* unrecognized option */
 
