--- panel-plugin/os.c.orig	2010-11-07 13:58:22.000000000 +0100
+++ panel-plugin/os.c	2011-12-31 17:30:16.000000000 +0100
@@ -134,28 +134,54 @@
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
-	gsize len = sizeof( cp_time );
+	glong *cp_time;
+	glong *cp_time1;
+	gint i;
+	unsigned int max_cpu;
+	gsize len = sizeof(max_cpu);
 
-	if( sysctlbyname( "kern.cp_time", &cp_time, &len, NULL, 0 ) < 0 )
+	data[0].load = 0;
+	if (sysctlbyname("kern.smp.maxid", &max_cpu, &len, NULL, 0) < 0)
 		return FALSE;
+	
+	max_cpu++; /* max_cpu is 0-based */
+	if (max_cpu < nb_cpu)
+		return FALSE; /* should not happen */
+	len = sizeof(glong) * max_cpu * CPUSTATES;
+	cp_time = (glong *) g_malloc(len);
 
-	used = cp_time[CP_USER] + cp_time[CP_NICE] + cp_time[CP_SYS] + cp_time[CP_INTR];
-	total = used + cp_time[CP_IDLE];
-	if( (total - data[0].previous_total) != 0 )
-		data[0].load = (CPU_SCALE * (used - data[0].previous_used))/(total - data[0].previous_total);
-	else
-		data[0].load = 0;
-
-	data[0].previous_used = used;
-	data[0].previous_total = total;
+	if (sysctlbyname( "kern.cp_times", cp_time, &len, NULL, 0 ) < 0) {
+		g_free(cp_time);
+		return FALSE;
+	}
+	for (i = 1; i <= nb_cpu; i++ )
+	{
+		cp_time1 = &cp_time[CPUSTATES * (i - 1)];
+		used = cp_time1[CP_USER] + cp_time1[CP_NICE] + cp_time1[CP_SYS] + cp_time1[CP_INTR];
+		total = used + cp_time1[CP_IDLE];
+		if( (total - data[i].previous_total) != 0 )
+			data[i].load = (CPU_SCALE * (used - data[i].previous_used))/(total - data[i].previous_total);
+		else
+			data[i].load = 0;
 
+		data[i].previous_used = used;
+		data[i].previous_total = total;
+		data[0].load += data[i].load;
+	}
+	data[0].load /= nb_cpu;
+	g_free(cp_time);
 	return TRUE;
 }
 
