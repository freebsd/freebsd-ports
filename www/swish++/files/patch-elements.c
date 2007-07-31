--- mod/html/elements.c.orig	2007-07-31 20:12:01.000000000 +0200
+++ mod/html/elements.c	2007-07-31 20:12:22.000000000 +0200
@@ -295,7 +295,7 @@
         // become overly pedantic about casting to enums.
         //
         element::end_tag_type const
-            v = (element::end_tag_type const)(int const)(p[1]);
+            v = (element::end_tag_type const)(intptr_t const)(p[1]);
         element &e = insert( value_type( *p++, element( v ) ) ).first->second;
 
         switch ( v ) {
