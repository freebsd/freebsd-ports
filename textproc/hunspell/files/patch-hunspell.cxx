--- hunspell.cxx.orig	Wed Dec 17 18:50:49 2003
+++ hunspell.cxx	Thu May 20 15:54:49 2004
@@ -49,8 +49,8 @@
 #include "manparser.hxx"
 #include "firstparser.hxx"
 
-#define LIBDIR "/usr/share/myspell/"
-#define LIBDIR2 "/usr/share/hunmorph/"
+#define LIBDIR "%%PREFIX%%/share/myspell/"
+#define LIBDIR2 "%%PREFIX%%/share/hunmorph/"
 #define HOME getenv("HOME")
 #define DICBASENAME ".hunspell_"
 #define LOGFILE "/tmp/hunspell.log"
