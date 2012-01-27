+++ libbitdht/src/util/bdrandom.cc	2012-01-15 03:45:36.000000000 +0100
--- libbitdht/src/util/bdrandom.cc.orig	2012-01-15 03:45:07.000000000 +0100
@@ -13,7 +13,7 @@
   #ifdef __APPLE__
 	static bool auto_seed = bdRandom::seed( (time(NULL) + pthread_mach_thread_np(pthread_self())*0x1293fe + (getpid()^0x113ef76b))^0x18e34a12 ) ;
   #else
+//    static bool auto_seed = bdRandom::seed( (time(NULL) + pthread_self()*0x1293fe + (getpid()^0x113ef76b))^0x18e34a12 ) ;
-    static bool auto_seed = bdRandom::seed( (time(NULL) + pthread_self()*0x1293fe + (getpid()^0x113ef76b))^0x18e34a12 ) ;
   #endif
 #endif
 bool bdRandom::seed(uint32_t s) 
