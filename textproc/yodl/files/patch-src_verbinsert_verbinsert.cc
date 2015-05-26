--- src/verbinsert/verbinsert.cc.orig	2014-09-23 19:16:48 UTC
+++ src/verbinsert/verbinsert.cc
@@ -2,6 +2,7 @@
 #include <fstream>
 #include <iomanip>
 #include <string>
+#include <cstdlib>
 #include <unistd.h>
 
 using namespace std;
@@ -37,19 +38,19 @@ int main(int argc, char **argv)
             continue;
 
             case 's':
-                indent.append(stoul(optarg), ' ');
+                indent.append(strtoul(optarg, NULL, 0), ' ');
             continue;
 
             case 't':
-                indent.insert(0, stoul(optarg), '\t');
+                indent.insert(0, strtoul(optarg, NULL, 0), '\t');
             continue;
 
             case 'S':
-                vindent.append(stoul(optarg), ' ');
+                vindent.append(strtoul(optarg, NULL, 0), ' ');
             continue;
 
             case 'T':
-                vindent.insert(0, stoul(optarg), '\t');
+                vindent.insert(0, strtoul(optarg, NULL, 0), '\t');
             continue;
 
             case 'N':
