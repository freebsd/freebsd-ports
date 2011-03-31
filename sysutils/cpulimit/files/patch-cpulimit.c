--- cpulimit.c.orig	2010-08-20 19:35:15.000000000 -0300
+++ cpulimit.c	2010-08-21 14:17:52.000000000 -0300
@@ -43,6 +43,15 @@
 #include <errno.h>
 #include <string.h>
 
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
@@ -235,6 +244,31 @@
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
@@ -255,6 +289,8 @@
 	int ktime=atoi(p+1);
 	return utime+ktime;
 }
+*/
+
 
 //process instant photo
 struct process_screenshot {
