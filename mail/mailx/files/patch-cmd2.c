--- cmd2.c	Sun Mar  8 04:46:25 1998
+++ cmd2.c	Tue Jun  4 20:59:44 2002
@@ -367,7 +367,7 @@
 core()
 {
 	int pid;
-	extern union wait wait_status;
+	extern int wait_status;
 
 	switch (pid = vfork()) {
 	case -1:
@@ -380,7 +380,7 @@
 	printf("Okie dokie");
 	fflush(stdout);
 	wait_child(pid);
-	if (wait_status.w_coredump)
+	if (WCOREDUMP(wait_status))
 		printf(" -- Core dumped.\n");
 	else
 		printf(" -- Can't dump core.\n");
