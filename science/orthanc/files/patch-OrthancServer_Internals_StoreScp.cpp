--- OrthancServer/Internals/StoreScp.cpp.orig	2015-02-12 13:47:38 UTC
+++ OrthancServer/Internals/StoreScp.cpp
@@ -182,7 +182,7 @@ namespace Orthanc
 
           // check the image to make sure it is consistent, i.e. that its sopClass and sopInstance correspond
           // to those mentioned in the request. If not, set the status in the response message variable.
-          if ((rsp->DimseStatus == STATUS_Success))
+          if (rsp->DimseStatus == STATUS_Success)
           {
             // which SOP class and SOP instance ?
             if (!DU_findSOPClassAndInstanceInDataSet(*imageDataSet, sopClass, sopInstance, /*opt_correctUIDPadding*/ OFFalse))
