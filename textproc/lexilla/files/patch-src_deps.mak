--- src/deps.mak.orig	2024-06-25 22:48:45 UTC
+++ src/deps.mak
@@ -1,15 +1,15 @@ $(DIR_O)/Lexilla.o: \
 # Created by DepGen.py. To recreate, run DepGen.py.
 $(DIR_O)/Lexilla.o: \
 	../src/Lexilla.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
 	../lexlib/LexerModule.h \
 	../lexlib/CatalogueModules.h
 $(DIR_O)/Accessor.o: \
 	../lexlib/Accessor.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/PropSetSimple.h \
 	../lexlib/WordList.h \
@@ -23,9 +23,9 @@ $(DIR_O)/DefaultLexer.o: \
 	../lexlib/CharacterSet.h
 $(DIR_O)/DefaultLexer.o: \
 	../lexlib/DefaultLexer.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/PropSetSimple.h \
 	../lexlib/WordList.h \
@@ -39,15 +39,15 @@ $(DIR_O)/LexAccessor.o: \
 	../lexlib/CharacterSet.h
 $(DIR_O)/LexAccessor.o: \
 	../lexlib/LexAccessor.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
 	../lexlib/LexAccessor.h \
 	../lexlib/CharacterSet.h
 $(DIR_O)/LexerBase.o: \
 	../lexlib/LexerBase.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/PropSetSimple.h \
 	../lexlib/WordList.h \
@@ -57,9 +57,9 @@ $(DIR_O)/LexerModule.o: \
 	../lexlib/LexerBase.h
 $(DIR_O)/LexerModule.o: \
 	../lexlib/LexerModule.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/PropSetSimple.h \
 	../lexlib/WordList.h \
@@ -70,9 +70,9 @@ $(DIR_O)/LexerNoExceptions.o: \
 	../lexlib/LexerSimple.h
 $(DIR_O)/LexerNoExceptions.o: \
 	../lexlib/LexerNoExceptions.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/PropSetSimple.h \
 	../lexlib/WordList.h \
@@ -83,9 +83,9 @@ $(DIR_O)/LexerSimple.o: \
 	../lexlib/LexerNoExceptions.h
 $(DIR_O)/LexerSimple.o: \
 	../lexlib/LexerSimple.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/PropSetSimple.h \
 	../lexlib/WordList.h \
@@ -99,8 +99,8 @@ $(DIR_O)/StyleContext.o: \
 	../lexlib/PropSetSimple.h
 $(DIR_O)/StyleContext.o: \
 	../lexlib/StyleContext.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
 	../lexlib/LexAccessor.h \
 	../lexlib/Accessor.h \
 	../lexlib/StyleContext.h \
@@ -110,9 +110,9 @@ $(DIR_O)/LexA68k.o: \
 	../lexlib/WordList.h
 $(DIR_O)/LexA68k.o: \
 	../lexers/LexA68k.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -122,9 +122,9 @@ $(DIR_O)/LexAbaqus.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexAbaqus.o: \
 	../lexers/LexAbaqus.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -134,9 +134,9 @@ $(DIR_O)/LexAda.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexAda.o: \
 	../lexers/LexAda.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -146,9 +146,9 @@ $(DIR_O)/LexAPDL.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexAPDL.o: \
 	../lexers/LexAPDL.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -158,9 +158,9 @@ $(DIR_O)/LexAsciidoc.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexAsciidoc.o: \
 	../lexers/LexAsciidoc.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -170,9 +170,9 @@ $(DIR_O)/LexAsm.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexAsm.o: \
 	../lexers/LexAsm.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -183,9 +183,9 @@ $(DIR_O)/LexAsn1.o: \
 	../lexlib/DefaultLexer.h
 $(DIR_O)/LexAsn1.o: \
 	../lexers/LexAsn1.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -195,9 +195,9 @@ $(DIR_O)/LexASY.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexASY.o: \
 	../lexers/LexASY.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -207,9 +207,9 @@ $(DIR_O)/LexAU3.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexAU3.o: \
 	../lexers/LexAU3.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -219,9 +219,9 @@ $(DIR_O)/LexAVE.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexAVE.o: \
 	../lexers/LexAVE.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -231,9 +231,9 @@ $(DIR_O)/LexAVS.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexAVS.o: \
 	../lexers/LexAVS.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -243,9 +243,9 @@ $(DIR_O)/LexBaan.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexBaan.o: \
 	../lexers/LexBaan.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -256,9 +256,9 @@ $(DIR_O)/LexBash.o: \
 	../lexlib/DefaultLexer.h
 $(DIR_O)/LexBash.o: \
 	../lexers/LexBash.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/StringCopy.h \
 	../lexlib/InList.h \
@@ -272,9 +272,9 @@ $(DIR_O)/LexBasic.o: \
 	../lexlib/DefaultLexer.h
 $(DIR_O)/LexBasic.o: \
 	../lexers/LexBasic.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -285,9 +285,9 @@ $(DIR_O)/LexBatch.o: \
 	../lexlib/DefaultLexer.h
 $(DIR_O)/LexBatch.o: \
 	../lexers/LexBatch.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/InList.h \
 	../lexlib/WordList.h \
@@ -298,9 +298,9 @@ $(DIR_O)/LexBibTeX.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexBibTeX.o: \
 	../lexers/LexBibTeX.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/PropSetSimple.h \
 	../lexlib/WordList.h \
@@ -311,9 +311,9 @@ $(DIR_O)/LexBullant.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexBullant.o: \
 	../lexers/LexBullant.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -323,9 +323,9 @@ $(DIR_O)/LexCaml.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexCaml.o: \
 	../lexers/LexCaml.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -335,9 +335,9 @@ $(DIR_O)/LexCIL.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexCIL.o: \
 	../lexers/LexCIL.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/StringCopy.h \
 	../lexlib/WordList.h \
@@ -350,9 +350,9 @@ $(DIR_O)/LexCLW.o: \
 	../lexlib/DefaultLexer.h
 $(DIR_O)/LexCLW.o: \
 	../lexers/LexCLW.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -362,9 +362,9 @@ $(DIR_O)/LexCmake.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexCmake.o: \
 	../lexers/LexCmake.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -374,9 +374,9 @@ $(DIR_O)/LexCOBOL.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexCOBOL.o: \
 	../lexers/LexCOBOL.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -386,9 +386,9 @@ $(DIR_O)/LexCoffeeScript.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexCoffeeScript.o: \
 	../lexers/LexCoffeeScript.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -398,9 +398,9 @@ $(DIR_O)/LexConf.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexConf.o: \
 	../lexers/LexConf.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -410,9 +410,9 @@ $(DIR_O)/LexCPP.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexCPP.o: \
 	../lexers/LexCPP.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/StringCopy.h \
 	../lexlib/WordList.h \
@@ -426,9 +426,9 @@ $(DIR_O)/LexCrontab.o: \
 	../lexlib/SubStyles.h
 $(DIR_O)/LexCrontab.o: \
 	../lexers/LexCrontab.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -438,9 +438,9 @@ $(DIR_O)/LexCsound.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexCsound.o: \
 	../lexers/LexCsound.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -450,9 +450,9 @@ $(DIR_O)/LexCSS.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexCSS.o: \
 	../lexers/LexCSS.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -462,9 +462,9 @@ $(DIR_O)/LexD.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexD.o: \
 	../lexers/LexD.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -475,9 +475,9 @@ $(DIR_O)/LexDataflex.o: \
 	../lexlib/DefaultLexer.h
 $(DIR_O)/LexDataflex.o: \
 	../lexers/LexDataflex.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -487,9 +487,9 @@ $(DIR_O)/LexDiff.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexDiff.o: \
 	../lexers/LexDiff.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -499,9 +499,9 @@ $(DIR_O)/LexDMAP.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexDMAP.o: \
 	../lexers/LexDMAP.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -511,9 +511,9 @@ $(DIR_O)/LexDMIS.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexDMIS.o: \
 	../lexers/LexDMIS.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -523,9 +523,9 @@ $(DIR_O)/LexECL.o: \
 	../lexlib/DefaultLexer.h
 $(DIR_O)/LexECL.o: \
 	../lexers/LexECL.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/PropSetSimple.h \
 	../lexlib/WordList.h \
@@ -537,18 +537,18 @@ $(DIR_O)/LexEDIFACT.o: \
 	../lexlib/OptionSet.h
 $(DIR_O)/LexEDIFACT.o: \
 	../lexers/LexEDIFACT.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/LexAccessor.h \
 	../lexlib/LexerModule.h \
 	../lexlib/DefaultLexer.h
 $(DIR_O)/LexEiffel.o: \
 	../lexers/LexEiffel.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -558,9 +558,9 @@ $(DIR_O)/LexErlang.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexErlang.o: \
 	../lexers/LexErlang.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -570,9 +570,9 @@ $(DIR_O)/LexErrorList.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexErrorList.o: \
 	../lexers/LexErrorList.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/InList.h \
 	../lexlib/WordList.h \
@@ -583,9 +583,9 @@ $(DIR_O)/LexEScript.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexEScript.o: \
 	../lexers/LexEScript.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -595,9 +595,9 @@ $(DIR_O)/LexFlagship.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexFlagship.o: \
 	../lexers/LexFlagship.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -607,9 +607,9 @@ $(DIR_O)/LexForth.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexForth.o: \
 	../lexers/LexForth.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -619,9 +619,9 @@ $(DIR_O)/LexFortran.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexFortran.o: \
 	../lexers/LexFortran.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -631,9 +631,9 @@ $(DIR_O)/LexFSharp.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexFSharp.o: \
 	../lexers/LexFSharp.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -644,9 +644,9 @@ $(DIR_O)/LexGAP.o: \
 	../lexlib/DefaultLexer.h
 $(DIR_O)/LexGAP.o: \
 	../lexers/LexGAP.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -656,9 +656,9 @@ $(DIR_O)/LexGDScript.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexGDScript.o: \
 	../lexers/LexGDScript.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/StringCopy.h \
 	../lexlib/WordList.h \
@@ -673,9 +673,9 @@ $(DIR_O)/LexGui4Cli.o: \
 	../lexlib/DefaultLexer.h
 $(DIR_O)/LexGui4Cli.o: \
 	../lexers/LexGui4Cli.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -685,9 +685,9 @@ $(DIR_O)/LexHaskell.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexHaskell.o: \
 	../lexers/LexHaskell.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/PropSetSimple.h \
 	../lexlib/WordList.h \
@@ -701,9 +701,9 @@ $(DIR_O)/LexHex.o: \
 	../lexlib/DefaultLexer.h
 $(DIR_O)/LexHex.o: \
 	../lexers/LexHex.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -713,9 +713,9 @@ $(DIR_O)/LexHollywood.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexHollywood.o: \
 	../lexers/LexHollywood.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -726,9 +726,9 @@ $(DIR_O)/LexHTML.o: \
 	../lexlib/DefaultLexer.h
 $(DIR_O)/LexHTML.o: \
 	../lexers/LexHTML.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/InList.h \
 	../lexlib/WordList.h \
@@ -742,9 +742,9 @@ $(DIR_O)/LexIndent.o: \
 	../lexlib/DefaultLexer.h
 $(DIR_O)/LexIndent.o: \
 	../lexers/LexIndent.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -754,9 +754,9 @@ $(DIR_O)/LexInno.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexInno.o: \
 	../lexers/LexInno.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -766,9 +766,9 @@ $(DIR_O)/LexJSON.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexJSON.o: \
 	../lexers/LexJSON.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -779,9 +779,9 @@ $(DIR_O)/LexJulia.o: \
 	../lexlib/DefaultLexer.h
 $(DIR_O)/LexJulia.o: \
 	../lexers/LexJulia.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/StringCopy.h \
 	../lexlib/PropSetSimple.h \
@@ -796,9 +796,9 @@ $(DIR_O)/LexKix.o: \
 	../lexlib/DefaultLexer.h
 $(DIR_O)/LexKix.o: \
 	../lexers/LexKix.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -808,9 +808,9 @@ $(DIR_O)/LexKVIrc.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexKVIrc.o: \
 	../lexers/LexKVIrc.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -820,9 +820,9 @@ $(DIR_O)/LexLaTeX.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexLaTeX.o: \
 	../lexers/LexLaTeX.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/PropSetSimple.h \
 	../lexlib/WordList.h \
@@ -835,9 +835,9 @@ $(DIR_O)/LexLisp.o: \
 	../lexlib/LexerBase.h
 $(DIR_O)/LexLisp.o: \
 	../lexers/LexLisp.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -847,9 +847,9 @@ $(DIR_O)/LexLout.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexLout.o: \
 	../lexers/LexLout.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -859,9 +859,9 @@ $(DIR_O)/LexLua.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexLua.o: \
 	../lexers/LexLua.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -874,9 +874,9 @@ $(DIR_O)/LexMagik.o: \
 	../lexlib/DefaultLexer.h
 $(DIR_O)/LexMagik.o: \
 	../lexers/LexMagik.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -886,9 +886,9 @@ $(DIR_O)/LexMake.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexMake.o: \
 	../lexers/LexMake.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -898,9 +898,9 @@ $(DIR_O)/LexMarkdown.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexMarkdown.o: \
 	../lexers/LexMarkdown.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -910,9 +910,9 @@ $(DIR_O)/LexMatlab.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexMatlab.o: \
 	../lexers/LexMatlab.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -922,9 +922,9 @@ $(DIR_O)/LexMaxima.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexMaxima.o: \
 	../lexers/LexMaxima.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -934,9 +934,9 @@ $(DIR_O)/LexMetapost.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexMetapost.o: \
 	../lexers/LexMetapost.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -946,9 +946,9 @@ $(DIR_O)/LexMMIXAL.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexMMIXAL.o: \
 	../lexers/LexMMIXAL.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -958,9 +958,9 @@ $(DIR_O)/LexModula.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexModula.o: \
 	../lexers/LexModula.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/PropSetSimple.h \
 	../lexlib/WordList.h \
@@ -971,9 +971,9 @@ $(DIR_O)/LexMPT.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexMPT.o: \
 	../lexers/LexMPT.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -983,9 +983,9 @@ $(DIR_O)/LexMSSQL.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexMSSQL.o: \
 	../lexers/LexMSSQL.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -995,9 +995,9 @@ $(DIR_O)/LexMySQL.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexMySQL.o: \
 	../lexers/LexMySQL.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -1007,9 +1007,9 @@ $(DIR_O)/LexNim.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexNim.o: \
 	../lexers/LexNim.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/StringCopy.h \
 	../lexlib/WordList.h \
@@ -1022,9 +1022,9 @@ $(DIR_O)/LexNimrod.o: \
 	../lexlib/DefaultLexer.h
 $(DIR_O)/LexNimrod.o: \
 	../lexers/LexNimrod.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -1034,9 +1034,9 @@ $(DIR_O)/LexNsis.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexNsis.o: \
 	../lexers/LexNsis.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -1046,9 +1046,9 @@ $(DIR_O)/LexNull.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexNull.o: \
 	../lexers/LexNull.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -1058,9 +1058,9 @@ $(DIR_O)/LexOpal.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexOpal.o: \
 	../lexers/LexOpal.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -1070,9 +1070,9 @@ $(DIR_O)/LexOScript.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexOScript.o: \
 	../lexers/LexOScript.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -1082,9 +1082,9 @@ $(DIR_O)/LexPascal.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexPascal.o: \
 	../lexers/LexPascal.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -1094,9 +1094,9 @@ $(DIR_O)/LexPB.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexPB.o: \
 	../lexers/LexPB.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -1106,9 +1106,9 @@ $(DIR_O)/LexPerl.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexPerl.o: \
 	../lexers/LexPerl.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -1119,9 +1119,9 @@ $(DIR_O)/LexPLM.o: \
 	../lexlib/DefaultLexer.h
 $(DIR_O)/LexPLM.o: \
 	../lexers/LexPLM.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -1131,9 +1131,9 @@ $(DIR_O)/LexPO.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexPO.o: \
 	../lexers/LexPO.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -1143,9 +1143,9 @@ $(DIR_O)/LexPOV.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexPOV.o: \
 	../lexers/LexPOV.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -1155,9 +1155,9 @@ $(DIR_O)/LexPowerPro.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexPowerPro.o: \
 	../lexers/LexPowerPro.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -1167,9 +1167,9 @@ $(DIR_O)/LexPowerShell.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexPowerShell.o: \
 	../lexers/LexPowerShell.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -1179,9 +1179,9 @@ $(DIR_O)/LexProgress.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexProgress.o: \
 	../lexers/LexProgress.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -1193,9 +1193,9 @@ $(DIR_O)/LexProps.o: \
 	../lexlib/DefaultLexer.h
 $(DIR_O)/LexProps.o: \
 	../lexers/LexProps.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -1205,9 +1205,9 @@ $(DIR_O)/LexPS.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexPS.o: \
 	../lexers/LexPS.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -1217,9 +1217,9 @@ $(DIR_O)/LexPython.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexPython.o: \
 	../lexers/LexPython.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -1233,9 +1233,9 @@ $(DIR_O)/LexR.o: \
 	../lexlib/DefaultLexer.h
 $(DIR_O)/LexR.o: \
 	../lexers/LexR.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -1245,9 +1245,9 @@ $(DIR_O)/LexRaku.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexRaku.o: \
 	../lexers/LexRaku.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -1259,9 +1259,9 @@ $(DIR_O)/LexRebol.o: \
 	../lexlib/DefaultLexer.h
 $(DIR_O)/LexRebol.o: \
 	../lexers/LexRebol.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -1271,9 +1271,9 @@ $(DIR_O)/LexRegistry.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexRegistry.o: \
 	../lexers/LexRegistry.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -1284,9 +1284,9 @@ $(DIR_O)/LexRuby.o: \
 	../lexlib/DefaultLexer.h
 $(DIR_O)/LexRuby.o: \
 	../lexers/LexRuby.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -1296,9 +1296,9 @@ $(DIR_O)/LexRust.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexRust.o: \
 	../lexers/LexRust.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/PropSetSimple.h \
 	../lexlib/WordList.h \
@@ -1311,9 +1311,9 @@ $(DIR_O)/LexSAS.o: \
 	../lexlib/DefaultLexer.h
 $(DIR_O)/LexSAS.o: \
 	../lexers/LexSAS.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -1323,9 +1323,9 @@ $(DIR_O)/LexScriptol.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexScriptol.o: \
 	../lexers/LexScriptol.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -1335,9 +1335,9 @@ $(DIR_O)/LexSmalltalk.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexSmalltalk.o: \
 	../lexers/LexSmalltalk.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -1347,9 +1347,9 @@ $(DIR_O)/LexSML.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexSML.o: \
 	../lexers/LexSML.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -1359,9 +1359,9 @@ $(DIR_O)/LexSorcus.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexSorcus.o: \
 	../lexers/LexSorcus.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -1371,9 +1371,9 @@ $(DIR_O)/LexSpecman.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexSpecman.o: \
 	../lexers/LexSpecman.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -1383,9 +1383,9 @@ $(DIR_O)/LexSpice.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexSpice.o: \
 	../lexers/LexSpice.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -1395,9 +1395,9 @@ $(DIR_O)/LexSQL.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexSQL.o: \
 	../lexers/LexSQL.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -1410,9 +1410,9 @@ $(DIR_O)/LexStata.o: \
 	../lexlib/DefaultLexer.h
 $(DIR_O)/LexStata.o: \
 	../lexers/LexStata.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -1422,9 +1422,9 @@ $(DIR_O)/LexSTTXT.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexSTTXT.o: \
 	../lexers/LexSTTXT.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -1434,9 +1434,9 @@ $(DIR_O)/LexTACL.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexTACL.o: \
 	../lexers/LexTACL.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -1446,9 +1446,9 @@ $(DIR_O)/LexTADS3.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexTADS3.o: \
 	../lexers/LexTADS3.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -1458,9 +1458,9 @@ $(DIR_O)/LexTAL.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexTAL.o: \
 	../lexers/LexTAL.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -1470,9 +1470,9 @@ $(DIR_O)/LexTCL.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexTCL.o: \
 	../lexers/LexTCL.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -1482,9 +1482,9 @@ $(DIR_O)/LexTCMD.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexTCMD.o: \
 	../lexers/LexTCMD.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -1494,9 +1494,9 @@ $(DIR_O)/LexTeX.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexTeX.o: \
 	../lexers/LexTeX.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -1506,9 +1506,9 @@ $(DIR_O)/LexTxt2tags.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexTxt2tags.o: \
 	../lexers/LexTxt2tags.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -1518,9 +1518,9 @@ $(DIR_O)/LexVB.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexVB.o: \
 	../lexers/LexVB.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -1530,9 +1530,9 @@ $(DIR_O)/LexVerilog.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexVerilog.o: \
 	../lexers/LexVerilog.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -1545,9 +1545,9 @@ $(DIR_O)/LexVHDL.o: \
 	../lexlib/DefaultLexer.h
 $(DIR_O)/LexVHDL.o: \
 	../lexers/LexVHDL.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -1557,9 +1557,9 @@ $(DIR_O)/LexVisualProlog.o: \
 	../lexlib/LexerModule.h
 $(DIR_O)/LexVisualProlog.o: \
 	../lexers/LexVisualProlog.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
@@ -1572,17 +1572,17 @@ $(DIR_O)/LexX12.o: \
 	../lexlib/DefaultLexer.h
 $(DIR_O)/LexX12.o: \
 	../lexers/LexX12.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/LexerModule.h \
 	../lexlib/DefaultLexer.h
 $(DIR_O)/LexYAML.o: \
 	../lexers/LexYAML.cxx \
-	../../scintilla/include/ILexer.h \
-	../../scintilla/include/Sci_Position.h \
-	../../scintilla/include/Scintilla.h \
+	$(LOCALBASE)/include/scintilla/ILexer.h \
+	$(LOCALBASE)/include/scintilla/Sci_Position.h \
+	$(LOCALBASE)/include/scintilla/Scintilla.h \
 	../include/SciLexer.h \
 	../lexlib/WordList.h \
 	../lexlib/LexAccessor.h \
