- make it single-threaded as a workaround for https://github.com/OpenModelica/OpenModelica/issues/9922

--- OMCompiler/Compiler/runtime/systemimpl.c.orig	2025-11-24 16:18:03 UTC
+++ OMCompiler/Compiler/runtime/systemimpl.c
@@ -779,6 +779,7 @@ int System_numProcessors(void)
 
 int System_numProcessors(void)
 {
+#if 1
 #if WITH_HWLOC==1
   hwloc_topology_t topology;
   if (0==hwloc_topology_init(&topology) && 0==hwloc_topology_load(topology)) {
@@ -797,6 +798,8 @@ int System_numProcessors(void)
 #else
   return intMax(sysconf(_SC_NPROCESSORS_ONLN), 1);
 #endif
+#endif
+  return 1;
 }
 
 struct systemCallWorkerThreadArgs {
