--- pci.cpp.orig	2016-04-20 10:01:09 UTC
+++ pci.cpp
@@ -20,6 +20,7 @@ THIS SOFTWARE IS PROVIDED BY THE COPYRIG
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
+#include <strings.h> // for bzero()
 #include "pci.h"
 
 #ifndef _MSC_VER
