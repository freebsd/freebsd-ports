--- services/docker/docker.go.orig	2022-07-17 19:10:19 UTC
+++ services/docker/docker.go
@@ -402,7 +402,7 @@ var infoResp = map[string]interface{}{
 		"Mirrors": []interface{}{},
 	},
 	"NCPU":              8,
-	"MemTotal":          16348065792,
+	"MemTotal":          int64(16348065792),
 	"GenericResources":  nil,
 	"DockerRootDir":     "/var/lib/docker",
 	"HttpProxy":         "",
