--- ./classes/include/ArtsCflowdCustomData.hh.orig	Tue Nov  9 05:39:42 1999
+++ ./classes/include/ArtsCflowdCustomData.hh	Wed Sep 25 16:38:10 2002
@@ -20,6 +20,7 @@
 }
 
 #include <map>
+using namespace std;
 
 //----------------------------------------------------------------------------
 //                      class ArtsCflowdCustomDataKey 
@@ -145,4 +146,5 @@
 };
 
 
-#endif  // _ARTSCFLOWDCUSTOMDATA_HH_
+#endif  /* _ARTSCFLOWDCUSTOMDATA_HH_ */
+
