--- projwrap.h.orig	2020-05-07 16:41:54 UTC
+++ projwrap.h
@@ -24,6 +24,7 @@ or http://www.gnu.org
 #include<stdio.h>
 #include<stdlib.h>
 #include<math.h>
+#undef ACCEPT_USE_OF_DEPRECATED_PROJ_API_H
 #include<proj.h>
 /******************************************************************************/
 /******************************************************************************/
