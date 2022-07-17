--- vendor/github.com/shirou/gopsutil/v3/process/process_freebsd.go.orig	2022-07-17 16:56:05 UTC
+++ vendor/github.com/shirou/gopsutil/v3/process/process_freebsd.go
@@ -115,7 +115,7 @@ func (p *Process) createTimeWithContext(ctx context.Co
 	if err != nil {
 		return 0, err
 	}
-	return k.Start.Sec*1000 + k.Start.Usec/1000, nil
+	return int64(k.Start.Sec)*1000 + int64(k.Start.Usec)/1000, nil
 }
 
 func (p *Process) StatusWithContext(ctx context.Context) ([]string, error) {
