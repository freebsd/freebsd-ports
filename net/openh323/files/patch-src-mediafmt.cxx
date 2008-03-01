diff -ruN src/mediafmt.cxx.orig src/mediafmt.cxx
--- src/mediafmt.cxx.orig   2005-01-11 02:12:13.000000000 -0500
+++ src/mediafmt.cxx       2007-12-31 14:48:26.000000000 -0500
@@ -395,7 +395,7 @@
     OpalMediaFormatFactory::KeyMap_T & keyMap = OpalMediaFormatFactory::GetKeyMap();
     OpalMediaFormatFactory::KeyMap_T::const_iterator r;
     for (r = keyMap.begin(); r != keyMap.end(); ++r) {
-      if (r->first.Find(search) != P_MAX_INDEX) {
+      if (r->first.find(search) != P_MAX_INDEX) {
         *this = *OpalMediaFormatFactory::CreateInstance(r->first);
         break;
       }
