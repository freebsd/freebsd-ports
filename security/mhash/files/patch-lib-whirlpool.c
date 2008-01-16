diff -urN -x .svn ../../branches/vendor/mhash/lib/whirlpool.c ./lib/whirlpool.c
--- ../../branches/vendor/mhash/lib/whirlpool.c	2008-01-16 14:26:51.000000000 +0200
+++ ./lib/whirlpool.c	2008-01-16 15:13:06.000000000 +0200
@@ -883,10 +883,10 @@
  * Increment the block counter by step
  */
 #define INCCTR(cnt,step) do {        \
- if ((cnt[3] += (step)) < (step))    \
-   if (!(++cnt[2]))                  \
-     if (!(++cnt[1]))                \
-       if (!(++cnt[0]));             \
+ if (((cnt)[3] += (step)) < (step))    \
+   if (!(++(cnt)[2]))                  \
+     if (!(++(cnt)[1]))                \
+       if (!(++(cnt)[0]));             \
 } while(0);
 
 
