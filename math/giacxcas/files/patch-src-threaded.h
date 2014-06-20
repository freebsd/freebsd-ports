--- src/threaded.h.orig	2014-03-27 14:21:00.000000000 +0100
+++ src/threaded.h	2014-05-01 10:44:15.000000000 +0200
@@ -300,7 +300,7 @@
     return os << std::endl;
   }
 
-#ifdef VISUALC
+#if defined VISUALC || defined __clang__
   template<class T>
   class vector_size64:public std::vector<T>{
   };
@@ -1869,7 +1869,7 @@
     // degree of product wrt to the main variable
     // will launch deg1v+1 threads to compute each degree
     pthread_t tab[deg1v+1];
-    threadmult_t<T,U> arg[deg1v+1];
+    threadmult_t<T,U> * arg=new threadmult_t<T,U>[deg1v+1];//pr clang
     possible_size=0;
     int res=0;
     int i=deg1v;
@@ -1940,6 +1940,7 @@
 	res=pthread_create(&tab[i],(pthread_attr_t *) NULL,do_threadmult<T,U>,(void *) &arg[i]);
 	if (res){
 	  // should cancel previous threads and delete created arg[i].vptr
+	  delete [] arg;//pr clang
 	  return false;
 	}
       } // end initial thread creation
@@ -1973,6 +1974,7 @@
 		res=pthread_create(&tab[i],(pthread_attr_t *) NULL,do_threadmult<T,U>,(void *) &arg[i]);
 		if (res){
 		  // should cancel previous threads and delete created arg[i].vptr
+		  delete [] arg; //cf clang
 		  return false;
 		}
 		in_progress[j]=i;
@@ -2051,6 +2053,7 @@
     }
     if (debug_infolevel>30)
       std::cerr << "End copy " << clock() << std::endl;
+    delete [] arg; //cf clang
     return true;
   }
 
