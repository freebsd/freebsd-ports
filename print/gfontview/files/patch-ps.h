--- ps.h.orig	Sun Jun 25 21:17:29 2000
+++ ps.h	Sun Nov  2 21:27:10 2003
@@ -71,303 +71,303 @@
 ";
 
 
-const char *text_samples = "\
-/TextSamplerDict 40 dict def
-TextSamplerDict begin
-/Inch {72 mul} def
-/linewidth 7 Inch def
-/yline 9.7 Inch def
-/LM 0.7 Inch def
-/wordbreak ( ) def
-/buf 8 string def
-
-/DoTitle { % fontname DoTitle
-  /Helvetica findfont 18 scalefont setfont
-  LM 10.5 Inch moveto
-  show 
-  ( at ) show fontsize buf cvs show ( points, spacing = ) show
-  spacing buf cvs show
-} def
-
-/DoSamples { % fontname fontsize spacing DoSamples
-  /spacing exch def
-  /fontsize exch def
-  /fontname exch def
-
-  fontname findfont fontsize scalefont setfont
-  /newline {/yline yline fontsize spacing mul sub def LM yline moveto} def
-  /breakwidth wordbreak stringwidth pop def
-  /curwidth 0 def
-  /lastwordbreak 0 def
-  /startchar 0 def
-  /restoftext textstring def
-
-
-  LM yline moveto
-  { restoftext wordbreak search
-    {
-      /nextword exch def pop
-      /restoftext exch def
-      /wordwidth nextword stringwidth pop def
-    
-      curwidth wordwidth add linewidth gt
-      {
-        textstring startchar lastwordbreak startchar sub getinterval
-        show newline
-        /startchar lastwordbreak def
-        /curwidth wordwidth breakwidth add def
-      }
-      {
-        /curwidth curwidth wordwidth breakwidth add add def
-      } 
-      ifelse
-      /lastwordbreak lastwordbreak nextword length 1 add add def
-    }
-    {pop exit}
-    ifelse
-  } loop
-  /lastchar textstring length def
-  textstring startchar lastchar startchar sub getinterval show
-} def
-end
+const char *text_samples = "\n\
+/TextSamplerDict 40 dict def\n\
+TextSamplerDict begin\n\
+/Inch {72 mul} def\n\
+/linewidth 7 Inch def\n\
+/yline 9.7 Inch def\n\
+/LM 0.7 Inch def\n\
+/wordbreak ( ) def\n\
+/buf 8 string def\n\
+\n\
+/DoTitle { % fontname DoTitle\n\
+  /Helvetica findfont 18 scalefont setfont\n\
+  LM 10.5 Inch moveto\n\
+  show\n\
+  ( at ) show fontsize buf cvs show ( points, spacing = ) show\n\
+  spacing buf cvs show\n\
+} def\n\
+\n\
+/DoSamples { % fontname fontsize spacing DoSamples\n\
+  /spacing exch def\n\
+  /fontsize exch def\n\
+  /fontname exch def\n\
+\n\
+  fontname findfont fontsize scalefont setfont\n\
+  /newline {/yline yline fontsize spacing mul sub def LM yline moveto} def\n\
+  /breakwidth wordbreak stringwidth pop def\n\
+  /curwidth 0 def\n\
+  /lastwordbreak 0 def\n\
+  /startchar 0 def\n\
+  /restoftext textstring def\n\
+\n\
+\n\
+  LM yline moveto\n\
+  { restoftext wordbreak search\n\
+    {\n\
+      /nextword exch def pop\n\
+      /restoftext exch def\n\
+      /wordwidth nextword stringwidth pop def\n\
+   \n\
+      curwidth wordwidth add linewidth gt\n\
+      {\n\
+        textstring startchar lastwordbreak startchar sub getinterval\n\
+        show newline\n\
+        /startchar lastwordbreak def\n\
+        /curwidth wordwidth breakwidth add def\n\
+      }\n\
+      {\n\
+        /curwidth curwidth wordwidth breakwidth add add def\n\
+      }\n\
+      ifelse\n\
+      /lastwordbreak lastwordbreak nextword length 1 add add def\n\
+    }\n\
+    {pop exit}\n\
+    ifelse\n\
+  } loop\n\
+  /lastchar textstring length def\n\
+  textstring startchar lastchar startchar sub getinterval show\n\
+} def\n\
+end\n\
 ";
 
 
 
-const char *check_type42 = "\
-languagelevel 2 lt
-{
-  /Helvetica findfont 14 scalefont setfont
-  72 420 moveto
-  (Your printer or PostScript interpreter does not support PostScript Level 2) show
-  showpage
-  quit
-} if
-
-42 /FontType resourcestatus not
-{
-  /Helvetica findfont 14 scalefont setfont
-  72 420 moveto
-  (Your printer or PostScript interpreter does not support Type 42 fonts) show
-  showpage
-  quit
-} if
-pop pop
+const char *check_type42 = "\n\
+languagelevel 2 lt\n\
+{\n\
+  /Helvetica findfont 14 scalefont setfont\n\
+  72 420 moveto\n\
+  (Your printer or PostScript interpreter does not support PostScript Level 2) show\n\
+  showpage\n\
+  quit\n\
+} if\n\
+\n\
+42 /FontType resourcestatus not\n\
+{\n\
+  /Helvetica findfont 14 scalefont setfont\n\
+  72 420 moveto\n\
+  (Your printer or PostScript interpreter does not support Type 42 fonts) show\n\
+  showpage\n\
+  quit\n\
+} if\n\
+pop pop\n\
 ";
 
 
-const char *phrase_samples = "\
-/PhraseSamplerDict 20 dict def
-PhraseSamplerDict begin
-/Inch {72 mul} def
-/LM 0.5 Inch def
-/RM 7.6 Inch def
-/Temp 64 string def
-/T /Helvetica findfont 10 scalefont def
-/T6 /Helvetica findfont 6 scalefont def 
-/Header {  % text height Header
-  RM exch moveto T6 setfont dup stringwidth pop neg 0 rmoveto show
-} def
-/FontName { % fontname fontfile height FontName
-  /y exch def
-  /FFile exch def
-  /FName exch def
-
-  LM y moveto
-  T setfont FName Temp cvs show
-  LM y 8 sub moveto
-  T6 setfont FFile show
-} def
-/FontSample {  % fontname size height FontSample
-  /y exch def
-  /FSize exch def
-  /FName exch def
-
-  LM 160 add y moveto
-  mark
-  {
-    FName findfont FSize scalefont setfont 
-    StringSample show
-  }
-  stopped {
-    LM 160 add y moveto
-    T6 setfont (Error: ) show
-    $error /errorname get Temp cvs show
-    ( [) show
-    $error /command get Temp cvs show
-    (] ) show               
-  }
-  if
-  cleartomark
-} def
-end
+const char *phrase_samples = "\n\
+/PhraseSamplerDict 20 dict def\n\
+PhraseSamplerDict begin\n\
+/Inch {72 mul} def\n\
+/LM 0.5 Inch def\n\
+/RM 7.6 Inch def\n\
+/Temp 64 string def\n\
+/T /Helvetica findfont 10 scalefont def\n\
+/T6 /Helvetica findfont 6 scalefont def\n\
+/Header {  % text height Header\n\
+  RM exch moveto T6 setfont dup stringwidth pop neg 0 rmoveto show\n\
+} def\n\
+/FontName { % fontname fontfile height FontName\n\
+  /y exch def\n\
+  /FFile exch def\n\
+  /FName exch def\n\
+\n\
+  LM y moveto\n\
+  T setfont FName Temp cvs show\n\
+  LM y 8 sub moveto\n\
+  T6 setfont FFile show\n\
+} def\n\
+/FontSample {  % fontname size height FontSample\n\
+  /y exch def\n\
+  /FSize exch def\n\
+  /FName exch def\n\
+\n\
+  LM 160 add y moveto\n\
+  mark\n\
+  {\n\
+    FName findfont FSize scalefont setfont\n\
+    StringSample show\n\
+  }\n\
+  stopped {\n\
+    LM 160 add y moveto\n\
+    T6 setfont (Error: ) show\n\
+    $error /errorname get Temp cvs show\n\
+    ( [) show\n\
+    $error /command get Temp cvs show\n\
+    (] ) show              \n\
+  }\n\
+  if\n\
+  cleartomark\n\
+} def\n\
+end\n\
 ";
 
 
-const char *size_samples = "\
-/SizeSamplerDict 40 dict def
-SizeSamplerDict begin
-/Strings 
-{ [
-	(ABCDEFGHIJKLMNOPQRSTUVWXYZ)
-	(abcdefghijklmnopqrstuvwxyz)
-	(0123456789<=>:;?@!\"#$%&')
-	(\\( \\)*+,-./ [ \\\\ ]^_`{|}~)
-] } def
-
-
-/Sizes 
-{ [
-  8 10 12 14 20 24 28
-] } def
-
-/infofont /Helvetica findfont 10 scalefont def
-/msg 8 string def
-/Inch {72 mul} def
-/DoTitle { % fontname DoTitle
-  % Write the font name on top of the page
-  /Helvetica findfont 18 scalefont setfont
-  dup stringwidth
-  exch 8 Inch exch sub 2 div exch
-  10.5 Inch exch sub
-  moveto show
-} def
-/DoSamples { % font DoSamples
-  % Make the font samples
-  /fontname exch def
-  /testfont fontname findfont def
-  1 setlinewidth
-  60 50 moveto
-
-  Sizes
-  {
-    /size exch def
-    testfont size scalefont setfont
-    currentpoint translate % start of line
-    5 0 rmoveto
-
-    Strings 
-    {
-      currentpoint
-      3 -1 roll show
-      moveto
-      0 1.2 size mul rmoveto  % add 30% of the size vertically
-    } forall  % Strings
-
-    -5 0 rmoveto
-    currentpoint         % end of line
-    newpath 0 0 moveto lineto
-    currentpoint stroke  % leave end of line pos in stack
-  
-  % Print the font size in the middle of the line
-    dup                            % leave y in the stack (x is 0)
-    infofont setfont
-    size msg cvs dup stringwidth   % Push string 'n' and its size on the stack
-    4 -1 roll exch sub 2 div         % Stack is 'string width ypos'
-    exch 5 add neg exch moveto show  % Move to the left and print
-
-    moveto         % take end of line pos from stack
-    0 15 rmoveto   % Add vertical space between groups
-  } forall % Sizes
-} def
-end
+const char *size_samples = "\n\
+/SizeSamplerDict 40 dict def\n\
+SizeSamplerDict begin\n\
+/Strings\n\
+{ [\n\
+	(ABCDEFGHIJKLMNOPQRSTUVWXYZ)\n\
+	(abcdefghijklmnopqrstuvwxyz)\n\
+	(0123456789<=>:;?@!\"#$%&')\n\
+	(\\( \\)*+,-./ [ \\\\ ]^_`{|}~)\n\
+] } def\n\
+\n\
+\n\
+/Sizes\n\
+{ [\n\
+  8 10 12 14 20 24 28\n\
+] } def\n\
+\n\
+/infofont /Helvetica findfont 10 scalefont def\n\
+/msg 8 string def\n\
+/Inch {72 mul} def\n\
+/DoTitle { % fontname DoTitle\n\
+  % Write the font name on top of the page\n\
+  /Helvetica findfont 18 scalefont setfont\n\
+  dup stringwidth\n\
+  exch 8 Inch exch sub 2 div exch\n\
+  10.5 Inch exch sub\n\
+  moveto show\n\
+} def\n\
+/DoSamples { % font DoSamples\n\
+  % Make the font samples\n\
+  /fontname exch def\n\
+  /testfont fontname findfont def\n\
+  1 setlinewidth\n\
+  60 50 moveto\n\
+\n\
+  Sizes\n\
+  {\n\
+    /size exch def\n\
+    testfont size scalefont setfont\n\
+    currentpoint translate % start of line\n\
+    5 0 rmoveto\n\
+\n\
+    Strings\n\
+    {\n\
+      currentpoint\n\
+      3 -1 roll show\n\
+      moveto\n\
+      0 1.2 size mul rmoveto  % add 30% of the size vertically\n\
+    } forall  % Strings\n\
+\n\
+    -5 0 rmoveto\n\
+    currentpoint         % end of line\n\
+    newpath 0 0 moveto lineto\n\
+    currentpoint stroke  % leave end of line pos in stack\n\
+ \n\
+  % Print the font size in the middle of the line\n\
+    dup                            % leave y in the stack (x is 0)\n\
+    infofont setfont\n\
+    size msg cvs dup stringwidth   % Push string 'n' and its size on the stack\n\
+    4 -1 roll exch sub 2 div         % Stack is 'string width ypos'\n\
+    exch 5 add neg exch moveto show  % Move to the left and print\n\
+\n\
+    moveto         % take end of line pos from stack\n\
+    0 15 rmoveto   % Add vertical space between groups\n\
+  } forall % Sizes\n\
+} def\n\
+end\n\
 ";
 
 
 
-const char *map_samples = "\
-/MapSamplerDict 40 dict def
-MapSamplerDict begin
-/T /Helvetica findfont 10 scalefont def
-/T6 /Times-Roman findfont 6 scalefont def
-/Temp 64 string def
-/Inch {72 mul} def
-/Base 16 def    % char code output base
-/TempEncoding [ 256 { /.notdef } repeat ] def
-/ISOLatin1Dict 256 dict def
-ISOLatin1Encoding { ISOLatin1Dict exch true put } forall
-/min { 2 copy gt { exch } if pop } bind def
-/DoChar {
-  /C exch def
-  /S (_) dup 0 C put def
-  /N F /Encoding get C get def
-  /W F setfont S stringwidth pop def
-  T6 setfont
-  0 -20 moveto N Temp cvs show
-  0 -12 moveto
-  W 0.0005 add Temp cvs 0 5 getinterval show
-  N /.notdef ne {
-    3 0 translate
-    0 0 moveto F24 setfont S show
-    /W S stringwidth pop def
-    0 -6 moveto 0 24 lineto
-    W -6 moveto W 24 lineto
-    -3 0 moveto W 3 add 0 lineto
-    0 setlinewidth stroke
-  } if
-} def                            
-/DoTitle { % fontname DoTitle
-  /Helvetica findfont 18 scalefont setfont
-  dup stringwidth
-  exch 8 Inch exch sub 2 div exch
-  10.7 Inch exch sub
-  moveto show
-} def
-/Header {  % header Header
-  7.6 Inch 10.7 Inch moveto T setfont dup stringwidth pop neg 0 rmoveto show
-} def
-/DoBlock {      % firstcode lastcode DoBlock
-  /FirstCode 2 index def
-  1 exch {
-    /I exch def
-    /Xn I FirstCode sub 16 mod def /Yn I FirstCode sub 16 idiv def
-    gsave
-    Xn 36 mul 9 add Yn -56 mul 9.5 Inch add translate
-    I DoChar
-    grestore
-  } for
-} def                          
-/FontShow0 {  % fontname FontShow0
-  /FName exch def       % font name
-  /F FName findfont def
-  /Done 256 dict def
-  /NewEncoding [
-      ISOLatin1Encoding {
-        dup F /CharStrings get exch known {
-          dup Done exch known { pop } { dup Done exch true put } ifelse
-        } { pop } ifelse
-      } forall
-      F /CharStrings get {
-        pop dup ISOLatin1Dict exch known { pop } if
-      } forall
-  ] def
-  F length dict F {
-    1 index /FID eq { pop pop } { 2 index 3 1 roll put } ifelse
-  } forall
-  dup /Encoding NewEncoding put
-  /* exch definefont
-  /F exch def
-  /F24 F 24 scalefont def
-  70 160 translate
-  0.80 dup scale
-  0 NewEncoding length 1 sub DoBlock
-} def                        
-/FontShowV {  % encoding fontname FontShowV
-  /FName exch def       
-  /NewEncoding exch def
-  /F FName findfont def
-  F length dict F {
-    1 index /FID eq { pop pop } { 2 index 3 1 roll put } ifelse
-  } forall
-  dup /Encoding NewEncoding put
-  /* exch definefont
-  /F exch def
-  /F24 F 24 scalefont def
-  70 160 translate
-  0.80 dup scale
-  0 NewEncoding length 1 sub DoBlock
-} def
-end  
+const char *map_samples = "\n\
+/MapSamplerDict 40 dict def\n\
+MapSamplerDict begin\n\
+/T /Helvetica findfont 10 scalefont def\n\
+/T6 /Times-Roman findfont 6 scalefont def\n\
+/Temp 64 string def\n\
+/Inch {72 mul} def\n\
+/Base 16 def    % char code output base\n\
+/TempEncoding [ 256 { /.notdef } repeat ] def\n\
+/ISOLatin1Dict 256 dict def\n\
+ISOLatin1Encoding { ISOLatin1Dict exch true put } forall\n\
+/min { 2 copy gt { exch } if pop } bind def\n\
+/DoChar {\n\
+  /C exch def\n\
+  /S (_) dup 0 C put def\n\
+  /N F /Encoding get C get def\n\
+  /W F setfont S stringwidth pop def\n\
+  T6 setfont\n\
+  0 -20 moveto N Temp cvs show\n\
+  0 -12 moveto\n\
+  W 0.0005 add Temp cvs 0 5 getinterval show\n\
+  N /.notdef ne {\n\
+    3 0 translate\n\
+    0 0 moveto F24 setfont S show\n\
+    /W S stringwidth pop def\n\
+    0 -6 moveto 0 24 lineto\n\
+    W -6 moveto W 24 lineto\n\
+    -3 0 moveto W 3 add 0 lineto\n\
+    0 setlinewidth stroke\n\
+  } if\n\
+} def                           \n\
+/DoTitle { % fontname DoTitle\n\
+  /Helvetica findfont 18 scalefont setfont\n\
+  dup stringwidth\n\
+  exch 8 Inch exch sub 2 div exch\n\
+  10.7 Inch exch sub\n\
+  moveto show\n\
+} def\n\
+/Header {  % header Header\n\
+  7.6 Inch 10.7 Inch moveto T setfont dup stringwidth pop neg 0 rmoveto show\n\
+} def\n\
+/DoBlock {      % firstcode lastcode DoBlock\n\
+  /FirstCode 2 index def\n\
+  1 exch {\n\
+    /I exch def\n\
+    /Xn I FirstCode sub 16 mod def /Yn I FirstCode sub 16 idiv def\n\
+    gsave\n\
+    Xn 36 mul 9 add Yn -56 mul 9.5 Inch add translate\n\
+    I DoChar\n\
+    grestore\n\
+  } for\n\
+} def                         \n\
+/FontShow0 {  % fontname FontShow0\n\
+  /FName exch def       % font name\n\
+  /F FName findfont def\n\
+  /Done 256 dict def\n\
+  /NewEncoding [\n\
+      ISOLatin1Encoding {\n\
+        dup F /CharStrings get exch known {\n\
+          dup Done exch known { pop } { dup Done exch true put } ifelse\n\
+        } { pop } ifelse\n\
+      } forall\n\
+      F /CharStrings get {\n\
+        pop dup ISOLatin1Dict exch known { pop } if\n\
+      } forall\n\
+  ] def\n\
+  F length dict F {\n\
+    1 index /FID eq { pop pop } { 2 index 3 1 roll put } ifelse\n\
+  } forall\n\
+  dup /Encoding NewEncoding put\n\
+  /* exch definefont\n\
+  /F exch def\n\
+  /F24 F 24 scalefont def\n\
+  70 160 translate\n\
+  0.80 dup scale\n\
+  0 NewEncoding length 1 sub DoBlock\n\
+} def                       \n\
+/FontShowV {  % encoding fontname FontShowV\n\
+  /FName exch def      \n\
+  /NewEncoding exch def\n\
+  /F FName findfont def\n\
+  F length dict F {\n\
+    1 index /FID eq { pop pop } { 2 index 3 1 roll put } ifelse\n\
+  } forall\n\
+  dup /Encoding NewEncoding put\n\
+  /* exch definefont\n\
+  /F exch def\n\
+  /F24 F 24 scalefont def\n\
+  70 160 translate\n\
+  0.80 dup scale\n\
+  0 NewEncoding length 1 sub DoBlock\n\
+} def\n\
+end\n\
 ";
 
 
