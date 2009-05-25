Index: libcpupowerd.c
diff -u -p libcpupowerd.c.orig libcpupowerd.c
--- libcpupowerd.c.orig	2009-01-01 22:05:10.000000000 +0900
+++ libcpupowerd.c	2009-05-24 16:16:35.182882907 +0900
@@ -34,7 +34,8 @@
 #include <sys/sysctl.h>
 #ifdef __FreeBSD__
 #include <sys/param.h>
-#if __FreeBSD_version < 800042
+#if (__FreeBSD_version < 800042 && __FreeBSD_version >= 800000) ||	\
+	__FreeBSD_version < 701102
 #include <cpu.h>
 #define RDMSR			CPU_RDMSR
 #define WRMSR			CPU_WRMSR
@@ -627,7 +628,8 @@ static int libcpupowerd_get_interfacefil
 static int libcpupowerd_read_msr_ioctl(char *msrfile, unsigned long index, unsigned long long *msrvalue)
 {
   	int fd;
-	#if __FreeBSD_version < 800042
+	#if (__FreeBSD_version < 800042 && __FreeBSD_version >= 800000) || \
+		__FreeBSD_version < 701102
  	cpu_msr_args_t args;
 	#else
 	cpuctl_msr_args_t args;
@@ -663,7 +665,8 @@ static int libcpupowerd_read_msr_ioctl(c
 static int libcpupowerd_write_msr_ioctl(char *msrfile, unsigned long index, unsigned long long *msrvalue)
 {
 	int fd;
-	#if __FreeBSD_version < 800042
+	#if (__FreeBSD_version < 800042 && __FreeBSD_version >= 800000) || \
+		__FreeBSD_version < 701102
  	cpu_msr_args_t args;
 	#else
 	cpuctl_msr_args_t args;
@@ -698,7 +701,8 @@ static int libcpupowerd_write_msr_ioctl(
 static int libcpupowerd_read_cpuid_ioctl(char *cpuidfile, unsigned long index, unsigned long *eax, unsigned long *ebx, unsigned long *ecx, unsigned long *edx)
 {
   	int fd;
-	#if __FreeBSD_version < 800042
+	#if (__FreeBSD_version < 800042 && __FreeBSD_version >= 800000) || \
+		__FreeBSD_version < 701102
  	cpu_cpuid_args_t args;
 	#else
 	cpuctl_cpuid_args_t args;
