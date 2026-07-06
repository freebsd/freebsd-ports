-- Remove GetCPUDetails() which references an undefined CPU struct type, and
-- the unused "strings" import. GetCPUDetails() is not called anywhere in the
-- codebase and the CPU type does not exist in 0.30.0.
--- discover/cpu_freebsd.go.orig	2026-06-04 02:55:00 UTC
+++ discover/cpu_freebsd.go
@@ -0,0 +1,69 @@
+package discover
+
+/*
+#include <stdlib.h>
+#include <sys/types.h>
+#include <sys/sysctl.h>
+*/
+import "C"
+
+import (
+	"log/slog"
+	"syscall"
+	"unsafe"
+)
+
+func sysctlUint64(name string) (uint64, error) {
+	cname := C.CString(name)
+	defer C.free(unsafe.Pointer(cname))
+	
+	var value C.uint64_t
+	size := C.size_t(unsafe.Sizeof(value))
+	
+	ret := C.sysctlbyname(cname, unsafe.Pointer(&value), &size, nil, 0)
+	if ret != 0 {
+		return 0, syscall.Errno(ret)
+	}
+	
+	return uint64(value), nil
+}
+
+func GetCPUMem() (memInfo, error) {
+	var mem memInfo
+
+	// Get page size - this is a 32-bit value
+	pageSize32, err := syscall.SysctlUint32("vm.stats.vm.v_page_size")
+	if err != nil {
+		return mem, err
+	}
+	pageSize := uint64(pageSize32)
+
+	// Get physical memory - use sysctlUint64
+	physmem, err := sysctlUint64("hw.physmem")
+	if err != nil {
+		return mem, err
+	}
+
+	// Get free page count - this is also a 32-bit value
+	freeCount32, err := syscall.SysctlUint32("vm.stats.vm.v_free_count")
+	if err != nil {
+		return mem, err
+	}
+	freeCount := uint64(freeCount32)
+
+	// Get swap total - use sysctlUint64
+	swapTotal, err := sysctlUint64("vm.swap_total")
+	if err != nil {
+		// Swap may not be configured, default to 0
+		swapTotal = 0
+	}
+
+	mem.TotalMemory = physmem
+	mem.FreeMemory = freeCount * pageSize
+	mem.FreeSwap = swapTotal
+
+	slog.Debug("GetCPUMem", "total_memory", mem.TotalMemory, "free_memory", mem.FreeMemory, "free_swap", mem.FreeSwap)
+
+	return mem, nil
+}
+
