--- include/carve/kd_node.hpp.orig	2013-02-22 09:47:07.000000000 +0100
+++ include/carve/kd_node.hpp	2013-02-22 09:50:00.000000000 +0100
@@ -238,7 +238,7 @@
         // q_t - the priority queue value type.
         // q_t.first:  distance from object to query point.
         // q_t.second: pointer to object
-        typedef std::pair<double, const typename kd_node::data_t *> q_t;
+        typedef std::pair<double, const data_t *> q_t;
 
         // the queue priority should sort from smallest distance to largest, and on equal distance, by object pointer.
         struct pcmp {
@@ -266,7 +266,7 @@
           }
         }
 
-        const typename kd_node::data_t *next() {
+        const data_t *next() {
           while (1) {
             if (pq.size()) {
               q_t t = pq.top();
