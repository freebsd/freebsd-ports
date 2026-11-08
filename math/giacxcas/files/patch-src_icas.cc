--- src/icas.cc.orig	2026-02-13 17:50:20 UTC
+++ src/icas.cc
@@ -57,6 +57,9 @@ using namespace std;
 #endif
 #include <fcntl.h>
 #include <cstdlib>
+#if defined(__FreeBSD__)
+#include <sys/wait.h>
+#endif
 #include "gen.h"
 #include "index.h"
 #include "sym2poly.h"
@@ -887,8 +890,8 @@ void pgiac(std::string infile,std::string outfile,std:
     if (giac::is_file_available("/usr/share/giac/doc/giac.tex"))
       giac::system_no_deprecation("cp /usr/share/giac/doc/giac.tex .");
     else {
-      if (giac::is_file_available("/usr/local/share/giac/doc/giac.tex"))
-	giac::system_no_deprecation("cp /usr/local/share/giac/doc/giac.tex .");
+      if (giac::is_file_available("/usr/local/share/doc/giac/giac.tex"))
+	giac::system_no_deprecation("cp /usr/local/share/doc/giac/giac.tex .");
       else 
 	if (giac::is_file_available("/Applications/share/giac/doc/giac.tex"))
 	  giac::system_no_deprecation("cp /Applications/share/giac/doc/giac.tex .");
@@ -898,8 +901,8 @@ void pgiac(std::string infile,std::string outfile,std:
     if (giac::is_file_available("/usr/share/giac/doc/giacfr.tex"))
       giac::system_no_deprecation("cp /usr/share/giac/doc/giacfr.tex .");
     else {
-      if (giac::is_file_available("/usr/local/share/giac/doc/giacfr.tex"))
-	giac::system_no_deprecation("cp /usr/local/share/giac/doc/giacfr.tex .");
+      if (giac::is_file_available("/usr/local/share/doc/giac/giacfr.tex"))
+	giac::system_no_deprecation("cp /usr/local/share/doc/giac/giacfr.tex .");
       else 
 	if (giac::is_file_available("/Applications/share/giac/doc/giacfr.tex"))
 	  giac::system_no_deprecation("cp /Applications/share/giac/doc/giacfr.tex .");
