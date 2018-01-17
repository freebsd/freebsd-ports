https://github.com/scim-im/scim/commit/bdeff0b45eda

--- src/scim_pointer.h.orig	2008-11-02 06:42:37 UTC
+++ src/scim_pointer.h
@@ -84,7 +84,7 @@ class Pointer (public)
     //!<
     //!< <BR>Initialize a new Pointer with any dumb pointer.
 
-    Pointer(Pointer& src) : t(0)
+    Pointer(const Pointer& src) : t(0)
     {
         set(src.get());
     }
