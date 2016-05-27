--- libretroshare/src/rsserver/rsinit.cc.orig	2016-02-05 19:04:46 UTC
+++ libretroshare/src/rsserver/rsinit.cc
@@ -367,7 +367,7 @@ int RsInit::InitRetroShare(int argcIgnor
 #ifdef LOCALNET_TESTING
 			   >> parameter('R',"restrict-port" ,portRestrictions             ,"port1-port2","Apply port restriction"                   ,false)
 #endif
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
  				>> help('h',"help","Display this Help") ;
 #else
 				>> help() ;
