
$FreeBSD$

--- mesdbc.c.orig	Sun Aug 22 17:06:05 2004
+++ mesdbc.c	Sun Aug 22 17:06:23 2004
@@ -1543,7 +1543,8 @@
                     db->entry.boundl      = 0;
                     db->entry.bound       = 0;
                  case MAGIK_VV:
-                };
+                break;
+		};
                 if (LLists_defined)
                 {   if (var_size_defined < LLists_defined)
                     {   bcopy( &db->entry.var[db->header.LList - LLists_defined]
