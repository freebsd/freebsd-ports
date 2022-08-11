--- extern/KaHIP/lib/partition/uncoarsening/refinement/kway_graph_refinement/kway_graph_refinement_commons.cpp.orig	2022-07-01 08:58:46 UTC
+++ extern/KaHIP/lib/partition/uncoarsening/refinement/kway_graph_refinement/kway_graph_refinement_commons.cpp
@@ -9,7 +9,7 @@
 
 #include "kway_graph_refinement_commons.h"
 
-std::vector<kway_graph_refinement_commons*>* kway_graph_refinement_commons::m_instances = NULL;
+std::vector<kway_graph_refinement_commons*>* kway_graph_refinement_commons::m_instances = nullptr;
 
 kway_graph_refinement_commons::kway_graph_refinement_commons() {
 
@@ -24,13 +24,13 @@ kway_graph_refinement_commons* kway_graph_refinement_c
         bool created = false;
         #pragma omp critical 
         {
-                if( m_instances == NULL ) {
-                        m_instances = new std::vector< kway_graph_refinement_commons*>(omp_get_max_threads(), reinterpret_cast<kway_graph_refinement_commons*>(NULL));
+                if( m_instances == nullptr ) {
+                        m_instances = new std::vector< kway_graph_refinement_commons*>(omp_get_max_threads(), (kway_graph_refinement_commons*)nullptr);
                 }
         } 
 
         int id = omp_get_thread_num();
-        if((*m_instances)[id] == NULL) {
+        if((*m_instances)[id] == nullptr) {
                 (*m_instances)[id] = new kway_graph_refinement_commons();
                 (*m_instances)[id]->init(config);
                 created = true;
