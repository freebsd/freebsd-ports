--- ascpu_x.c.orig	2009-12-23 12:38:21.000000000 +0300
+++ ascpu_x.c	2009-12-23 12:38:35.000000000 +0300
@@ -18,6 +18,12 @@
 #include <nlist.h>
 #include <fcntl.h>
 #include <kvm.h>
+#include <sys/types.h>
+#include <err.h>
+#include <string.h>
+#include <sys/resource.h>
+#include <sys/sysctl.h>
+#include <sys/wait.h>
 #endif
 
 #ifdef __hpux__
@@ -81,6 +87,8 @@ time_t last_time = 0;
 int update_request = 0;
 
 #ifdef	__FreeBSD__
+static int		cp_time_mib[2];
+static int		cp_times_mib[2];
 static kvm_t		*kd;
 static struct nlist	nlst[] = {
 	{"_cp_time"}, {0}
@@ -554,12 +562,45 @@ void read_stat()
 	memcpy(&last, &fresh, sizeof(last));
 
 #ifdef __FreeBSD__
-	if (kvm_read(kd, nlst[0].n_value, &fresh, sizeof(fresh)) != sizeof(fresh)) {
-		printf("ascpu : cannot read kvm\n");
-		exit(1);
+	if (state.cpu_number >= 0 && cp_times_mib[0] != 0) {
+		long cp_times[MAX_CPU][CPUSTATES];
+		size_t cp_times_len = sizeof(cp_times);
+		int error = sysctl(cp_times_mib, 2, cp_times, &cp_times_len, NULL, 0);
+		if (error) {
+			printf("ascpu: cannot sysctl cp_times\n");
+			exit(1);
+		}
+
+		long *cp_time = cp_times[state.cpu_number];
+		fresh.load[0] = cp_time[CP_USER];
+		fresh.load[1] = cp_time[CP_NICE];
+		fresh.load[2] = cp_time[CP_SYS] + cp_time[CP_INTR];
+		fresh.load[3] = cp_time[CP_IDLE];
+	} else if (state.cpu_number == -1 && cp_time_mib[0] != 0) {
+		long cp_time[CPUSTATES];
+		size_t cp_time_len = sizeof(cp_time);
+		int error = sysctl(cp_time_mib, 2, cp_time, &cp_time_len, NULL, 0);
+		if (error) {
+			printf("ascpu: cannot sysctl cp_time\n");
+			exit(1);
+		}
+
+		fresh.load[0] = cp_time[CP_USER];
+		fresh.load[1] = cp_time[CP_NICE];
+		fresh.load[2] = cp_time[CP_SYS] + cp_time[CP_INTR];
+		fresh.load[3] = cp_time[CP_IDLE];
+	} else {
+		if (nlst[0].n_type == 0) {
+			printf("ascpu : cannot get nlist\n");
+			exit(1);
+		}
+		if (kvm_read(kd, nlst[0].n_value, &fresh, sizeof(fresh)) != sizeof(fresh)) {
+			printf("ascpu : cannot read kvm\n");
+			exit(1);
+		}
+		/* compatible with Linux(overwrite 'interrupt' with 'idle' field) */
+		fresh.load[3] = fresh.load[4];
 	}
-	/* compatible with Linux(overwrite 'interrupt' with 'idle' field) */
-	fresh.load[3] = fresh.load[4];
 #endif
 
 #ifdef __hpux__
@@ -677,6 +718,12 @@ void ExecuteExternal()
 #ifdef DEBUG
 	printf("ascpu: system(%s)\n",Command);
 #endif
+
+	if (setgid(getgid()) != 0)
+		err(1, "Can't drop setgid privileges");
+	if (setuid(getuid()) != 0)
+		err(1, "Can't drop setuid privileges");
+
 	if( ! Command ) {
 		return;
 	}
@@ -1087,14 +1134,12 @@ void ascpu_initialize(
 		ascpu_cleanup();
 	}
 #ifdef	__FreeBSD__
-	if ((kd = kvm_open(NULL, NULL, NULL, O_RDONLY, "kvm_open")) == NULL) {
-		printf("ascpu : cannot open kvm\n");
-		exit(1);
-	}
-	kvm_nlist(kd, nlst);
-	if (nlst[0].n_type == 0) {
-		printf("ascpu : cannot get nlist\n");
-		exit(1);
+	size_t len = 2;
+	sysctlnametomib("kern.cp_times", cp_times_mib, &len);
+	len = 2;
+	sysctlnametomib("kern.cp_time", cp_time_mib, &len);
+	if ((kd = kvm_open(NULL, NULL, NULL, O_RDONLY, "kvm_open")) != NULL) {
+		kvm_nlist(kd, nlst);
 	}
 #endif
 
