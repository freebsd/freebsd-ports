--- list.cxx.orig	Fri Oct 22 12:59:24 1999
+++ list.cxx	Fri Mar 19 01:17:52 2004
@@ -17,6 +17,8 @@
 
 #include <latte.h>
 
+using namespace std;
+
 Latte_List::Latte_List() :
   m_self_eval(Latte_List::SelfEvalFn(*this)),
   m_operator(Latte_List::GetOperatorFn(*this))
