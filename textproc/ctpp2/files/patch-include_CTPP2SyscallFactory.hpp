--- include/CTPP2SyscallFactory.hpp.orig	2012-08-02 07:22:44 UTC
+++ include/CTPP2SyscallFactory.hpp
@@ -104,8 +104,7 @@ class CTPP2DECL SyscallFactory (private)
 	  @struct HandlerRefsSort SyscallFactory.hpp <SyscallFactory.hpp>
 	  @brief Case-insensitive sorting functor
 	*/
-	struct HandlerRefsSort:
-	  public STLW::binary_function<STLW::string, STLW::string, bool>
+	struct HandlerRefsSort
 	{
 		/**
 		  @brief comparison operator
