--- knode/knconfig.cpp.orig     Thu Jun 20 18:14:26 2002
+++ knode/knconfig.cpp  Thu Jun 20 18:14:44 2002
@@ -688,7 +688,7 @@
   s_howSig=conf->readBoolEntry("showSig", true);
   i_nterpretFormatTags=conf->readBoolEntry("interpretFormatTags", true);
   q_uoteCharacters=conf->readEntry("quoteCharacters",">:");
-  i_nlineAtt=conf->readBoolEntry("inlüineAtt", true);
+  i_nlineAtt=conf->readBoolEntry("inlineAtt", true);
   o_penAtt=conf->readBoolEntry("openAtt", false) ;
   s_howAlts=conf->readBoolEntry("showAlts", false);
   f_ullHdrs=conf->readBoolEntry("fullHdrs", false);
