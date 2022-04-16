--- vendor/github.com/modern-go/reflect2/go_above_118.go.orig	2022-04-16 21:52:43 UTC
+++ vendor/github.com/modern-go/reflect2/go_above_118.go
@@ -0,0 +1,23 @@
+//+build go1.18
+
+package reflect2
+
+import (
+	"unsafe"
+)
+
+// m escapes into the return value, but the caller of mapiterinit
+// doesn't let the return value escape.
+//go:noescape
+//go:linkname mapiterinit reflect.mapiterinit
+func mapiterinit(rtype unsafe.Pointer, m unsafe.Pointer, it *hiter)
+
+func (type2 *UnsafeMapType) UnsafeIterate(obj unsafe.Pointer) MapIterator {
+	var it hiter
+	mapiterinit(type2.rtype, *(*unsafe.Pointer)(obj), &it)
+	return &UnsafeMapIterator{
+		hiter:      &it,
+		pKeyRType:  type2.pKeyRType,
+		pElemRType: type2.pElemRType,
+	}
+}
