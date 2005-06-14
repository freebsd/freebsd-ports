--- Utilities/Xdmf/libsrc/XdmfDataDesc.cxx.orig	Tue Jun  7 16:06:38 2005
+++ Utilities/Xdmf/libsrc/XdmfDataDesc.cxx	Tue Jun  7 16:06:40 2005
@@ -313,7 +313,7 @@
 
 XdmfInt32
 XdmfDataDesc::SelectCoordinates(  XdmfInt64 NumberOfElements, XdmfInt64 *Coordinates ){
-hssize_t  *HCoordinates;
+hsize_t  *HCoordinates;
 XdmfInt32  status;
 XdmfInt64  i, rank = this->Rank;
 hssize_t  Length = NumberOfElements * rank;
@@ -326,14 +326,14 @@
 
 this->SelectionType = XDMF_COORDINATES;
 XdmfDebug(" Selecting " << (int)NElements << " elements" );
-HCoordinates = new hssize_t[ Length ];
+HCoordinates = new hsize_t[ Length ];
 for( i = 0 ; i < Length ; i++ ){
   HCoordinates[i] = Coordinates[i];
   }
 status = H5Sselect_elements( this->DataSpace,
         H5S_SELECT_SET,
          NElements,
-         ( const hssize_t **)HCoordinates);
+         ( const hsize_t **)HCoordinates);
 if( status < 0 ) {
   return( XDMF_FAIL );
 }
