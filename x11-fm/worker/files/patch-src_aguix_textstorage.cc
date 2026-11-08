--- src/aguix/textstorage.cc.orig	2026-10-17 15:44:21 UTC
+++ src/aguix/textstorage.cc
@@ -275,7 +275,7 @@ std::optional< TextStorage::unwrapped_line_descr > Tex
         offset += m_line_to_raw_line[l].wrapped_line_len;
     }
 
-    return std::make_optional<unwrapped_line_descr>( { line.line.unwrapped_line_nr, offset } );
+    return (unwrapped_line_descr){ line.line.unwrapped_line_nr, offset };
 }
 
 AWidth &TextStorageString::getAWidth()
