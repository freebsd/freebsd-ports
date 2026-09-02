--- third_party/xla/xla/codegen/intrinsic/cpp/eigen_unary.cc.orig	2026-03-04 22:33:50 UTC
+++ third_party/xla/xla/codegen/intrinsic/cpp/eigen_unary.cc
@@ -13,7 +13,8 @@
 limitations under the License.
 ==============================================================================*/
 
-#if defined(__has_attribute) && __has_attribute(ext_vector_type) && \
+#if defined(__FLT16_MANT_DIG__) && \
+    defined(__has_attribute) && __has_attribute(ext_vector_type) && \
     defined(__has_builtin) && __has_builtin(__builtin_vectorelements)
 
 #include "xla/codegen/intrinsic/cpp/eigen_unary.h"
