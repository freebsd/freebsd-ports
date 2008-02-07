--- ../thotlib/dialogue/attrmenu.c.orig	2008-02-05 04:32:31.000000000 +0000
+++ ../thotlib/dialogue/attrmenu.c	2008-02-05 04:32:41.000000000 +0000
@@ -2097,7 +2097,7 @@
         {
         case AtEnumAttr:
         case AtNumAttr:
-          pAttrNew->AeAttrValue = (int)value;
+          pAttrNew->AeAttrValue = (long)value;
           /* applique les attributs a la partie selectionnee */
           AttachAttrToRange (pAttrNew, lastChar, firstChar, lastSel,
                              firstSel, pDoc, TRUE);
