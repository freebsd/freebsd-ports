--- src/Core/gnu/RNG.cc.orig	2002-03-27 12:32:59.000000000 +0100
+++ src/Core/gnu/RNG.cc
@@ -40,7 +40,7 @@ RNG::RNG()
   if (!initialized)
   {
 
-	assert (sizeof(double) == 2 * sizeof(_G_uint32_t)); 
+	assert (sizeof(double) == 2 * sizeof(uint32_t)); 
 
 	//
 	//	The following is a hack that I attribute to
