--- freebsd/FreeBSDProcessList.c.orig	2016-02-13 00:37:56.160832000 +0800
+++ freebsd/FreeBSDProcessList.c	2016-02-13 00:38:19.671290000 +0800
@@ -477,8 +477,8 @@
       }
 
       // from FreeBSD source /src/usr.bin/top/machine.c
-      proc->m_size = kproc->ki_size / 1024;
-      proc->m_resident = kproc->ki_rssize * pageSizeKb;
+      proc->m_size = kproc->ki_size / 1024 / pageSizeKb;
+      proc->m_resident = kproc->ki_rssize;
       proc->nlwp = kproc->ki_numthreads;
       proc->time = (kproc->ki_runtime + 5000) / 10000;
 
