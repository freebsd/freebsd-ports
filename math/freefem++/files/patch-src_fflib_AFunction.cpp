--- ./src/fflib/AFunction.cpp.orig	2007-10-22 18:10:22.000000000 +0200
+++ ./src/fflib/AFunction.cpp	2007-11-13 22:27:16.000000000 +0100
@@ -1265,7 +1265,7 @@
     const E_Array & a=  ta ? *tea->v : *ea;
     cout << " pv =" << pv << " size = "<< a.size() << endl;
     ffassert(pv >=0 && pv <a.size());
-    return a[pv];
+    return (* a.v)[pv];
 }
 
 C_F0  opDot::code2(const basicAC_F0 &args) const      
