--- lib/config/fileconf.go.orig	2020-07-08 18:08:40 UTC
+++ lib/config/fileconf.go
@@ -281,7 +281,7 @@ func MakeSampleFileConfig() (fc *FileConfig, err error
 	s.Commands = []CommandLabel{
 		{
 			Name:    "hostname",
-			Command: []string{"/usr/bin/hostname"},
+			Command: []string{"/bin/hostname"},
 			Period:  time.Minute,
 		},
 		{
