--- htdocs/index.html.es.orig	Fri Aug 27 06:08:59 1999
+++ htdocs/index.html.es	Sun Feb 20 17:15:30 2000
@@ -35,17 +35,24 @@
   <P>
   La
   <A
-   HREF="manual/index.html"
+   HREF="http://@@HOSTNAME@@:8080/manual/index.html"
   >documentaci&oacute;n</A>
   de Apache ha sido incluida en esta distribuci&oacute;n.
   </P>
+<P>The <STRONG>FrontPage 2000 Extentions (mod_frontpage)</STRONG> has been installed, read the
+<A HREF="http://@@HOSTNAME@@:8080/manual/mod/mod_frontpage/index.html">FrontPage 2000 documentation</A> carefully.</P>
+<P>Information on the FreeBSD operating system can be found on the <A HREF="http://www.freebsd.org/">FreeBSD Home Page</A>.</P>
   <P>
   El administrador del sitio esta invitado a usar la siguiente
   imagen para indicar que su sitio es servido por Apache.
-  &iexcl;Gracias por usar Apache!
+  &iexcl;Gracias por usar Apachei and FreeBSD!
   </P>
   <DIV ALIGN="CENTER">
-   <IMG SRC="apache_pb.gif" ALT="">
+  <A HREF="http://www.apache.org/"><IMG SRC="/images/apache_pb.gif" ALT="Powered by Apache"></A>
+  <A HREF="http://www.freebsd.org/">
+        <IMG SRC="/images/powerlogo.gif" ALT="Site driven by FreeBSD - FreeBSD: The Power to Server!"></A>
+  <A HREF="http://www.microsoft.com/frontpage/default.htm">
+        <IMG SRC="/images/fplogo.gif" ALT="Created with Microsoft FrontPage 2000"></A>
   </DIV>
  </BODY>
 </HTML>
