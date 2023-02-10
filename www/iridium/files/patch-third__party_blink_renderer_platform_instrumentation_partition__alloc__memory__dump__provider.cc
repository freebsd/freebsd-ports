--- third_party/blink/renderer/platform/instrumentation/partition_alloc_memory_dump_provider.cc.orig	2023-01-17 19:19:00 UTC
+++ third_party/blink/renderer/platform/instrumentation/partition_alloc_memory_dump_provider.cc
@@ -24,6 +24,7 @@ PartitionAllocMemoryDumpProvider* PartitionAllocMemory
 bool PartitionAllocMemoryDumpProvider::OnMemoryDump(
     const base::trace_event::MemoryDumpArgs& args,
     base::trace_event::ProcessMemoryDump* memory_dump) {
+#if !BUILDFLAG(IS_BSD)
   using base::trace_event::MemoryDumpLevelOfDetail;
 
   MemoryDumpLevelOfDetail level_of_detail = args.level_of_detail;
@@ -49,6 +50,7 @@ bool PartitionAllocMemoryDumpProvider::OnMemoryDump(
       "size", "bytes", partition_stats_dumper.total_active_bytes());
   memory_dump->AddOwnershipEdge(allocated_objects_dump->guid(),
                                 partitions_dump->guid());
+#endif
 
   return true;
 }
