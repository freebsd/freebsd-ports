
$FreeBSD$

--- safe_ostrstream.cpp.orig	Fri Feb 21 03:11:22 2003
+++ safe_ostrstream.cpp	Fri Feb 21 03:11:51 2003
@@ -20,6 +20,8 @@
  */
 #ifdef __GNUC__
 
+using namespace std;
+
 #include	"safe_ostrstream.h"
 #include	<stdio.h>
 
