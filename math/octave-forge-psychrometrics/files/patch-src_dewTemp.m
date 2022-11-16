--- src/dewTemp.m.orig	2022-11-16 17:24:42 UTC
+++ src/dewTemp.m
@@ -18,7 +18,7 @@
 # It is also available at https://www.gnu.org/licenses/.
 
 function Tdew=dewTemp(pw)
-    c=load("constants.dat");
+    constants;
     alpha=log(pw/1000);
     Tdew=c(14)+...
          c(15)*alpha+...
