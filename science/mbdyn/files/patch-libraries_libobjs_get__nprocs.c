--- libraries/libobjs/get_nprocs.c.orig	2021-04-22 19:18:04 UTC
+++ libraries/libobjs/get_nprocs.c
@@ -39,10 +39,28 @@
 
 #ifndef HAVE_GET_NPROCS
 
+#if defined(__FreeBSD__)
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#include <stdio.h>
+#include <stdlib.h>
+#endif
+
 /* GNU libc */
 int
 get_nprocs(void)
 {
+#if defined(__FreeBSD__)
+	static int name[2] = {CTL_HW, HW_NCPU};
+	int32_t ncpu;
+	size_t size = sizeof(ncpu);
+	if (sysctl(name, sizeof(name)/sizeof(*name), &ncpu, &size, NULL, 0)) {
+		perror("unable to determine number of CPUs");
+		abort();
+	}
+	return (int)ncpu;
+
+#else
 #warning "pippero!!!"
 #if defined(_SC_NPROCESSORS_ONLN)
 	/* POSIX.1. */
@@ -65,6 +83,7 @@ get_nprocs(void)
 #endif
 	/* we assume that there is at least one :) */
 	return 1;
+#endif
 }
 
 #endif /* HAVE_GET_NPROCS */
