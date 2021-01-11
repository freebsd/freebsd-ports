--- pkg/collector/corechecks/system/memory_nix.go.orig	2021-01-08 11:29:04 UTC
+++ pkg/collector/corechecks/system/memory_nix.go
@@ -94,6 +94,11 @@ func (c *MemoryCheck) linuxSpecificVirtualMemoryCheck(
 	sender.Gauge("system.mem.commit_limit", float64(v.CommitLimit)/mbSize, "", nil)
 	sender.Gauge("system.mem.committed_as", float64(v.CommittedAS)/mbSize, "", nil)
 	sender.Gauge("system.swap.cached", float64(v.SwapCached)/mbSize, "", nil)
+	sender.Gauge("system.mem.active", float64(v.Active)/mbSize, "", nil)
+	sender.Gauge("system.mem.inactive", float64(v.Inactive)/mbSize, "", nil)
+	sender.Gauge("system.mem.buffers", float64(v.Buffers)/mbSize, "", nil)
+	sender.Gauge("system.mem.wired", float64(v.Wired)/mbSize, "", nil)
+	sender.Gauge("system.mem.laundry", float64(v.Laundry)/mbSize, "", nil)
 	return nil
 }
 
