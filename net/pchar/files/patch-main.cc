--- main.cc.orig	2005-02-13 05:32:18.000000000 +0900
+++ main.cc	2013-05-06 00:41:42.842653383 +0900
@@ -292,7 +292,7 @@
 //
 // Output:  ASCII representation of network protocol name.
 //
-char *GetPrintableNetworkProtocol(NetworkProtocolType np)
+const char *GetPrintableNetworkProtocol(NetworkProtocolType np)
 {
     switch (np) {
     case (NetworkProtocolIpv4Udp): 
@@ -371,7 +371,7 @@
 	case 'b': {
 	    Burst = atoi(optarg);
 	    if (Burst < 1) {
-		fprintf(stderr, "Warning: burst size %d too small; resetting to 1\n");
+		fprintf(stderr, "Warning: burst size %u too small; resetting to 1\n", Burst);
 		Burst = 1;
 	    }
 	    break;
