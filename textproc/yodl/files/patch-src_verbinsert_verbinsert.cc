--- src/verbinsert/verbinsert.cc.orig	2015-01-20 18:56:00.226610975 +0600
+++ src/verbinsert/verbinsert.cc	2015-01-20 18:56:46.890607566 +0600
@@ -2,6 +2,7 @@
 #include <fstream>
 #include <iomanip>
 #include <string>
+#include <cstdlib>
 #include <unistd.h>
 
 using namespace std;
@@ -37,19 +38,19 @@
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
