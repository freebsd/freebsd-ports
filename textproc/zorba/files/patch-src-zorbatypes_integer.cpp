--- src/zorbatypes/integer.cpp.orig	2011-09-15 13:39:45.000000000 +0200
+++ src/zorbatypes/integer.cpp	2011-09-15 13:40:12.000000000 +0200
@@ -208,7 +208,11 @@
   MAPM const temp( d.sign() >= 0 ? d.floor() : d.ceil() );
   char *const buf = new char[ temp.exponent() + 3 ];
   temp.toIntegerString( buf );
+#if defined( WIN32 )
   value_type const result( std::strtoll( buf, nullptr, 10 ) );
+#else
+  value_type const result( strtoll( buf, nullptr, 10 ) );
+#endif
   delete[] buf;
   return result;
 }
