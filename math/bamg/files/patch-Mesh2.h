--- Mesh2.h.orig	Thu Dec 23 17:25:52 1999
+++ Mesh2.h	Thu Dec 18 22:37:45 2003
@@ -21,6 +21,11 @@
 #include "meshtype.h"
 #include <stdlib.h>
 
+using std::cerr;
+using std::cout;
+using std::endl;
+using std::flush;
+
 #include <math.h>
 #include <limits.h>
 
@@ -183,7 +188,7 @@
   Real8  Smoothing(Triangles & ,const Triangles & ,Triangle  * & ,Real8 =1);
   int ref(){ return ReferenceNumber;}
 
-  friend ostream& operator <<(ostream& f, const  Vertex & v)
+  friend std::ostream& operator <<(std::ostream& f, const  Vertex & v)
   {f << "(" << v.i  << "," << v.r << MatVVP2x2(v.m) << ")" ;   return f;}
   inline void Set(const Vertex & rec,const Triangles &,Triangles &);
   
@@ -200,7 +205,7 @@
 
 /////////////////////////////////////////////////////////////////////////////////////
 class TriangleAdjacent {
-  friend ostream& operator <<(ostream& f, const  TriangleAdjacent & ta)
+  friend std::ostream& operator <<(std::ostream& f, const  TriangleAdjacent & ta)
   {f << "{" << ta.t << "," << ((int) ta.a) << "}" ;
    return f;}
 
@@ -286,7 +291,7 @@
   int IsThe() const { return link == this;}  
   
 inline void Set(const GeometricalVertex & rec,const Geometry & Gh ,const Geometry & GhNew);
-  inline friend ostream& operator <<(ostream& f, const  GeometricalVertex & s) 
+  inline friend std::ostream& operator <<(std::ostream& f, const  GeometricalVertex & s) 
      { f << s.r << "," << s.cas << ".";return f; }
 };
 
@@ -341,7 +346,7 @@
 /////////////////////////////////////////////////////////////////////////////////////
 class Triangle {
   friend class TriangleAdjacent;
-  friend ostream& operator <<(ostream& f, const  Triangle & ta);
+  friend std::ostream& operator <<(std::ostream& f, const  Triangle & ta);
 
 
   private: // les arete sont opposes a un sommet
@@ -613,7 +618,7 @@
   operator const Real8 & () const {return abscisse;}
   int IsRequiredVertex(){ return this? (( abscisse<0 ? (gv?gv->Required():0):0 )) : 0;}
   void SetOn(){mv->on=this;mv->vint=IsVertexOnGeom;}
-  friend ostream& operator <<(ostream& f, const  VertexOnGeom & vog){
+  friend std::ostream& operator <<(std::ostream& f, const  VertexOnGeom & vog){
     f << vog.abscisse << " " << vog.mv << " " << vog.gv << " ; ";
     if (vog.abscisse < 0) f << *vog.gv << " ;; " ;
     //    else f << *vog.ge << " ;; " ;
@@ -650,11 +655,11 @@
  
 class CrackedEdge { // a small class to store on crack an uncrack information 
   friend class Triangles;
-  friend ostream& operator <<(ostream& f, const   Triangles & Th) ;  
+  friend std::ostream& operator <<(std::ostream& f, const   Triangles & Th) ;  
  class CrackedTriangle {
   friend class Triangles;
   friend class CrackedEdge;
-  friend ostream& operator <<(ostream& f, const   Triangles & Th) ;  
+  friend std::ostream& operator <<(std::ostream& f, const   Triangles & Th) ;  
   Triangle * t; // edge of triangle t
   int i; //  edge number of in triangle
   Edge *edge; // the  2 edge 
@@ -803,7 +808,7 @@
   void SmoothMetric(Real8 raisonmax) ;
   void BoundAnisotropy(Real8 anisomax,double hminaniso= 1e-100) ;
   void MaxSubDivision(Real8 maxsubdiv);
-  void WriteMetric(ostream &,int iso) ;
+  void WriteMetric(std::ostream &,int iso) ;
   Edge** MakeGeometricalEdgeToEdge();
   void  SetVertexFieldOn();  
   void  SetVertexFieldOnBTh();
@@ -823,7 +828,7 @@
                       Vertex & R,VertexOnEdge & BR,VertexOnGeom & GR);
    
   
-  void WriteElements(ostream& f,Int4 * reft ,Int4 nbInT) const;
+  void WriteElements(std::ostream& f,Int4 * reft ,Int4 nbInT) const;
 
   
   Int4 Number(const Triangle & t) const  { return &t - triangles;}
@@ -841,12 +846,12 @@
   Vertex * NearestVertex(Icoor1 i,Icoor1 j) ;
   Triangle * FindTriangleContening(const I2 & ,Icoor2 [3],Triangle *tstart=0) const;
   void Write(char * filename,const TypeFileMesh type = AutoMesh);
-  void Write_am_fmt(ostream &) const ;
-  void Write_am(ostream &) const ;
-  void Write_ftq(ostream &) const ;
-  void Write_nopo(ostream &) const ;
-  void Write_msh(ostream &) const ;
-  void Write_amdba(ostream &) const ;
+  void Write_am_fmt(std::ostream &) const ;
+  void Write_am(std::ostream &) const ;
+  void Write_ftq(std::ostream &) const ;
+  void Write_nopo(std::ostream &) const ;
+  void Write_msh(std::ostream &) const ;
+  void Write_amdba(std::ostream &) const ;
 
   void Read(MeshIstream &,int version,Real8 cutoffradian);
   void Read_am_fmt(MeshIstream &);
@@ -878,7 +883,7 @@
   void  InitDraw() const ;
   void   inquire()  ;
 #endif
- friend ostream& operator <<(ostream& f,  const  Triangles & Th); 
+ friend std::ostream& operator <<(std::ostream& f,  const  Triangles & Th); 
   void  Write(const char * filename);
   void ConsGeometry(Real8 =-1.0); // construct a geometry if no geo 
   void FillHoleInMesh() ;
@@ -954,7 +959,7 @@
 
  GeometricalEdge *  ProjectOnCurve(const Edge & ,Real8,Vertex &,VertexOnGeom &) const ;
   GeometricalEdge *  Contening(const R2 P,  GeometricalEdge * start) const;
- friend ostream& operator <<(ostream& f, const   Geometry & Gh); 
+ friend std::ostream& operator <<(std::ostream& f, const   Geometry & Gh); 
  void Write(const char * filename);
  
 #ifdef DEBUG
