--- Process.h.orig	2008-03-15 02:42:15.000000000 +0800
+++ Process.h	2008-07-16 12:52:37.000000000 +0800
@@ -31,7 +31,9 @@
 #include <pwd.h>
 #include <sched.h>
 
+#if 0
 #include <plpa.h>
+#endif
 
 // This works only with glibc 2.1+. On earlier versions
 // the behavior is similar to have a hardcoded page size.
@@ -166,9 +168,11 @@
 
 bool Process_setPriority(Process* this, int priority);
 
+#if 0
 unsigned long Process_getAffinity(Process* this);
 
 bool Process_setAffinity(Process* this, unsigned long mask);
+#endif
 
 void Process_sendSignal(Process* this, int signal);
 
