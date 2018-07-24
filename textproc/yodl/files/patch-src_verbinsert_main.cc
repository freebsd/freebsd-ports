--- src/verbinsert/main.cc.orig	2018-07-22 13:07:15 UTC
+++ src/verbinsert/main.cc
@@ -2,6 +2,7 @@
 #include <fstream>
 #include <iomanip>
 #include <string>
+#include <cstdlib>
 #include <unistd.h>
 #include <regex>
 
@@ -43,19 +44,19 @@ int main(int argc, char **argv)
             continue;
 
             case 's':
-                indent.append(stoul(optarg), ' ');
+                indent.append(stoul(optarg, NULL, 0), ' ');
             continue;
 
             case 't':
-                indent.insert(0, stoul(optarg), '\t');
+                indent.insert(0, stoul(optarg, NULL, 0), '\t');
             continue;
 
             case 'S':
-                vindent.append(stoul(optarg), ' ');
+                vindent.append(stoul(optarg, NULL, 0), ' ');
             continue;
 
             case 'T':
-                vindent.insert(0, stoul(optarg), '\t');
+                vindent.insert(0, stoul(optarg, NULL, 0), '\t');
             continue;
 
             case 'N':
