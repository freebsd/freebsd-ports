--- common/aarch64/quant-a.S.orig	2016-01-04 11:28:55.378084000 +0000
+++ common/aarch64/quant-a.S	2016-01-04 11:30:55.055050000 +0000
@@ -546,12 +546,10 @@
     sub         x0,  x0,  #2
 .endif
 .if         \size < 15
-    .equ        shiftw, 3
     ld1         {v0.8h}, [x0]
     uqxtn       v0.8b,  v0.8h
     cmtst       v0.8b,  v0.8b,  v0.8b
 .else
-    .equ        shiftw, 2
     ld1         {v0.8h,v1.8h}, [x0]
     uqxtn       v0.8b,  v0.8h
     uqxtn2      v0.16b, v1.8h
@@ -565,7 +563,7 @@
 
     coeff_level_run_start \size
 
-    coeff_level_run shiftw
+    coeff_level_run (4 - (\size + 1) / 8)
 
     ret
 endfunc
