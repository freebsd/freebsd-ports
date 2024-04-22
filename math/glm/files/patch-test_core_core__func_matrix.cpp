--- test/core/core_func_matrix.cpp.orig	2024-02-27 17:19:47 UTC
+++ test/core/core_func_matrix.cpp
@@ -392,7 +392,7 @@ static int test_inverse_perf(std::size_t Count, std::s
 	//glm::uint Ulp = 0;
 	//Ulp = glm::max(glm::float_distance(*Dst, *Src), Ulp);
 
-	std::printf("inverse<%s>(%f): %lu\n", Message, static_cast<double>(Diff), EndTime - StartTime);
+	std::printf("inverse<%s>(%f): %lu\n", Message, static_cast<double>(Diff), (unsigned long)(EndTime - StartTime));
 
 	return 0;
 }
