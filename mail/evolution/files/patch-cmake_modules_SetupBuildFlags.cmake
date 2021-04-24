--- cmake/modules/SetupBuildFlags.cmake.orig	2021-03-19 06:41:05 UTC
+++ cmake/modules/SetupBuildFlags.cmake
@@ -20,7 +20,7 @@ macro(setup_build_flags _maintainer_mode)
 		-Wundef
 		-Wwrite-strings
 		-Wno-cast-function-type
-		-no-undefined
+		-Wl,--no-undefined
 		-fno-strict-aliasing
 	)
 
@@ -34,7 +34,7 @@ macro(setup_build_flags _maintainer_mode)
 	else(${_maintainer_mode})
 		list(APPEND proposed_flags
 			-Wno-deprecated-declarations
-			-Wno-missing-include-dir)
+			-Wno-missing-include-dirs)
 	endif(${_maintainer_mode})
 
 	list(APPEND proposed_c_flags
