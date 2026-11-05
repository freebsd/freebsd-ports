-- Add FreeBSD threading support. Upstream only provides thread/semaphore
-- implementations for Windows, Linux, macOS, and Emscripten, so FreeBSD fell
-- through to a no-op dummy implementation that breaks multi-threaded physics
-- and hangs the unit tests.

--- src/timer.c.orig	2026-11-05 18:11:59 UTC
+++ src/timer.c
@@ -3,7 +3,7 @@
 
 // Required on Linux to expose pthread_setname_np. Must be defined before any
 // system header is included.
-#if defined( __linux__ ) && !defined( _GNU_SOURCE )
+#if ( defined( __linux__ ) || defined( __FreeBSD__ ) ) && !defined( _GNU_SOURCE )
 #define _GNU_SOURCE
 #endif
 
@@ -245,7 +245,7 @@ void b2JoinThread( b2Thread* t )
 	b2Free( t, sizeof( b2Thread ) );
 }
 
-#elif defined( __linux__ ) || defined( __EMSCRIPTEN__ )
+#elif defined( __linux__ ) || defined( __FreeBSD__ ) || defined( __EMSCRIPTEN__ )
 
 #include <sched.h>
 #include <time.h>
@@ -352,7 +352,7 @@ static void b2SetCurrentThreadName( const char* name )
 		return;
 	}
 
-#if defined( __linux__ )
+#if defined( __linux__ ) || defined( __FreeBSD__ )
 	// Linux caps thread names at 15 chars + null terminator.
 	char truncated[16];
 	snprintf( truncated, sizeof( truncated ), "%.15s", name );
