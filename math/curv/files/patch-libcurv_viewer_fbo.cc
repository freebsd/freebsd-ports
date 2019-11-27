--- libcurv/viewer/fbo.cc.orig	2019-10-22 18:20:49 UTC
+++ libcurv/viewer/fbo.cc
@@ -25,6 +25,7 @@ SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH D
 
 #include "fbo.h"
 #include <iostream>
+#include <sys/types.h>
 
 Fbo::Fbo():m_id(0), m_old_fbo_id(0), m_texture(0), m_depth_buffer(0), m_width(0), m_height(0), m_allocated(false), m_binded(false) {
 }
