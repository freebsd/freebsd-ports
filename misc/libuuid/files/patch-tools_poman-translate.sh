--- tools/poman-translate.sh.orig	2025-03-18 12:50:51 UTC
+++ tools/poman-translate.sh
@@ -82,7 +82,7 @@ mapfile -t PO4ACFG_TRANSLATIONS < <( awk '/\[type:asci
 mapfile -t LOCALES < <( awk '/\[po4a_langs\]/ {for (i=2; i<=NF; i++) print $i}' "$PO4ACFG" )
 mapfile -t PO4ACFG_TRANSLATIONS < <( awk '/\[type:asciidoc\]/ {print $2;}' "$PO4ACFG" )
 
-mkdir --parents "$DESTDIR"
+mkdir -p "$DESTDIR"
 
 DESTDIR=$( OLDPWD=- CDPATH='' cd -P -- "$DESTDIR" && pwd )
 
