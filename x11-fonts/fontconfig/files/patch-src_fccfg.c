--- src/fccfg.c.orig	Fri Jul 18 15:22:21 2003
+++ src/fccfg.c	Fri Jul 18 15:20:03 2003
@@ -617,10 +617,10 @@
 	case FcTypeLangSet:
 	    switch (op) {
 	    case FcOpContains:
-		ret = FcLangSetContains (m.u.l, v.u.l);
+		ret = FcLangSetContains (v.u.l, m.u.l);
 		break;
 	    case FcOpNotContains:
-		ret = FcLangSetContains (m.u.l, v.u.l);
+		ret = FcLangSetContains (v.u.l, m.u.l);
 		break;
 	    case FcOpEqual:
 		ret = FcLangSetEqual (m.u.l, v.u.l);
