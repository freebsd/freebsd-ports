--- extconf.rb.orig	Sun Dec  3 23:50:31 2000
+++ extconf.rb	Sat Mar 10 00:35:37 2001
@@ -2,10 +2,10 @@
 
 dir_config('sablot')
 
-$LOCAL_LIBS += " -L/usr/local/lib -lsablot -lxmlparse -lxmltok"
-
-if have_header("sablot.h") &&
-    have_library("sablot", "SablotProcessStrings") &&
-    have_library("xmltok", "XML_ParserCreate")
+if have_header("expat.h") &&
+    have_header("sablot.h") &&
+    have_library("expat", "XML_ParserCreate") &&
+    have_library("iconv") &&
+    have_library("sablot", "SablotProcessStrings")
   create_makefile("sablot")
 end
