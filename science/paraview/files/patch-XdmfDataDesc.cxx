--- Utilities/Xdmf/libsrc/XdmfDataDesc.cxx.orig	Sat Oct 15 13:58:21 2005
+++ Utilities/Xdmf/libsrc/XdmfDataDesc.cxx	Sat Oct 15 13:58:36 2005
@@ -334,7 +334,7 @@
 
 this->SelectionType = XDMF_COORDINATES;
 XdmfDebug(" Selecting " << (int)NElements << " elements" );
-HCoordinates = new hssize_t[ Length ];
+HCoordinates = new hsize_t[ Length ];
 for( i = 0 ; i < Length ; i++ ){
   HCoordinates[i] = Coordinates[i];
   }
