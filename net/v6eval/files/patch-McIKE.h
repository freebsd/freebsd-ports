--- lib/Pz/McIKE.h	2005-05-09 18:35:23.000000000 +0900
+++ lib/Pz/McIKE.h	2008-01-01 04:36:34.000000000 +0900
@@ -397,7 +397,7 @@ class WmISAKMP_Padding: public WmObject 
 
 class PaISAKMP: public PaESP {
 	public:
-		PaISAKMP::PaISAKMP(const MObject *m, CSTR st, int l):
+		PaISAKMP(const MObject *m, CSTR st, int l):
 			PaESP(m, st, l) {};
 		virtual ~PaISAKMP() {}
 
