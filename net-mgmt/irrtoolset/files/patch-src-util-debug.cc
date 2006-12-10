--- src/util/debug.cc.orig	2002-04-09 13:48:49.000000000 +0200
+++ src/util/debug.cc
@@ -108,7 +108,7 @@ void Abort() {
 }
 
 void copy_constructor(char *p) {
-   cerr << "Copy constructor called for " << p << "\n";
+   std::cerr << "Copy constructor called for " << p << std::endl;
 }
 
 #endif /* DEBUG */
