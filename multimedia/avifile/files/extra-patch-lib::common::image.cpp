--- lib/common/image.cpp.orig	Fri Aug  6 12:35:40 2004
+++ lib/common/image.cpp	Fri Aug  6 12:47:59 2004
@@ -954,7 +954,7 @@
     fillMembers();
     if (!copy)
     {
-	(const uint8_t*) m_pPlane[0] = data;
+	m_pPlane[0] = (uint8_t*) data;
     }
     else
     {
