--- Metric.h.orig	Thu Dec 23 14:22:35 1999
+++ Metric.h	Thu Dec 18 22:18:24 2003
@@ -57,7 +57,7 @@
   MetricIso operator/(Real8 c) const {return  MetricIso(h*c);} 
 
   void     Box(Real4 & hx,Real4 & hy) { hx=h,hy=h;}
-  friend ostream& operator <<(ostream& f, const  MetricIso & M)
+  friend std::ostream& operator <<(std::ostream& f, const  MetricIso & M)
   {f << " h=" << M.h<< ";" ;   return f;}
 
 #ifdef DRAWING
@@ -88,7 +88,7 @@
 //  Real8 operator()(D2 x) const { return sqrt(x.x*x.x*a11+2*x.x*x.y*a21+x.y*x.y*a22);};
   Real8 operator()(R2 x,R2 y) const { return x.x*y.x*a11+(x.x*x.y+x.y*y.x)*a21+x.y*y.y*a22;};
   inline void  Box(Real4 &hx,Real4 &hy) const ;  
- friend ostream& operator <<(ostream& f, const  MetricAnIso & M)
+ friend std::ostream& operator <<(std::ostream& f, const  MetricAnIso & M)
   {f << " mtr a11=" << M.a11 << " a21=a12=" << M.a21 << " a22=" << M.a22 << ";" ;   return f;}
 #ifdef DRAWING
   void Draw(R2 ) const;
@@ -116,9 +116,9 @@
   void Minh(double h) {Max(1.0/(h*h));}
   void Maxh(double h) {Min(1.0/(h*h));}
   void Isotrope() {lambda1=lambda2=::Max(lambda1,lambda2);}
-  friend ostream& operator <<(ostream& f, const MatVVP2x2 & c)
+  friend std::ostream& operator <<(std::ostream& f, const MatVVP2x2 & c)
   { f << '{' << 1/sqrt(c.lambda1)<< ',' << 1/sqrt(c.lambda2) << ','<< c.v << '}' <<flush ; return f; }
-  friend istream& operator >>(istream& f,  MatVVP2x2 & c)
+  friend std::istream& operator >>(std::istream& f,  MatVVP2x2 & c)
   { f >> c.lambda1 >>c.lambda2 >> c.v.x >> c.v.y ;c.v /= Norme2(c.v); return f; }
   MatVVP2x2(const MetricAnIso );
   MatVVP2x2(const MetricIso M) :  lambda1(1/(M.h*M.h)),lambda2(1/(M.h*M.h)),v(1,0) {}
