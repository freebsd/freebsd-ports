--- src/lib/libmwaw_internal.hxx.orig	2017-11-13 09:08:03 UTC
+++ src/lib/libmwaw_internal.hxx
@@ -1027,7 +1027,7 @@ template <class T> class MWAWBox2 (public)
   }
   //! generic constructor
   template <class U> explicit MWAWBox2(MWAWBox2<U> const &p)
-    : m_data(p.min(), p.max())
+    : m_data(MWAWVec2<T>(p.min()), MWAWVec2<T>(p.max()))
   {
   }
 
