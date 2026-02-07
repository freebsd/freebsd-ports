--- spell/Makefile.mk.orig	Wed May 24 16:46:54 2006
+++ spell/Makefile.mk	Wed Mar 28 11:04:59 2007
@@ -36,11 +36,11 @@
 		hlista hlistb hstop hashmake hashcheck
 
 spell: spell.sh
-	echo '#!$(SHELL)' | cat - spell.sh | sed ' s,@DEFBIN@,$(DEFBIN),g; s,@SV3BIN@,$(SV3BIN),g; s,@DEFLIB@,$(DEFLIB),g; s,@SPELLHIST@,$(SPELLHIST),g' >spell
+	echo '#!$(SHELL)' | cat - spell.sh | sed " s,@DEFBIN@,$(DEFBIN),g; s,@SV3BIN@,$(SV3BIN),g; s,@DEFLIB@,$(DEFLIB),g; s,@SPELLHIST@,$(SPELLHIST),g" >spell
 	chmod 755 spell
 
 compress: compress.sh
-	echo '#!$(SHELL)' | cat - compress.sh | sed ' s,@DEFBIN@,$(DEFBIN),g; s,@SV3BIN@,$(SV3BIN),g; s,@DEFLIB@,$(DEFLIB),g; s,@SPELLHIST@,$(SPELLHIST),g' >compress
+	echo '#!$(SHELL)' | cat - compress.sh | sed " s,@DEFBIN@,$(DEFBIN),g; s,@SV3BIN@,$(SV3BIN),g; s,@DEFLIB@,$(DEFLIB),g; s,@SPELLHIST@,$(SPELLHIST),g" >compress
 	chmod 755 compress
 
 spellprog: spellprog.o hash.o hashlook.o huff.o
