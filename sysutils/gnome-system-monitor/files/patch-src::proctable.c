--- src/proctable.c.orig	Sun Feb  8 10:06:08 2004
+++ src/proctable.c	Tue Apr 13 01:01:51 2004
@@ -547,6 +548,9 @@
 	glibtop_get_proc_uid (&procuid, pid);
 	glibtop_get_proc_time (&proctime, pid);
 	newcputime = proctime.utime + proctime.stime;
+	if (proctime.frequency) {
+		newcputime /= (proctime.frequency/100);
+	}
 	model = gtk_tree_view_get_model (GTK_TREE_VIEW (procdata->tree));
 
         wnck_pid_read_resource_usage (gdk_screen_get_display (gdk_screen_get_default ()),
@@ -651,6 +655,9 @@
 	glibtop_get_proc_uid (&procuid, pid);
 	glibtop_get_proc_time (&proctime, pid);
 	newcputime = proctime.utime + proctime.stime;
+	if (proctime.frequency) {
+		newcputime /= (proctime.frequency/100);
+	}
 
         wnck_pid_read_resource_usage (gdk_screen_get_display (gdk_screen_get_default ()),
                                       pid,
@@ -751,12 +758,20 @@
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
@@ -848,6 +863,9 @@
 	** should probably have a total_time_last gint in the ProcInfo structure */
 	glibtop_get_cpu (&cpu);
 	total_time = cpu.total - total_time_last;
+	if (cpu.frequency) {
+		total_time /= (cpu.frequency/100);
+	}
 	total_time_last = cpu.total;
 	
 	refresh_list (procdata, pid_list, n);
