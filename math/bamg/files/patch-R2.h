--- R2.h.orig	Tue Dec  1 18:50:24 1998
+++ R2.h	Thu Dec 18 22:14:39 2003
@@ -40,7 +40,7 @@
 template <class R,class RR>
 class P2xP2 { // x ligne 1 y ligne2 
 
-  friend ostream& operator <<(ostream& f, const P2xP2<R,RR> & c) 
+  friend std::ostream& operator <<(std::ostream& f, const P2xP2<R,RR> & c) 
      { f << '[' << c.x << ',' << c.y << ']' <<flush ; return f; }
      
   friend P2<R,RR> operator*(P2<R,RR> c,P2xP2<R,RR> cc)
@@ -105,7 +105,7 @@
   return  P2<R,RR>(-x.y,x.x);} 
 
 template <class R,class RR>
-inline  ostream& operator <<(ostream& f, const P2<R,RR> & c)
+inline  std::ostream& operator <<(std::ostream& f, const P2<R,RR> & c)
   { f << '[' << c.x << ',' << c.y <<']' <<flush ; return f; }
 
    
