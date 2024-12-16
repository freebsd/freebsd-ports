- workaround for https://github.com/OpenModelica/OpenModelica/issues/13413

--- OMCompiler/SimulationRuntime/ParModelica/auto/pm_cluster_system.hpp.orig	2024-12-16 08:23:05 UTC
+++ OMCompiler/SimulationRuntime/ParModelica/auto/pm_cluster_system.hpp
@@ -38,6 +38,7 @@
 */
 
 #include <iostream>
+#include <fstream>
 #include <map>
 
 #include <boost/graph/adjacency_list.hpp>
@@ -534,4 +535,4 @@ class TaskSystem_v2 {
 
 }} // namespace openmodelica::parmodelica
 
-#endif // header
\ No newline at end of file
+#endif // header
