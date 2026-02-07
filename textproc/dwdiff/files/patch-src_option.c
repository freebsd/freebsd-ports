Fix the compilation for when Unicode (ICU) support is disabled.

	-mi

--- src/option.c.orig	2018-12-10 18:25:15 UTC
+++ src/option.c
@@ -468,7 +468,7 @@ static void initializeOptions(void) {
 	option.output = stdout;
 
 	initOptions();
-  UErrorCode error = U_ZERO_ERROR;
+	ONLY_UNICODE(UErrorCode error = U_ZERO_ERROR;)
 	ONLY_UNICODE(option.decomposition = unorm2_getNFDInstance(&error);)
 
 	option.needStartStop = true;
