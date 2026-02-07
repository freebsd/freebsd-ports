--- nrange.h	2004-05-29 16:00:08.000000000 -0700
+++ nrange.h	2008-03-02 23:03:02.000000000 -0800
@@ -25,6 +25,7 @@
 #include <sys/types.h>
 #include <map>
 #include <stdexcept>
+#include <limits.h>
 
 
 typedef map<ulong, ulong> t_rlist;//we are going to use high as the key, and low as the value
