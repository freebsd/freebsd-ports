--- src/mathcommands.h	2003/03/11 16:53:16	1.27
+++ src/mathcommands.h	2004/07/03 19:32:15	1.28
@@ -11,9 +11,9 @@
 
 //#define CORE_FUNCTION(NAME) void NAME(LispEnvironment& aEnvironment, LispPtr& aResult, LispPtr& aArguments);
 
-#define CORE_KERNEL_FUNCTION(iname,fname,nrargs,flags) void fname(LispEnvironment& aEnvironment, LispInt aStackTop);
-#define CORE_KERNEL_FUNCTION_ALIAS(iname,fname,nrargs,flags) 
-#define OPERATOR(kind, prec, yacas_name)
+#define CORE_KERNEL_FUNCTION(iname,fname,nrargs,flags) void fname(LispEnvironment& aEnvironment, LispInt aStackTop)
+#define CORE_KERNEL_FUNCTION_ALIAS(iname,fname,nrargs,flags)  int JimDummyFunction()
+#define OPERATOR(kind, prec, yacas_name) int JimDummyFunction()
 
 #include "corefunctions.h"
 #undef CORE_KERNEL_FUNCTION
