--- vendor/github.com/shirou/gopsutil/v4/disk/disk_freebsd.go.orig	2025-08-28 06:12:56 UTC
+++ vendor/github.com/shirou/gopsutil/v4/disk/disk_freebsd.go
@@ -154,9 +154,7 @@ func parsedevstat(buf []byte) (devstat, error) {
 func parsedevstat(buf []byte) (devstat, error) {
 	var ds devstat
 	br := bytes.NewReader(buf)
-	//	err := binary.Read(br, binary.LittleEndian, &ds)
-	err := common.Read(br, binary.LittleEndian, &ds)
-	if err != nil {
+	if err := binary.Read(br, binary.LittleEndian, &ds); err != nil {
 		return ds, err
 	}
 
