--- lout/misc.hh.orig	2024-05-04 04:01:21.000000000 -0700
+++ lout/misc.hh	2024-10-25 09:28:31.897945000 -0700
@@ -310,7 +310,7 @@
 template <class T> class NotSoSimpleVector
 {
 private:
-   T *arrayMain, *arrayExtra1, *arrayExtra2;
+   T *arrayMain, *arrayExtra, *arrayExtra1, *arrayExtra2;
    int numMain, numExtra, numAllocMain, numAllocExtra, startExtra;
 
    inline void resizeMain ()
