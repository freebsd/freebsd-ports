--- src/preferences.cc.orig	Sun Jan 25 21:56:46 2004
+++ src/preferences.cc	Fri Mar 19 23:16:27 2004
@@ -34,7 +34,7 @@
 #include "rcfile.hh"
 extern "C"
 {
-#include <wordexp.h>
+#include <glob.h>
 #include <sys/types.h>
 #include <regex.h>
 }
@@ -230,15 +230,15 @@
   void Preferences :: set_headers_file (const char* name)
   {
     // Expand the given file name.
-    wordexp_t result;
-    if (wordexp (name, &result, 0) == 0)
-      headers_file_name = result.we_wordv[0];
+    glob_t result;
+    if (glob (name, 0, NULL, &result) == 0)
+      headers_file_name = result.gl_pathv[0];
     else
       {
 	ERROR_MSG(_("Invalid file name: ") + (string)name + ".");
 	exit (-1);
       }
-    wordfree (&result);
+    globfree (&result);
   }
 
   string Preferences :: headers_file (void)
@@ -256,15 +256,15 @@
     // command line.
     if (log_file_name.length () == 0)
       {
-	wordexp_t result;
-	if (wordexp (name, &result, 0) == 0)
-	  log_file_name = result.we_wordv[0];
+	glob_t result;
+	if (glob (name, 0, NULL, &result) == 0)
+	  log_file_name = result.gl_pathv[0];
 	else
 	  {
 	    ERROR_MSG(_("Invalid file name: ") + (string)name + ".");
 	    exit (-1);
 	  }
-	wordfree (&result);
+	globfree (&result);
       }
   }
 
