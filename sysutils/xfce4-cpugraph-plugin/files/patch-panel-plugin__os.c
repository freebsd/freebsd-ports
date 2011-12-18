--- panel-plugin/os.c.orig	2010-11-07 13:58:22.000000000 +0100
+++ panel-plugin/os.c	2011-12-18 13:52:22.000000000 +0100
@@ -134,28 +134,41 @@
 #elif defined (__FreeBSD__)
 guint detect_cpu_number()
 {
-	return 1;
+	static gint mib[] = {CTL_HW, HW_NCPU};
+	gint ncpu;
+	gsize len = sizeof( gint );
+	if( sysctl( mib, 2, &ncpu, &len, NULL, 0 ) < 0 )
+		return 0;
+	else
+		return ncpu;
 }
 
 gboolean read_cpu_data( CpuData *data, guint nb_cpu)
 {
 	glong used, total;
-	glong cp_time[CPUSTATES];
+	glong cp_time[CPUSTATES * nb_cpu];
+	glong *cp_time1;
 	gsize len = sizeof( cp_time );
+	gint i;
 
-	if( sysctlbyname( "kern.cp_time", &cp_time, &len, NULL, 0 ) < 0 )
+	data[0].load = 0;
+	if( sysctlbyname( "kern.cp_times", &cp_time, &len, NULL, 0 ) < 0 )
 		return FALSE;
+	for (i = 1; i <= nb_cpu; i++ )
+	{
+		cp_time1 = cp_time + CPUSTATES * (i - 1);
+		used = cp_time1[CP_USER] + cp_time1[CP_NICE] + cp_time1[CP_SYS] + cp_time1[CP_INTR];
+		total = used + cp_time1[CP_IDLE];
+		if( (total - data[i].previous_total) != 0 )
+			data[i].load = (CPU_SCALE * (used - data[i].previous_used))/(total - data[i].previous_total);
+		else
+			data[i].load = 0;
 
-	used = cp_time[CP_USER] + cp_time[CP_NICE] + cp_time[CP_SYS] + cp_time[CP_INTR];
-	total = used + cp_time[CP_IDLE];
-	if( (total - data[0].previous_total) != 0 )
-		data[0].load = (CPU_SCALE * (used - data[0].previous_used))/(total - data[0].previous_total);
-	else
-		data[0].load = 0;
-
-	data[0].previous_used = used;
-	data[0].previous_total = total;
-
+		data[i].previous_used = used;
+		data[i].previous_total = total;
+		data[0].load += data[i].load;
+	}
+	data[0].load /= nb_cpu;
 	return TRUE;
 }
 
