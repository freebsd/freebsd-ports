- Fix i386 build.

--- packages/external/JEGA/eddy/threads/src/thread.cpp.orig	2021-03-01 17:15:15 UTC
+++ packages/external/JEGA/eddy/threads/src/thread.cpp
@@ -152,7 +152,7 @@ thread::sleep(
     )
 {
     struct timespec ts = {
-		msecs/1000, static_cast<long>((msecs%1000)*1000000)
+		time_t(msecs/1000), static_cast<long>((msecs%1000)*1000000)
 		};
 
 #if defined(EDDY_WINDOWS)
