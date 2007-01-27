--- src/gui/wxIconManager.cpp.orig	Mon Jan 16 21:32:27 2006
+++ src/gui/wxIconManager.cpp	Sat Jan 27 16:25:26 2007
@@ -669,7 +669,11 @@
    // now try to find it by name
    icon = GetIcon(type);
 
+#if wxCHECK_VERSION(2, 8, 0)
+   if ( icon.IsSameAs(m_unknownIcon) )
+#else
    if ( icon == m_unknownIcon )
+#endif
    {
       // the generic icon for this class of things
       String primType = type.BeforeLast(_T('/'));
