--- iiimsf/src/IMSignal.cpp.orig	Sat Oct 16 10:28:13 2004
+++ iiimsf/src/IMSignal.cpp	Sun Feb 20 18:43:18 2005
@@ -1,7 +1,11 @@
 #include <config.h>
 #include <sstream>
 #include <sys/types.h>
+#ifdef __FreeBSD__
+#include <sys/wait.h>
+#else
 #include <wait.h>
+#endif
 #include <unistd.h>
 #ifdef HAVE_SIGNAL
 #include <signal.h>
@@ -67,10 +71,8 @@
     stringstream s;
     string spid, signum;
 
-    s << getpid();
-    spid = s.str();
-    s << num;
-    signum = s.str();
+    s << getpid() << " " << num;
+    s >> spid >> signum;
 
     in_segv++;
 
