--- scribus/scribusXml.cpp.orig	Tue Apr 20 16:36:12 2004
+++ scribus/scribusXml.cpp	Tue Apr 20 16:38:07 2004
@@ -2400,7 +2400,7 @@
 		}
 		else
 			ob.setAttribute("ANNOTATION",0);
-		ob.setAttribute("ANNAME", !item->AutoName ? item->AnName : "");
+		ob.setAttribute("ANNAME", !item->AutoName ? item->AnName : QString(""));
 		ob.setAttribute("TEXTFLOW", item->Textflow ? 1 : 0);
 		ob.setAttribute("TEXTFLOW2", item->Textflow2 ? 1 : 0);
 		ob.setAttribute("AUTOTEXT", item->isAutoText ? 1 : 0);
@@ -2785,7 +2785,7 @@
 			}
 			else
 				ob.setAttribute("ANNOTATION",0);
-			ob.setAttribute("ANNAME", !item->AutoName ? item->AnName : "");
+			ob.setAttribute("ANNAME", !item->AutoName ? item->AnName : QString(""));
 			ob.setAttribute("TEXTFLOW", item->Textflow ? 1 : 0);
 			ob.setAttribute("TEXTFLOW2", item->Textflow2 ? 1 : 0);
 			ob.setAttribute("AUTOTEXT", item->isAutoText ? 1 : 0);
