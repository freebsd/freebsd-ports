--- ./spell/Makefile.mk.orig	Sun Jul 17 13:24:27 2005
+++ ./spell/Makefile.mk	Thu Jul 27 01:00:46 2006
@@ -36,19 +36,19 @@
 		hlista hlistb hstop hashmake hashcheck
 
 spell: spell.sh
-	echo '#!$(SHELL)' | cat - spell.sh | sed ' \
+	echo '#!$(SHELL)' | cat - spell.sh | sed " \
 		s,@DEFBIN@,$(DEFBIN),g; \
 		s,@SV3BIN@,$(SV3BIN),g; \
 		s,@DEFLIB@,$(DEFLIB),g; \
-		s,@SPELLHIST@,$(SPELLHIST),g' >spell
+		s,@SPELLHIST@,$(SPELLHIST),g" >spell
 	chmod 755 spell
 
 compress: compress.sh
-	echo '#!$(SHELL)' | cat - compress.sh | sed ' \
+	echo '#!$(SHELL)' | cat - compress.sh | sed " \
 		s,@DEFBIN@,$(DEFBIN),g; \
 		s,@SV3BIN@,$(SV3BIN),g; \
 		s,@DEFLIB@,$(DEFLIB),g; \
-		s,@SPELLHIST@,$(SPELLHIST),g' >compress
+		s,@SPELLHIST@,$(SPELLHIST),g" >compress
 	chmod 755 compress
 
 spellprog: spellprog.o hash.o hashlook.o huff.o
