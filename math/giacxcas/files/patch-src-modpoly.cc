--- src/modpoly.cc.orig	2014-05-01 13:30:07.000000000 +0200
+++ src/modpoly.cc	2014-05-01 13:29:45.000000000 +0200
@@ -4455,12 +4455,17 @@
       return giac_gcd_modular_algo1(p,q,d);
     bool res=true;
     try {
-      inttype tabp[np+1]; // dense rep of the polynomial
-      if (!polynome2tab(p,np,tabp))
+      inttype * tabp=new inttype[np+1]; // dense rep of the polynomial
+      if (!polynome2tab(p,np,tabp)){
+	delete [] tabp; //cf clang
 	return false;
-      inttype tabq[nq+1]; // dense rep of the polynomial
-      if (!polynome2tab(q,nq,tabq))
+      }
+      inttype * tabq=new inttype[nq+1]; // dense rep of the polynomial
+      if (!polynome2tab(q,nq,tabq)){
+	delete [] tabp; //cf clang
+	delete [] tabq; //cf clang
 	return false;
+      }
       int nd;
       inttype * res;
       ntlgcd(tabp,np,tabq,nq,res,nd);
@@ -4471,6 +4476,8 @@
 	p = p/d;
 	q = q/d;
       }
+    delete [] tabp; // cf clang
+    delete [] tabq; // cf clang
     } catch(std::runtime_error & e){
       res=false;
     }
