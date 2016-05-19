--- plugin/status.cpp.orig	2012-09-09 23:00:32 UTC
+++ plugin/status.cpp
@@ -6,6 +6,12 @@
  */
 
 #include <signal.h>
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#include <sys/user.h>
+#include <sys/vmmeter.h>
+#endif
 
 #include "status.h"
 
@@ -135,7 +141,12 @@ bool cStatusMarkAd::LogoExists(const cha
     cTimer *timer=NULL;
     for (cTimer *Timer = Timers.First(); Timer; Timer=Timers.Next(Timer))
     {
+#if 1
+        if (Timer->Recording() &&
+	    (!strcmp(Timer->ToDescr(),Name) || !strcmp(Timer->File(),Name)))
+#else
         if (Timer->Recording() && (!strcmp(Timer->ToDescr(),Name)))
+#endif
         {
             timer=Timer;
             break;
@@ -150,6 +161,16 @@ bool cStatusMarkAd::LogoExists(const cha
     if (!chan) return false;
     char *cname=strdup(chan->Name());
     if (!cname) return false;
+#if 1
+    int len = strlen(cname);
+    if (len > 5 &&
+        (!strcmp(cname + len - 4, " (A)") ||
+         !strcmp(cname + len - 4, " (C)") ||
+         !strcmp(cname + len - 4, " (S)") ||
+         !strcmp(cname + len - 4, " (T)") ||
+         !strcmp(cname + len - 4, " (I)")))
+        cname[len - 4] = '\0';
+#endif
     for (int i=0; i<(int) strlen(cname); i++)
     {
         if (cname[i]==' ') cname[i]='_';
@@ -233,6 +254,7 @@ bool cStatusMarkAd::getStatus(int Positi
     if (Position<0) return false;
     if (!recs[Position].Pid) return false;
     int ret=0;
+#ifndef __FreeBSD__
     char procname[256]="";
     snprintf(procname,sizeof(procname),"/proc/%i/stat",recs[Position].Pid);
     FILE *fstat=fopen(procname,"r");
@@ -252,6 +274,59 @@ bool cStatusMarkAd::getStatus(int Positi
         }
     }
     return (ret==1);
+#else
+    int mib[4] = {CTL_KERN, KERN_PROC, KERN_PROC_PID, recs[Position].Pid};
+    size_t len = 0;
+    struct kinfo_proc *kipp = NULL;
+    if (sysctl(mib, sizeof(mib)/sizeof(*mib), NULL, &len, NULL, 0) >= 0 &&
+        (kipp = (kinfo_proc *)malloc(len)) != NULL &&
+        sysctl(mib, sizeof(mib)/sizeof(*mib), kipp, &len, NULL, 0) >= 0 &&
+        len == sizeof(*kipp) && kipp->ki_structsize == sizeof(*kipp) &&
+        kipp->ki_pid == recs[Position].Pid) {
+
+        int tdflags = kipp->ki_tdflags;  /* XXXKSE */
+
+        ret = 1;
+
+        switch (kipp->ki_stat) {
+
+        case SSTOP:
+            recs[Position].Status = 'T';
+            break;
+
+        case SSLEEP:
+            if (tdflags & TDF_SINTR)        /* interruptable (long) */
+                recs[Position].Status = /* kipp->ki_slptime >= MAXSLP ? 'I' : */ 'S';
+            else
+                recs[Position].Status = 'D';
+            break;
+
+        case SRUN:
+        case SIDL:
+            recs[Position].Status = 'R';
+            break;
+
+        case SWAIT:
+            recs[Position].Status = 'W';
+            break;
+
+        case SLOCK:
+            recs[Position].Status = 'L';
+            break;
+
+        case SZOMB:
+            recs[Position].Status = 'Z';
+            break;
+
+        default:
+            recs[Position].Status = '?';
+        }
+    } else {
+        Remove(Position);
+    }
+    free(kipp);
+    return ret;
+#endif
 }
 
 bool cStatusMarkAd::getPid(int Position)
