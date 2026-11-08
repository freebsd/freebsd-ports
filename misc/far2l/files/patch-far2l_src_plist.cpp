--- far2l/src/plist.cpp.orig	2026-10-07 18:45:16 UTC
+++ far2l/src/plist.cpp
@@ -252,21 +252,21 @@ static void enumerateProcesses(std::vector<FarPidInfo>
 	}
 
 #elif defined(__OpenBSD__) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__HAIKU__)
-	int mib[4] = { CTL_KERN, KERN_PROC, KERN_PROC_ALL, 0 };
+	const int mib[] = { CTL_KERN, KERN_PROC, KERN_PROC_PROC };
 	struct kinfo_proc *procs = NULL;
 	size_t len = 0;
 
 	// First call: get required buffer size
-	if (sysctl(mib, 4, NULL, &len, NULL, 0) < 0) {
+	if (sysctl(mib, 3, NULL, &len, NULL, 0) < 0) {
 		perror("sysctl size");
 		return;
 	}
 
-	procs = malloc(len);
+	procs = static_cast<struct kinfo_proc *>(malloc(len));
 	if (!procs) return;
 
 	// Second call: retrieve process list
-	if (sysctl(mib, 4, procs, &len, NULL, 0) < 0) {
+	if (sysctl(mib, 3, procs, &len, NULL, 0) < 0) {
 		perror("sysctl data");
 		free(procs);
 		return;
