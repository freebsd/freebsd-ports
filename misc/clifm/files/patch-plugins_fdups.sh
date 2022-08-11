--- plugins/fdups.sh.orig	2022-06-28 06:17:34 UTC
+++ plugins/fdups.sh
@@ -1,4 +1,4 @@
-#!/bin/bash
+#!/bin/sh
 
 # Plugin to find/remove duplicate files for CliFM
 #
@@ -8,14 +8,12 @@
 # by MD5) in DIR (current directory if omitted) and allow the user to remove
 # one or more of them
 #
-# Dependencies: find md5sum sort uniq xargs sed stat
+# Dependencies: gfind md5 sort guniq xargs sed stat
 #
 # Notes:
 # 1. If the file size exceeds SIZE_DIGITS digits the file will be misplaced.
 #    (12 digits amount to sizes up to 931GiB)
-# 2. Bash compatible shell required for mktemp(1)
 #
-# Shell: Bash
 # Based on https://github.com/jarun/nnn/blob/master/plugins/dups and modified
 # to fit our needs
 #
@@ -25,14 +23,14 @@ no_dep=0
 me="clifm"
 no_dep=0
 
-if ! type find > /dev/null 2>&1; then
-	printf "%s: find: command not found\n" "$me" >&2; no_dep=1
-elif ! type md5sum > /dev/null 2>&1; then
-	printf "%s: md5sum: command not found\n" "$me" >&2; no_dep=1
+if ! type gfind > /dev/null 2>&1; then
+	printf "%s: gfind: command not found\n" "$me" >&2; no_dep=1
+elif ! type md5 > /dev/null 2>&1; then
+	printf "%s: md5: command not found\n" "$me" >&2; no_dep=1
 elif ! type sort > /dev/null 2>&1; then
 	printf "%s: sort: command not found\n" "$me" >&2; no_dep=1
-elif ! type uniq > /dev/null 2>&1; then
-	printf "%s: uniq: command not found\n" "$me" >&2; no_dep=1
+elif ! type guniq > /dev/null 2>&1; then
+	printf "%s: guniq: command not found\n" "$me" >&2; no_dep=1
 elif ! type xargs > /dev/null 2>&1; then
 	printf "%s: xargs: command not found\n" "$me" >&2; no_dep=1
 elif ! type sed > /dev/null 2>&1; then
@@ -72,20 +70,20 @@ printf "\
 " > "$tmp_file"
 
 # shellcheck disable=SC2016
-find "$dir" -size +0 -type f -printf "%${size_digits}s %p\n" | sort -rn | uniq -w"${size_digits}" -D | sed -e '                                s/^ \{0,12\}\([0-9]\{0,12\}\) \(.*\)$/printf "%s %s\\n" "$(md5sum "\2")" "d\1"/                                                                       ' | tr '\n' '\0' | xargs -0 -n1 -r sh -c | sort | { uniq -w32 --all-repeated=separate; echo; } | sed -ne '
-h                                                           
+gfind "$dir" -size +0 -type f -printf "%${size_digits}s %p\n" | sort -rn | guniq -w"${size_digits}" -D | sed -e 's/^ \{0,12\}\([0-9]\{0,12\}\) \(.*\)$/printf "%s %s\\n" "$(md5 -r "\2")" "d\1"/' | tr '\n' '\0' | xargs -0 -n1 -r sh -c | sort | { guniq -w32 --all-repeated=separate; echo; } | sed -ne '
+h
 s/^\(.\{32\}\).* d\([0-9]*\)$/## md5sum: \1 size: \2 bytes/p
-g    
+g
 :loop
-N             
-/.*\n$/!b loop                               
-p' | sed -e 's/^.\{32\}  \(.*\) d[0-9]*$/\1/' >> "$tmp_file"
+N
+/.*\n$/!b loop
+p' | sed -e 's/^.\{32\} \(.*\) d[0-9]*$/\1/' >> "$tmp_file"
 
-time_pre="$(stat -c '%Y' "$tmp_file")"
+time_pre="$(stat -f '%m' "$tmp_file")"
 
 "$EDITOR" "$tmp_file"
 
-time_post="$(stat -c '%Y' "$tmp_file")"
+time_post="$(stat -f '%m' "$tmp_file")"
 
 if [ "$time_pre" = "$time_post" ]; then
 	printf "%s: Nothing to do\n" "$me"
