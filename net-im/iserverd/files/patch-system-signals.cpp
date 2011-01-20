--- system/signals.cpp.orig	2011-01-20 14:21:46.000000000 +0100
+++ system/signals.cpp	2011-01-20 14:22:51.000000000 +0100
@@ -274,7 +274,7 @@
 		   
      fprintf(ftrace, "IServerd stack backtrace dump: \n\n");
 
-#ifdef HAVE_BACKTRACE  
+#if 0
      /* trying to dump stack backtrace */
      void *addr_array[32];
      int addr_num = backtrace(addr_array, 32);
