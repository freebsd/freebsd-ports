Index: juk/filerenamer.cpp
===================================================================
RCS file: /home/kde/kdemultimedia/juk/filerenamer.cpp,v
retrieving revision 1.23
retrieving revision 1.23.2.2
diff -u -3 -p -u -r1.23 -r1.23.2.2
--- juk/filerenamer.cpp	2 Nov 2003 00:23:01 -0000	1.23
+++ juk/filerenamer.cpp	6 Jun 2004 13:47:57 -0000	1.23.2.2
@@ -138,8 +138,11 @@ QString FileRenamer::expandToken(TokenTy
         value.replace(QDir::separator(), "");
     }
 
+    if((type == Track) && needValue && (value.toUInt() == 0))
+        return QString::null;
+
     if((needValue) && value.isEmpty())
-        return QString();
+        return QString::null;
 
     token.replace("%s", value);
     return token;
