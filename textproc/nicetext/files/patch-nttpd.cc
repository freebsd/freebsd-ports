--- nttpd/src/nttpd.cc.orig	Fri Aug 28 01:16:30 1998
+++ nttpd/src/nttpd.cc	Thu Oct 30 18:37:05 2003
@@ -98,7 +98,7 @@
 #include <unistd.h>
 #include <iostream.h>
 #include <fstream.h>
-#include <strstream.h>
+#include <strstream>
 #include <signal.h>
 #include "../../mtc++/include/MTC++.h"
 #include "../../mtc++/include/mstring.h"
@@ -608,37 +608,37 @@
 BOOL sendInitial(MTCstringList &os)
 {
 	DEBUGMSG(cout << "INITIAL REQUEST." << endl;)
- 	os.add("<HTML> 
-<HEAD> 
-<TITLE>NICETEXT Primary Input Screen</TITLE> 
-</HEAD> 
-<BODY BGCOLOR=\"#AAAAAA\"> 
-<H2>NICETEXT Web-Sampler &copy; 1998  -  Primary Input Screen</H2>
-<P>The purpose of this demo is to convert your message into something 
-completely different. The same message can be changed into many
-different texts - even with the same style and dictionary.  What's more, 
-you will have the opportunity to convert the <I>nicetext</I> back into
-your original message!</P> 
-<FORM METHOD=POST ACTION=\"nicetext?\"> 
-<INPUT TYPE=HIDDEN NAME=NTTPDATA VALUE=\"INITIAL\">
-<H3>Enter a Message:</H3>
-<P>
-<TEXTAREA NAME=PLAINTEXT COLS=80 ROWS=12></TEXTAREA> 
-</P> 
-<H3>Select the <B>NICETEXT</B> Style:
-<SELECT NAME=STYLE> 
-<OPTION VALUE=\"Shakespeare\"> Shakespeare 
-<OPTION VALUE=\"Asoep's Fables\"> Asoep's Fables 
-<OPTION VALUE=\"Wizard of OZ\"> Wizard of OZ 
-</SELECT> 
-<INPUT TYPE=CHECKBOX NAME=BIGDICT VALUE=\"YES\"> Use a larger dictionary
-</H3>
-</P>
-<INPUT TYPE=SUBMIT VALUE=\" Convert my message \"> 
-<INPUT TYPE=RESET  VALUE=\" Clear \"> 
-</FORM> 
-<P>For more information please see the <A HREF=\"http://www.ctgi.net/nicetext/\">Official NICETEXT Home Page</A></P> 
-</BODY> 
+ 	os.add("<HTML>\n\
+<HEAD>\n\
+<TITLE>NICETEXT Primary Input Screen</TITLE>\n\
+</HEAD>\n\
+<BODY BGCOLOR=\"#AAAAAA\">\n\
+<H2>NICETEXT Web-Sampler &copy; 1998  -  Primary Input Screen</H2>\n\
+<P>The purpose of this demo is to convert your message into something\n\
+completely different. The same message can be changed into many\n\
+different texts - even with the same style and dictionary.  What's more,\n\
+you will have the opportunity to convert the <I>nicetext</I> back into\n\
+your original message!</P>\n\
+<FORM METHOD=POST ACTION=\"nicetext?\">\n\
+<INPUT TYPE=HIDDEN NAME=NTTPDATA VALUE=\"INITIAL\">\n\
+<H3>Enter a Message:</H3>\n\
+<P>\n\
+<TEXTAREA NAME=PLAINTEXT COLS=80 ROWS=12></TEXTAREA>\n\
+</P>\n\
+<H3>Select the <B>NICETEXT</B> Style:\n\
+<SELECT NAME=STYLE>\n\
+<OPTION VALUE=\"Shakespeare\"> Shakespeare\n\
+<OPTION VALUE=\"Asoep's Fables\"> Asoep's Fables\n\
+<OPTION VALUE=\"Wizard of OZ\"> Wizard of OZ\n\
+</SELECT>\n\
+<INPUT TYPE=CHECKBOX NAME=BIGDICT VALUE=\"YES\"> Use a larger dictionary\n\
+</H3>\n\
+</P>\n\
+<INPUT TYPE=SUBMIT VALUE=\" Convert my message \">\n\
+<INPUT TYPE=RESET  VALUE=\" Clear \">\n\
+</FORM>\n\
+<P>For more information please see the <A HREF=\"http://www.ctgi.net/nicetext/\">Official NICETEXT Home Page</A></P>\n\
+</BODY>\n\
 </HTML>");
 
 	return TRUE;
@@ -877,23 +877,23 @@
 
 BOOL sendNiceText(MTCstringList &os, MTCRBT<MTCpostData> &pdSet)
 {
-	os.add("<HTML> 
-<HEAD> 
-<TITLE>NICETEXT Output Screen</TITLE> 
-</HEAD> 
-<BODY BGCOLOR=\"#AAAAAA\"> 
-<H2>NICETEXT Web-Sampler &copy; 1998  -  <I>Nicetext</I> Output Screen</H2>
-<P>This is the result of the <I>nicetext</I> operation on the message
-you selected.  If you <I>scramble</I> the unmodified text below then  
-the software will recover your original message on the next page.
-But, if you modify the text - who knows what you will end up with?  Also,
-if you are not satisfied with the quality of the <I>nicetext</I> then 
-use the reload button on your browser for another try!</P>
-<FORM METHOD=POST ACTION=\"scramble?\"> 
-<INPUT TYPE=HIDDEN NAME=NTTPDATA VALUE=\"NICETEXT\">
-<P>
-<H3>Here is the <I>NICETEXT</I>:</H3>
-<TEXTAREA NAME=PLAINTEXT COLS=80 ROWS=12>
+	os.add("<HTML>\n\
+<HEAD>\n\
+<TITLE>NICETEXT Output Screen</TITLE>\n\
+</HEAD>\n\
+<BODY BGCOLOR=\"#AAAAAA\">\n\
+<H2>NICETEXT Web-Sampler &copy; 1998  -  <I>Nicetext</I> Output Screen</H2>\n\
+<P>This is the result of the <I>nicetext</I> operation on the message\n\
+you selected.  If you <I>scramble</I> the unmodified text below then\n\
+the software will recover your original message on the next page.\n\
+But, if you modify the text - who knows what you will end up with?  Also,\n\
+if you are not satisfied with the quality of the <I>nicetext</I> then\n\
+use the reload button on your browser for another try!</P>\n\
+<FORM METHOD=POST ACTION=\"scramble?\">\n\
+<INPUT TYPE=HIDDEN NAME=NTTPDATA VALUE=\"NICETEXT\">\n\
+<P>\n\
+<H3>Here is the <I>NICETEXT</I>:</H3>\n\
+<TEXTAREA NAME=PLAINTEXT COLS=80 ROWS=12>\n\
 ");
 
 	MTCstring plainTextFileName(tempnam(tmpDir.c_str(), "nttp-pt"));
@@ -1023,9 +1023,9 @@
 		}
 	}
 
-	os.add("</TEXTAREA> 
-</P> 
-<H3>
+	os.add("</TEXTAREA>\n\
+</P>\n\
+<H3>\n\
 <INPUT TYPE=HIDDEN NAME=STYLE VALUE=\"");
 
 	os.add(formStyle.c_str());
@@ -1038,16 +1038,16 @@
 
 	if (formDict.length()!=0)
 	{
-		os.add("... with a larger dictionary.
+		os.add("... with a larger dictionary.\n\
 <INPUT TYPE=HIDDEN NAME=BIGDICT VALUE=\"YES\">");
 	}
 
-	os.add("</H3>
-<INPUT TYPE=SUBMIT VALUE=\" Scramble this message \"> 
-<INPUT TYPE=RESET  VALUE=\" Reset \"> 
-</FORM> 
-</BODY>
-</HTML>
+	os.add("</H3>\n\
+<INPUT TYPE=SUBMIT VALUE=\" Scramble this message \">\n\
+<INPUT TYPE=RESET  VALUE=\" Reset \">\n\
+</FORM>\n\
+</BODY>\n\
+</HTML>\n\
 ");
 }
 
@@ -1073,23 +1073,23 @@
 
 BOOL sendScramText(MTCstringList &os, MTCRBT<MTCpostData> &pdSet)
 {
-	os.add("<HTML> 
-<HEAD> 
-<TITLE>SCRAMBLED Output Screen</TITLE> 
-</HEAD> 
-<BODY BGCOLOR=\"#AAAAAA\"> 
-
-<H2>NICETEXT Web-Sampler &copy; 1998  -  <I>Scrambled</I> Output Screen</H2>
-<P>This page contains the <I>scrambled</I> version of the <I>nicetext</I>
-on the previous page.  If you did not modify the <I>nicetext</I> then this
-should be your original message! (If it does NOT match your original message
-then rest assured that it is because of the poor implementation of HTTP/1.0
-rather than a problem with the basic transformation software.)</P>
-<H3>Here is the SCRAMBLED Text:</H3> 
-<FORM METHOD=POST ACTION=\"index.html\"> 
-<INPUT TYPE=HIDDEN NAME=NTTPDATA VALUE=\"INITIAL\">
-<P>
-<TEXTAREA NAME=PLAINTEXT COLS=80 ROWS=12 READONLY=\"YES\">
+	os.add("<HTML>\n\
+<HEAD>\n\
+<TITLE>SCRAMBLED Output Screen</TITLE>\n\
+</HEAD>\n\
+<BODY BGCOLOR=\"#AAAAAA\">\n\
+\n\
+<H2>NICETEXT Web-Sampler &copy; 1998  -  <I>Scrambled</I> Output Screen</H2>\n\
+<P>This page contains the <I>scrambled</I> version of the <I>nicetext</I>\n\
+on the previous page.  If you did not modify the <I>nicetext</I> then this\n\
+should be your original message! (If it does NOT match your original message\n\
+then rest assured that it is because of the poor implementation of HTTP/1.0\n\
+rather than a problem with the basic transformation software.)</P>\n\
+<H3>Here is the SCRAMBLED Text:</H3>\n\
+<FORM METHOD=POST ACTION=\"index.html\">\n\
+<INPUT TYPE=HIDDEN NAME=NTTPDATA VALUE=\"INITIAL\">\n\
+<P>\n\
+<TEXTAREA NAME=PLAINTEXT COLS=80 ROWS=12 READONLY=\"YES\">\n\
 ");
 
 	MTCstring plainTextFileName(tempnam(tmpDir.c_str(), "nttp-pt"));
@@ -1207,15 +1207,15 @@
 		}
 	}
 
-	os.add("
-</TEXTAREA> 
-</P>
-</FORM> 
-<P>
-<A HREF=\"start.html\">GO BACK TO START PAGE...</A>
-</P>
-</BODY>
-</HTML>
+	os.add("\n\
+</TEXTAREA>\n\
+</P>\n\
+</FORM>\n\
+<P>\n\
+<A HREF=\"start.html\">GO BACK TO START PAGE...</A>\n\
+</P>\n\
+</BODY>\n\
+</HTML>\n\
 ");
 }
 
@@ -1236,8 +1236,7 @@
 
         if (gettimeofday(&t, &tz)==-1)
         {
-                errorMsg(EMT_WARNING, "random seed generation failed...no big de
-al though...", "randomize()");
+                errorMsg(EMT_WARNING, "random seed generation failed...no big deal though...", "randomize()");
         }
 
         srandom(t.tv_sec|t.tv_usec);
