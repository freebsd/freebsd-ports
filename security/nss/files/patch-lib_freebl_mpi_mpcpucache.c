--- lib/freebl/mpi/mpcpucache.c.orig	2018-08-31 12:55:53 UTC
+++ lib/freebl/mpi/mpcpucache.c
@@ -705,6 +705,32 @@ s_mpi_getProcessorLineSize()
 #endif
 
 #if defined(__ppc64__)
+
+#if defined(__FreeBSD__)
+#include <sys/stddef.h>
+#include <sys/sysctl.h>
+
+#include <machine/cpu.h>
+#include <machine/md_var.h>
+
+unsigned long
+s_mpi_getProcessorLineSize()
+{
+	static int cacheline_size = 0;
+	static int cachemib[] = { CTL_MACHDEP, CPU_CACHELINE };
+	size_t clen;
+	
+	if (cacheline_size > 0)
+		return cacheline_size;
+
+	clen = sizeof(cacheline_size);
+	if (sysctl(cachemib, sizeof(cachemib) / sizeof(cachemib[0]),
+	    &cacheline_size, &clen, NULL, 0) < 0 || !cacheline_size)
+		return 128; /* guess */
+
+	return cacheline_size;
+}
+#else
 /*
  *  Sigh, The PPC has some really nice features to help us determine cache
  *  size, since it had lots of direct control functions to do so. The POWER
@@ -758,6 +784,7 @@ s_mpi_getProcessorLineSize()
     }
     return 0;
 }
+#endif
 
 #define MPI_GET_PROCESSOR_LINE_SIZE_DEFINED 1
 #endif
