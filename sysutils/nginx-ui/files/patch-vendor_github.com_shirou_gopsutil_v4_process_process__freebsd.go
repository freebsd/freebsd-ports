--- vendor/github.com/shirou/gopsutil/v4/process/process_freebsd.go.orig	2025-08-28 06:19:32 UTC
+++ vendor/github.com/shirou/gopsutil/v4/process/process_freebsd.go
@@ -79,7 +79,7 @@ func (p *Process) CwdWithContext(_ context.Context) (s
 
 	var k kinfoFile
 	br := bytes.NewReader(buf)
-	if err := common.Read(br, binary.LittleEndian, &k); err != nil {
+	if err := binary.Read(br, binary.LittleEndian, &k); err != nil {
 		return "", err
 	}
 	cwd := common.IntToString(k.Path[:])
@@ -279,7 +279,7 @@ func (p *Process) MemoryInfoWithContext(_ context.Cont
 	if err != nil {
 		return nil, err
 	}
-	pageSize := common.LittleEndian.Uint16([]byte(v))
+	pageSize := binary.LittleEndian.Uint16([]byte(v))
 
 	return &MemoryInfoStat{
 		RSS: uint64(k.Rssize) * uint64(pageSize),
