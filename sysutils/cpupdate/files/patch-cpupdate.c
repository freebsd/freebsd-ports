--- cpupdate.c.orig	2018-03-20 04:24:53 UTC
+++ cpupdate.c
@@ -39,6 +39,8 @@ __FBSDID("$FreeBSD$");
 
 #include <sys/queue.h>
 #include <sys/param.h>
+#include <sys/linker.h>
+#include <sys/module.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <sys/ioctl.h>
@@ -99,6 +101,16 @@ usage( void)
   exit(EX_USAGE);
 }
 
+static int
+modload( const char *name)
+{
+	if (modfind(name) < 0)
+		if (kldload(name) < 0 || modfind(name) < 0) {
+			warn("%s: module not found", name);
+			return 0;
+		}
+	return 1;
+}
 
 static int 
 cpu_getCoreNum( void)
@@ -111,6 +123,7 @@ cpu_getCoreNum( void)
 	if (dirp == NULL) {
 		r = -1;
 	} else {
+		modload("cpuctl");
 		while ((direntry = readdir(dirp)) != NULL) {
 			if (direntry->d_namlen == 0)
 				continue;
@@ -466,7 +479,7 @@ main( int argc, char *argv[])
 #else
 					if (!r) {
 						INFO( 10, "No updating error.\n");
-						INFO( 10, "NOTICE: This FreeBSD version does not support registering new CPU features!\n", numCores);
+						INFO( 10, "NOTICE: This FreeBSD version does not support registering new CPU features!\n");
 						handler->freeucodeinfo( &cpupbuf);
 					}
 #endif
