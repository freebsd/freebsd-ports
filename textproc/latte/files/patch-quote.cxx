--- quote.cxx.orig	Fri Oct 22 13:00:12 1999
+++ quote.cxx	Fri Mar 19 01:17:52 2004
@@ -17,6 +17,8 @@
 
 #include <latte.h>
 
+using namespace std;
+
 Latte_Quote::Latte_Quote(const Latte_Wstate &ws,
                          const Latte_FileLoc &loc,
                          enum Latte_Quote::Type type) :
