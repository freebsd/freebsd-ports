--- src/net/Fl_FTP_Connect.cpp.orig	Fri Feb 27 04:09:46 2004
+++ src/net/Fl_FTP_Connect.cpp	Fri Feb 27 04:10:32 2004
@@ -1,6 +1,6 @@
 #include <efltk/net/Fl_FTP_Connect.h>
 #include <stdio.h>
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #  include <netinet/in.h>
 #endif
 
