diff -u curveFitData.cpp.orig curveFitData.cpp
--- curveFitData.cpp.orig	Wed May 20 05:10:03 1998
+++ curveFitData.cpp	Thu Oct 30 21:42:04 2003
@@ -103,7 +103,7 @@
 	{
 		QFont font( "helvetica", 24, 50, 0 );
 		font.setStyleHint( (QFont::StyleHint)0 );
-		font.setCharSet( (QFont::CharSet)0 );
+		//font.setCharSet( (QFont::CharSet)0 );
 		equalLabel->setFont( font );
 	}
 	equalLabel->setText( "=" );
