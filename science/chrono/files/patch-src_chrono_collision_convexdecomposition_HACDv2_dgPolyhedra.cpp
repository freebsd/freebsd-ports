--- src/chrono/collision/convexdecomposition/HACDv2/dgPolyhedra.cpp.orig	2018-08-15 19:24:06 UTC
+++ src/chrono/collision/convexdecomposition/HACDv2/dgPolyhedra.cpp
@@ -2867,7 +2867,7 @@ void dgPolyhedra::Optimize (const hacd::
 							if (handle) {
 								handle->m_edge = NULL;
 							}
-							ptr->m_userData = hacd::HaU32 (NULL);
+							ptr->m_userData = 0;
 
 						}
 
@@ -2906,7 +2906,7 @@ void dgPolyhedra::Optimize (const hacd::
 									if (handle) {
 										handle->m_edge = NULL;
 									}
-									ptr1->m_userData = hacd::HaU32 (NULL);
+									ptr1->m_userData = 0;
 
 								}
 							}
@@ -2932,7 +2932,7 @@ void dgPolyhedra::Optimize (const hacd::
 									if (handle) {
 										handle->m_edge = NULL;
 									}
-									ptr1->m_twin->m_userData = hacd::HaU32 (NULL);
+									ptr1->m_twin->m_userData = 0;
 
 								}
 							}
