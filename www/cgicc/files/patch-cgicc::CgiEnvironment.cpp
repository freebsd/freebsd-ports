--- cgicc/CgiEnvironment.cpp.orig	Thu Mar 11 01:29:33 2004
+++ cgicc/CgiEnvironment.cpp	Thu Mar 11 01:29:42 2004
@@ -138,7 +138,7 @@
   std::string::const_iterator data_iter;
   
   for(data_iter = data.begin(); data_iter != data.end(); ++data_iter,++wscount)
-    if(std::isspace(*data_iter) == 0)
+    if(isspace(*data_iter) == 0)
       break;			
   
   // Per RFC 2091, do not unescape the data (thanks to afm@othello.ch)

