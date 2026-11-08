--- vendor/github.com/keys-pub/go-libfido2/fido2.go.orig	2026-08-23 12:31:13 UTC
+++ vendor/github.com/keys-pub/go-libfido2/fido2.go
@@ -1094,7 +1094,10 @@ func goStrings(argc C.int, argv **C.char) []string {
 
 func goStrings(argc C.int, argv **C.char) []string {
 	length := int(argc)
-	tmpslice := (*[1 << 30]*C.char)(unsafe.Pointer(argv))[:length:length]
+	if length <= 0 || argv == nil {
+		return nil
+	}
+	tmpslice := unsafe.Slice(argv, length)
 	gostrings := make([]string, length)
 	for i, s := range tmpslice {
 		gostrings[i] = C.GoString(s)
@@ -1104,7 +1107,10 @@ func goBools(argc C.int, argv *C.bool) []bool {
 
 func goBools(argc C.int, argv *C.bool) []bool {
 	length := int(argc)
-	tmpslice := (*[1 << 30]C.bool)(unsafe.Pointer(argv))[:length:length]
+	if length <= 0 || argv == nil {
+		return nil
+	}
+	tmpslice := unsafe.Slice(argv, length)
 	gobools := make([]bool, length)
 	for i, s := range tmpslice {
 		gobools[i] = bool(s)
