--- components/cli/vendor/github.com/docker/docker/pkg/mount/mountinfo_freebsd.go.orig	2018-08-03 16:04:11 UTC
+++ components/cli/vendor/github.com/docker/docker/pkg/mount/mountinfo_freebsd.go
@@ -37,7 +37,7 @@ func parseMountTable(filter FilterFunc) 
 
 		if filter != nil {
 			// filter out entries we're not interested in
-			skip, stop = filter(p)
+			skip, stop = filter(&mountinfo)
 			if skip {
 				continue
 			}
