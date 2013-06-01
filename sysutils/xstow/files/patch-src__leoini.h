--- src/leoini.h~	2013-06-01 22:28:45.000000000 +0300
+++ src/leoini.h	2013-06-01 22:32:05.000000000 +0300
@@ -260,11 +260,9 @@
 
     if( start == std::string::npos ||
 	end == std::string::npos )
-      s = "";
-    else
-      s = s.substr( start+1, start-end -1 );
+      return s2x<A>("");
 
-    return s2x<A>(s);
+    return s2x<A>(s.substr( start+1, start-end -1 ));
   }
 } // namespace Leo
 
