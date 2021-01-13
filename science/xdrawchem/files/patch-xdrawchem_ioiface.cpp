--- xdrawchem/ioiface.cpp.orig	2017-01-09 12:25:32 UTC
+++ xdrawchem/ioiface.cpp
@@ -193,7 +193,7 @@ void IOIface::convertToChemData()
         int bondorder = bond->GetBondOrder();
 
         //set elements
-        if ( !atom1->IsCarbon() ) {
+        if ( atom1->GetAtomicNum() != 6 ) {
             QString str( "<element>" );
             str += IOIface::symbol[atom1->GetAtomicNum() - 1];
             str += "</element>";
@@ -201,7 +201,7 @@ void IOIface::convertToChemData()
 
         }
 
-        if ( !atom2->IsCarbon() ) {
+        if ( atom2->GetAtomicNum() != 6 ) {
             QString str( "<element>" );
 
             str += IOIface::symbol[atom2->GetAtomicNum() - 1];
@@ -216,7 +216,7 @@ void IOIface::convertToChemData()
 
         //label atoms if not Carbon
 
-        if ( !atom1->IsCarbon() ) {
+        if ( atom1->GetAtomicNum() != 6 ) {
 
             text = new Text( chemdata->getRender2D() );
             QString str = IOIface::symbol[atom1->GetAtomicNum() - 1];
@@ -229,7 +229,7 @@ void IOIface::convertToChemData()
             //qDebug() << "ioiface(1) text:" << str;
         }
 
-        if ( !atom2->IsCarbon() ) {
+        if ( atom2->GetAtomicNum() != 6 ) {
 
             text = new Text( chemdata->getRender2D() );
             QString str = IOIface::symbol[atom2->GetAtomicNum() - 1];
