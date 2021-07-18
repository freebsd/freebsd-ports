--- 3rdparty/gmock/include/gmock/internal/gmock-internal-utils.h.orig	2014-10-22 20:07:20 UTC
+++ 3rdparty/gmock/include/gmock/internal/gmock-internal-utils.h
@@ -361,17 +361,30 @@ template <typename T> struct DecayArray<T[]> {
   typedef const T* type;
 };
 
-// Invalid<T>() returns an invalid value of type T.  This is useful
+// Disable MSVC warnings for infinite recursion, since in this case the
+// the recursion is unreachable.
+#ifdef _MSC_VER
+# pragma warning(push)
+# pragma warning(disable:4717)
+#endif
+
+// Invalid<T>() is usable as an expression of type T, but will terminate
+// the program with an assertion failure if actually run.  This is useful
 // when a value of type T is needed for compilation, but the statement
 // will not really be executed (or we don't care if the statement
 // crashes).
 template <typename T>
 inline T Invalid() {
-  return const_cast<typename remove_reference<T>::type&>(
-      *static_cast<volatile typename remove_reference<T>::type*>(NULL));
+  Assert(false, "", -1, "Internal error: attempt to return invalid value");
+  // This statement is unreachable, and would never terminate even if it
+  // could be reached. It is provided only to placate compiler warnings
+  // about missing return statements.
+  return Invalid<T>();
 }
-template <>
-inline void Invalid<void>() {}
+
+#ifdef _MSC_VER
+# pragma warning(pop)
+#endif
 
 // Given a raw type (i.e. having no top-level reference or const
 // modifier) RawContainer that's either an STL-style container or a
