--- src/xfce-taskmanager-linux.c.orig	2019-01-13 13:25:38.000000000 -0800
+++ src/xfce-taskmanager-linux.c	2020-10-21 12:58:00.556146000 -0700
@@ -30,6 +30,8 @@
 #include "xfce-taskmanager-linux.h"
 /* #include <sys/sysinfo.h> */
 
+#define page_size ( sysconf(_SC_PAGESIZE) )
+
 void get_task_details(pid_t pid,struct task *task)
 {
 	int fd;
@@ -41,7 +43,7 @@
 	task->checked=FALSE;
 	task->size=0;
 
-	sprintf(line,"/proc/%d/statm",(int)pid);
+	sprintf(line,"/compat/linux/proc/%d/statm",(int)pid);
         fd=open(line,O_RDONLY);
         if(fd==-1) return;
         ret = read(fd,line,255);
@@ -57,7 +59,7 @@
 	task->size = t_size * page_size;
 	task->rss = t_rss * page_size;
 
-	sprintf(line,"/proc/%d/stat",(gint)pid);
+	sprintf(line,"/compat/linux/proc/%d/stat",(gint)pid);
 	fd=open(line,O_RDONLY);
 	if(fd!=-1)
 	{
@@ -98,7 +100,7 @@
 		if(show_full_path)
 		{
 			FILE *fp;
-			sprintf(line,"/proc/%d/cmdline",(int)pid);
+			sprintf(line,"/compat/linux/proc/%d/cmdline",(int)pid);
 			fp=fopen(line,"r");
 			if(fp)
 			{
@@ -124,7 +126,7 @@
 		else if(len>=15)
 		{
 			FILE *fp;
-			sprintf(line,"/proc/%d/cmdline",(int)pid);
+			sprintf(line,"/compat/linux/proc/%d/cmdline",(int)pid);
 			fp=fopen(line,"r");
 			if(fp)
 			{
@@ -169,7 +171,7 @@
 		task->time_percentage = 0;
 		task->ppid = ppid;
 
-		sprintf(line,"/proc/%d/task",(int)pid);
+		sprintf(line,"/compat/linux/proc/%d/task",(int)pid);
 		/* SF bug #843: /proc/%d/stat owned by UID instead of EUID */
 		if (stat(line,&st) < 0)
 			fstat(fd,&st);
