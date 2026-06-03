--- src/LogStream.h.orig	2026-03-24 19:59:40 UTC
+++ src/LogStream.h
@@ -129,6 +129,7 @@ LogStream & operator<<( LogStream & str, long long    
 LogStream & operator<<( LogStream & str, long          val );
 LogStream & operator<<( LogStream & str, unsigned long val );
 LogStream & operator<<( LogStream & str, long long     val );
+LogStream & operator<<( LogStream & str, unsigned long long val );
 LogStream & operator<<( LogStream & str, double        val );
 LogStream & operator<<( LogStream & str, bool val );
 LogStream & operator<<( LogStream & str, char val );
