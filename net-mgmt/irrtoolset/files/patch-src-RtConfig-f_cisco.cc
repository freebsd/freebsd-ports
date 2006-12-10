--- src/RtConfig/f_cisco.cc.orig	2004-07-30 12:58:11.000000000 +0200
+++ src/RtConfig/f_cisco.cc
@@ -1810,7 +1810,7 @@ void CiscoConfig::exportGroup(ASt asno, 
      sprintf(mapName, mapNameFormat, asno, mapCount++);
      for (fa = common_list->head(); fa && !last; fa = common_list->next(fa)) {
        ne = NormalExpression::evaluate(new FilterAFI((ItemAFI *) afi->dup(), fa->filter), ~0);
-       last = print(ne, fa->action, IMPORT, (ItemAFI *) afi);;
+       last = print(ne, fa->action, EXPORT, (ItemAFI *) afi);;
        delete ne;
      }
    }
