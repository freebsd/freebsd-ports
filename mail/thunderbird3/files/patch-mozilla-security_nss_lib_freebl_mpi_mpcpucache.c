--- mozilla/security/nss/lib/freebl/mpi/mpcpucache.c.orig	2011-02-26 23:13:08.000000000 +0100
+++ mozilla/security/nss/lib/freebl/mpi/mpcpucache.c	2011-02-26 23:18:46.000000000 +0100
@@ -733,6 +733,32 @@
 #endif
 
 #if defined(__ppc64__) 
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
+       static int cacheline_size = 0;
+       static int cachemib[] = { CTL_MACHDEP, CPU_CACHELINE };
+       int clen;
+
+       if (cacheline_size > 0)
+               return cacheline_size;
+
+       clen = sizeof(cacheline_size);
+       if (sysctl(cachemib, sizeof(cachemib) / sizeof(cachemib[0]),
+           &cacheline_size, &clen, NULL, 0) < 0 || !cacheline_size)
+               return 128; /* guess */
+
+       return cacheline_size;
+}
+#else /* __FreeBSD__ */
+
 /*
  *  Sigh, The PPC has some really nice features to help us determine cache
  *  size, since it had lots of direct control functions to do so. The POWER
@@ -786,6 +812,7 @@
     return 0;
 }
 
+#endif /* __FreeBSD__ */
 #define MPI_GET_PROCESSOR_LINE_SIZE_DEFINED 1
 #endif
 
