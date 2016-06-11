--- osd.c.orig	2012-05-16 20:25:00 UTC
+++ osd.c
@@ -780,7 +780,7 @@ eOSState cOsdPipObject::ProcessKey(eKeys
                 if (cControl::Control())
                 {
                     cControl::Control()->GetIndex(pos, end);
-                    if (pPos == "")
+                    if (*pPos == '\0')
                     {
                         pPos = IndexToHMSF(pos);
                     }
