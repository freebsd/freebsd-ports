--- src/setconst.f.org	Tue Jan  9 17:41:30 2007
+++ src/setconst.f	Tue Jan  9 17:41:42 2007
@@ -31,7 +31,7 @@
 
 c     set default lengths of integer and real constants and variables used
 
-      i8tmp1=2**31
+      i8tmp1=2**30
       i8tmp2=100000*i8tmp1
       i4tmp1=i8tmp2
       if (i4tmp1.eq.0) then
