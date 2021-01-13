--- xdrawchem/molecule_obmol.cpp.orig	2017-01-09 12:25:32 UTC
+++ xdrawchem/molecule_obmol.cpp
@@ -58,7 +58,7 @@ bool Molecule::convertFromOBMol( OBMol * obmol )
     Point point;
     Text *text;
 
-    std::vector < OBEdgeBase * >::iterator bonditr;
+    std::vector < OBBond * >::iterator bonditr;
     std::map < Point, DPoint *, pt_cmp > points;
     std::map < Point, DPoint *, pt_cmp >::iterator itr;
 
@@ -133,7 +133,7 @@ bool Molecule::convertFromOBMol( OBMol * obmol )
         int bondorder = bond->GetBondOrder();
 
         //set elements
-        if ( !atom1->IsCarbon() ) {
+        if ( atom1->GetAtomicNum() != 6 ) {
             QString str( "<element>" );
 
             str += symbol[atom1->GetAtomicNum() - 1];
@@ -142,7 +142,7 @@ bool Molecule::convertFromOBMol( OBMol * obmol )
 
         }
 
-        if ( !atom2->IsCarbon() ) {
+        if ( atom2->GetAtomicNum() != 6 ) {
             QString str( "<element>" );
 
             str += symbol[atom2->GetAtomicNum() - 1];
@@ -155,7 +155,7 @@ bool Molecule::convertFromOBMol( OBMol * obmol )
 
         //label atoms if not Carbon
 
-        if ( !atom1->IsCarbon() ) {
+        if ( atom1->GetAtomicNum() != 6 ) {
 
             text = new Text( r );
             QString str = symbol[atom1->GetAtomicNum() - 1];
@@ -167,7 +167,7 @@ bool Molecule::convertFromOBMol( OBMol * obmol )
             addText( text );
         }
 
-        if ( !atom2->IsCarbon() ) {
+        if ( atom2->GetAtomicNum() != 6 ) {
 
             text = new Text( r );
             QString str = symbol[atom2->GetAtomicNum() - 1];
