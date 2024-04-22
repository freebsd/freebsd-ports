- workaround for https://github.com/fraunhoferhhi/vvdec/issues/170

--- source/Lib/vvdec/vvdecimpl.h.orig	2024-03-13 17:45:41 UTC
+++ source/Lib/vvdec/vvdecimpl.h
@@ -225,7 +225,7 @@ inline auto VVDecImpl::catchExceptions( MembFunc fn, A
   static auto returnErrOrNullptr = []( intptr_t err )
   {
     if( std::is_pointer<TRet>() )
-      return (TRet) NULL;
+      return (TRet) 0;
     return (TRet) err;
   };
 
