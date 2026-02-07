--- lib/llrb.h.orig	2016-01-07 09:47:40 UTC
+++ lib/llrb.h
@@ -74,7 +74,7 @@ struct name { struct type *rbh_root; }
 #define LLRB_RED   1
 
 #define LLRB_ENTRY(type) \
-struct { struct type *rbe_left, *rbe_right, *rbe_parent; _Bool rbe_color; }
+struct { struct type *rbe_left, *rbe_right, *rbe_parent; bool rbe_color; }
 
 #define LLRB_LEFT(elm, field) (elm)->field.rbe_left
 #define LLRB_RIGHT(elm, field) (elm)->field.rbe_right
