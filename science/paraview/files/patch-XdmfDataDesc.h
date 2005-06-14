--- Utilities/Xdmf/libsrc/XdmfDataDesc.h.orig	Tue Jun  7 16:08:31 2005
+++ Utilities/Xdmf/libsrc/XdmfDataDesc.h	Tue Jun  7 16:08:31 2005
@@ -208,7 +208,7 @@
   XdmfInt32  Rank;
   XdmfInt64  NextOffset;
   XdmfInt64  Dimension[XDMF_MAX_DIMENSION];
-  hssize_t  Start[XDMF_MAX_DIMENSION];
+  hsize_t  Start[XDMF_MAX_DIMENSION];
   hsize_t    Stride[XDMF_MAX_DIMENSION];
   hsize_t    Count[XDMF_MAX_DIMENSION];
 
