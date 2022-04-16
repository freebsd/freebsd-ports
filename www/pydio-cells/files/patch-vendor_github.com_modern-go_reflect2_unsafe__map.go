--- vendor/github.com/modern-go/reflect2/unsafe_map.go.orig	2022-04-16 22:00:28 UTC
+++ vendor/github.com/modern-go/reflect2/unsafe_map.go
@@ -107,14 +107,6 @@ func (type2 *UnsafeMapType) Iterate(obj interface{}) M
 	return type2.UnsafeIterate(objEFace.data)
 }
 
-func (type2 *UnsafeMapType) UnsafeIterate(obj unsafe.Pointer) MapIterator {
-	return &UnsafeMapIterator{
-		hiter:      mapiterinit(type2.rtype, *(*unsafe.Pointer)(obj)),
-		pKeyRType:  type2.pKeyRType,
-		pElemRType: type2.pElemRType,
-	}
-}
-
 type UnsafeMapIterator struct {
 	*hiter
 	pKeyRType  unsafe.Pointer
