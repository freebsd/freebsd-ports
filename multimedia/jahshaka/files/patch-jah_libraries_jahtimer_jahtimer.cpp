--- jah/libraries/jahtimer/jahtimer.cpp.orig
+++ jah/libraries/jahtimer/jahtimer.cpp
@@ -11,18 +11,22 @@
 
 void JahTimer::starttime( void ) 
 { 
-    ftime(&current_time); 
-    start_time = (int)current_time.millitm; 
+struct timezone tz;
 
-    start_time_float = (double)current_time.time + ((double)current_time.millitm / 1000.0);
+    gettimeofday(&current_time,&tz); 
+    start_time = (int)current_time.tv_usec; 
+
+    start_time_float = (double)current_time.tv_sec + ((double)current_time.tv_usec / 1000.0);
 
 }
 
 void JahTimer::endtime  ( void ) 
 { 
-    ftime(&current_time);
-    end_time = (int)current_time.millitm;
-    end_time_float = (double)current_time.time + ((double)current_time.millitm / 1000.0);
+struct timezone tz;
+
+    gettimeofday(&current_time,&tz);
+    end_time = (int)current_time.tv_usec;
+    end_time_float = (double)current_time.tv_sec + ((double)current_time.tv_usec / 1000.0);
     total_time_float = end_time_float - start_time_float;
 }
 
