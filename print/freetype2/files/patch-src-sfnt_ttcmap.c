diff --git a/src/sfnt/ttcmap.c b/src/sfnt/ttcmap.c
index 6830391..1bd2ce7 100644
--- src/sfnt/ttcmap.c
+++ src/sfnt/ttcmap.c
@@ -1635,7 +1635,7 @@
       FT_INVALID_TOO_SHORT;
 
     length = TT_NEXT_ULONG( p );
-    if ( table + length > valid->limit || length < 8208 )
+    if ( length > (FT_UInt32)( valid->limit - table ) || length < 8192 + 16 )
       FT_INVALID_TOO_SHORT;
 
     is32       = table + 12;
@@ -1863,7 +1863,8 @@
     p      = table + 16;
     count  = TT_NEXT_ULONG( p );
 
-    if ( table + length > valid->limit || length < 20 + count * 2 )
+    if ( length > (FT_ULong)( valid->limit - table ) ||
+         length < 20 + count * 2                     )
       FT_INVALID_TOO_SHORT;
 
     /* check glyph indices */
@@ -2048,7 +2049,8 @@
     p          = table + 12;
     num_groups = TT_NEXT_ULONG( p );
 
-    if ( table + length > valid->limit || length < 16 + 12 * num_groups )
+    if ( length > (FT_ULong)( valid->limit - table ) ||
+         length < 16 + 12 * num_groups               )
       FT_INVALID_TOO_SHORT;
 
     /* check groups, they must be in increasing order */
@@ -2429,7 +2431,8 @@
     FT_ULong  num_selectors = TT_NEXT_ULONG( p );
 
 
-    if ( table + length > valid->limit || length < 10 + 11 * num_selectors )
+    if ( length > (FT_ULong)( valid->limit - table ) ||
+         length < 10 + 11 * num_selectors            )
       FT_INVALID_TOO_SHORT;
 
     /* check selectors, they must be in increasing order */
@@ -2491,7 +2494,7 @@
           FT_ULong  i, lastUni = 0;
 
 
-          if ( ndp + numMappings * 4 > valid->limit )
+          if ( numMappings * 4 > (FT_ULong)( valid->limit - ndp ) )
             FT_INVALID_TOO_SHORT;
 
           for ( i = 0; i < numMappings; ++i )
