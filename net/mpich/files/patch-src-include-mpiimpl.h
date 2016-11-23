--- src/include/mpiimpl.h.orig	2015-11-10 02:39:01 UTC
+++ src/include/mpiimpl.h
@@ -1528,7 +1528,7 @@ typedef struct MPID_Request {
 #ifdef MPID_DEV_REQUEST_DECL
     MPID_DEV_REQUEST_DECL
 #endif
-} MPID_Request ATTRIBUTE((__aligned__(32)));
+} ATTRIBUTE((__aligned__(32))) MPID_Request;
 
 extern MPIU_Object_alloc_t MPID_Request_mem;
 /* Preallocated request objects */
