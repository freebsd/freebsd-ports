--- src/LogStream.cpp.orig	2026-03-24 20:00:19 UTC
+++ src/LogStream.cpp
@@ -155,6 +155,11 @@ LogStream & operator<<( LogStream & str, long long val
     return logStreamOut<long long>( str, val );
 }
 
+LogStream & operator<<( LogStream & str, unsigned long long val )
+{
+    return logStreamOut<unsigned long long>( str, val );
+}
+
 
 LogStream & operator<<( LogStream & str, bool val )
 {
