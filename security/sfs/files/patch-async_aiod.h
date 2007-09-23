--- async/aiod.h.orig	2002-10-29 01:29:02.000000000 -0500
+++ async/aiod.h	2007-09-15 16:53:08.000000000 -0400
@@ -30,6 +30,9 @@
 #include "ihash.h"
 #include "aiod_prot.h"
 
+class aiod;
+class aiofh;
+
 struct aiod_req;
 
 class aiobuf {
