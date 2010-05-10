--- src/gpm-load.c.orig	2010-01-01 23:29:11.000000000 -0500
+++ src/gpm-load.c	2010-01-01 23:46:31.000000000 -0500
@@ -33,6 +33,10 @@
 #include <kstat.h>
 #include <sys/sysinfo.h>
 #endif
+#if defined(__FreeBSD__)
+#include <sys/resource.h>
+#include <sys/sysctl.h>
+#endif
 #ifdef HAVE_UNISTD_H
 #include <unistd.h>
 #endif /* HAVE_UNISTD_H */
@@ -151,6 +155,32 @@ out:
 	return FALSE;
 }
 
+#elif defined(__FreeBSD__)
+
+/**
+ * gpm_load_get_cpu_values:
+ * @cpu_idle: The idle time reported by the CPU
+ * @cpu_total: The total time reported by the CPU
+ * Return value: Success of reading of the kern.cp_time sysctl.
+ **/
+static gboolean
+gpm_load_get_cpu_values (long unsigned *cpu_idle, long unsigned *cpu_total)
+{
+	long cpts[CPUSTATES];
+	size_t length;
+
+	length = sizeof (cpts);
+	if (sysctlbyname ("kern.cp_time", cpts, &length, NULL, 0)) {
+		return FALSE;
+	}
+
+	*cpu_idle = (unsigned long) cpts[CP_IDLE];
+	*cpu_total = (unsigned long) (cpts[CP_USER] + cpts[CP_NICE] + \
+			cpts[CP_SYS] + cpts[CP_IDLE] + cpts[CP_INTR]);
+
+	return TRUE;
+}
+
 #else
 
 /**
@@ -192,7 +222,7 @@ gpm_load_get_cpu_values (long unsigned *
 	*cpu_total = cpu_user + cpu_nice + cpu_system + *cpu_idle;
 	ret = TRUE;
 out:
-	if (!fd)
+	if (fd)
 		fclose (fd);
 	return ret;
 }
