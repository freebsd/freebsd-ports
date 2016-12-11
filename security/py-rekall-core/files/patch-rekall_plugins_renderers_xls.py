--- rekall/plugins/renderers/xls.py.orig	2015-10-23 12:57:00 UTC
+++ rekall/plugins/renderers/xls.py
@@ -37,11 +37,11 @@ from rekall.ui import text
 # pylint: disable=unexpected-keyword-arg,no-value-for-parameter
 # pylint: disable=redefined-outer-name
 
-HEADER_STYLE = styles.Style(font=styles.Font(bold=True))
-SECTION_STYLE = styles.Style(
+HEADER_STYLE = styles.NamedStyle(name='header', font=styles.Font(bold=True))
+SECTION_STYLE = styles.NamedStyle(name='section',
     fill=styles.PatternFill(
         fill_type=fills.FILL_SOLID, start_color=styles.Color(colors.RED)))
-FORMAT_STYLE = styles.Style(
+FORMAT_STYLE = styles.NamedStyle(name='format',
     alignment=styles.Alignment(vertical="top", wrap_text=False))
 
 
@@ -291,7 +291,7 @@ class XLSNoneObjectRenderer(XLSObjectRen
 class XLSDateTimeRenderer(XLSObjectRenderer):
     """Renders timestamps as python datetime objects."""
     renders_type = "UnixTimeStamp"
-    STYLE = styles.Style(number_format='MM/DD/YYYY HH:MM:SS')
+    STYLE = styles.NamedStyle(name='style', number_format='MM/DD/YYYY HH:MM:SS')
 
     def GetData(self, item, **options):
         if item.v() == 0:
