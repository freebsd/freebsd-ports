--- retroshare-nogui/src/retroshare.cc.orig	2016-02-05 19:04:46 UTC
+++ retroshare-nogui/src/retroshare.cc
@@ -86,7 +86,7 @@ int main(int argc, char **argv)
     // unfinished
     //args >> parameter("http-listen", listenAddress, "ipv6 address", "Listen only on the specified address.", false);
     args >> option("http-allow-all", allowAllIps, "allow connections from all IP adresses (default= localhost only)");
-#ifdef __APPLE__    
+#if defined(__APPLE__) || defined(__FreeBSD__)
     args >> help('h',"help","Display this Help");
 #else
     args >> help();
