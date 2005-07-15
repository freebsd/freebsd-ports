--- src/net/Fl_FTP_Connect.cpp.orig	Fri Jul 15 11:31:49 2005
+++ src/net/Fl_FTP_Connect.cpp	Fri Jul 15 11:39:47 2005
@@ -1,6 +1,6 @@
 #include <efltk/net/Fl_FTP_Connect.h>
 #include <stdio.h>
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #  include <netinet/in.h>
 #endif
 
