--- 3rdparty/gmock/include/gmock/gmock-actions.h.orig	2014-10-22 20:07:20 UTC
+++ 3rdparty/gmock/include/gmock/gmock-actions.h
@@ -163,18 +163,27 @@ class DefaultValue {
   // Sets the default value for type T; requires T to be
   // copy-constructable and have a public destructor.
   static void Set(T x) {
-    delete value_;
-    value_ = new T(x);
+    delete producer_;
+    producer_ = new FixedValueProducer(x);
   }
 
+  // Provides a factory function to be called to generate the default value.
+  // This method can be used even if T is only move-constructible, but it is not
+  // limited to that case.
+  typedef T (*FactoryFunction)();
+  static void SetFactory(FactoryFunction factory) {
+    delete producer_;
+    producer_ = new FactoryValueProducer(factory);
+  }
+
   // Unsets the default value for type T.
   static void Clear() {
-    delete value_;
-    value_ = NULL;
+    delete producer_;
+    producer_ = NULL;
   }
 
   // Returns true iff the user has set the default value for type T.
-  static bool IsSet() { return value_ != NULL; }
+  static bool IsSet() { return producer_ != NULL; }
 
   // Returns true if T has a default return value set by the user or there
   // exists a built-in default value.
@@ -183,15 +192,42 @@ class DefaultValue {
   }
 
   // Returns the default value for type T if the user has set one;
-  // otherwise returns the built-in default value if there is one;
-  // otherwise aborts the process.
+  // otherwise returns the built-in default value. Requires that Exists()
+  // is true, which ensures that the return value is well-defined.
   static T Get() {
-    return value_ == NULL ?
-        internal::BuiltInDefaultValue<T>::Get() : *value_;
+    return producer_ == NULL ?
+        internal::BuiltInDefaultValue<T>::Get() : producer_->Produce();
   }
 
  private:
-  static const T* value_;
+  class ValueProducer {
+   public:
+    virtual ~ValueProducer() {}
+    virtual T Produce() = 0;
+  };
+
+  class FixedValueProducer : public ValueProducer {
+   public:
+    explicit FixedValueProducer(T value) : value_(value) {}
+    virtual T Produce() { return value_; }
+
+   private:
+    const T value_;
+    GTEST_DISALLOW_COPY_AND_ASSIGN_(FixedValueProducer);
+  };
+
+  class FactoryValueProducer : public ValueProducer {
+   public:
+    explicit FactoryValueProducer(FactoryFunction factory)
+        : factory_(factory) {}
+    virtual T Produce() { return factory_(); }
+
+   private:
+    const FactoryFunction factory_;
+    GTEST_DISALLOW_COPY_AND_ASSIGN_(FactoryValueProducer);
+  };
+
+  static ValueProducer* producer_;
 };
 
 // This partial specialization allows a user to set default values for
@@ -241,7 +277,7 @@ class DefaultValue<void> {
 
 // Points to the user-set default value for type T.
 template <typename T>
-const T* DefaultValue<T>::value_ = NULL;
+typename DefaultValue<T>::ValueProducer* DefaultValue<T>::producer_ = NULL;
 
 // Points to the user-set default value for type T&.
 template <typename T>
