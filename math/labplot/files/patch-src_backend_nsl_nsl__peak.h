--- src/backend/nsl/nsl_peak.h.orig	2025-08-14 23:00:36 UTC
+++ src/backend/nsl/nsl_peak.h
@@ -13,7 +13,7 @@ template<typename T>
 #include <cmath>
 
 template<typename T>
-size_t* nsl_peak_detect(T* data, size_t n, size_t& np, T height = -INFINITY, size_t distance = 0);
+std::size_t* nsl_peak_detect(T* data, std::size_t n, std::size_t& np, T height = -INFINITY, std::size_t distance = 0);
 
 /* TODO: more advanced peak detection (CWT, etc.)*/
 
