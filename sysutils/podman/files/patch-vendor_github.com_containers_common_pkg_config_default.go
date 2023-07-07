--- vendor/github.com/containers/common/pkg/config/default.go.orig	2023-07-21 12:24:39 UTC
+++ vendor/github.com/containers/common/pkg/config/default.go
@@ -28,7 +28,7 @@ const (
 	_defaultTransport = "docker://"
 
 	// _defaultImageVolumeMode is a mode to handle built-in image volumes.
-	_defaultImageVolumeMode = "bind"
+	_defaultImageVolumeMode = "nullfs"
 )
 
 var (
