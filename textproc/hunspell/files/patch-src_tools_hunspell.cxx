
$FreeBSD$

--- src/tools/hunspell.cxx.orig
+++ src/tools/hunspell.cxx
@@ -47,7 +47,7 @@
 #include "manparser.hxx"
 #include "firstparser.hxx"
 
-#define LIBDIR "/usr/share/myspell/"
+#define LIBDIR "%%PREFIX%%/share/myspell/"
 #define HOME getenv("HOME")
 #define DICBASENAME ".hunspell_"
 #define LOGFILE "/tmp/hunspell.log"
