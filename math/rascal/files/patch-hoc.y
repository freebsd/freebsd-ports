--- hoc.y.orig	Tue May 14 06:09:26 2002
+++ hoc.y	Tue Dec  3 14:45:21 2002
@@ -38,6 +38,11 @@
 #include <math.h>
 #include <stdlib.h>
 #include <string.h>
+#include <stdio.h>
+extern "C" {
+#include <getopt.h>
+}
+
 int precis=8;
 
 void * set_string_input(char *);
@@ -517,7 +522,7 @@
             cout << " The content of given files and expressions will be treated as user input" << endl;
             cout << " in the order rc-file, given files, expressions." << endl;
             cout << endl;
-            cout << " The rc-file is searched in /etc/rascal.rc, /usr/local/bin/rascal.rc, rascal.rc" << endl;
+            cout << " The rc-file is searched in %%PREFIX%%/etc/rascal.rc, rascal.rc" << endl;
             return 0;
          case 'n':
             norc=1;
@@ -556,7 +561,7 @@
    }
 
    if(norc==0)
-      if(load("/etc/rascal.rc") && load("/usr/local/bin/rascal.rc") && load("rascal.rc"))
+      if(load("%%PREFIX%%/etc/rascal.rc") && load("rascal.rc"))
          ; // no rcfile found
 
    if(doeval!="")
