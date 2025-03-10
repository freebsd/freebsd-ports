--- plugins/D0RunIICone/ProtoJet.hpp.orig	2024-11-03 18:44:32 UTC
+++ plugins/D0RunIICone/ProtoJet.hpp
@@ -193,6 +193,7 @@ void ProtoJet<Item>::NowStable() {
   _info.initialET(_pT);
 }
 
+#if 0 // https://github.com/scikit-hep/fastjet/issues/324
 template<class Item>
 void ProtoJet<Item>::print(std::ostream& os) const {
   os<<"y phi Et = ("<<_y<<", "<<_phi<<", "<<this->_Et<<")"<<std::endl;
@@ -202,6 +203,7 @@ void ProtoJet<Item>::print(std::ostream& os) const {
     (*i)->print(os);
   os << std::endl;
 }
+#endif
 
 template<class Item>
 inline float ProtoJet<Item>::y() const{
