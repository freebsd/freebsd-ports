--- src/pipeline.cpp.orig	2009-02-12 20:44:18.000000000 +0000
+++ src/pipeline.cpp	2009-02-12 20:44:30.000000000 +0000
@@ -15,6 +15,7 @@
 #include <config.h>
 #include <stdio.h>
 #include <sys/types.h>
+#include <sys/stat.h>
 #include <unistd.h>
 #include <fcntl.h>
 #include <errno.h>
