--- MeshWrite.cpp.orig	Thu Apr  5 10:03:54 2001
+++ MeshWrite.cpp	Fri Dec 19 00:01:40 2003
@@ -52,7 +52,7 @@
      cout    << endl;
 
     }
-  ofstream f(filename /*,ios::trunc*/);
+  std::ofstream f(filename /*,ios::trunc*/);
    if (f)
      switch (type) 
        {
@@ -263,7 +263,7 @@
   
 }
 
-void Triangles::Write_nopo(ostream &ff) const
+void Triangles::Write_nopo(std::ostream &ff) const
 
 {
  Int4  nef=0;
@@ -332,7 +332,7 @@
   // cout << "fin write nopo" << endl;
 }
 
-void Triangles::Write_am_fmt(ostream &f) const 
+void Triangles::Write_am_fmt(std::ostream &f) const 
 {
   Int4 i,j;
   assert(this && nbt);
@@ -362,7 +362,7 @@
 
 }
 
-void Triangles::Write_am(ostream &ff) const 
+void Triangles::Write_am(std::ostream &ff) const 
 {
   OFortranUnFormattedFile f(ff);  
   Int4 i,j;
@@ -393,7 +393,7 @@
   delete [] reft;
 }
 
-void Triangles::Write_ftq(ostream &f) const 
+void Triangles::Write_ftq(std::ostream &f) const 
 {
 
   Int4 i;
@@ -440,7 +440,7 @@
   
   
 }
-void Triangles::Write_msh(ostream &f) const 
+void Triangles::Write_msh(std::ostream &f) const 
 {
   Int4 i;
   assert(this && nbt);
@@ -469,7 +469,7 @@
 
 }
 
-void Triangles::Write_amdba(ostream &f) const 
+void Triangles::Write_amdba(std::ostream &f) const 
 {
   assert(this && nbt);
 
@@ -499,7 +499,7 @@
 
 void Triangles::Write(const char * filename)
 {
-  ofstream f(filename);
+  std::ofstream f(filename);
   if (f)
     {
        if (name) delete name;
@@ -509,7 +509,7 @@
        f << *this;
     }
 }
-void Triangles::WriteElements(ostream& f,Int4 * reft ,Int4 nbInT) const
+void Triangles::WriteElements(std::ostream& f,Int4 * reft ,Int4 nbInT) const
    { 
      const Triangles & Th= *this;
      // do triangle and quad 
@@ -558,7 +558,7 @@
      // warning reft is now the element number 
    }
 
-ostream& operator <<(ostream& f, const   Triangles & Th) 
+std::ostream& operator <<(std::ostream& f, const   Triangles & Th) 
  {
   //  Th.FindSubDomain();
    // warning just on say the class is on the disk
@@ -744,7 +744,7 @@
 
 void Geometry::Write(const char * filename)
 {
-  ofstream f(filename);
+  std::ofstream f(filename);
   if (f)
     {
       if(verbosity>1)
@@ -756,7 +756,7 @@
        f << *this;
     }
 }
-ostream& operator <<(ostream& f, const   Geometry & Gh) 
+std::ostream& operator <<(std::ostream& f, const   Geometry & Gh) 
 {
    Int4  NbCorner=0;
    {
