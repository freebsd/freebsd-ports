--- ./qtiplot/src/scripting/scripting.pri.orig	2010-11-16 13:42:07.000000000 +0300
+++ ./qtiplot/src/scripting/scripting.pri	2011-03-19 00:09:38.182155936 +0300
@@ -115,7 +115,6 @@
 			 $${SIP_DIR}/sipqtitTest.cpp \
 			 $${SIP_DIR}/sipqtiShapiroWilkTest.cpp \
 			 $${SIP_DIR}/sipqtiChiSquareTest.cpp \
-			 $${SIP_DIR}/sipqtiAnova.cpp \
 
 exists(../../$${SIP_DIR}/sipqtiQList.cpp) {
   # SIP < 4.9
