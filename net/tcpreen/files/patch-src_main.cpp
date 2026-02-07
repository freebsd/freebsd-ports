main.cpp:111:27: error: invalid suffix on literal; C++11 requires a space between literal and identifier [-Wreserved-user-defined-literal]
"TCP re-engineering tool "VERSION" ("PACKAGE_HOST")\n"
                          ^

Also remove build host and date information to prepare for reproducible builds

--- src/main.cpp.orig	2018-08-25 18:26:34 UTC
+++ src/main.cpp
@@ -108,8 +108,7 @@ version (void)
 # define VERSION "unknown version"
 #endif
 	puts (
-"TCP re-engineering tool "VERSION" ("PACKAGE_HOST")\n"
-" built "__DATE__" on "PACKAGE_BUILD_HOSTNAME" ("PACKAGE_BUILD")\n"
+"TCP re-engineering tool " VERSION "\n"
 "Copyright (C) 2002-2004 Remi Denis-Courmont");
 	puts (_(
 "This is free software; see the source for copying conditions.\n"
