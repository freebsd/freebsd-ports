--- ProcessList.c.orig	2014-10-19 02:09:17.000000000 +0800
+++ ProcessList.c	2014-10-19 02:11:07.000000000 +0800
@@ -804,8 +804,6 @@
       unsigned long long int lasttimes = (process->utime + process->stime);
       if (! ProcessList_readStatFile(process, dirname, name, command))
          goto errorReadingProcess;
-      if (this->flags & PROCESS_FLAG_IOPRIO)
-         Process_updateIOPriority(process);
       float percent_cpu = (process->utime + process->stime - lasttimes) / period * 100.0;
       process->percent_cpu = MAX(MIN(percent_cpu, cpus*100.0), 0.0);
       if (isnan(process->percent_cpu)) process->percent_cpu = 0.0;
