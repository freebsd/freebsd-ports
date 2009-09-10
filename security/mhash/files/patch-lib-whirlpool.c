Description: Protect some macro parameters with parentheses.
Author: Peter Pentchev <roam@FreeBSD.org>
Forwarded: http://sourceforge.net/mailarchive/message.php?msg_name=20090910102100.GA26539%40straylight.m.ringlet.net
Last-Update: 2009-09-10

--- lib/whirlpool.c.orig
+++ lib/whirlpool.c
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
 
 
