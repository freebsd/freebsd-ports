
$FreeBSD$

--- src/symboltable.cc.orig	Fri Feb 21 23:32:21 2003
+++ src/symboltable.cc	Fri Feb 21 23:35:23 2003
@@ -13,6 +13,8 @@
 #include <cstdlib>		// For malloc() and friends
 #include "symboltable.h"
 
+using namespace std;
+
 static char *make_c_string(const string &s);
 
 map<string,string> table;	/* XXX - Is this going to cause problems on
