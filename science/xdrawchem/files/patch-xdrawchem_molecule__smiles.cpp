--- xdrawchem/molecule_smiles.cpp.orig	2017-01-09 12:25:32 UTC
+++ xdrawchem/molecule_smiles.cpp
@@ -254,8 +254,6 @@ void Molecule::FromSMILES( QString sm )
 
     DPoint *thisDPoint;
 
-    OpenBabel::OBElementTable etable;
-
     std::vector < OpenBabel::OBNodeBase * >::iterator ait;
 
     std::map < OpenBabel::OBAtom *, DPoint * >hashit;
@@ -265,9 +263,9 @@ void Molecule::FromSMILES( QString sm )
 
         qInfo() << "Adding OBAtom: " << i++ << " of element#: " <<
           thisAtom->GetAtomicNum() << " type: " <<
-          etable.GetSymbol(thisAtom->GetAtomicNum()) ;
+          OBElements::GetSymbol(thisAtom->GetAtomicNum()) ;
         thisDPoint = new DPoint;
-        tmp_element = etable.GetSymbol( thisAtom->GetAtomicNum() );
+        tmp_element = OBElements::GetSymbol( thisAtom->GetAtomicNum() );
 
         tmp_element_mask = tmp_element;
         tmp_element_mask.fill( ' ' );   // fix the mask characters
@@ -292,7 +290,7 @@ void Molecule::FromSMILES( QString sm )
 
     OpenBabel::OBBond * thisBond;
 
-    std::vector < OpenBabel::OBEdgeBase * >::iterator bit;
+    std::vector < OpenBabel::OBBond * >::iterator bit;
     for ( thisBond = myMol.BeginBond( bit ); thisBond; thisBond = myMol.NextBond( bit ) ) {
         addBond( hashit[thisBond->GetBeginAtom()], hashit[thisBond->GetEndAtom()], 1, thisBond->GetBondOrder(), QColor( 0, 0, 0 ), true );
     }
