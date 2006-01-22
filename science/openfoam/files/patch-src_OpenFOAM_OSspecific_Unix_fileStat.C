--- src/OpenFOAM/OSspecific/Unix/fileStat.C.orig	Tue Jun 21 18:06:05 2005
+++ src/OpenFOAM/OSspecific/Unix/fileStat.C	Sun Dec 18 14:59:12 2005
@@ -33,7 +33,6 @@
 
 #include <signal.h>
 #include <unistd.h>
-#include <sys/sysmacros.h>
 
 /*
 #undef major
