--- src/proctable.c.orig	Tue Nov 30 01:28:31 2004
+++ src/proctable.c	Wed Dec  1 13:25:55 2004
@@ -772,6 +772,12 @@
 
 
 
+static int
+pid_compare(const void* first, const void* second)
+{
+	return *(unsigned*)first - *(unsigned*)second;
+}
+
 static void
 refresh_list (ProcData *procdata, const unsigned *pid_list, const guint n)
 {
@@ -863,10 +869,15 @@
 
 	pid_list = glibtop_get_proclist (&proclist, which, arg);
 
+	qsort(pid_list, proclist.number, sizeof (*pid_list), pid_compare);
+
 	/* FIXME: total cpu time elapsed should be calculated on an individual basis here
 	** should probably have a total_time_last gint in the ProcInfo structure */
 	glibtop_get_cpu (&cpu);
 	total_time = cpu.total - total_time_last;
+	if (cpu.frequency) {
+		total_time /= (cpu.frequency/100);
+	}
 	total_time_last = cpu.total;
 
 	refresh_list (procdata, pid_list, proclist.number);
