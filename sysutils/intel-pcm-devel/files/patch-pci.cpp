--- pci.cpp.orig	2017-05-15 10:43:22 UTC
+++ pci.cpp
@@ -17,6 +17,7 @@ THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
 
 #include <iostream>
 #include <stdio.h>
+#include <strings.h> //for bzero
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
