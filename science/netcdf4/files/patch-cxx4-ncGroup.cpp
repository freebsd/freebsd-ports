--- cxx4/ncGroup.cpp.orig
+++ cxx4/ncGroup.cpp
@@ -218,7 +218,7 @@
  
   // search in child groups of the children
   if(location == ChildrenOfChildrenGrps || location == AllChildrenGrps || location == AllGrps ) {
-    map<string,NcGroup>::iterator it;
+    multimap<string,NcGroup>::iterator it;
     multimap<string,NcGroup> groups(getGroups(ChildrenGrps));
     for (it=groups.begin();it!=groups.end();it++) {
       multimap<string,NcGroup> childGroups(it->second.getGroups(AllChildrenGrps));
@@ -1251,7 +1251,7 @@
   // search in current group and parent groups.
   NcGroup tmpGroup(*this); 
   multimap<string,NcDim>::iterator itD;
-  map<string,NcVar>::iterator itV;
+  multimap<string,NcVar>::iterator itV;
   while(1) {
     // get the collection of NcDim objects defined in this group.
     multimap<string,NcDim> dimTmp(tmpGroup.getDims());
@@ -1289,7 +1289,7 @@
   // search in current group and parent groups.
   multimap<string,NcDim>::iterator itD;
   NcGroup tmpGroup(*this); 
-  map<string,NcVar>::iterator itV;
+  multimap<string,NcVar>::iterator itV;
   while(1) {
     // get the collection of NcDim objects defined in this group.
     multimap<string,NcDim> dimTmp(tmpGroup.getDims());
