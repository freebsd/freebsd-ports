-- FreeBSD compatibility fixes for MLX image generation CGO code.
-- 1. Add FreeBSD LDFLAGS (-lc++ -ldl) required for C++ runtime and dynamic loading.
-- 2. Fall back to CPU stream in default_stream() when GPU stream is unavailable (no Metal on FreeBSD).
-- 3. Use CPU stream for safetensors loading on FreeBSD (Metal eval_gpu not implemented).
-- 4. Wrap mlx_load_safetensors with safe init mode to capture C++ exceptions as Go errors
--    instead of process exit(1), enabling proper error reporting to the user.
--- x/imagegen/mlx/mlx.go.orig	2026-06-03 07:41:51 UTC
+++ x/imagegen/mlx/mlx.go
@@ -4,6 +4,7 @@ package mlx
 #cgo CFLAGS: -O3 -I${SRCDIR}/../../mlxrunner/mlx/include -I${SRCDIR}
 #cgo darwin LDFLAGS: -lc++ -framework Metal -framework Foundation -framework Accelerate
 #cgo linux LDFLAGS: -lstdc++ -ldl
+#cgo freebsd LDFLAGS: -lc++ -ldl
 #cgo windows LDFLAGS: -lstdc++
 
 // Use generated wrappers instead of direct MLX headers
@@ -23,6 +24,9 @@ static inline mlx_stream default_stream() {
 static inline mlx_stream default_stream() {
     if (_default_stream.ctx == NULL) {
         _default_stream = mlx_default_gpu_stream_new();
+        if (_default_stream.ctx == NULL) {
+            _default_stream = mlx_default_cpu_stream_new();
+        }
     }
     return _default_stream;
 }
@@ -1512,13 +1516,21 @@ func LoadSafetensorsNative(path string) (*SafetensorsF
 	defer C.free(unsafe.Pointer(cPath))
 
 	stream := C.default_stream()
-	if runtime.GOOS == "darwin" {
+	if runtime.GOOS == "darwin" || runtime.GOOS == "freebsd" {
 		stream = C.cpu_stream()
 	}
 
 	var arrays C.mlx_map_string_to_array
 	var metadata C.mlx_map_string_to_string
-	if C.mlx_load_safetensors(&arrays, &metadata, cPath, stream) != 0 {
+	C.mlx_set_safe_init_mode()
+	ret := C.mlx_load_safetensors(&arrays, &metadata, cPath, stream)
+	if C.mlx_had_init_error() != 0 {
+		msg := C.GoString(C.mlx_get_init_error())
+		C.mlx_set_default_error_mode()
+		return nil, fmt.Errorf("failed to load safetensors: %s (mlx error: %s)", path, msg)
+	}
+	C.mlx_set_default_error_mode()
+	if ret != 0 {
 		return nil, fmt.Errorf("failed to load safetensors: %s", path)
 	}
 	return &SafetensorsFile{arrays: arrays, metadata: metadata}, nil
