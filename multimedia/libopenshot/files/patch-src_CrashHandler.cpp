--- src/CrashHandler.cpp.orig	2026-04-02 23:34:37 UTC
+++ src/CrashHandler.cpp
@@ -189,8 +189,12 @@ void CrashHandler::printStackTrace(FILE *out, unsigned
 #else
     // Linux and Mac stack unwinding
 	// Storage array for stack trace address data
-	void* addrlist[max_frames+1];
+	void* addrlist[63+1];
 
+	if (sizeof( addrlist ) / sizeof( void* ) < max_frames+1) {
+		ZmqLogger::Instance()->LogToFile("  Allocated addrlist size is smaller than the size requested by the caller.\n");
+	}
+
 	// Retrieve current stack addresses
 	unsigned int addrlen = backtrace( addrlist, sizeof( addrlist ) / sizeof( void* ));
 
@@ -204,14 +208,14 @@ void CrashHandler::printStackTrace(FILE *out, unsigned
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
