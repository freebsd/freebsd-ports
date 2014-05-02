--- tests/CDTTest.cpp.orig	2012-08-02 11:22:44.000000000 +0400
+++ tests/CDTTest.cpp	2014-05-02 18:06:25.531285819 +0400
@@ -590,7 +590,7 @@
 
 	fprintf(stderr, "Get HASH values: %s\n", oCDT_array.GetHashValues().Dump().c_str());
 
-	CDT::Iterator itCDTArray = oCDT_array.Begin();
+	CDTIterator itCDTArray = oCDT_array.Begin();
 	while (itCDTArray != oCDT_array.End())
 	{
 		fprintf(stderr, "oCDT_array[\"%s\"] => %s\n", itCDTArray -> first.c_str(), itCDTArray -> second.GetString().c_str());
@@ -598,7 +598,7 @@
 		++itCDTArray;
 	}
 
-	CDT::ConstIterator itCDTCArray = oCDT_array.Begin();
+	CDTConstIterator itCDTCArray = oCDT_array.Begin();
 	while (itCDTCArray != oCDT_array.End())
 	{
 		fprintf(stderr, "oCDT_array[\"%s\"] => %s\n", itCDTCArray -> first.c_str(), itCDTCArray -> second.GetString().c_str());
