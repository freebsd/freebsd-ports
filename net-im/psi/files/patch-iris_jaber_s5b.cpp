--- iris/jabber/s5b.cpp.orig	Fri Apr  8 09:22:20 2005
+++ iris/jabber/s5b.cpp	Fri Apr  8 09:22:48 2005
@@ -31,6 +31,7 @@
 #ifdef Q_OS_WIN
 # include <windows.h>
 #else
+# include <sys/types.h>
 # include <netinet/in.h>
 #endif
 
