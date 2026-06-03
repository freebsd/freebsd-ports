-- Remove GetCPUDetails() which references an undefined CPU struct type, and
-- the unused "strings" import. GetCPUDetails() is not called anywhere in the
-- codebase and the CPU type does not exist in 0.30.0.
--- discover/cpu_freebsd.go.orig	2026-06-02 21:48:58 UTC
+++ discover/cpu_freebsd.go
@@ -9,7 +9,6 @@ import (
 
 import (
 	"log/slog"
-	"strings"
 	"syscall"
 	"unsafe"
 )
@@ -68,55 +67,3 @@ func GetCPUMem() (memInfo, error) {
 	return mem, nil
 }
 
-func GetCPUDetails() []CPU {
-	var cpus []CPU
-
-	// Get CPU model name - this is a string
-	modelName, err := syscall.Sysctl("hw.model")
-	if err != nil {
-		slog.Warn("failed to get CPU model", "error", err)
-		modelName = "Unknown"
-	}
-
-	// Get number of physical cores - this is a 32-bit integer
-	cores32, err := syscall.SysctlUint32("kern.smp.cores")
-	if err != nil {
-		slog.Warn("failed to get CPU cores", "error", err)
-		return nil
-	}
-	cores := int(cores32)
-
-	// Get number of logical CPUs (threads) - this is a 32-bit integer
-	threads32, err := syscall.SysctlUint32("hw.ncpu")
-	if err != nil {
-		slog.Warn("failed to get CPU threads", "error", err)
-		return nil
-	}
-	threads := int(threads32)
-
-	// Extract vendor ID from model name if possible
-	vendorID := ""
-	modelNameLower := strings.ToLower(modelName)
-	if strings.Contains(modelNameLower, "intel") {
-		vendorID = "GenuineIntel"
-	} else if strings.Contains(modelNameLower, "amd") {
-		vendorID = "AuthenticAMD"
-	}
-
-	// For FreeBSD, we assume a single socket for now
-	// In the future, this could be enhanced to detect multi-socket systems
-	cpu := CPU{
-		ID:                  "0",
-		VendorID:            vendorID,
-		ModelName:           strings.TrimSpace(modelName),
-		CoreCount:           cores,
-		EfficiencyCoreCount: 0, // FreeBSD doesn't distinguish efficiency cores
-		ThreadCount:         threads,
-	}
-
-	cpus = append(cpus, cpu)
-
-	slog.Debug("GetCPUDetails", "cpus", cpus)
-
-	return cpus
-}
