--- ./golded3/geutil2.cpp.orig	Fri Feb 25 17:04:04 2000
+++ ./golded3/geutil2.cpp	Mon Oct 20 04:14:52 2003
@@ -190,9 +190,9 @@
 
 int AkaMatch(ftn_addr* match, const ftn_addr* addr) {
 
-  int aka;
+  int aka = 0;
 
-  for(vector<AkaMatchG>::iterator am = CFG->akamatch.begin(), aka=0; am != CFG->akamatch.end(); am++, aka++) {
+  for(vector<AkaMatchG>::iterator am = CFG->akamatch.begin(); am != CFG->akamatch.end(); am++, aka++) {
     if(addr->match(am->mask)) {
       int akano = GetAkaNo(am->aka);
       if(akano != -1) {
@@ -207,7 +207,8 @@
   int matchaka = 0;
   vector<gaka>::iterator a;
 
-  for(a = CFG->aka.begin(), aka = 0; a != CFG->aka.end(); aka++, a++) {
+  aka = 0;
+  for(a = CFG->aka.begin(); a != CFG->aka.end(); aka++, a++) {
 
     if(match->equals(a->addr))
       matchaka = aka;
