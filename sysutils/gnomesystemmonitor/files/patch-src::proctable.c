--- src/proctable.c.orig	Fri Jul 22 18:58:42 2005
+++ src/proctable.c	Mon Jul 25 22:25:58 2005
@@ -853,6 +853,12 @@ static void cb_exclude(ProcInfo* info, G
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
@@ -945,10 +951,15 @@ proctable_update_list (ProcData * const 
 
 	pid_list = glibtop_get_proclist (&proclist, which, arg);
 
+	qsort(pid_list, proclist.number, sizeof (*pid_list), pid_compare);
+
 	/* FIXME: total cpu time elapsed should be calculated on an individual basis here
 	** should probably have a total_time_last gint in the ProcInfo structure */
 	glibtop_get_cpu (&cpu);
 	total_time = MAX(cpu.total - total_time_last, 1);
+	if (cpu.frequency) {
+		total_time /= (cpu.frequency/100);
+	}
 	total_time_last = cpu.total;
 
 	refresh_list (procdata, pid_list, proclist.number);
