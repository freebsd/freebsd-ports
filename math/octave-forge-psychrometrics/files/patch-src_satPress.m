--- src/satPress.m.orig	2022-11-16 17:24:48 UTC
+++ src/satPress.m
@@ -18,7 +18,7 @@
 # It is also available at https://www.gnu.org/licenses/.
 
 function psat=satPress(Tdry)
-    c=load("constants.dat");
+    constants;
     if -100<=Tdry-273.15 & Tdry-273.15<0
         k=c(1)/Tdry+...
         c(2)+...
