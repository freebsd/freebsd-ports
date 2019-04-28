--- vendor/github.com/docker/docker/pkg/mount/mountinfo_freebsd.go.orig	2019-04-09 15:51:37 UTC
+++ vendor/github.com/docker/docker/pkg/mount/mountinfo_freebsd.go
@@ -37,7 +37,7 @@ func parseMountTable(filter FilterFunc) ([]*Info, erro
 
 		if filter != nil {
 			// filter out entries we're not interested in
-			skip, stop = filter(p)
+			//skip, stop = filter(p)
 			if skip {
 				continue
 			}
