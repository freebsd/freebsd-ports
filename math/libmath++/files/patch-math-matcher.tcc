--- math++/matcher.tcc.orig	Fri Aug 13 13:11:35 2004
+++ math++/matcher.tcc	Fri Aug 13 13:15:44 2004
@@ -35,12 +35,12 @@
 
 template<class T>
 TMatchRegistry<T>::TMatchRegistry() {
-};
+}
 
 template<class T>
 TMatchRegistry<T>::TMatchRegistry(const TMatchRegistry<T>& AProto) :
     FAnyMap(AProto.FAnyMap), FNodeList(AProto.FNodeList) {
-};
+}
 
 template<class T>
 void TMatchRegistry<T>::define(const std::string& AId, const TNode<T> *ANode) {
@@ -158,7 +158,7 @@
     va_start(ap, ARight);
 
     while (TMatch<T> *p = va_arg(ap, TMatch<T> *))
-        FPatterns.push_back(p);
+        this->FPatterns.push_back(p);
 
     va_end(ap);
 }
@@ -166,7 +166,7 @@
 template<class T>
 bool TPlusMatch<T>::match(const TNode<T> *AExpr, TMatchRegistry<T> *AReg) const {
     // yet a primitive sequencial search
-    for (typename T2Match<T>::TList::const_iterator p = FPatterns.begin(); p != FPatterns.end(); ++p)
+    for (typename T2Match<T>::TList::const_iterator p = this->FPatterns.begin(); p != this->FPatterns.end(); ++p)
         if (!TMatcher<T>::match(*p, AExpr, AReg))
             return false;
 
@@ -182,7 +182,7 @@
     va_start(ap, ARight);
 
     while (TMatch<T> *p = va_arg(ap, TMatch<T> *))
-        FPatterns.push_back(p);
+        this->FPatterns.push_back(p);
 
     va_end(ap);
 }
