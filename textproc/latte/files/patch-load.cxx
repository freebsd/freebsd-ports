--- load.cxx.orig	Fri Oct 22 12:59:24 1999
+++ load.cxx	Fri Mar 19 01:17:52 2004
@@ -19,6 +19,8 @@
 #include <latte-fstream.h>
 #include <unistd.h>
 
+using namespace std;
+
 class LoadVisitor : public Latte_Visitor {
  public:
   void visit_str(Latte_Str &) {}
