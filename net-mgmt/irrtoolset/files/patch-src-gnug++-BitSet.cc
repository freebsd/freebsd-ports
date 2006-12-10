--- src/gnug++/BitSet.cc.orig	2004-07-30 12:58:11.000000000 +0200
+++ src/gnug++/BitSet.cc
@@ -30,7 +30,11 @@ Foundation, 59 Temple Place - Suite 330,
 #include <new>
 #include <builtin.h>
 #include <string>
+#if (__GNUC__ > 2)
 #include <sstream>
+#else
+#include <strstream.h>
+#endif
 
 using namespace std;
 
@@ -895,8 +899,11 @@ const char* BitSettoa(const BitSet& x, c
   trim(x.rep);
   int wrksiz = (x.rep->len + 1) * BITSETBITS + 2;
   char* fmtbase = (char *) _libgxx_fmtq.alloc(wrksiz);
-  //ostrstream stream(fmtbase, wrksiz);
+#if (__GNUC__ > 2)
   std::ostringstream stream(fmtbase, ios_base::out | ios_base::trunc);
+#else
+  ostrstream stream(fmtbase, wrksiz);
+#endif
   
   x.printon(stream, f, t, star);
   stream << ends;
@@ -1043,11 +1050,17 @@ BitSet atoBitSet(const char* s, char f, 
 
 ostream& operator<<(ostream& s, const BitSet& x)
 {
+#if (__GNUC__ > 2)
     ostream::sentry opfx(s);
 
     if (opfx) {
         x.printon(s);
     }
+#else
+	if (s.opfx()) {
+		x.printon(s);
+	}
+#endif
     return s;
 }
 
