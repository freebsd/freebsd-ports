--- src/proctable.c.orig	Wed Aug 30 14:11:01 2006
+++ src/proctable.c	Tue Oct 24 13:39:29 2006
@@ -923,6 +923,12 @@ static void cb_exclude(ProcInfo* info, G
 }
 
 
+static int
+pid_compare(const void* first, const void* second)
+{
+	return *(unsigned*)first - *(unsigned*)second;
+}
+
 static void
 refresh_list (ProcData *procdata, const unsigned *pid_list, const guint n)
 {
@@ -1015,10 +1021,16 @@ proctable_update_list (ProcData * const 
 
 	pid_list = glibtop_get_proclist (&proclist, which, arg);
 
+	qsort(pid_list, proclist.number, sizeof (*pid_list), pid_compare);
+
 	/* FIXME: total cpu time elapsed should be calculated on an individual basis here
 	** should probably have a total_time_last gint in the ProcInfo structure */
 	glibtop_get_cpu (&cpu);
-	total_time = MAX(cpu.total - total_time_last, 1);
+	total_time = cpu.total - total_time_last;
+	if (cpu.frequency) {
+		total_time /= (cpu.frequency/100);
+	}
+	total_time = MAX(total_time, 1);
 	total_time_last = cpu.total;
 
 	refresh_list (procdata, pid_list, proclist.number);
