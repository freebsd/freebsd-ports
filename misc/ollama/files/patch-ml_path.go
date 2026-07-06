-- Add FreeBSD to the list of OS cases that look for lib/ollama helpers.
-- Without this, FreeBSD falls through to the default case and may not
-- find the llama-server binary at the expected path.
--- ml/path.go.orig	2026-06-02 21:19:57 UTC
+++ ml/path.go
@@ -82,7 +82,7 @@ func libOllamaPathCandidates(search libOllamaPathSearc
 			// Local dist output and standard installs keep helpers under lib/ollama.
 			add(filepath.Join(exeDir, "lib", "ollama"))
 			add(filepath.Join(exeDir, "..", "lib", "ollama"))
-		case "linux":
+		case "linux", "freebsd":
 			add(filepath.Join(exeDir, "..", "lib", "ollama"))
 			add(filepath.Join(exeDir, "lib", "ollama"))
 		case "windows":
