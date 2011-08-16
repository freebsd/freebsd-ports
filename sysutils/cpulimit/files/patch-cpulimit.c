--- ./cpulimit.c.orig	2011-08-12 19:35:36.000000000 -0300
+++ ./cpulimit.c	2011-08-12 21:31:58.000000000 -0300
@@ -35,6 +35,15 @@
 #include <limits.h>    // for compatibility
 
 
+#include <limits.h>
+#include <fcntl.h>
+#include <kvm.h>
+#include <paths.h>
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <sys/user.h>
+
+
 //kernel time resolution (inverse of one jiffy interval) in Hertz
 //i don't know how to detect it, then define to the default (not very clean!)
 #define HZ 100
@@ -245,6 +254,31 @@
 }
 
 //get jiffies count from /proc filesystem
+int getjiffies(int pid)
+{
+   kvm_t *my_kernel = NULL;
+   struct kinfo_proc *process_data = NULL;
+   int processes;
+   int my_jiffies = -1;
+
+   my_kernel = kvm_open(0, 0, 0, O_RDONLY, "kvm_open");
+   if (! my_kernel)
+   {
+      printf("Error opening kernel vm. You should be running as root.\n");
+      return -1;
+   }
+
+   process_data = kvm_getprocs(my_kernel, KERN_PROC_PID, pid, &processes);
+   if ( (process_data) && (processes >= 1) )
+       my_jiffies = process_data->ki_runtime;
+   
+   kvm_close(my_kernel);
+   if (my_jiffies >= 0)
+     my_jiffies /= 1000;
+   return my_jiffies;
+}
+
+/*
 int getjiffies(int pid) {
 	static char stat[20];
 	static char buffer[1024];
@@ -271,6 +305,8 @@
         // could not read info
         return -1;
 }
+*/
+
 
 //process instant photo
 struct process_screenshot {
