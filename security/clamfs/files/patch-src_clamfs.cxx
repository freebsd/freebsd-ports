clamfs.cxx:963:26: error: invalid suffix on literal; C++11 requires a space between literal and identifier [-Wreserved-user-defined-literal]
    rLog(Info, "ClamFS v"VERSION);
                         ^

--- src/clamfs.cxx.orig	2009-11-29 21:04:33 UTC
+++ src/clamfs.cxx
@@ -960,7 +960,7 @@ int main(int argc, char *argv[])
     RLogInit(argc, argv);
     RLogOpenStdio();
 
-    rLog(Info, "ClamFS v"VERSION);
+    rLog(Info, "ClamFS v" VERSION);
     rLog(Info, "Copyright (c) 2007,2008 Krzysztof Burghardt <krzysztof@burghardt.pl>");
     rLog(Info, "http://clamfs.sourceforge.net/");
 
