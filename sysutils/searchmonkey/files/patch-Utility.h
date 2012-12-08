--- Utility.h.orig	2010-05-16 20:37:32.000000000 +0900
+++ Utility.h	2012-10-17 06:41:46.000000000 +0900
@@ -92,16 +92,6 @@
     CallEach(observers, searchable, &Subject::Register);
     here the Subject is the type of Caller
 */
-template <typename CalleeContainer, typename Caller, typename Op>
-void CallEach(const CalleeContainer& container, Caller& caller, Op op)
-{
-    for_each(container.begin(), container.end(), bind1st(mem_fun(op), caller));
-}
-template <typename T>
-bool IsValueInRange(T value, T lowerBound, T upperBound)
-{
-    return LowerBoundFit(value, lowerBound) && UpperBoundFit(value, upperBound);
-}
 template <typename T>
 bool BoundSpecified(T boundValue)
 {
@@ -129,5 +119,15 @@
 
     return false;
 }
+template <typename CalleeContainer, typename Caller, typename Op>
+void CallEach(const CalleeContainer& container, Caller& caller, Op op)
+{
+    for_each(container.begin(), container.end(), bind1st(mem_fun(op), caller));
+}
+template <typename T>
+bool IsValueInRange(T value, T lowerBound, T upperBound)
+{
+    return LowerBoundFit(value, lowerBound) && UpperBoundFit(value, upperBound);
+}
 
 #endif
