--- src/FontVault.h.orig	Fri Nov 22 00:07:06 2002
+++ src/FontVault.h	Thu Nov 28 23:41:37 2002
@@ -34,7 +34,7 @@
 	   }
 };
 
-#if (HASHMAP_NAMESPACE == __gnu_cxx)
+#if defined(HAVE_GNU_CXX_HASHMAP)
        typedef __gnu_cxx::hash_map<std::string, TTF_Font*, ures_hasher, ures_eqstr> Fonts_HashMap;
 #else
        typedef std::hash_map<std::string, TTF_Font*, ures_hasher, ures_eqstr> Fonts_HashMap;
