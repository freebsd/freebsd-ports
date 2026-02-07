--- src/subdir.mk.orig	2020-02-19 03:33:58 UTC
+++ src/subdir.mk
@@ -56,7 +56,7 @@ CPP_DEPS += \
 src/%.o: ../src/%.cpp
 	@echo 'Building file: $<'
 	@echo 'Invoking: GCC C++ Compiler'
-	g++ -I/usr/local/include -O3 -c -std=c++11 -pthread -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
+	g++ -I/usr/local/include $(CXXFLAGS) -c -std=c++11 -pthread -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
 	@echo 'Finished building: $<'
 	@echo ' '
 
