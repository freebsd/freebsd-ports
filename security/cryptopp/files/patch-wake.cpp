--- wake.cpp.orig
+++ wake.cpp
@@ -25,13 +25,13 @@ void WAKE_Base::GenKey(word32 k0, word32 k1, word32 k2, word32 k3)
 	CRYPTOPP_COMPILE_ASSERT(sizeof(x) == 4);
 	static int tt[10]= {
 		0x726a8f3b,								 // table
-		0xe69a3b5c,
-		0xd3c71fe5,
-		0xab3c73d2,
+		static_cast<int>(0xe69a3b5c),
+		static_cast<int>(0xd3c71fe5),
+		static_cast<int>(0xab3c73d2),
 		0x4d3a8eb3,
 		0x0396d6e8,
 		0x3d4c2f7a,
-		0x9ee27cf3, } ;
+		static_cast<int>(0x9ee27cf3), } ;
 	t[0] = k0;
 	t[1] = k1;
 	t[2] = k2;
