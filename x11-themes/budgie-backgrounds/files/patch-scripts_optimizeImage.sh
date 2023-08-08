--- scripts/optimizeImage.sh.orig	2022-09-07 16:55:07 UTC
+++ scripts/optimizeImage.sh
@@ -1,4 +1,4 @@
-#!/usr/bin/env bash
+#!/bin/sh
 
 INPUT="$1"
 OUTPUT="$2"
@@ -8,9 +8,9 @@ cp "$INPUT" "$OUTPUT" || exit 1
 mogrify -format jpg "$OUTPUT" || exit 2
 mogrify -resize 3840x "$OUTPUT" || exit 3
 
-QUALITY="$(identify -verbose $OUTPUT | grep 'Image:\|Quality')"
+QUALITY=$(identify -format %Q  $OUTPUT) 
 
-if [[ "$QUALITY" > 90 ]]; then
+if [ $QUALITY -gt 90 ]; then
     mogrify -quality 90 "$OUTPUT" || exit 4
 fi
 
