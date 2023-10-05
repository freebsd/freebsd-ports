- make it single-threaded as a workaround for https://github.com/OpenModelica/OpenModelica/issues/9922

--- OMCompiler/Compiler/runtime/systemimpl.c.orig	2023-04-14 14:33:28 UTC
+++ OMCompiler/Compiler/runtime/systemimpl.c
@@ -772,6 +772,7 @@ char* System_popen(threadData_t *threadData, const cha
 
 int System_numProcessors(void)
 {
+#if 1
 #if WITH_HWLOC==1
   hwloc_topology_t topology;
   if (0==hwloc_topology_init(&topology) && 0==hwloc_topology_load(topology)) {
@@ -790,6 +791,8 @@ int System_numProcessors(void)
 #else
   return intMax(sysconf(_SC_NPROCESSORS_ONLN), 1);
 #endif
+#endif
+  return 1;
 }
 
 struct systemCallWorkerThreadArgs {
