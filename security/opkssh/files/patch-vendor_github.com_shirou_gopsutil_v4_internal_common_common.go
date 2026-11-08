--- vendor/github.com/shirou/gopsutil/v4/internal/common/common.go.orig	2026-09-25 23:41:01 UTC
+++ vendor/github.com/shirou/gopsutil/v4/internal/common/common.go
@@ -397,7 +397,7 @@ func HostEtc(combineWith ...string) string {
 }
 
 func HostEtc(combineWith ...string) string {
-	return GetEnv("HOST_ETC", "/etc", combineWith...)
+	return GetEnv("HOST_ETC", "%%PREFIX%%/etc", combineWith...)
 }
 
 func HostVar(combineWith ...string) string {
@@ -429,7 +429,7 @@ func HostEtcWithContext(ctx context.Context, combineWi
 }
 
 func HostEtcWithContext(ctx context.Context, combineWith ...string) string {
-	return GetEnvWithContext(ctx, "HOST_ETC", "/etc", combineWith...)
+	return GetEnvWithContext(ctx, "HOST_ETC", "%%PREFIX%%/etc", combineWith...)
 }
 
 func HostVarWithContext(ctx context.Context, combineWith ...string) string {
