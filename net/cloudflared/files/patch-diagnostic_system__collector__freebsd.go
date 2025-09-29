--- /dev/null	2024-01-01 00:00:00 UTC
+++ diagnostic/system_collector_freebsd.go
@@ -0,0 +1,170 @@
+//go:build freebsd
+
+package diagnostic
+
+import (
+	"context"
+	"fmt"
+	"os/exec"
+	"runtime"
+	"strconv"
+	"strings"
+)
+
+type SystemCollectorImpl struct {
+	version string
+}
+
+func NewSystemCollectorImpl(
+	version string,
+) *SystemCollectorImpl {
+	return &SystemCollectorImpl{
+		version,
+	}
+}
+
+func (collector *SystemCollectorImpl) Collect(ctx context.Context) (*SystemInformation, error) {
+	memoryInfo, memoryInfoRaw, memoryInfoErr := collectMemoryInformation(ctx)
+	fdInfo, fdInfoRaw, fdInfoErr := collectFileDescriptorInformation(ctx)
+	disks, disksRaw, diskErr := collectDiskVolumeInformationUnix(ctx)
+	osInfo, osInfoRaw, osInfoErr := collectOSInformationUnix(ctx)
+
+	var memoryMaximum, memoryCurrent, fileDescriptorMaximum, fileDescriptorCurrent uint64
+	var osSystem, name, osVersion, osRelease, architecture string
+	gerror := SystemInformationGeneralError{}
+
+	if memoryInfoErr != nil {
+		gerror.MemoryInformationError = SystemInformationError{
+			Err:     memoryInfoErr,
+			RawInfo: memoryInfoRaw,
+		}
+	} else {
+		memoryMaximum = memoryInfo.MemoryMaximum
+		memoryCurrent = memoryInfo.MemoryCurrent
+	}
+
+	if fdInfoErr != nil {
+		gerror.FileDescriptorsInformationError = SystemInformationError{
+			Err:     fdInfoErr,
+			RawInfo: fdInfoRaw,
+		}
+	} else {
+		fileDescriptorMaximum = fdInfo.FileDescriptorMaximum
+		fileDescriptorCurrent = fdInfo.FileDescriptorCurrent
+	}
+
+	if diskErr != nil {
+		gerror.DiskVolumeInformationError = SystemInformationError{
+			Err:     diskErr,
+			RawInfo: disksRaw,
+		}
+	}
+
+	if osInfoErr != nil {
+		gerror.OperatingSystemInformationError = SystemInformationError{
+			Err:     osInfoErr,
+			RawInfo: osInfoRaw,
+		}
+	} else {
+		osSystem = osInfo.OsSystem
+		name = osInfo.Name
+		osVersion = osInfo.OsVersion
+		osRelease = osInfo.OsRelease
+		architecture = osInfo.Architecture
+	}
+
+	cloudflaredVersion := collector.version
+	info := NewSystemInformation(
+		memoryMaximum,
+		memoryCurrent,
+		fileDescriptorMaximum,
+		fileDescriptorCurrent,
+		osSystem,
+		name,
+		osVersion,
+		osRelease,
+		architecture,
+		cloudflaredVersion,
+		runtime.Version(),
+		runtime.GOARCH,
+		disks,
+	)
+
+	return info, gerror
+}
+
+func collectMemoryInformation(ctx context.Context) (*MemoryInformation, string, error) {
+	// Use sysctl to get memory information on FreeBSD
+	command := exec.CommandContext(ctx, "sysctl", "-n", "hw.physmem", "vm.stats.vm.v_free_count", "hw.pagesize")
+
+	stdout, err := command.Output()
+	if err != nil {
+		return nil, "", fmt.Errorf("error retrieving output from command '%s': %w", command.String(), err)
+	}
+
+	output := string(stdout)
+	lines := strings.Split(strings.TrimSpace(output), "\n")
+
+	if len(lines) < 3 {
+		return nil, output, fmt.Errorf("unexpected sysctl output format")
+	}
+
+	physmem, err := strconv.ParseUint(lines[0], 10, 64)
+	if err != nil {
+		return nil, output, fmt.Errorf("error parsing physmem: %w", err)
+	}
+
+	freePages, err := strconv.ParseUint(lines[1], 10, 64)
+	if err != nil {
+		return nil, output, fmt.Errorf("error parsing free pages: %w", err)
+	}
+
+	pageSize, err := strconv.ParseUint(lines[2], 10, 64)
+	if err != nil {
+		return nil, output, fmt.Errorf("error parsing page size: %w", err)
+	}
+
+	memoryMaximum := physmem / 1024 // Convert to KB
+	memoryCurrent := (freePages * pageSize) / 1024 // Convert to KB
+
+	memoryInfo := &MemoryInformation{
+		MemoryMaximum: memoryMaximum,
+		MemoryCurrent: memoryCurrent,
+	}
+
+	return memoryInfo, output, nil
+}
+
+func collectFileDescriptorInformation(ctx context.Context) (*FileDescriptorInformation, string, error) {
+	// Use sysctl to get file descriptor limits on FreeBSD
+	command := exec.CommandContext(ctx, "sysctl", "-n", "kern.maxfiles", "kern.openfiles")
+
+	stdout, err := command.Output()
+	if err != nil {
+		return nil, "", fmt.Errorf("error retrieving output from command '%s': %w", command.String(), err)
+	}
+
+	output := string(stdout)
+	lines := strings.Split(strings.TrimSpace(output), "\n")
+
+	if len(lines) < 2 {
+		return nil, output, fmt.Errorf("unexpected sysctl output format")
+	}
+
+	maxFiles, err := strconv.ParseUint(lines[0], 10, 64)
+	if err != nil {
+		return nil, output, fmt.Errorf("error parsing maxfiles: %w", err)
+	}
+
+	openFiles, err := strconv.ParseUint(lines[1], 10, 64)
+	if err != nil {
+		return nil, output, fmt.Errorf("error parsing openfiles: %w", err)
+	}
+
+	fdInfo := &FileDescriptorInformation{
+		FileDescriptorMaximum: maxFiles,
+		FileDescriptorCurrent: openFiles,
+	}
+
+	return fdInfo, output, nil
+}
