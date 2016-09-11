--- ./helper_functions.c.orig	2012-09-11 08:15:54.000000000 +0200
+++ ./helper_functions.c	2015-04-05 20:52:59.850869370 +0200
@@ -30,6 +30,11 @@
 #include <inttypes.h>
 #include <sys/types.h>
 #include <sys/time.h>
+#ifdef __FreeBSD__
+#include <sys/cpuctl.h>
+#include <sys/ioctl.h>
+#include <sys/sysctl.h>
+#endif
 #include <time.h>
 #include <assert.h>
 #include <math.h>
@@ -45,6 +50,14 @@
 #define IA32_TEMPERATURE_TARGET 0x1a2
 #define IA32_PACKAGE_THERM_STATUS 0x1b1
 
+#ifdef __linux__
+#define	_DEV_CPU_MSR	"/dev/cpu/%d/msr"
+#define	_DEV_CPU0_MSR	"/dev/cpu/0/msr"
+#elif __FreeBSD__
+#define	_DEV_CPU_MSR	"/dev/cpuctl%d"
+#define	_DEV_CPU0_MSR	"/dev/cpuctl0"
+#endif
+
 int Get_Bits_Value(unsigned long val,int highbit, int lowbit){ 
 	unsigned long data = val;
 	int bits = highbit - lowbit + 1;
@@ -92,14 +105,22 @@
 static inline void cpuid (unsigned int info, unsigned int *eax, unsigned int *ebx,
                           unsigned int *ecx, unsigned int *edx)
 {
-    unsigned int _eax = info, _ebx, _ecx, _edx;
-    asm volatile ("mov %%ebx, %%edi;" // save ebx (for PIC)
-                  "cpuid;"
-                  "mov %%ebx, %%esi;" // pass to caller
-                  "mov %%edi, %%ebx;" // restore ebx
-                  :"+a" (_eax), "=S" (_ebx), "=c" (_ecx), "=d" (_edx)
-                  :      /* inputs: eax is handled above */
-                  :"edi" /* clobbers: we hit edi directly */);
+    unsigned int _eax, _ebx, _ecx, _edx;
+    asm volatile (
+#ifdef __i386__
+        "pushl %%ebx\n"    // save ebx (for PIC)
+#else // __x86_64__
+        "pushq %%rbx\n"    // save rbx (for PIC)
+#endif
+        "cpuid\n"
+        "mov %%ebx, %1\n"  // pass to caller
+#ifdef __i386__
+        "popl %%ebx\n"     // restore ebx
+#else // __x86_64__
+        "popq %%rbx\n"     // restore rbx
+#endif
+        :"=a" (_eax), "=r" (_ebx), "=c" (_ecx), "=d" (_edx)
+        :"0" (info));
     if (eax) *eax = _eax;
     if (ebx) *ebx = _ebx;
     if (ecx) *ecx = _ecx;
@@ -234,7 +255,7 @@
     int bits;
     *error_indx =0;
 
-    sprintf (msr_file_name, "/dev/cpu/%d/msr", cpu);
+    sprintf (msr_file_name, _DEV_CPU_MSR, cpu);
     fd = open (msr_file_name, O_RDONLY);
     if (fd < 0)
     {
@@ -255,11 +276,21 @@
         }
     }
 
+#ifdef __linux__
     if (pread (fd, &data, sizeof data, reg) != sizeof data)
     {
         perror ("rdmsr:pread");
         exit (127);
     }
+#elif __FreeBSD__
+    cpuctl_msr_args_t args;
+    args.msr = reg;
+    if (ioctl (fd, CPUCTL_RDMSR, &args) < 0) {
+        perror ("rdmsr:ioctl");
+        exit (127);
+    }
+    data = args.data;
+#endif
 
     close (fd);
 
@@ -287,7 +318,7 @@
     int fd;
     char msr_file_name[64];
 
-    sprintf (msr_file_name, "/dev/cpu/%d/msr", cpu);
+    sprintf (msr_file_name, _DEV_CPU_MSR, cpu);
     fd = open (msr_file_name, O_WRONLY);
     if (fd < 0)
     {
@@ -304,11 +335,21 @@
         }
     }
 
+#if __linux__
     if (pwrite (fd, &data, sizeof data, reg) != sizeof data)
     {
         perror ("wrmsr:pwrite");
         exit (127);
     }
+#elif __FreeBSD__
+    cpuctl_msr_args_t args;
+    args.msr = reg;
+    args.data = data;
+    if (ioctl (fd, CPUCTL_WRMSR, &args) < 0) {
+        perror ("wrmsr:ioctl");
+        exit (127);
+    }
+#endif
     close(fd);
     return(1);
 }
@@ -487,10 +528,10 @@
 void Test_Or_Make_MSR_DEVICE_FILES() 
 {
     //test if the msr file exists
-    if (access ("/dev/cpu/0/msr", F_OK) == 0)
+    if (access (_DEV_CPU0_MSR, F_OK) == 0)
     {
-        printf ("i7z DEBUG: msr device files exist /dev/cpu/*/msr\n");
-        if (access ("/dev/cpu/0/msr", W_OK) == 0)
+        printf ("i7z DEBUG: msr device files exist %s\n", _DEV_CPU0_MSR);
+        if (access (_DEV_CPU0_MSR, W_OK) == 0)
         {
             //a system mght have been set with msr allowable to be written
             //by a normal user so...
@@ -505,6 +546,7 @@
         printf ("i7z DEBUG: msr device files DONOT exist, trying out a makedev script\n");
         if (geteuid () == 0)
         {
+#ifdef __linux__
             //Try the Makedev script
             //sourced from MAKEDEV-cpuid-msr script in msr-tools
             system ("msr_major=202; \
@@ -519,6 +561,9 @@
 							");
             printf ("i7z DEBUG: modprobbing for msr\n");
             system ("modprobe msr");
+#elif __FreeBSD__
+            system ("kldload cpuctl");
+#endif
         } else {
             printf ("i7z DEBUG: You DONOT have root privileges, mknod to create device entries won't work out\n");
             printf ("i7z DEBUG: A solution is to run this program as root\n");
@@ -526,6 +571,7 @@
         }
     }
 }
+#ifdef __linux__
 double cpufreq_info()
 {
     //CPUINFO is wrong for i7 but correct for the number of physical and logical cores present
@@ -543,6 +589,21 @@
     fclose (tmp_file);
     return atof(tmp_str);
 }
+#elif __FreeBSD__
+double cpufreq_info()
+{
+    struct clockinfo clock;
+    size_t len;
+
+    len = sizeof(clock);
+    if (sysctlbyname ("hw.clockrate", &clock, &len, NULL, 0) == -1)
+    {
+        perror ("cpufreq_info:sysctl");
+        exit (127);
+    }
+    return (clock.hz);
+}
+#endif
 
 int check_and_return_processor(char*strinfo)
 {
@@ -669,6 +730,7 @@
     printf("Socket-%d [num of cpus %d physical %d logical %d] %s\n",socket->socket_num,socket->max_cpu,socket->num_physical_cores,socket->num_logical_cores,socket_list);
 }
 
+#ifdef __linux__
 void construct_CPU_Heirarchy_info(struct cpu_heirarchy_info* chi)
 {
     FILE *fp = fopen("/proc/cpuinfo","r");
@@ -715,7 +777,51 @@
     chi->max_online_cpu = it_processor_num+1;
     fclose(fp);
 }
+#elif __FreeBSD__
+void construct_CPU_Heirarchy_info(struct cpu_heirarchy_info* chi)
+{
+    int i;
+    FILE *fp = fopen("/var/run/dmesg.boot", "r");
+    char strinfo[200];
+    char *tmp;
+
+    int processor_num, physicalid_num = 0, coreid_num = 0;
+    int ncpu = 0, packages, cores, threads;
+
+    if (fp!=NULL) {
+        while ( fgets(strinfo,200,fp) != NULL) {
+            if (strstr(strinfo, "FreeBSD/SMP: ") != NULL) {
+                if ((tmp = strstr(strinfo, "Multiprocessor System Detected: ")) != NULL) {
+                    tmp = strchr(tmp, ':');
+                    tmp++; /* skip space */
+                    ncpu = atoi(tmp);
+                } else {
+                    tmp = strchr(strinfo, ' ');
+                    tmp++; /* skip space */
+                    packages = atoi(tmp);
+                    tmp = strchr(tmp, 'x');
+                    tmp++; /* skip space */
+                    cores = atoi(tmp);
+                    threads = ncpu / (packages * cores);
+                }
+            }
+        }
+        for (i = 0; i < ncpu; i++) {
+            processor_num = i;
+            if ((coreid_num + 1) == cores)
+                physicalid_num++;
+            physicalid_num %= packages;
+            coreid_num = processor_num % cores;
 
+            chi->processor_num[i] = processor_num;
+            chi->package_num[i] = physicalid_num;
+            chi->coreid_num[i] = coreid_num;
+        }
+    }
+    chi->max_online_cpu = ncpu;
+    fclose(fp);
+}
+#endif
 void print_CPU_Heirarchy(struct cpu_heirarchy_info chi)
 {
     int i;
