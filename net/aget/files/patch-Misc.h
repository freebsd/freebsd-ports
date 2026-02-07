--- Misc.h.orig	2009-05-12 05:24:18 UTC
+++ Misc.h
@@ -24,7 +24,7 @@ void Log(char *, ...);				/* Log 						*/
 void updateProgressBar(float, float);
 void handleHttpRetcode(char *);
 
-time_t  t_start, t_finish;
+extern time_t  t_start, t_finish;
 
 #endif
 
