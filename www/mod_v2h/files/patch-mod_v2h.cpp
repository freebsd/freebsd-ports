--- mod_v2h.cpp.orig	Sat Apr  9 16:38:04 2005
+++ mod_v2h.cpp	Sat Apr  9 16:38:30 2005
@@ -199,6 +199,7 @@
 	}
 };
 
+template <>
 class plist<char*> {
   protected:
 	osize_t sz;
