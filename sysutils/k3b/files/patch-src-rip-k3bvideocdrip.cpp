--- src/rip/k3bvideocdrip.cpp.orig	Wed Jan 21 11:20:20 2004
+++ src/rip/k3bvideocdrip.cpp	Sun Jan  2 09:30:08 2005
@@ -41,7 +41,8 @@
         m_ripsourceType( 0 ),
         m_videooptions( options ),
         m_canceled( false ),
-        m_process( 0 )
+        m_process( 0 ),
+	m_subPosition( 0 )
 {}
 
 
