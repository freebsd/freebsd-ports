--- vendor/intel/sfcsample/VDecAccelVA.cpp.orig	2019-02-01 23:11:33 UTC
+++ vendor/intel/sfcsample/VDecAccelVA.cpp
@@ -32,7 +32,9 @@
 #include <fcntl.h>
 #include <sys/mman.h>
 #include <sys/ioctl.h>
+#ifdef __linux__
 #include <linux/fb.h>
+#endif
 #include <stdio.h>
 #include <stdlib.h>
 #include <iostream>
