--- ps.c.orig	Tue Jul 22 18:56:13 2003
+++ ps.c	Tue Jul 22 19:02:44 2003
@@ -187,7 +187,7 @@
 /didShowPage false def \n\
 %%------------------------------------------------------\n\
 %% Set up the ISO fonts \n\
-
+\n\
 %% Times \n\
 %% ----- \n\
 /Times-Roman findfont dup length dict begin {		\n\
@@ -196,28 +196,28 @@
 /Encoding ISOLatin1Encoding def 			\n\
 currentdict end						\n\
 /TRomanISO exch definefont pop			\n\
-
+\n\
 /Times-Bold findfont dup length dict begin {		\n\
 	1 index /FID ne { def } { pop pop } ifelse	\n\
 } forall						\n\
 /Encoding ISOLatin1Encoding def 			\n\
 currentdict end						\n\
 /TBoldISO exch definefont pop			\n\
-
+\n\
 /Times-BoldItalic findfont dup length dict begin {	\n\
 	1 index /FID ne { def } { pop pop } ifelse	\n\
 } forall						\n\
 /Encoding ISOLatin1Encoding def 			\n\
 currentdict end						\n\
 /TBoldItalicISO exch definefont pop			\n\
-
+\n\
 /Times-Italic findfont dup length dict begin {		\n\
 	1 index /FID ne { def } { pop pop } ifelse	\n\
 } forall						\n\
 /Encoding ISOLatin1Encoding def 			\n\
 currentdict end						\n\
 /TItalicISO exch definefont pop			\n\
-
+\n\
 %% Courier \n\
 %% ----- \n\
 /Courier-Roman findfont dup length dict begin {		\n\
@@ -226,28 +226,28 @@
 /Encoding ISOLatin1Encoding def 			\n\
 currentdict end						\n\
 /CRomanISO exch definefont pop			\n\
-
+\n\
 /Courier-Bold findfont dup length dict begin {		\n\
 	1 index /FID ne { def } { pop pop } ifelse	\n\
 } forall						\n\
 /Encoding ISOLatin1Encoding def 			\n\
 currentdict end						\n\
 /CBoldISO exch definefont pop			\n\
-
+\n\
 /Courier-BoldItalic findfont dup length dict begin {	\n\
 	1 index /FID ne { def } { pop pop } ifelse	\n\
 } forall						\n\
 /Encoding ISOLatin1Encoding def 			\n\
 currentdict end						\n\
 /CBoldItalicISO exch definefont pop			\n\
-
+\n\
 /Courier-Italic findfont dup length dict begin {		\n\
 	1 index /FID ne { def } { pop pop } ifelse	\n\
 } forall						\n\
 /Encoding ISOLatin1Encoding def 			\n\
 currentdict end						\n\
 /CItalicISO exch definefont pop			\n\
-
+\n\
 %% Symbol \n\
 %% ----- \n\
 /Symbol-Roman findfont dup length dict begin {		\n\
@@ -256,28 +256,28 @@
 /Encoding ISOLatin1Encoding def 			\n\
 currentdict end						\n\
 /SRomanISO exch definefont pop			\n\
-
+\n\
 /Symbol-Bold findfont dup length dict begin {		\n\
 	1 index /FID ne { def } { pop pop } ifelse	\n\
 } forall						\n\
 /Encoding ISOLatin1Encoding def 			\n\
 currentdict end						\n\
 /SBoldISO exch definefont pop			\n\
-
+\n\
 /Symbol-BoldItalic findfont dup length dict begin {	\n\
 	1 index /FID ne { def } { pop pop } ifelse	\n\
 } forall						\n\
 /Encoding ISOLatin1Encoding def 			\n\
 currentdict end						\n\
 /SBoldItalicISO exch definefont pop			\n\
-
+\n\
 /Symbol-Italic findfont dup length dict begin {		\n\
 	1 index /FID ne { def } { pop pop } ifelse	\n\
 } forall						\n\
 /Encoding ISOLatin1Encoding def 			\n\
 currentdict end						\n\
 /SItalicISO exch definefont pop			\n\
-
+\n\
 %% Helvetica \n\
 %% --------- \n\
 /Helvetica-Roman findfont dup length dict begin {		\n\
@@ -286,28 +286,28 @@
 /Encoding ISOLatin1Encoding def 			\n\
 currentdict end						\n\
 /HRomanISO exch definefont pop			\n\
-
+\n\
 /Helvetica-Bold findfont dup length dict begin {		\n\
 	1 index /FID ne { def } { pop pop } ifelse	\n\
 } forall						\n\
 /Encoding ISOLatin1Encoding def 			\n\
 currentdict end						\n\
 /HBoldISO exch definefont pop			\n\
-
+\n\
 /Helvetica-BoldOblique findfont dup length dict begin {	\n\
 	1 index /FID ne { def } { pop pop } ifelse	\n\
 } forall						\n\
 /Encoding ISOLatin1Encoding def 			\n\
 currentdict end						\n\
 /HBoldItalicISO exch definefont pop			\n\
-
+\n\
 /Helvetica-Oblique findfont dup length dict begin {		\n\
 	1 index /FID ne { def } { pop pop } ifelse	\n\
 } forall						\n\
 /Encoding ISOLatin1Encoding def 			\n\
 currentdict end						\n\
 /HItalicISO exch definefont pop			\n\
-
+\n\
 %% \n\
 %% Ideally, before we can draw a line of text, we need to collect all the\n\
 %% words that will be on it, just as I do in my Beest HTML viewer, as well\n\
@@ -318,39 +318,39 @@
 %% ----------- Functions ------------\n\
 /updateFont { \n\
 	/f0 null def \n\
-	(Times) fontFamily eq (Times New Roman) fontFamily eq or {
+	(Times) fontFamily eq (Times New Roman) fontFamily eq or {\n\
 		bold { \n\
 			italic { /TBoldItalicISO } { /TBoldISO } ifelse \n\
 		} { \n\
 			italic { /TItalicISO } { /TRomanISO } ifelse \n\
 		} \n\
 		ifelse \n\
-	} if
-	(Helvetica) fontFamily eq (Arial) fontFamily eq or {
+	} if\n\
+	(Helvetica) fontFamily eq (Arial) fontFamily eq or {\n\
 		bold { \n\
 			italic { /HBoldItalicISO } { /HBoldISO } ifelse \n\
 		} { \n\
 			italic { /HItalicISO } { /HRomanISO } ifelse \n\
 		} \n\
 		ifelse \n\
-	} if
-	(Courier) fontFamily eq (Courier New) fontFamily eq or {
+	} if\n\
+	(Courier) fontFamily eq (Courier New) fontFamily eq or {\n\
 		bold { \n\
 			italic { /CBoldItalicISO } { /CBoldISO } ifelse \n\
 		} { \n\
 			italic { /CItalicISO } { /CRomanISO } ifelse \n\
 		} \n\
 		ifelse \n\
-	} if
-	(Symbol) fontFamily eq {
+	} if\n\
+	(Symbol) fontFamily eq {\n\
 		bold { \n\
 			italic { /SBoldItalicISO } { /SBoldISO } ifelse \n\
 		} { \n\
 			italic { /SItalicISO } { /SRomanISO } ifelse \n\
 		} \n\
 		ifelse \n\
-	} if
-
+	} if\n\
+\n\
 	findfont /f0 exch def  \n\
 	/bboxBottom f0 /FontBBox get 1 get 1000 div fontSize mul -1 mul def \n\
 	/bboxTop    f0 /FontBBox get 3 get 1000 div fontSize mul def \n\
@@ -392,13 +392,13 @@
 } \n\
 def \n\
 /acharpath { \n\
-	/acstr exch def pop /acsp exch def
-	newpath 
-	str {
-		/ch exch def
-		1 string 0 ch put false charpath
-		acsp 0 rmoveto
-	} forall
+	/acstr exch def pop /acsp exch def\n\
+	newpath \n\
+	str {\n\
+		/ch exch def\n\
+		1 string 0 ch put false charpath\n\
+		acsp 0 rmoveto\n\
+	} forall\n\
 } def \n\
 /A { \n\
 	/str exch def \n\
@@ -412,7 +412,7 @@
 			1 -0.1 0 {                        \n\
 				/offset exch def \n\
 				offset setgray                 \n\
-				x offset 3 mul add y offset 3 mul sub moveto
+				x offset 3 mul add y offset 3 mul sub moveto\n\
 				intercharSpace 0 str acharpath \n\
 				%% str false charpath \n\
 				fontSize 30 div setlinewidth stroke \n\
@@ -428,11 +428,11 @@
 			1 -0.1 0 {                        \n\
 				/offset exch def \n\
 				offset setgray                 \n\
-				x offset 3 mul add y offset 3 mul sub moveto
+				x offset 3 mul add y offset 3 mul sub moveto\n\
 				intercharSpace 0 str ashow  \n\
 				%% str show \n\
 			} for                               \n\
-			0 setgray
+			0 setgray\n\
 		} {                                         \n\
 			intercharSpace 0 str ashow          \n\
 			%% str show \n\
