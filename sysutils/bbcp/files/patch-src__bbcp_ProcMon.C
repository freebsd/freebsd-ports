--- src/bbcp_ProcMon.C.orig	2015-01-15 22:40:09.000000000 -0800
+++ src/bbcp_ProcMon.C	2015-01-15 22:41:33.000000000 -0800
@@ -132,7 +132,7 @@
 
 // Run a thread to start the monitor
 //
-   if (retc = bbcp_Thread_Run(bbcp_MonProc, (void *)this, &mytid))
+   if ((retc = bbcp_Thread_Run(bbcp_MonProc, (void *)this, &mytid)))
       {DEBUG("Error " <<retc <<" starting MonProc thread.");}
       else {DEBUG("Thread " <<mytid <<" monitoring process " <<monPID);}
    return;
@@ -154,7 +154,7 @@
 
 // Run a thread to start the monitor
 //
-   if (retc = bbcp_Thread_Run(bbcp_MonProc, (void *)this, &mytid))
+   if ((retc = bbcp_Thread_Run(bbcp_MonProc, (void *)this, &mytid)))
       {DEBUG("Error " <<retc <<" starting buffpool monitor thread.");}
       else {DEBUG("Thread " <<mytid <<" monitoring buffpool.");}
    return;
