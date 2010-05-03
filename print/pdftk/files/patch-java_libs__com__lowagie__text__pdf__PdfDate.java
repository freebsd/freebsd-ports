--- ./java_libs/com/lowagie/text/pdf/PdfDate.java.orig	2006-07-26 19:56:42.000000000 -0400
+++ ./java_libs/com/lowagie/text/pdf/PdfDate.java	2010-04-08 18:13:54.000000000 -0400
@@ -76,7 +76,7 @@
     // ssteward; static builds of pdftk (Windows, gcc 3.3.1) would
     // omit this class because of its reference by reflection;
     // this treatment ensures that ld will include it
-    private static Class c1= gnu.java.locale.Calendar.class;
+    private static Class c1= java.util.Calendar.class;
 
     private static final int dateSpace[] = {Calendar.YEAR, 4, 0, Calendar.MONTH, 2, -1, Calendar.DAY_OF_MONTH, 2, 0,
         Calendar.HOUR_OF_DAY, 2, 0, Calendar.MINUTE, 2, 0, Calendar.SECOND, 2, 0};
