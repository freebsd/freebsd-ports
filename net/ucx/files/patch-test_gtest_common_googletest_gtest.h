--- test/gtest/common/googletest/gtest.h.orig	2026-06-12 20:49:52 UTC
+++ test/gtest/common/googletest/gtest.h
@@ -1629,6 +1629,14 @@ GTEST_IMPL_CMP_HELPER_(GT, >);
 GTEST_IMPL_CMP_HELPER_(GT, >);
 
 #undef GTEST_IMPL_CMP_HELPER_
+template <typename T>
+AssertionResult CmpHelperNE(const char* e1, const char* e2, std::nullptr_t, T* val2) {
+  if (nullptr != val2) { return AssertionSuccess(); }
+  return CmpHelperOpFailure(e1, e2, static_cast<T*>(nullptr), val2, "!="); }
+template <typename T>
+AssertionResult CmpHelperNE(const char* e1, const char* e2, T* val1, std::nullptr_t) {
+  if (val1 != nullptr) { return AssertionSuccess(); }
+  return CmpHelperOpFailure(e1, e2, val1, static_cast<T*>(nullptr), "!="); }
 
 // The helper function for {ASSERT|EXPECT}_STREQ.
 //
