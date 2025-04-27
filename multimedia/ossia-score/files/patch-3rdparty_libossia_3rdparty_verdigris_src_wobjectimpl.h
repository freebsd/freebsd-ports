Fix build with Qt >= 6.9.0

Backported from: https://github.com/woboq/verdigris/commit/9b3e3f26251444bf48011202db85c892b0f45c57

--- 3rdparty/libossia/3rdparty/verdigris/src/wobjectimpl.h.orig	2025-01-16 18:09:49 UTC
+++ 3rdparty/libossia/3rdparty/verdigris/src/wobjectimpl.h
@@ -796,13 +796,20 @@ struct DataBuilder {
         intCount += sizeof... (Ts);
     }
 
-#if QT_VERSION >= QT_VERSION_CHECK(6,0,0)
+#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
+#if QT_VERSION >= QT_VERSION_CHECK(6, 9, 0)
+    template<class Unique, bool TypeMustBeComplete>
+    static constexpr const QtPrivate::QMetaTypeInterface *metaTypeInterface = QtPrivate::qTryMetaTypeInterfaceForType<Unique,  std::conditional_t<TypeMustBeComplete, void, Unique>>();
+#else
     template<class T, bool isComplete>
-    static constexpr const QtPrivate::QMetaTypeInterface *metaTypeInterface = QtPrivate::qTryMetaTypeInterfaceForType<T, QtPrivate::TypeAndForceComplete<T, std::integral_constant<bool, isComplete>>>();
-
-    template<class T, bool isComplete = false>
+    static constexpr const QtPrivate::QMetaTypeInterface *metaTypeInterface
+        = QtPrivate::qTryMetaTypeInterfaceForType<
+            T,
+            QtPrivate::TypeAndForceComplete<T, std::integral_constant<bool, isComplete>>>();
+#endif
+    template<class T, bool TypeMustBeComplete = false>
     constexpr void addMetaType() {
-        *metaTypeP++ = metaTypeInterface<T, isComplete>;
+        *metaTypeP++ = metaTypeInterface<T, TypeMustBeComplete>;
         metaTypeCount += 1;
     }
 #endif
