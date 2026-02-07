--- vendor/github.com/bep/golibsass/internal/libsass/a__cgo.go.orig	2022-06-19 12:45:21 UTC
+++ vendor/github.com/bep/golibsass/internal/libsass/a__cgo.go
@@ -5,9 +5,8 @@ package libsass
 //
 package libsass
 
-// #cgo CFLAGS: -O2 -fPIC
-// #cgo CPPFLAGS: -I../../libsass_src/include
-// #cgo CXXFLAGS: -g -std=c++0x -O2 -fPIC
-// #cgo LDFLAGS: -lstdc++ -lm
+// #cgo CFLAGS: -DUSE_LIBSASS_SRC
+// #cgo CXXFLAGS: -DUSE_LIBSASS_SRC -std=c++0x
+// #cgo LDFLAGS: -lm
 // #cgo darwin linux LDFLAGS: -ldl
 import "C"
