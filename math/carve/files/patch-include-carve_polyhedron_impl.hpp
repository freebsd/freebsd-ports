--- include/carve/polyhedron_impl.hpp.orig	2013-02-22 09:41:13.000000000 +0100
+++ include/carve/polyhedron_impl.hpp	2013-02-22 09:46:30.000000000 +0100
@@ -88,9 +88,9 @@
       *(*result)++ = f;
 
       int r = 1;
-      for (size_t i = 0; i < f->edges.size(); ++i) {
-        const std::vector<const face_t *> &edge_faces = connectivity.edge_to_face[edgeToIndex_fast(f->edges[i])];
-        const face_t *f2 = connectedFace(f, f->edges[i]);
+      for (size_t i = 0; i < f->nEdges(); ++i) {
+        const std::vector<const face_t *> &edge_faces = connectivity.edge_to_face[edgeToIndex_fast(f->edge(i))];
+        const face_t *f2 = connectedFace(f, f->edge(i));
         if (f2) {
           r += _faceNeighbourhood(f2, depth - 1, (*result));
         }
@@ -116,7 +116,7 @@
       int r = 0;
       const std::vector<const face_t *> &edge_faces = connectivity.edge_to_face[edgeToIndex_fast(e)];
       for (size_t i = 0; i < edge_faces.size(); ++i) {
-        face_t *f = edge_faces[i];
+        const face_t *f = edge_faces[i];
         if (f && f->manifold_id == m_id) { r += _faceNeighbourhood(f, depth, &result); }
       }
       return r;
@@ -131,7 +131,7 @@
       int r = 0;
       const std::vector<const face_t *> &vertex_faces = connectivity.vertex_to_face[vertexToIndex_fast(v)];
       for (size_t i = 0; i < vertex_faces.size(); ++i) {
-        face_t *f = vertex_faces[i];
+        const face_t *f = vertex_faces[i];
         if (f && f->manifold_id == m_id) { r += _faceNeighbourhood(f, depth, &result); }
       }
       return r;
@@ -142,7 +142,7 @@
     // accessing connectivity information.
     template<typename T>
     int Geometry<3>::vertexToEdges(const vertex_t *v, T result) const {
-      std::vector<const edge_t *> &e = connectivity.vertex_to_edge[vertexToIndex_fast(v)];
+      const std::vector<const edge_t *> &e = connectivity.vertex_to_edge[vertexToIndex_fast(v)];
       std::copy(e.begin(), e.end(), result);
       return e.size();
     }
