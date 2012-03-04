--- modules/speller/default/affix.cpp.orig	2012-01-25 19:46:47.684690459 +0200
+++ modules/speller/default/affix.cpp	2012-01-25 19:46:56.385691084 +0200
@@ -796,7 +796,10 @@ bool AffixMgr::suffix_check (const Looku
     if (se->check(linf, word, ci, gi, sfxopts, ppfx)) return true;
     se = se->next;
   }
-  
+
+  if (word.size() == 0)
+    return false;
+
   // now handle the general case
   byte sp = *((const byte *)(word + word.size() - 1));
   SfxEntry * sptr = sStart[sp];
