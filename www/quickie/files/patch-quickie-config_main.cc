--- quickie-config/main.cc.orig	Sat May 20 23:56:52 2006
+++ quickie-config/main.cc	Thu May 25 12:57:25 2006
@@ -24,7 +24,13 @@
 #include <cstdio>
 #include <cstdlib>
 #include <unistd.h>
-#include <getopt.h>
+
+#ifdef __FreeBSD__
+//#  include <osreldate.h>
+//#  if __FreeBSD_version < 500041
+#    include <getopt.h>
+//#  endif
+#endif
 
 #include <configuration.h>
 #include <progname.h>
