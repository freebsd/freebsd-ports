--- gzip.cpp.orig	2013-10-06 17:11:38.000000000 +0400
+++ gzip.cpp	2013-10-06 17:12:35.000000000 +0400
@@ -0,0 +1,64 @@
+/* Copyright (C) 2007  John Whitney
+ *
+ * This program is free software; you can redistribute it and/or modify
+ * it under the terms of the GNU General Public License as published by
+ * the Free Software Foundation; version 2 of the License.
+ *
+ * This program is distributed in the hope that it will be useful,
+ * but WITHOUT ANY WARRANTY; without even the implied warranty of
+ * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+ * GNU General Public License for more details.
+ *
+ * Author: John Whitney <jjw@deltup.org>
+ */
+
+#include <string>
+#include <list>
+using namespace std;
+#include "file.h"
+#include "system.h"
+#include "tmpstore.h"
+#include "gzip.h"
+#include <stdio.h>
+#include <stdlib.h>
+
+int gzip_found = 0;
+char *gzip_name = NULL;
+
+void find_gzip_compressor() {
+  string tempfile = getTmpFilename();
+  string command = "find `echo $PATH | tr ':' ' '` -iname 'gzip' -exec sh -c 'echo {};{} -V 2>&1|grep ^gzip' \\; 2> /dev/null > "
+     + tempfile;
+
+  system(command.c_str());
+
+  FILE * fp;
+  char line[2*CHAR_MAX];
+  string fname;
+  fp = fopen(tempfile.c_str(), "r");
+  if (fp == NULL)
+       exit(EXIT_FAILURE);
+  while (fgets(line, 2*CHAR_MAX, fp)!=NULL) {
+       char *v = strstr(line, "gzip");       
+       if (v) {
+         int index=-1;
+        if (strncmp(v+5, "1.", 2) == 0) index=0;
+        if (index!=-1)
+        {
+          gzip_name = new char[fname.length()];
+          strncpy(gzip_name, fname.c_str(), fname.length()-1);
+          gzip_name[fname.length()-1] = 0;
+          break;
+        }
+       }
+      fname = line;
+  }
+  if (verbose) {
+    if (gzip_name!=NULL)
+    {
+      printf("found GNU gzip compressor/decompressor:\n");
+      printf("  %s\n", gzip_name);
+    } 
+    else printf("GNU gzip compressor/decompressor NOT found!\n");
+  }
+}
