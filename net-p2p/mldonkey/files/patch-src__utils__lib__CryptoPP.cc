--- src/utils/lib/CryptoPP.cc~
+++ src/utils/lib/CryptoPP.cc
@@ -5413,7 +5413,7 @@ template <class T> const T& AbstractEucl
 	Element g[3]={b, a};
 	unsigned int i0=0, i1=1, i2=2;
 
-	while (!Equal(g[i1], this->Identity()))
+	while (!this->Equal(g[i1], this->Identity()))
 	{
 		g[i2] = Mod(g[i0], g[i1]);
 		unsigned int t = i0; i0 = i1; i1 = i2; i2 = t;
