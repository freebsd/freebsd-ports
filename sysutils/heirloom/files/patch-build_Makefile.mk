--- build/Makefile.mk.orgi	Thu Mar 10 17:11:29 2005
+++ build/Makefile.mk	Thu Jul 27 00:45:12 2006
@@ -1,7 +1,7 @@
 all: maninst crossln genintro
 
 maninst: maninst.sh mk.config
-	<maninst.sh >maninst sed ' \
+	<maninst.sh >maninst sed " \
 		s,@DEFLIB@,$(DEFLIB),g; \
 		s,@SPELLHIST@,$(SPELLHIST),g; \
 		s,@MAGIC@,$(MAGIC),g; \
@@ -11,7 +11,7 @@
 		s,@S42BIN@,$(S42BIN),g; \
 		s,@SUSBIN@,$(SUSBIN),g; \
 		s,@SU3BIN@,$(SU3BIN),g; \
-		s,@UCBBIN@,$(UCBBIN),g'
+		s,@UCBBIN@,$(UCBBIN),g"
 	chmod 755 maninst
 
 crossln: crossln.sh
