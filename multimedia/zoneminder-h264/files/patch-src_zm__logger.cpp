--- src/zm_logger.cpp.orig	2016-11-03 11:08:37 UTC
+++ src/zm_logger.cpp
@@ -515,8 +515,9 @@ void Logger::logPrint( bool hex, const c
     va_list     argPtr;
     struct timeval  timeVal;
 
-    const char * const file = basename(filepath);
-    
+    char *filecopy = strdup(filepath);
+    const char * const file = basename(filecopy);  
+ 
     if ( level < PANIC || level > DEBUG9 )
       Panic( "Invalid logger level %d", level );
 
@@ -635,6 +636,8 @@ void Logger::logPrint( bool hex, const c
         abort();
       exit( -1 );
     }
+
+    free(filecopy);
   }
 }
 
