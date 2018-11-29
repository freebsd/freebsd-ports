--- src/freebsd.cc.orig	2018-11-28 18:50:47 UTC
+++ src/freebsd.cc
@@ -78,7 +78,7 @@ std::mutex kvm_proc_mutex;
 __attribute__((gnu_inline)) inline void
 proc_find_top(struct process **cpu, struct process **mem, struct process **time);
 
-static short cpu_setup = 0;
+static short conky_cpu_setup = 0;
 
 static int getsysctl(const char *name, void *ptr, size_t len)
 {
@@ -338,9 +338,9 @@ int update_cpu_usage(void)
 	extern void* global_cpu;
 
 	/* add check for !info.cpu_usage since that mem is freed on a SIGUSR1 */
-	if ((cpu_setup == 0) || (!info.cpu_usage)) {
+	if ((conky_cpu_setup == 0) || (!info.cpu_usage)) {
 		get_cpu_count();
-		cpu_setup = 1;
+		conky_cpu_setup = 1;
 	}
 
 	if (!global_cpu) {
