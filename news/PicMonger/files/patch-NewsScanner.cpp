--- NewsScanner.cpp.orig	Fri Jul 14 12:58:22 2000
+++ NewsScanner.cpp	Fri Dec  1 22:19:44 2006
@@ -58,7 +58,7 @@
 
 
 NewsScanner::NewsScanner(NewsScannerView *nsv, const char* saddr, 
-	const char* ng, ScanOrder so=NS_FORWARD)
+	const char* ng, ScanOrder so)
 
 	: 	p_NSV(nsv), so_(so), htmlgen("."), p_htgen( 0 ),
 		serv_addr( saddr ), serv_port( 119 ), group( ng ),
