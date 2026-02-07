https://github.com/Optware/Optware-ng/commit/cf5b5050c989fb4e969167d20e6b135ff2608a87

--- etree.cc.orig	2017-10-14 02:49:56 UTC
+++ etree.cc
@@ -79,7 +79,7 @@ pred<ClassType> *new_comparison(RetType (ClassType::*m
 	return new Comparison<Op, MemGetter, RetType, ClassType>(member, v);
 }
 template <template <class A, class B> class Op, class ClassType, class RetType>
-pred<ClassType> *new_comparison(RetType (ClassType::*memberf)(void), RetType v){
+pred<ClassType> *new_comparison(RetType (ClassType::*memberf)(void) const, RetType v){
 	return new Comparison<Op, MemfuncGetter, RetType, ClassType>(memberf, v);
 }
 template <class ClassType, class getterT, class T2>
@@ -112,7 +112,7 @@ pred<ClassType> *new_comparison_re(RetType (ClassType:
 	return new Comparison_re<Op, MemGetter, RetType, ClassType>(member, pattern, flags);
 }
 template <template <class A, class B> class Op, class ClassType, class RetType>
-pred<ClassType> *new_comparison_re(RetType (ClassType::*memberf)(void), const char *pattern, int flags){
+pred<ClassType> *new_comparison_re(RetType (ClassType::*memberf)(void) const, const char *pattern, int flags){
 	return new Comparison_re<Op, MemfuncGetter, RetType, ClassType>(memberf, pattern, flags);
 }
 template <class ClassType, class getterT>
