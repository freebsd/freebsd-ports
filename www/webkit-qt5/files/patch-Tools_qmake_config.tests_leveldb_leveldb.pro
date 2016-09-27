Setting OBJECTS_DIR to "obj" causes problems with make(1), as "obj" is one of
the directories make tries to enter in case it exists (because of .OBJDIR).
Since qmake will create it because of OBJECTS_DIR, make will invoke the
compiler from there and fail because it's trying to pass "-o obj/foo.o" while
already in obj/.

--- Tools/qmake/config.tests/leveldb/leveldb.pro.orig	2016-09-26 14:57:15 UTC
+++ Tools/qmake/config.tests/leveldb/leveldb.pro
@@ -1,5 +1,4 @@
 SOURCES = leveldb.cpp
-OBJECTS_DIR = obj
 LIBS += -lleveldb -lmemenv
 
 load(qt_build_config)
