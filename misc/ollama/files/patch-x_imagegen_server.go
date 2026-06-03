--- x/imagegen/server.go.orig	2026-04-23 17:32:09 UTC
+++ x/imagegen/server.go
@@ -55,7 +55,9 @@ func NewServer(modelName string) (*Server, error) {
 	return &Server{
 		modelName: modelName,
 		done:      make(chan error, 1),
-		client:    &http.Client{Timeout: 10 * time.Minute},
+		// No client-level timeout: image generation on CPU can take many minutes.
+		// Cancellation is handled via request context.
+		client: &http.Client{},
 	}, nil
 }
 
