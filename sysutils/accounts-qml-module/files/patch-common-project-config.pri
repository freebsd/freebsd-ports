--- common-project-config.pri.orig	2020-04-25 09:29:07 UTC
+++ common-project-config.pri
@@ -3,7 +3,7 @@
 #-----------------------------------------------------------------------------
 
 # we don't like warnings...
-QMAKE_CXXFLAGS += -Werror -Wno-write-strings
+QMAKE_CXXFLAGS += -Wno-write-strings
 # Disable RTTI
 QMAKE_CXXFLAGS += -fno-exceptions -fno-rtti
 # Use C++11
