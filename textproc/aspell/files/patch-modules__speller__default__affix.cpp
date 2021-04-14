--- modules/speller/default/affix.cpp.orig	2019-10-08 00:15:21 UTC
+++ modules/speller/default/affix.cpp
@@ -798,7 +798,10 @@ bool AffixMgr::suffix_check (const LookupInfo & linf, 
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
