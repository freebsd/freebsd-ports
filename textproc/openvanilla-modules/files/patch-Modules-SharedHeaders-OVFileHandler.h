--- Modules/SharedHeaders/OVFileHandler.h.orig	Mon May 14 14:23:35 2007
+++ Modules/SharedHeaders/OVFileHandler.h	Tue May 15 21:07:16 2007
@@ -43,9 +43,9 @@
     	HANDLE hMap;
 	} MmapHandles;
 #else
+	#include <sys/types.h>
 	#include <sys/mman.h>
 	#include <sys/stat.h>
-	#include <sys/types.h>
 	#include <stdio.h>
 	#include <fcntl.h>
 	#include <unistd.h>
