--- ./classes/src/ArtsFileUtil.cc.orig	Mon Oct  2 13:05:24 2000
+++ ./classes/src/ArtsFileUtil.cc	Wed Sep 25 16:38:10 2002
@@ -53,6 +53,7 @@
 
 #ifdef HAVE_FSTREAM
   #include <fstream>
+  #include <iterator>
 #else
   #include <fstream.h>
 #endif
@@ -69,7 +70,7 @@
 extern char *tzname[2];
 extern int   errno;
 
-const string rcsid = "@(#) $Name: arts++-1-1-a8 $ $Id: ArtsFileUtil.cc,v 1.14 2000/10/02 17:05:24 dwm Exp $";
+const char *rcsid = "@(#) $Name: arts++-1-1-a8 $ $Id: ArtsFileUtil.cc,v 1.14 2000/10/02 17:05:24 dwm Exp $";
 static const ArtsPackageVersion  k_artsVersion = ArtsPackageVersion(rcsid);
 
 //----------------------------------------------------------------------------
