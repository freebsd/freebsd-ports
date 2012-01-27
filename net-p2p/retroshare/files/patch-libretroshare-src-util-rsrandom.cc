--- libretroshare/src/util/rsrandom.cc~	2011-07-05 00:59:39.000000000 +0200
+++ libretroshare/src/util/rsrandom.cc	2012-01-15 04:56:47.000000000 +0100
@@ -13,7 +13,7 @@
   #ifdef __APPLE__
 	static bool auto_seed = RSRandom::seed( (time(NULL) + pthread_mach_thread_np(pthread_self())*0x1293fe + (getpid()^0x113ef76b))^0x18e34a12 ) ;
   #else
-    static bool auto_seed = RSRandom::seed( (time(NULL) + pthread_self()*0x1293fe + (getpid()^0x113ef76b))^0x18e34a12 ) ;
+//    static bool auto_seed = RSRandom::seed( (time(NULL) + pthread_self()*0x1293fe + (getpid()^0x113ef76b))^0x18e34a12 ) ;
   #endif
 #endif
 bool RSRandom::seed(uint32_t s) 
