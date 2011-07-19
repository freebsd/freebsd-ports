--- ./src/tools/hunspell.cxx.orig	2011-01-21 18:01:29.000000000 +0100
+++ ./src/tools/hunspell.cxx	2011-07-19 07:16:58.346225286 +0200
@@ -61,28 +61,23 @@
 #include "firstparser.hxx"
 
 #define LIBDIR \
-    "/usr/share/hunspell:" \
-    "/usr/share/myspell:" \
-    "/usr/share/myspell/dicts:" \
-    "/Library/Spelling"
+    "%%PREFIX%%/share/hunspell:" \
+    "%%PREFIX%%/share/myspell:" \
+    "%%PREFIX%%/share/myspell/dicts:"
 #define USEROOODIR \
     ".openoffice.org/3/user/wordbook:" \
     ".openoffice.org2/user/wordbook:" \
     ".openoffice.org2.0/user/wordbook:" \
     "Library/Spelling"
 #define OOODIR \
-    "/opt/openoffice.org/basis3.0/share/dict/ooo:" \
-    "/usr/lib/openoffice.org/basis3.0/share/dict/ooo:" \
-    "/opt/openoffice.org2.4/share/dict/ooo:" \
-    "/usr/lib/openoffice.org2.4/share/dict/ooo:" \
-    "/opt/openoffice.org2.3/share/dict/ooo:" \
-    "/usr/lib/openoffice.org2.3/share/dict/ooo:" \
-    "/opt/openoffice.org2.2/share/dict/ooo:" \
-    "/usr/lib/openoffice.org2.2/share/dict/ooo:" \
-    "/opt/openoffice.org2.1/share/dict/ooo:" \
-    "/usr/lib/openoffice.org2.1/share/dict/ooo:" \
-    "/opt/openoffice.org2.0/share/dict/ooo:" \
-    "/usr/lib/openoffice.org2.0/share/dict/ooo"
+    "%%PREFIX%%/openoffice.org3/share/dict/ooo:" \
+    "%%PREFIX%%/openoffice.org-3.0.0/share/dict/ooo:" \
+    "%%PREFIX%%/openoffice.org-2.4.2/share/dict/ooo:" \
+    "%%PREFIX%%/openoffice.org-2.4.1/share/dict/ooo:" \
+    "%%PREFIX%%/openoffice.org-2.4/share/dict/ooo:" \
+    "%%PREFIX%%/openoffice.org-2.2/share/dict/ooo:" \
+    "%%PREFIX%%/openoffice.org-2.1/share/dict/ooo:" \
+    "%%PREFIX%%/openoffice.org2.0/share/dict/ooo:"
 #define HOME getenv("HOME")
 #define DICBASENAME ".hunspell_"
 #define LOGFILE "/tmp/hunspell.log"
