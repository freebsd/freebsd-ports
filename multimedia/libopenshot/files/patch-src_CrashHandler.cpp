--- src/CrashHandler.cpp.orig	2023-03-27 18:48:43 UTC
+++ src/CrashHandler.cpp
@@ -204,14 +204,14 @@ void CrashHandler::printStackTrace(FILE *out, unsigned
 	// Resolve addresses into strings containing "filename(function+address)",
 	// Actually it will be ## program address function + offset
 	// this array must be free()-ed
-	char** symbollist = backtrace_symbols( addrlist, addrlen );
+	char** symbollist = backtrace_symbols_fmt( addrlist, addrlen, "%f(%n%D) [%a]" );
 
 	size_t funcnamesize = 1024;
 	char funcname[1024];
 
 	// Iterate over the returned symbol lines. Skip the first 4, it is the
 	// address of this function.
-	for ( unsigned int i = 4; i < addrlen; i++ )
+	for ( unsigned int i = 1; i < addrlen; i++ )
 	{
 		char* begin_name   = NULL;
 		char* begin_offset = NULL;
