--- src/comm.h.orig	Thu Dec 14 00:43:10 2000
+++ src/comm.h	Sat Sep 10 03:55:27 2005
@@ -11,7 +11,7 @@
 #define COMM_LEN sizeof(dummy.comm)
 extern struct task_struct dummy;
 #else
-#define COMM_LEN 16		/* synchronize with size of comm in struct task_struct in
+#define COMM_LEN 254		/* synchronize with size of comm in struct task_struct in
 				   /usr/include/linux/sched.h */
 #endif
 
