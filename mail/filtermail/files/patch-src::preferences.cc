--- src/preferences.cc.orig	Sat Nov 20 23:39:15 2004
+++ src/preferences.cc	Mon Mar  7 22:58:20 2005
@@ -35,7 +35,7 @@
 
 extern "C"
 {
-#include <wordexp.h>
+#include <glob.h>
 #include <sys/types.h>
 #include <regex.h>
 }
@@ -233,15 +233,15 @@
 void Preferences :: set_headers_file (const char* name)
 {
   // Expand the given file name.
-  wordexp_t result;
-  if (wordexp (name, &result, 0) == 0)
-    headers_file_name = result.we_wordv[0];
+  glob_t result;
+  if (glob (name, 0, NULL, &result) == 0)
+    headers_file_name = result.gl_pathv[0];
   else
     {
       ERROR_MSG(_("Invalid file name: ") + (string)name + ".");
       exit (-1);
     }
-  wordfree (&result);
+  globfree (&result);
 }
 
 string Preferences :: headers_file (void)
@@ -259,15 +259,15 @@
   // command line.
   if (log_file_name.length () == 0)
     {
-      wordexp_t result;
-      if (wordexp (name, &result, 0) == 0)
-	log_file_name = result.we_wordv[0];
+      glob_t result;
+      if (glob (name, 0, NULL, &result) == 0)
+	log_file_name = result.gl_pathv[0];
       else
 	{
 	  ERROR_MSG(_("Invalid file name: ") + (string)name + ".");
 	  exit (-1);
 	}
-      wordfree (&result);
+      globfree (&result);
     }
 }
 
