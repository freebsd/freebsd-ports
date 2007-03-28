--- src/HtmlLinks.h.orig	Wed Mar 28 04:13:45 2007
+++ src/HtmlLinks.h	Wed Mar 28 04:13:56 2007
@@ -19,7 +19,7 @@
   HtmlLink& operator=(const HtmlLink& x);
   HtmlLink(double xmin,double ymin,double xmax,double ymax,GString *_dest);
   ~HtmlLink();
-  GBool HtmlLink::isEqualDest(const HtmlLink& x) const;
+  GBool isEqualDest(const HtmlLink& x) const;
   GString *getDest(){return new GString(dest);}
   double getX1() const {return Xmin;}
   double getX2() const {return Xmax;}
