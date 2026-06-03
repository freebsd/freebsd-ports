--- src/agent/subagents/freebsd/proc.cpp.orig	2026-04-16 16:23:19 UTC
+++ src/agent/subagents/freebsd/proc.cpp
@@ -386,12 +386,12 @@ LONG H_ProcessTable(const TCHAR *cmd, const TCHAR *arg
          value->set(3, procs[i].ki_numthreads);
          // value->set(4, p->fd);
          // tv_sec are seconds, tv_usec are microseconds => converting both to milliseconds
-         value->set(5, procs[i].ki_rusage.ru_stime.tv_sec * 1000 + procs[i].ki_rusage.ru_stime.tv_usec / 1000);
-         value->set(6, procs[i].ki_rusage.ru_utime.tv_sec * 1000 + procs[i].ki_rusage.ru_utime.tv_usec / 1000);
+         value->set(5, (int64_t)procs[i].ki_rusage.ru_stime.tv_sec * 1000 + procs[i].ki_rusage.ru_stime.tv_usec / 1000);
+         value->set(6, (int64_t)procs[i].ki_rusage.ru_utime.tv_sec * 1000 + procs[i].ki_rusage.ru_utime.tv_usec / 1000);
          value->set(7, procs[i].ki_size);
          value->set(8, procs[i].ki_rssize * 1024);
          value->set(9, static_cast<double>(procs[i].ki_rssize * 10000 / totalMemory) / 100, 2);
-         value->set(10, procs[i].ki_rusage.ru_minflt + procs[i].ki_rusage.ru_majflt);
+         value->set(10, (int64_t)procs[i].ki_rusage.ru_minflt + procs[i].ki_rusage.ru_majflt);
          char cmdLine[MAX_CMD_LINE_LEN];
          if (ReadProcCmdLine(procs[i].ki_pid, cmdLine))
             value->set(11, cmdLine);
