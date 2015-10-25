--- SoObjects/Mailer/SOGoMailFolder.m.orig	2015-09-16 18:41:36 UTC
+++ SoObjects/Mailer/SOGoMailFolder.m
@@ -1645,7 +1645,7 @@ _compareFetchResultsByMODSEQ (id entry1,
 
   sortOrderings = [NSMutableArray array];
 
-  if ([self _sortElementIsAscending: sortElement])
+  if ([self _sortElementIsAscending: (NGDOMNodeWithChildren <DOMElement> *)sortElement])
     sortOrderingOrder = EOCompareAscending;
   else
     sortOrderingOrder = EOCompareDescending;
