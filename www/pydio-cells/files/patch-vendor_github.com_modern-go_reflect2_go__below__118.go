--- vendor/github.com/modern-go/reflect2/go_below_118.go.orig	2022-04-16 21:56:08 UTC
+++ vendor/github.com/modern-go/reflect2/go_below_118.go
@@ -0,0 +1,21 @@
+//+build !go1.18
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
+func mapiterinit(rtype unsafe.Pointer, m unsafe.Pointer) (val *hiter)
+
+func (type2 *UnsafeMapType) UnsafeIterate(obj unsafe.Pointer) MapIterator {
+	return &UnsafeMapIterator{
+		hiter:      mapiterinit(type2.rtype, *(*unsafe.Pointer)(obj)),
+		pKeyRType:  type2.pKeyRType,
+		pElemRType: type2.pElemRType,
+	}
+}
