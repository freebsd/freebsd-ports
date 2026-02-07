--- src/com/sun/pdfview/colorspace/PDFColorSpace.java.orig	2011-09-15 09:33:56 UTC
+++ src/com/sun/pdfview/colorspace/PDFColorSpace.java
@@ -161,7 +161,13 @@ public class PDFColorSpace {
         PDFObject[] ary = csobj.getArray();
         name = ary[0].getStringValue();
 
-        if (name.equals("CalGray")) {
+        if (name.equals("DeviceGray") || name.equals("G")) {
+            return getColorSpace(COLORSPACE_GRAY);
+        } else if (name.equals("DeviceRGB") || name.equals("RGB")) {
+            return getColorSpace(COLORSPACE_RGB);
+        } else if (name.equals("DeviceCMYK") || name.equals("CMYK")) {
+            return getColorSpace(COLORSPACE_CMYK);
+        } else if (name.equals("CalGray")) {
             value = new PDFColorSpace(new CalGrayColor(ary[1]));
         } else if (name.equals("CalRGB")) {
             value = new PDFColorSpace(new CalRGBColor(ary[1]));
@@ -194,8 +200,7 @@ public class PDFColorSpace {
 
             return new PatternSpace(base);
         } else {
-            throw new PDFParseException("Unknown color space: " + name +
-                " with " + ary[1]);
+            throw new PDFParseException("Unknown color space: " + name);
         }
 
         csobj.setCache(value);
