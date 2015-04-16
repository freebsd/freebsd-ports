--- gracetmpldemo.cpp.orig	2003-03-04 10:32:45 UTC
+++ gracetmpldemo.cpp
@@ -3,11 +3,13 @@ extern "C" {
 #include <stdlib.h>
 #include <stdio.h>
 #include <getopt.h>
+#include <sys/syslimits.h>
 }
 #include <iostream>
 #include <string>
 #include <vector>
 #include <map>
+#include <cstring>
 
 #include "gracetmpl.h"
 
