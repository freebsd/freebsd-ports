--- Modules/SharedHeaders/OVFileHandler.h.orig	Tue Feb 14 00:18:36 2006
+++ Modules/SharedHeaders/OVFileHandler.h	Mon Mar 20 16:19:33 2006
@@ -36,9 +36,9 @@
 #include <fstream>
 
 #ifndef WIN32
+	#include <sys/types.h>
 	#include <sys/mman.h>
 	#include <sys/stat.h>
-	#include <sys/types.h>
 	#include <stdio.h>
 	#include <fcntl.h>
 	#include <unistd.h>
