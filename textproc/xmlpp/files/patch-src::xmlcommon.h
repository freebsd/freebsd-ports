--- src/xmlcommon.h.orig	Wed Jul 23 04:10:04 2003
+++ src/xmlcommon.h	Wed Jul 23 04:12:03 2003
@@ -20,6 +20,8 @@
 
 //! dummy define		  
 #define XMLPP_API
+
+using std::string;
 		  
 //! handle to a tagname string in a tagname map
 typedef int xmltagnamehandle;
