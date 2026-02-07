- fix C++ error

--- src/library/generator.transpose.cpp.orig	2016-08-31 21:46:51 UTC
+++ src/library/generator.transpose.cpp
@@ -1089,8 +1089,9 @@ clfftStatus genSwapKernelGeneral(const FFTGeneratedTra
 
 	//std::string funcName = "swap_nonsquare_" + std::to_string(smaller_dim) + "_" + std::to_string(dim_ratio);
 	std::string funcName = "swap_nonsquare_";
-	std::string smaller_dim_str = static_cast<std::ostringstream*>(&(std::ostringstream() << smaller_dim))->str();
-	std::string dim_ratio_str = static_cast<std::ostringstream*>(&(std::ostringstream() << dim_ratio))->str();
+	std::ostringstream ss1, ss2;
+	std::string smaller_dim_str = (ss1 << smaller_dim, ss1.str());
+	std::string dim_ratio_str = (ss2 << dim_ratio, ss2.str());
 	if(params.fft_N[0] > params.fft_N[1])
 		funcName = funcName + smaller_dim_str + "_" + dim_ratio_str;
 	else
