diff -u -r1.3 element.cc
--- chemistry/element.cc	1 Mar 2003 17:02:49 -0000	1.3
+++ chemistry/element.cc	2 Apr 2003 04:14:46 -0000
@@ -97,7 +97,7 @@
 				if (!strcmp((const char*)child->name, "name"))
 				{
 					tmp = (char*) xmlNodeGetLang(child);
-					if ((!tmp) && (!lang) && (!strncmp(lang, tmp, 2))) Elt->name = (char*) xmlNodeGetContent(child);
+					if (tmp && lang && (!strncmp(lang, tmp, 2))) Elt->name = (char*) xmlNodeGetContent(child);
 					else DefaultName = (char*) xmlNodeGetContent(child);
 				}
 				else if (!strcmp((const char*)child->name, "color"))

