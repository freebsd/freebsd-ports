--- embeddedcryptopp/algebra.cpp.orig	2010-09-21 04:36:16.000000000 +0000
+++ embeddedcryptopp/algebra.cpp
@@ -58,7 +58,7 @@ template <class T> const T& AbstractEucl
 	Element g[3]={b, a};
 	unsigned int i0=0, i1=1, i2=2;
 
-	while (!Equal(g[i1], this->Identity()))
+	while (!this->Equal(g[i1], this->Identity()))
 	{
 		g[i2] = Mod(g[i0], g[i1]);
 		unsigned int t = i0; i0 = i1; i1 = i2; i2 = t;
@@ -74,7 +74,7 @@ template <class T> const typename Quotie
 	Element y;
 	unsigned int i0=0, i1=1, i2=2;
 
-	while (!Equal(g[i1], Identity()))
+	while (!this->Equal(g[i1], Identity()))
 	{
 		// y = g[i0] / g[i1];
 		// g[i2] = g[i0] % g[i1];
