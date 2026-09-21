--- vendor/github.com/elastic/elastic-agent-system-metrics/metric/system/filesystem/filesystem_unix.go.orig	2026-09-21 00:00:00 UTC
+++ vendor/github.com/elastic/elastic-agent-system-metrics/metric/system/filesystem/filesystem_unix.go
@@ -37,9 +37,9 @@ func (fs *FSStat) GetUsage() error {
 	blockSize := uint64(stat.Bsize) //nolint:gosec,nolintlint // G115 — statfs block size is non-negative
 	fs.Total = opt.UintWith(stat.Blocks).MultUint64OrNone(blockSize)
 	fs.Free = opt.UintWith(stat.Bfree).MultUint64OrNone(blockSize)
-	fs.Avail = opt.UintWith(stat.Bavail).MultUint64OrNone(blockSize)
+	fs.Avail = opt.UintWith(uint64(stat.Bavail)).MultUint64OrNone(blockSize)
 	fs.Files = opt.UintWith(stat.Files)
-	fs.FreeFiles = opt.UintWith(stat.Ffree)
+	fs.FreeFiles = opt.UintWith(uint64(stat.Ffree))
 
 	fs.fillMetrics()
 
