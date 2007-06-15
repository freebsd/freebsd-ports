--- classes/src/CflowdAsMatrix.cc.orig	Fri Jun 15 16:36:13 2007
+++ classes/src/CflowdAsMatrix.cc	Fri Jun 15 16:40:38 2007
@@ -41,6 +41,7 @@
 
 #include <string>
 #include <strstream.h>
+#include <strstream>
 
 #include "ArtsPrimitive.hh"
 #include "CflowdAsMatrix.hh"
@@ -50,6 +51,7 @@
                                    CflowdRawFlow::k_pktsMask|\
                                    CflowdRawFlow::k_bytesMask)
 
+using namespace std;
 static const string rcsid = "@(#) $Name: cflowd-2-1-b1 $ $Id: CflowdAsMatrix.cc,v 1.16 1999/02/19 02:20:04 dwm Exp $";
 
 ArtsPrimitive g_CfdArtsPrimitive;
