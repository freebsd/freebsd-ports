--- src/kmplayershared.h.orig
+++ src/kmplayershared.h
@@ -214,8 +214,8 @@
     // operator bool () const { return data && !!data->ptr; }
     bool operator == (const WeakPtr<T> & w) const { return data == w.data; }
     bool operator == (const SharedPtr<T> & s) const { return data == s.data; }
-    bool operator == (const T * t) const { return (!t && !data) || (data && data.ptr == t); }
-    bool operator == (T * t) const { return (!t && !data) || (data && data.ptr == t); }
+    bool operator == (const T * t) const { return (!t && !data) || (data && data->ptr == t); }
+    bool operator == (T * t) const { return (!t && !data) || (data && data->ptr == t); }
     bool operator != (const WeakPtr<T> & w) const { return data != w.data; }
     bool operator != (const SharedPtr<T> & s) const { return data != s.data; }
     operator T * () { return data ? data->ptr : 0L; }
