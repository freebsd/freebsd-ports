--- src/core/twlocale.h.orig	2011-11-21 17:06:56.000000000 +0100
+++ src/core/twlocale.h	2014-06-15 01:48:46.000000000 +0200
@@ -110,7 +110,7 @@ namespace tss
 #if USE_STD_CPP_LOCALE_WORKAROUND
             return std::use_facet( l, pf );
 #else
-            return std::use_facet< FacetT >( l ); pf;  // This is C++ standard
+            return std::use_facet< FacetT >( l ); (void)pf;  // This is C++ standard
 #endif
     }
 }
