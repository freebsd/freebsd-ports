--- rkward/rbackend/rthread.cpp.orig	2008-11-21 16:31:14.000000000 +0100
+++ rkward/rbackend/rthread.cpp	2009-05-06 23:40:25.000000000 +0200
@@ -33,6 +33,7 @@
 #include <QDBusConnection>
 #include <QList>
 
+#include <pthread.h>
 #include <signal.h>		// needed for pthread_kill
 
 #define MAX_BUF_LENGTH 4000
