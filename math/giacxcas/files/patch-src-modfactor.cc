--- src/modfactor.cc.orig	2014-05-01 13:30:20.000000000 +0200
+++ src/modfactor.cc	2014-05-01 13:29:26.000000000 +0200
@@ -1316,11 +1316,13 @@
     }
     try {
       int n=q.lexsorted_degree();
-      inttype tab[n+1]; // dense rep of the polynomial
+      inttype * tab=new inttype[n+1]; // dense rep of the polynomial
       inttype * result[n]; // array of dense rep of the polynomial
       int resultdeg[n];
-      if (!polynome2tab(q,n,tab))
+      if (!polynome2tab(q,n,tab)){
+	delete [] tab; //cf clang
 	return false;
+      }
       // cerr << "NTL factor begins" << endl;
       int size=ntlfactor(tab,n,result,resultdeg,debug); 
       // cerr << "NTL factor end" << endl;
@@ -1329,6 +1331,7 @@
 	v.push_back(tab2polynome(result[i],resultdeg[i]));
 	delete [] result[i];
       }
+      delete [] tab; // cf clang
     } catch (std::runtime_error & e){
     }
 #ifdef HAVE_LIBPTHREAD
