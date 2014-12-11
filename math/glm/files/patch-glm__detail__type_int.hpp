--- glm/detail/type_int.hpp.orig	2014-12-04 12:55:42.000000000 -0500
+++ glm/detail/type_int.hpp	2014-12-04 12:57:55.000000000 -0500
@@ -32,22 +32,22 @@
 #include "setup.hpp"
 
 #if GLM_HAS_EXTENDED_INTEGER_TYPE
-#	include <cstdint>
+#	include <tr1/cstdint>
 #endif
 
 namespace glm{
 namespace detail
 {
 #	if GLM_HAS_EXTENDED_INTEGER_TYPE
-		typedef std::int8_t					int8;
-		typedef std::int16_t				int16;
-		typedef std::int32_t				int32;
-		typedef std::int64_t				int64;
-	
-		typedef std::uint8_t				uint8;
-		typedef std::uint16_t				uint16;
-		typedef std::uint32_t				uint32;
-		typedef std::uint64_t				uint64;
+		typedef ::int8_t					int8;
+		typedef ::int16_t					int16;
+		typedef ::int32_t					int32;
+		typedef ::int64_t					int64;
+
+		typedef ::uint8_t					uint8;
+		typedef ::uint16_t					uint16;
+		typedef ::uint32_t					uint32;
+		typedef ::uint64_t					uint64;
 #	else
 #		if(defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)) // C99 detected, 64 bit types available
 			typedef int64_t					sint64;
