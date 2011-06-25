--- osd.c.orig
+++ osd.c
@@ -788,7 +788,7 @@ eOSState cOsdPipObject::ProcessKey(eKeys
                 if (cControl::Control())
                 {
                     cControl::Control()->GetIndex(pos, end);
-                    if (pPos == "")
+                    if (*pPos == '\0')
                     {
                         pPos = IndexToHMSF(pos);
                     }
