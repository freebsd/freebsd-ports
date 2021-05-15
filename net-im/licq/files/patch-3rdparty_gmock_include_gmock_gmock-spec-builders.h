--- 3rdparty/gmock/include/gmock/gmock-spec-builders.h.orig	2014-10-22 20:07:20 UTC
+++ 3rdparty/gmock/include/gmock/gmock-spec-builders.h
@@ -211,7 +211,7 @@ class GTEST_API_ UntypedFunctionMockerBase {
   // arguments.  This function can be safely called from multiple
   // threads concurrently.  The caller is responsible for deleting the
   // result.
-  const UntypedActionResultHolderBase* UntypedInvokeWith(
+  UntypedActionResultHolderBase* UntypedInvokeWith(
       const void* untyped_args)
           GTEST_LOCK_EXCLUDED_(g_gmock_mutex);
 
@@ -1289,6 +1289,58 @@ class MockSpec {
   GTEST_DISALLOW_ASSIGN_(MockSpec);
 };  // class MockSpec
 
+// Wrapper type for generically holding an ordinary value or lvalue reference.
+// If T is not a reference type, it must be copyable or movable.
+// ReferenceOrValueWrapper<T> is movable, and will also be copyable unless
+// T is a move-only value type (which means that it will always be copyable
+// if the current platform does not support move semantics).
+//
+// The primary template defines handling for values, but function header
+// comments describe the contract for the whole template (including
+// specializations).
+template <typename T>
+class ReferenceOrValueWrapper {
+ public:
+  // Constructs a wrapper from the given value/reference.
+  explicit ReferenceOrValueWrapper(T value)
+      : value_(GTEST_MOVE_(value)) {}
+
+  // Unwraps and returns the underlying value/reference, exactly as
+  // originally passed. The behavior of calling this more than once on
+  // the same object is unspecified.
+  T Unwrap() {
+    return GTEST_MOVE_(value_);
+  }
+
+  // Provides nondestructive access to the underlying value/reference.
+  // Always returns a const reference (more precisely,
+  // const RemoveReference<T>&). The behavior of calling this after
+  // calling Unwrap on the same object is unspecified.
+  const T& Peek() const {
+    return value_;
+  }
+
+ private:
+  T value_;
+};
+
+// Specialization for lvalue reference types. See primary template
+// for documentation.
+template <typename T>
+class ReferenceOrValueWrapper<T&> {
+ public:
+  // Workaround for debatable pass-by-reference lint warning (c-library-team
+  // policy precludes NOLINT in this context)
+  typedef T& reference;
+  explicit ReferenceOrValueWrapper(reference ref)
+      : value_ptr_(&ref) {}
+  T& Unwrap() { return *value_ptr_; }
+  const T& Peek() const { return *value_ptr_; }
+
+ private:
+  T* value_ptr_;
+};
+
 // MSVC warns about using 'this' in base member initializer list, so
 // we need to temporarily disable the warning.  We have to do it for
 // the entire class to suppress the warning, even though it's about
@@ -1320,23 +1372,16 @@ class UntypedActionResultHolderBase {
 template <typename T>
 class ActionResultHolder : public UntypedActionResultHolderBase {
  public:
-  explicit ActionResultHolder(T a_value) : value_(a_value) {}
-
-  // The compiler-generated copy constructor and assignment operator
-  // are exactly what we need, so we don't need to define them.
-
-  // Returns the held value and deletes this object.
-  T GetValueAndDelete() const {
-    T retval(value_);
-    delete this;
-    return retval;
+  // Returns the held value. Must not be called more than once.
+  T Unwrap() {
+    return result_.Unwrap();
   }
 
   // Prints the held value as an action's result to os.
   virtual void PrintAsActionResult(::std::ostream* os) const {
     *os << "\n          Returns: ";
     // T may be a reference type, so we don't use UniversalPrint().
-    UniversalPrinter<T>::Print(value_, os);
+    UniversalPrinter<T>::Print(result_.Peek(), os);
   }
 
   // Performs the given mock function's default action and returns the
@@ -1346,8 +1391,8 @@ class ActionResultHolder : public UntypedActionResultH
       const FunctionMockerBase<F>* func_mocker,
       const typename Function<F>::ArgumentTuple& args,
       const string& call_description) {
-    return new ActionResultHolder(
-        func_mocker->PerformDefaultAction(args, call_description));
+    return new ActionResultHolder(Wrapper(
+        func_mocker->PerformDefaultAction(args, call_description)));
   }
 
   // Performs the given action and returns the result in a new-ed
@@ -1356,42 +1401,52 @@ class ActionResultHolder : public UntypedActionResultH
   static ActionResultHolder*
   PerformAction(const Action<F>& action,
                 const typename Function<F>::ArgumentTuple& args) {
-    return new ActionResultHolder(action.Perform(args));
+    return new ActionResultHolder(Wrapper(action.Perform(args)));
   }
 
  private:
-  T value_;
+  typedef ReferenceOrValueWrapper<T> Wrapper;
 
-  // T could be a reference type, so = isn't supported.
-  GTEST_DISALLOW_ASSIGN_(ActionResultHolder);
+  explicit ActionResultHolder(Wrapper result)
+      : result_(GTEST_MOVE_(result)) {}
+
+  Wrapper result_;
+
+  GTEST_DISALLOW_COPY_AND_ASSIGN_(ActionResultHolder);
 };
 
 // Specialization for T = void.
 template <>
 class ActionResultHolder<void> : public UntypedActionResultHolderBase {
  public:
-  void GetValueAndDelete() const { delete this; }
+  void Unwrap() { }
 
   virtual void PrintAsActionResult(::std::ostream* /* os */) const {}
 
-  // Performs the given mock function's default action and returns NULL;
+  // Performs the given mock function's default action and returns ownership
+  // of an empty ActionResultHolder*.
   template <typename F>
   static ActionResultHolder* PerformDefaultAction(
       const FunctionMockerBase<F>* func_mocker,
       const typename Function<F>::ArgumentTuple& args,
       const string& call_description) {
     func_mocker->PerformDefaultAction(args, call_description);
-    return NULL;
+    return new ActionResultHolder;
   }
 
-  // Performs the given action and returns NULL.
+  // Performs the given action and returns ownership of an empty
+  // ActionResultHolder*.
   template <typename F>
   static ActionResultHolder* PerformAction(
       const Action<F>& action,
       const typename Function<F>::ArgumentTuple& args) {
     action.Perform(args);
-    return NULL;
+    return new ActionResultHolder;
   }
+
+ private:
+  ActionResultHolder() {}
+  GTEST_DISALLOW_COPY_AND_ASSIGN_(ActionResultHolder);
 };
 
 // The base of the function mocker class for the given function type.
@@ -1526,8 +1581,9 @@ class FunctionMockerBase : public UntypedFunctionMocke
   // threads concurrently.
   Result InvokeWith(const ArgumentTuple& args)
         GTEST_LOCK_EXCLUDED_(g_gmock_mutex) {
-    return static_cast<const ResultHolder*>(
-        this->UntypedInvokeWith(&args))->GetValueAndDelete();
+    scoped_ptr<ResultHolder> holder(
+        DownCast_<ResultHolder*>(this->UntypedInvokeWith(&args)));
+    return holder->Unwrap();
   }
 
   // Adds and returns a default action spec for this mock function.
