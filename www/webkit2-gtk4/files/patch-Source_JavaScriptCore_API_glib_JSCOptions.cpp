Unbreak i386:
- revert https://trac.webkit.org/changeset/241014/webkit
- https://bugs.webkit.org/show_bug.cgi?id=194330

Index: Source/JavaScriptCore/API/glib/JSCOptions.cpp
--- Source/JavaScriptCore/API/glib/JSCOptions.cpp.orig
+++ Source/JavaScriptCore/API/glib/JSCOptions.cpp
@@ -73,7 +73,6 @@ static void valueToGValue(int32_t value, GValue* gValu
     g_value_set_int(gValue, value);
 }
 
-#if CPU(ADDRESS64)
 static bool valueFromGValue(const GValue* gValue, unsigned& value)
 {
     value = g_value_get_uint(gValue);
@@ -84,7 +83,6 @@ static void valueToGValue(unsigned value, GValue* gVal
 {
     g_value_set_uint(gValue, value);
 }
-#endif
 
 static bool valueFromGValue(const GValue* gValue, size_t& value)
 {
@@ -556,12 +554,10 @@ static JSCOptionType jscOptionsType(int)
     return JSC_OPTION_INT;
 }
 
-#if CPU(ADDRESS64)
 static JSCOptionType jscOptionsType(unsigned)
 {
     return JSC_OPTION_UINT;
 }
-#endif
 
 static JSCOptionType jscOptionsType(size_t)
 {
