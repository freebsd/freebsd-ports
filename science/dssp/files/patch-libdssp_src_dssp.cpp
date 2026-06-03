--- libdssp/src/dssp.cpp.orig	2026-03-21 21:49:26.455914000 -0700
+++ libdssp/src/dssp.cpp	2026-03-21 21:49:52.366128000 -0700
@@ -278,7 +278,7 @@
 			p = {};
 	}
 
-	void addAtom(cif::row_handle atom)
+	void addAtom(cif::const_row_handle atom)
 	{
 		std::string asymID, compID, atomID, type, authAsymID;
 		std::optional<std::string> altID;
