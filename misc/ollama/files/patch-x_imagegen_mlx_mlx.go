--- x/imagegen/mlx/mlx.go.orig	1979-11-30 08:00:00 UTC
+++ x/imagegen/mlx/mlx.go
@@ -4,6 +4,7 @@ package mlx
 #cgo CFLAGS: -O3 -I${SRCDIR}/../../mlxrunner/mlx/include -I${SRCDIR}
 #cgo darwin LDFLAGS: -lc++ -framework Metal -framework Foundation -framework Accelerate
 #cgo linux LDFLAGS: -lstdc++ -ldl
+#cgo freebsd LDFLAGS: -lc++ -ldl
 #cgo windows LDFLAGS: -lstdc++
 
 // Use generated wrappers instead of direct MLX headers
@@ -23,6 +24,10 @@ static inline mlx_stream default_stream() {
 static inline mlx_stream default_stream() {
     if (_default_stream.ctx == NULL) {
         _default_stream = mlx_default_gpu_stream_new();
+        // On CPU-only systems (no Metal, no CUDA), fall back to the CPU stream.
+        if (_default_stream.ctx == NULL) {
+            _default_stream = mlx_default_cpu_stream_new();
+        }
     }
     return _default_stream;
 }
@@ -1512,14 +1517,21 @@ func LoadSafetensorsNative(path string) (*SafetensorsF
 	defer C.free(unsafe.Pointer(cPath))
 
 	stream := C.default_stream()
-	if runtime.GOOS == "darwin" {
+	if runtime.GOOS == "darwin" || runtime.GOOS == "freebsd" {
 		stream = C.cpu_stream()
 	}
 
 	var arrays C.mlx_map_string_to_array
 	var metadata C.mlx_map_string_to_string
-	if C.mlx_load_safetensors(&arrays, &metadata, cPath, stream) != 0 {
-		return nil, fmt.Errorf("failed to load safetensors: %s", path)
+	C.mlx_set_safe_init_mode()
+	rc := C.mlx_load_safetensors(&arrays, &metadata, cPath, stream)
+	C.mlx_set_default_error_mode()
+	if rc != 0 {
+		errMsg := ""
+		if C.mlx_had_init_error() != 0 {
+			errMsg = ": " + C.GoString(C.mlx_get_init_error())
+		}
+		return nil, fmt.Errorf("failed to load safetensors: %s%s", path, errMsg)
 	}
 	return &SafetensorsFile{arrays: arrays, metadata: metadata}, nil
 }
@@ -1755,12 +1767,17 @@ func findMLXLibrary() string {
 			return candidate
 		}
 
-		// Check exe_dir/lib/ollama/mlx* subdirectories
-		// and exe_dir/../lib/ollama/mlx* (standard bin/lib sibling layout)
+		// Check exe_dir/lib/ollama and exe_dir/../lib/ollama directly,
+		// and their mlx* subdirectories (standard bin/lib sibling layout)
 		for _, libOllamaDir := range []string{
 			filepath.Join(exeDir, "lib", "ollama"),
 			filepath.Join(exeDir, "..", "lib", "ollama"),
 		} {
+			// Check the directory itself first (FreeBSD/Linux installed layout)
+			candidate = filepath.Join(libOllamaDir, libName)
+			if _, err := os.Stat(candidate); err == nil {
+				return candidate
+			}
 			if mlxDirs, err := filepath.Glob(filepath.Join(libOllamaDir, "mlx*")); err == nil {
 				for _, mlxDir := range mlxDirs {
 					candidate = filepath.Join(mlxDir, libName)
