--- cpp2latex/main.cpp.orig	Mon May 12 15:22:24 2003
+++ cpp2latex/main.cpp	Mon May 12 15:22:34 2003
@@ -25,7 +25,7 @@
 #include <fstream>
 #include <vector>
 #include <stdio.h>
-#include <getopt.h>
+#include <unistd.h>
 
 struct replace{
 	std::string voraus;
