--- src/rip/k3bvideocdrip.cpp.orig	Sun Jul 11 15:13:42 2004
+++ src/rip/k3bvideocdrip.cpp	Sun Jul 11 15:14:07 2004
@@ -41,7 +41,8 @@
         m_ripsourceType( 0 ),
         m_videooptions( options ),
         m_canceled( false ),
-        m_process( 0 )
+        m_process( 0 ),
+	m_subPosition( 0 )
 {}
 
 
