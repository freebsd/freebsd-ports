--- common/arm/cpu-a.S.orig	2014-08-27 20:45:08 UTC
+++ common/arm/cpu-a.S
@@ -33,7 +33,7 @@
 function x264_cpu_neon_test
     vadd.i16    q0, q0, q0
     bx          lr
-.endfunc
+endfunc
 
 // return: 0 on success
 //         1 if counters were already enabled
@@ -49,14 +49,14 @@ function x264_cpu_enable_armv7_counter, 
     mov         r2, #1 << 31                // enable cycle counter
     mcr         p15, 0, r2, c9, c12, 1      // write CNTENS
     bx          lr
-.endfunc
+endfunc
 
 function x264_cpu_disable_armv7_counter, export=0
     mrc         p15, 0, r0, c9, c12, 0      // read PMNC
     bic         r0, r0, #1                  // disable counters
     mcr         p15, 0, r0, c9, c12, 0      // write PMNC
     bx          lr
-.endfunc
+endfunc
 
 
 .macro READ_TIME r
@@ -106,4 +106,4 @@ average_loop:
     cmp         r0, #10
     movgt       r0, #0
     pop         {r4-r6,pc}
-.endfunc
+endfunc
