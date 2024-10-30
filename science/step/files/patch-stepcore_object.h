Clang >= 19.1.0-rc1 requires a template argument list after an identifier
prefixed by the template keyword. [1]

/wrkdirs/usr/ports/science/step/work/step-23.08.5/stepcore/object.h:252:45:
error: a template argument list is expected after a name prefixed by the
template keyword [-Wmissing-template-arg-list-after-template-kw]
  252 |     if(!src || !src->metaObject()->template inherits(_Dst())) return NULL;

[1] https://github.com/llvm/llvm-project/commit/f46d1463b835560d90ad3ac02b63c771e4ebe566

--- stepcore/object.h.orig	2024-02-10 03:35:30 UTC
+++ stepcore/object.h
@@ -249,7 +249,7 @@ _Dst stepcore_cast(_Src src) {
 /** Casts between pointers to Object */
 template<class _Dst, class _Src> // XXX: implement it better
 _Dst stepcore_cast(_Src src) {
-    if(!src || !src->metaObject()->template inherits(_Dst())) return NULL;
+    if(!src || !src->metaObject()->template inherits<_Dst>(_Dst())) return NULL;
     return static_cast<_Dst>(src);
 }
 
