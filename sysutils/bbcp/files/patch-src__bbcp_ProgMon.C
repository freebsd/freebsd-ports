--- src/bbcp_ProgMon.C.orig	2015-01-15 22:47:57.000000000 -0800
+++ src/bbcp_ProgMon.C	2015-01-15 22:49:27.000000000 -0800
@@ -146,7 +146,7 @@
 
 // Run a thread to start the monitor
 //
-   if (retc = bbcp_Thread_Run(bbcp_MonProg, (void *)this, &mytid))
+   if ((retc = bbcp_Thread_Run(bbcp_MonProg, (void *)this, &mytid)))
       {DEBUG("Error " <<retc <<" starting progress monitor thread.");}
       else {DEBUG("Thread " <<mytid <<" monitoring progress.");}
    return;
