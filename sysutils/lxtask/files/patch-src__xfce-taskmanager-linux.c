--- ./src/xfce-taskmanager-linux.c.orig	2010-04-12 13:54:32.000000000 +0400
+++ ./src/xfce-taskmanager-linux.c	2010-09-25 23:50:53.956637695 +0400
@@ -28,6 +28,7 @@
 #include <glib/gi18n.h>
 #include "xfce-taskmanager-linux.h"
 
+#define PAGE_SIZE ( sysconf(_SC_PAGESIZE) )
 
 #if 1
 void get_task_details(gint pid,struct task *task)
@@ -39,7 +40,7 @@
 	task->checked=FALSE;
         task->size=0;
 
-	sprintf(line,"/proc/%d/statm",pid);
+	sprintf(line,"/compat/linux/proc/%d/statm",pid);
         fd=open(line,O_RDONLY);
         if(fd==-1) return;
         read(fd,line,256);
@@ -49,7 +50,7 @@
 	task->size*=PAGE_SIZE;
 	task->rss*=PAGE_SIZE;
 
-	sprintf(line,"/proc/%d/stat",pid);
+	sprintf(line,"/compat/linux/proc/%d/stat",pid);
 	fd=open(line,O_RDONLY);
 	if(fd!=-1)
 	{
@@ -118,8 +119,8 @@
     gchar filename[255];
     gchar cmdline_filename[255];
 
-    sprintf(filename, "/proc/%i/stat", pid);
-    sprintf(cmdline_filename, "/proc/%i/cmdline", pid);
+    sprintf(filename, "/compat/linux/proc/%i/stat", pid);
+    sprintf(cmdline_filename, "/compat/linux/proc/%i/cmdline", pid);
 
     stat(filename, &status);
 
@@ -235,9 +236,9 @@
     GArray *task_list;
     int count=0;
 
-    if((dir = opendir("/proc/")) == NULL)
+    if((dir = opendir("/compat/linux/proc/")) == NULL)
     {
-        fprintf(stderr, "Error: couldn't load the /proc directory\n");
+        fprintf(stderr, "Error: couldn't load the /compat/linux/proc directory\n");
         return NULL;
     }
 
@@ -277,7 +278,7 @@
 
 
     task_list = g_array_new(FALSE, FALSE, sizeof (struct task));
-    n=scandir("/proc",&namelist,proc_filter,0);
+    n=scandir("/compat/linux/proc",&namelist,proc_filter,0);
     if(n<0) return task_list;
 
     g_array_set_size(task_list,n);
@@ -299,7 +300,7 @@
 
 gboolean get_cpu_usage_from_proc(system_status *sys_stat)
 {
-    const gchar *file_name = "/proc/stat";
+    const gchar *file_name = "/compat/linux/proc/stat";
     FILE *file;
 
     if ( sys_stat->valid_proc_reading == TRUE ) {
@@ -340,7 +341,7 @@
     int reach;
     static int cpu_count;
 
-    file = fopen ("/proc/meminfo", "r");
+    file = fopen ("/compat/linux/proc/meminfo", "r");
     if(!file) return FALSE;
     reach=0;
     while (fgets (buffer, 100, file) != NULL)
@@ -357,7 +358,7 @@
 
     if(!cpu_count)
     {
-        file = fopen ("/proc/cpuinfo", "r");
+        file = fopen ("/compat/linux/proc/cpuinfo", "r");
         if(!file) return FALSE;
         while (fgets (buffer, 100, file) != NULL)
         {
