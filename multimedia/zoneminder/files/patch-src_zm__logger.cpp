--- src/zm_logger.cpp	
+++ src/zm_logger.cpp	
@@ -504,7 +504,8 @@ 
     va_list     argPtr;
     struct timeval  timeVal;
 
-    const char * const file = basename(filepath);
+    char *filecopy = strdup(filepath);
+    const char * const file = basename(filecopy);
     
     if ( level < PANIC || level > DEBUG9 )
       Panic( "Invalid logger level %d", level );
@@ -624,6 +625,8 @@ 
         abort();
       exit( -1 );
     }
+
+    free(filecopy);
   }
 }
