--- src/proctable.c.orig	Sat Jun  7 04:35:32 2003
+++ src/proctable.c	Thu Sep  4 16:29:18 2003
@@ -539,6 +539,9 @@
 	glibtop_get_proc_uid (&procuid, pid);
 	glibtop_get_proc_time (&proctime, pid);
 	newcputime = proctime.utime + proctime.stime;
+	if (proctime.frequency) {
+		newcputime /= (proctime.frequency/100);
+	}
 	model = gtk_tree_view_get_model (GTK_TREE_VIEW (procdata->tree));
 
 	info->mem = procmem.size;
@@ -620,6 +623,9 @@
 	glibtop_get_proc_uid (&procuid, pid);
 	glibtop_get_proc_time (&proctime, pid);
 	newcputime = proctime.utime + proctime.stime;
+	if (proctime.frequency) {
+		newcputime /= (proctime.frequency/100);
+	}
 
 	arguments = glibtop_get_proc_args (&procargs, pid, 0);	
 	get_process_name (procdata, info, procstate.cmd, arguments);
@@ -709,12 +715,20 @@
 	return NULL;
 }
 
+static int
+pid_compare(const void* first, const void* second)
+{
+  return *(unsigned*)first - *(unsigned*)second;
+}
+
 static void
 refresh_list (ProcData *data, unsigned *pid_list, gint n)
 {
 	ProcData *procdata = data;
 	GList *list = procdata->info;
 	gint i = 0;
+
+	qsort(pid_list, n, sizeof (*pid_list), pid_compare);
 	
 	while (i < n)
 	{
@@ -812,6 +826,9 @@
 	** should probably have a total_time_last gint in the ProcInfo structure */
 	glibtop_get_cpu (&cpu);
 	total_time = cpu.total - total_time_last;
+	if (cpu.frequency) {
+		total_time /= (cpu.frequency/100);
+	}
 	total_time_last = cpu.total;
 	
 	refresh_list (procdata, pid_list, n);
