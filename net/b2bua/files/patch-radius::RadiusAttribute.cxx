
$FreeBSD$

--- radius/RadiusAttribute.cxx.orig	Sat Sep 22 05:16:51 2001
+++ radius/RadiusAttribute.cxx	Sun Jan 19 01:35:01 2003
@@ -52,6 +52,8 @@
 static const char* const RadiusAttribute_cxx_Version =
     "$Id: RadiusAttribute.cxx,v 1.11 2001/09/22 02:16:51 sprajpat Exp $";
 
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <netinet/in.h>
 #include <cstdio>
 
