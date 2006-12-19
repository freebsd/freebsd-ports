--- version.pro~	Thu Jan 26 21:01:39 2006
+++ version.pro	Tue Nov 14 13:43:28 2006
@@ -10,11 +10,7 @@
 SOURCES += version.cpp
 
 version.target = version.cpp 
-version.commands = echo 'const char *myth_source_version =' \
-'"'`(svnversion $${SVNTREEDIR} 2>/dev/null) || echo Unknown`'";' > .vers.new ; \
-diff .vers.new version.cpp > .vers.diff 2>&1 ; \
-if test -s .vers.diff ; then mv -f .vers.new version.cpp ; fi ; \
-rm -f .vers.new .vers.diff
-version.depends = FORCE 
+version.commands = 
+version.depends =
 
 QMAKE_EXTRA_UNIX_TARGETS += version
