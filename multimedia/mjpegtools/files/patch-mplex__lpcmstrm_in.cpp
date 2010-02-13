--- mplex/lpcmstrm_in.cpp.orig	2005-10-14 01:43:10.000000000 +0900
+++ mplex/lpcmstrm_in.cpp	2010-01-09 17:12:17.000000000 +0900
@@ -53,7 +53,7 @@
 
 bool LPCMStream::Probe(IBitStream &bs )
 {
-    char *last_dot = strrchr( bs.StreamName(), '.' );
+    const char *last_dot = strrchr( bs.StreamName(), '.' );
     return 
         last_dot != NULL 
         && strcmp( last_dot+1, "lpcm") == 0;
