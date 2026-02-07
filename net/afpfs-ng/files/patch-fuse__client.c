--- fuse/client.c.orig	2008-03-08 02:44:16.000000000 +0000
+++ fuse/client.c	2012-10-14 13:11:44.000000000 +0000
@@ -12,11 +12,11 @@
 #include <grp.h>
 
 #include "config.h"
-#include <afp.h>
+#include <afpfs-ng/afp.h>
 #include "afp_server.h"
-#include "uams_def.h"
-#include "map_def.h"
-#include "libafpclient.h"
+#include "afpfs-ng/uams_def.h"
+#include "afpfs-ng/map_def.h"
+#include "afpfs-ng/libafpclient.h"
 
 #define default_uam "Cleartxt Passwrd"
 
@@ -61,8 +61,9 @@
 			snprintf(filename, PATH_MAX,
 				"/usr/local/bin/%s",AFPFSD_FILENAME);
 			if (access(filename,X_OK)) {
-				snprintf(filename, "/usr/bin/%s",
+				snprintf(filename, sizeof(filename), "/usr/bin/%s",
 					AFPFSD_FILENAME);
+				filename[sizeof(filename) - 1] = 0;
 				if (access(filename,X_OK)) {
 					printf("Could not find server (%s)\n",
 						filename);
diff -Naur afpfs-ng-0.8.1.orig/fuse/commands.c afpfs-ng-0.8.1/fuse/commands.c
