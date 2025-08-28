--- vendor/github.com/shirou/gopsutil/v4/process/process_bsd.go.orig	2025-08-28 06:18:32 UTC
+++ vendor/github.com/shirou/gopsutil/v4/process/process_bsd.go
@@ -71,6 +71,6 @@ func parseKinfoProc(buf []byte) (KinfoProc, error) {
 func parseKinfoProc(buf []byte) (KinfoProc, error) {
 	var k KinfoProc
 	br := bytes.NewReader(buf)
-	err := common.Read(br, binary.LittleEndian, &k)
+	err := binary.Read(br, binary.LittleEndian, &k)
 	return k, err
 }
