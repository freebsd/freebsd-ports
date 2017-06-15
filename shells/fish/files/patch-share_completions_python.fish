--- share/completions/python.fish.orig	2017-02-11 04:56:23 UTC
+++ share/completions/python.fish
@@ -16,15 +16,3 @@ complete -c python -s W -x --description
 complete -c python -s x -d 'Skip first line of source, allowing use of non-Unix forms of #!cmd'
 complete -c python -a "(__fish_complete_suffix .py)"
 complete -c python -a '-' -d 'Read program from stdin'
-
-switch (python -V 2>&1 | string replace -r '^.*\s([23])..*' '$1')[1]
-    case 2
-        complete -c python -s 3 -d 'Warn about Python 3.x incompatibilities that 2to3 cannot trivially fix'
-        complete -c python -s t --description "Warn on mixed tabs and spaces"
-        complete -c python -s Q -x -a "old new warn warnall" --description "Division control"
-    case 3
-        complete -c python -s q --description 'Don\'t print version and copyright messages on interactive startup'
-        complete -c python -s X -x -d 'Set implementation-specific option'
-        complete -c python -s b  -d 'Issue warnings about str(bytes_instance), str(bytearray_instance) and comparing bytes/bytearray with str'
-        complete -c python -o bb -d 'Issue errors'
-end
