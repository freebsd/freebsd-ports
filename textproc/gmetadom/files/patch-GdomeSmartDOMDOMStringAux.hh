--- src/gdome_cpp_smart/include/GdomeSmartDOMDOMStringAux.hh.orig	Tue Oct 15 19:18:15 2002
+++ src/gdome_cpp_smart/include/GdomeSmartDOMDOMStringAux.hh	Tue Oct 15 19:32:13 2002
@@ -35,7 +35,7 @@
 
 }
 
-namespace std {
+namespace __gnu_cxx {
 
   struct hash<GdomeSmartDOM::DOMString> {
     size_t operator()(const GdomeSmartDOM::DOMString& key) const;
