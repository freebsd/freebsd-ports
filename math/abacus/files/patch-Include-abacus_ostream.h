--- Include/abacus/ostream.h.orig	2010-11-19 15:47:57 UTC
+++ Include/abacus/ostream.h
@@ -47,7 +47,7 @@ using namespace std;
 class ABA_OSTREAM;
 ABA_OSTREAM& endl(ABA_OSTREAM &o);
 ABA_OSTREAM& flush(ABA_OSTREAM &o);
-using ::endl;
+using std::endl;
 
 #include "abacus/abacusroot.h"
 class ABA_STRING;
