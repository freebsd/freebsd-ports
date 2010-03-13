--- courier/submit2.C.orig	2008-01-29 13:06:47.000000000 +0100
+++ courier/submit2.C	2009-10-03 22:34:47.000000000 +0200
@@ -860,7 +860,7 @@
 	if (sizelimit && bytecount > sizelimit)
 	{
 		std::cout << "523 Message length (" <<
-			sizelimit << " bytes) exceeds administrative limit."
+			bytecount << " bytes) exceeds administrative limit(" << sizelimit << ")."
 			<< std::endl << std::flush;
 		return (1);
 	}
