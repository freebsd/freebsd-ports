- make it single-threaded as a workaround for https://github.com/OpenModelica/OpenModelica/issues/9922

--- OMCompiler/Compiler/runtime/systemimpl.c.orig	2022-12-11 20:16:40 UTC
+++ OMCompiler/Compiler/runtime/systemimpl.c
@@ -775,6 +775,7 @@ char* System_popen(threadData_t *threadData, const cha
 
 int System_numProcessors(void)
 {
+#if 0
 #if WITH_HWLOC==1
   hwloc_topology_t topology;
   if (0==hwloc_topology_init(&topology) && 0==hwloc_topology_load(topology)) {
@@ -793,6 +794,8 @@ int System_numProcessors(void)
 #else
   return intMax(sysconf(_SC_NPROCESSORS_ONLN), 1);
 #endif
+#endif
+  return 1;
 }
 
 struct systemCallWorkerThreadArgs {
