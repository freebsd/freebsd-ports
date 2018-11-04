--- math_vector.h.orig	2018-11-02 06:51:37 UTC
+++ math_vector.h
@@ -94,7 +94,7 @@ inline void vec_neg(vector &dest) {     
   dest[2] = -dest[2]; }
 
 inline void vec_norm(vector &dest) {                                 // a/|a|
-  register double f = sqrt(vec_dot(dest, dest));
+  double f = sqrt(vec_dot(dest, dest));
   dest[0] /= f;
   dest[1] /= f;
   dest[2] /= f; }
@@ -222,7 +222,7 @@ inline void form_subtr(shape &dest, form
   dest[3] -= src[3]; dest[4] -= src[4]; dest[5] -= src[5]; }
 
 inline int form_inv(form &m_inv, form &m) {                        // m^-1
-  register double det = form_det(m);
+  double det = form_det(m);
   if (fzero(det)) return 0;
   m_inv[0] = (m[1]*m[2]-m[3]*m[3])/det;
   m_inv[1] = (m[0]*m[2]-m[4]*m[4])/det;
@@ -377,7 +377,7 @@ inline void form4_unit(form4 &dest) {
   dest[0] = dest[1] = dest[2] = dest[3] = 1.0; }
 
 inline double form4_det(form4 &m) {
-  register double f = m[6]*m[7]-m[5]*m[8];
+  double f = m[6]*m[7]-m[5]*m[8];
   return m[0]*(
       m[1]*(m[2]*m[3]-m[4]*m[4])+
       m[5]*(2.0*m[4]*m[7]-m[2]*m[5])-m[3]*m[7]*m[7])+f*f+
@@ -387,7 +387,7 @@ inline double form4_det(form4 &m) {
         m[9]*(m[4]*m[4]-m[2]*m[3])); }
 
 inline int form4_inv(form4 &m_inv, form4 &m) {
-  register double det = form4_det(m);
+  double det = form4_det(m);
   if (fzero(det)) return 0;
   m_inv[0] = (m[1]*(m[2]*m[3]-m[4]*m[4])+
       m[5]*(2.0*m[4]*m[7]-m[2]*m[5])-m[3]*m[7]*m[7])/det;
