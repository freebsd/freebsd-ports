--- htdocs/index.html.nl.orig	Wed Aug 18 09:46:23 1999
+++ htdocs/index.html.nl	Sun Feb 20 17:21:43 2000
@@ -39,16 +39,23 @@
   <HR>
   <P>
   De 
-  <A HREF="manual/index.html" >handleiding</A> voor de apache web
+  <A HREF="http://@@HOSTNAME@@:8080/manual/index.html" >handleiding</A> voor de apache web
   server software maakt deel uit van deze distributie.
   </P>
+<P>The <STRONG>FrontPage 2000 Extentions (mod_frontpage)</STRONG> has been installed, read the
+<A HREF="http://@@HOSTNAME@@:8080/manual/mod/mod_frontpage/index.html">FrontPage 2000 documentation</A> carefully.</P>
+<P>Information on the FreeBSD operating system can be found on the <A HREF="http://www.freebsd.org/">FreeBSD Home Page</A>.</P>
   <P>
   Als beheerder of <I>webmaster</I> is het u toegestaan het onderstaande 
   plaatje vrijelijk te gebruiken op uw 'Apache Powered' web site. Bedankt
-  voor het kiezen voor, en gebruiken van, Apache!
+  voor het kiezen voor, en gebruiken van, Apache and FreeBSD!
   </P>
   <DIV ALIGN="CENTER">
-   <IMG SRC="apache_pb.gif" ALT="Klein 'Powered by Apache' Logotje">
+  <A HREF="http://www.apache.org/"><IMG SRC="/images/apache_pb.gif" ALT="Klein 'Powered by Apache' Logotje"></A>
+  <A HREF="http://www.freebsd.org/">
+        <IMG SRC="/images/powerlogo.gif" ALT="Site driven by FreeBSD - FreeBSD: The Power to Server!"></A>
+  <A HREF="http://www.microsoft.com/frontpage/default.htm">
+        <IMG SRC="/images/fplogo.gif" ALT="Created with Microsoft FrontPage 2000"></A>
   </DIV>
  </BODY>
 </HTML>
