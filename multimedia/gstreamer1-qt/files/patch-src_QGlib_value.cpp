--- src/QGlib/value.cpp.orig	2021-08-03 00:00:47 UTC
+++ src/QGlib/value.cpp
@@ -57,7 +57,7 @@ Dispatcher::Dispatcher()
     }; \
     setVTable(GTYPE, ValueVTable(ValueVTable_##NICK::set, ValueVTable_##NICK::get));
 
-    DECLARE_VTABLE(char, char, Type::Char)
+    DECLARE_VTABLE(char, schar, Type::Char)
     DECLARE_VTABLE(unsigned char, uchar, Type::Uchar)
     DECLARE_VTABLE(bool, boolean, Type::Boolean)
     DECLARE_VTABLE(int, int, Type::Int)
