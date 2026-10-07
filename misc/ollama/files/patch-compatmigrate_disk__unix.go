-- workaround for https://github.com/ollama/ollama/issues/18835

--- compatmigrate/disk_unix.go.orig	2026-10-07 07:19:10 UTC
+++ compatmigrate/disk_unix.go
@@ -10,5 +10,5 @@ func availableSpace(path string) (uint64, error) {
 		return 0, err
 	}
 
-	return st.Bavail * uint64(st.Bsize), nil
+	return uint64(st.Bavail) * uint64(st.Bsize), nil
 }
