https://github.com/ulikunitz/xz/commit/235be8df4f86c943c154112d1abb3c951c86babb

--- vendor/github.com/ulikunitz/xz/lzma/reader.go.orig	2026-01-15 17:03:26 UTC
+++ vendor/github.com/ulikunitz/xz/lzma/reader.go
@@ -30,7 +30,7 @@ func (c *ReaderConfig) fill() {
 	if c.DictCap == 0 {
 		// set an upper limit of 2 GB for dictionary capacity to address
 		// the zero prefix security issue.
-		c.DictCap = 1 << 31
+		c.DictCap = 1 << 31 - 1
 		// original: c.DictCap = 8 * 1024 * 1024
 	}
 }
