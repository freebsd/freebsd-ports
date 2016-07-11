--- src/shared.c.orig	2016-06-28 09:47:32 UTC
+++ src/shared.c
@@ -10,6 +10,11 @@
 #include <stdio.h>
 #endif
 
+#ifdef __FreeBSD__
+#include <stdio.h>
+#include <pthread_np.h>
+#endif
+
 #include <shared.h>
 #include <limits.h>
 
@@ -2382,7 +2387,7 @@ int tty_fix()
 }
 #endif
 
-#ifdef DARWIN
+#if defined(DARWIN) || defined(__FreeBSD__)
 static struct termios savemodes;
 static int havemodes = 0;
 
@@ -4371,6 +4376,23 @@ char *get_exec_path ()
 
   const int len = strlen (exec_path);
 
+  #elif __FreeBSD__
+
+  #include <sys/sysctl.h>
+
+  int mib[4];
+  mib[0] = CTL_KERN;
+  mib[1] = KERN_PROC;
+  mib[2] = KERN_PROC_PATHNAME;
+  mib[3] = -1;
+
+  char tmp[32] = { 0 };
+
+  size_t size = exec_path_len;
+  sysctl(mib, 4, exec_path, &size, NULL, 0);
+
+  const int len = readlink (tmp, exec_path, exec_path_len - 1);
+
   #else
   #error Your Operating System is not supported or detected
   #endif
@@ -4523,6 +4545,9 @@ void set_cpu_affinity (char *cpu_affinit
 {
   #ifdef _WIN
   DWORD_PTR aff_mask = 0;
+  #elif __FreeBSD__
+  cpuset_t cpuset;
+  CPU_ZERO (&cpuset);
   #elif _POSIX
   cpu_set_t cpuset;
   CPU_ZERO (&cpuset);
@@ -4570,6 +4595,9 @@ void set_cpu_affinity (char *cpu_affinit
   #ifdef _WIN
   SetProcessAffinityMask (GetCurrentProcess (), aff_mask);
   SetThreadAffinityMask (GetCurrentThread (), aff_mask);
+  #elif __FreeBSD__
+  pthread_t thread = pthread_self ();
+  pthread_setaffinity_np (thread, sizeof (cpuset_t), &cpuset);
   #elif _POSIX
   pthread_t thread = pthread_self ();
   pthread_setaffinity_np (thread, sizeof (cpu_set_t), &cpuset);
