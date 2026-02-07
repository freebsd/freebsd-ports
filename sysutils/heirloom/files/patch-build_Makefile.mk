--- build/Makefile.mk.orig	Sat Jan 27 17:39:38 2007
+++ build/Makefile.mk	Wed Mar 28 10:55:47 2007
@@ -1,7 +1,7 @@
 all: maninst crossln genintro
 
 maninst: maninst.sh mk.config
-	<maninst.sh >maninst sed ' s,@DEFLIB@,$(DEFLIB),g; s,@SPELLHIST@,$(SPELLHIST),g; s,@MAGIC@,$(MAGIC),g; s,@DFLDIR@,$(DFLDIR),g; s,@DEFBIN@,$(DEFBIN),g; s,@SV3BIN@,$(SV3BIN),g; s,@S42BIN@,$(S42BIN),g; s,@SUSBIN@,$(SUSBIN),g; s,@SU3BIN@,$(SU3BIN),g; s,@UCBBIN@,$(UCBBIN),g; s,@CCSBIN@,$(CCSBIN),g'
+	<maninst.sh >maninst sed " s,@DEFLIB@,$(DEFLIB),g; s,@SPELLHIST@,$(SPELLHIST),g; s,@MAGIC@,$(MAGIC),g; s,@DFLDIR@,$(DFLDIR),g; s,@DEFBIN@,$(DEFBIN),g; s,@SV3BIN@,$(SV3BIN),g; s,@S42BIN@,$(S42BIN),g; s,@SUSBIN@,$(SUSBIN),g; s,@SU3BIN@,$(SU3BIN),g; s,@UCBBIN@,$(UCBBIN),g; s,@CCSBIN@,$(CCSBIN),g"
 	chmod 755 maninst
 
 crossln: crossln.sh
