--- vendor/github.com/modern-go/reflect2/unsafe_link.go.orig	2022-04-16 22:01:31 UTC
+++ vendor/github.com/modern-go/reflect2/unsafe_link.go
@@ -19,19 +19,13 @@ func typedslicecopy(elemType unsafe.Pointer, dst, src 
 
 //go:linkname mapassign reflect.mapassign
 //go:noescape
-func mapassign(rtype unsafe.Pointer, m unsafe.Pointer, key, val unsafe.Pointer)
+func mapassign(rtype unsafe.Pointer, m unsafe.Pointer, key unsafe.Pointer, val unsafe.Pointer)
 
 //go:linkname mapaccess reflect.mapaccess
 //go:noescape
 func mapaccess(rtype unsafe.Pointer, m unsafe.Pointer, key unsafe.Pointer) (val unsafe.Pointer)
 
-// m escapes into the return value, but the caller of mapiterinit
-// doesn't let the return value escape.
 //go:noescape
-//go:linkname mapiterinit reflect.mapiterinit
-func mapiterinit(rtype unsafe.Pointer, m unsafe.Pointer) *hiter
-
-//go:noescape
 //go:linkname mapiternext reflect.mapiternext
 func mapiternext(it *hiter)
 
@@ -42,9 +36,21 @@ func ifaceE2I(rtype unsafe.Pointer, src interface{}, d
 // If you modify hiter, also change cmd/internal/gc/reflect.go to indicate
 // the layout of this structure.
 type hiter struct {
-	key   unsafe.Pointer // Must be in first position.  Write nil to indicate iteration end (see cmd/internal/gc/range.go).
-	value unsafe.Pointer // Must be in second position (see cmd/internal/gc/range.go).
-	// rest fields are ignored
+	key         unsafe.Pointer
+	value       unsafe.Pointer
+	t           unsafe.Pointer
+	h           unsafe.Pointer
+	buckets     unsafe.Pointer
+	bptr        unsafe.Pointer
+	overflow    *[]unsafe.Pointer
+	oldoverflow *[]unsafe.Pointer
+	startBucket uintptr
+	offset      uint8
+	wrapped     bool
+	B           uint8
+	i           uint8
+	bucket      uintptr
+	checkBucket uintptr
 }
 
 // add returns p+x.
