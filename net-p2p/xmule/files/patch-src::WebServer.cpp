--- src/WebServer.cpp.orig	Tue May 20 20:42:30 2003
+++ src/WebServer.cpp	Tue May 20 21:06:14 2003
@@ -9,6 +9,10 @@
 #include <wx/wfstream.h>
 #include <wx/txtstrm.h>
 
+#ifdef __FreeBSD__
+extern long long atoll(const char *s);
+#endif /* __FreeBSD__ */
+
 #ifdef _DEBUG
 #undef THIS_FILE
 static char THIS_FILE[]=__FILE__;
