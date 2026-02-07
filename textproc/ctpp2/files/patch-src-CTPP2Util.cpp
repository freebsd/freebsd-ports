--- src/CTPP2Util.cpp.orig	2012-08-02 11:22:44.000000000 +0400
+++ src/CTPP2Util.cpp	2014-05-02 18:06:25.511300597 +0400
@@ -751,7 +751,7 @@
 		case CDT::HASH_VAL:
 			{
 				oResult.Write("{", 1);
-				CDT::ConstIterator itCDTCArray = oCDT.Begin();
+				CDTConstIterator itCDTCArray = oCDT.Begin();
 				while (itCDTCArray != oCDT.End())
 				{
 					oResult.Write("\"", 1);
