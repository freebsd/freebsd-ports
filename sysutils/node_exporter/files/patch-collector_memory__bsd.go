--- collector/memory_bsd.go.orig	2023-02-03 16:38:43 UTC
+++ collector/memory_bsd.go
@@ -87,6 +87,7 @@ func NewMemoryCollector(logger log.Logger) (Collector,
 				description: "Locked in memory by user, mlock, etc",
 				mib:         "vm.stats.vm.v_user_wire_count",
 				conversion:  fromPage,
+				dataType:    bsdSysctlTypeCLong,
 			},
 			{
 				name:        "cache_bytes",
