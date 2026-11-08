--- src/CTPP2Util.cpp.orig	2012-08-02 07:22:44 UTC
+++ src/CTPP2Util.cpp
@@ -751,7 +751,7 @@ DumpBuffer & DumpCDT2JSON(const CTPP::CDT & oCDT, Dump
 		case CDT::HASH_VAL:
 			{
 				oResult.Write("{", 1);
-				CDT::ConstIterator itCDTCArray = oCDT.Begin();
+				CDTConstIterator itCDTCArray = oCDT.Begin();
 				while (itCDTCArray != oCDT.End())
 				{
 					oResult.Write("\"", 1);
