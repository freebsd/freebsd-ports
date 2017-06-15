--- pci.cpp.orig	2016-10-31 10:26:34 UTC
+++ pci.cpp
@@ -17,6 +17,7 @@ THIS SOFTWARE IS PROVIDED BY THE COPYRIG
 
 #include <iostream>
 #include <stdio.h>
+#include <strings.h> //for bzero
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
