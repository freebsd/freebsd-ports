--- Process.c.orig	2008-03-15 02:35:05.000000000 +0800
+++ Process.c	2008-07-16 12:51:24.000000000 +0800
@@ -28,7 +28,9 @@
 #include <pwd.h>
 #include <sched.h>
 
+#if 0
 #include <plpa.h>
+#endif
 
 // This works only with glibc 2.1+. On earlier versions
 // the behavior is similar to have a hardcoded page size.
@@ -478,6 +480,7 @@
    return (err == 0);
 }
 
+#if 0
 unsigned long Process_getAffinity(Process* this) {
    unsigned long mask = 0;
    plpa_sched_getaffinity(this->pid, sizeof(unsigned long), (plpa_cpu_set_t*) &mask);
@@ -487,6 +490,7 @@
 bool Process_setAffinity(Process* this, unsigned long mask) {
    return (plpa_sched_setaffinity(this->pid, sizeof(unsigned long), (plpa_cpu_set_t*) &mask) == 0);
 }
+#endif
 
 void Process_sendSignal(Process* this, int signal) {
    kill(this->pid, signal);
