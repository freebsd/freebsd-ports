$NetBSD: patch-aj,v 1.1 2009/03/26 23:12:22 wiz Exp $

--- widgets/popup.cc.orig	2008-03-05 21:31:12.000000000 +0000
+++ widgets/popup.cc
@@ -308,7 +308,7 @@ namespace Bmp
 
 		if (m_location == ARROW_TOP)
 		{
-			Cairo::Matrix matrix = { 1, 0, 0, -1, 0, h };
+			Cairo::Matrix matrix ( 1, 0, 0, -1, 0, h );
 			cr->set_matrix (matrix);
 		}
 
