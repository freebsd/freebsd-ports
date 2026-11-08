--- tests/CDTTest.cpp.orig	2012-08-02 07:22:44 UTC
+++ tests/CDTTest.cpp
@@ -590,7 +590,7 @@ $H{'q'} -> [1] -> {"test"} = "passed";
 
 	fprintf(stderr, "Get HASH values: %s\n", oCDT_array.GetHashValues().Dump().c_str());
 
-	CDT::Iterator itCDTArray = oCDT_array.Begin();
+	CDTIterator itCDTArray = oCDT_array.Begin();
 	while (itCDTArray != oCDT_array.End())
 	{
 		fprintf(stderr, "oCDT_array[\"%s\"] => %s\n", itCDTArray -> first.c_str(), itCDTArray -> second.GetString().c_str());
@@ -598,7 +598,7 @@ $H{'q'} -> [1] -> {"test"} = "passed";
 		++itCDTArray;
 	}
 
-	CDT::ConstIterator itCDTCArray = oCDT_array.Begin();
+	CDTConstIterator itCDTCArray = oCDT_array.Begin();
 	while (itCDTCArray != oCDT_array.End())
 	{
 		fprintf(stderr, "oCDT_array[\"%s\"] => %s\n", itCDTCArray -> first.c_str(), itCDTCArray -> second.GetString().c_str());
