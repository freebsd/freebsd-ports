--- vendor/github.com/elastic/elastic-agent-system-metrics/metric/system/filesystem/filesystem_unix.go.orig	2022-11-25 22:00:53 UTC
+++ vendor/github.com/elastic/elastic-agent-system-metrics/metric/system/filesystem/filesystem_unix.go
@@ -37,9 +37,9 @@ func (fs *FSStat) GetUsage() error {
 
 	fs.Total = opt.UintWith(stat.Blocks).MultUint64OrNone(uint64(stat.Bsize))
 	fs.Free = opt.UintWith(stat.Bfree).MultUint64OrNone(uint64(stat.Bsize))
-	fs.Avail = opt.UintWith(stat.Bavail).MultUint64OrNone(uint64(stat.Bsize))
+	fs.Avail = opt.UintWith(uint64(stat.Bavail)).MultUint64OrNone(uint64(stat.Bsize))
 	fs.Files = opt.UintWith(stat.Files)
-	fs.FreeFiles = opt.UintWith(stat.Ffree)
+	fs.FreeFiles = opt.UintWith(uint64(stat.Ffree))
 
 	fs.fillMetrics()
 
