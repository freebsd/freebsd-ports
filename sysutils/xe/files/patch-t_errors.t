--- t/errors.t.orig	2017-11-07 14:15:52 UTC
+++ t/errors.t
@@ -40,7 +40,7 @@ tap3 'exit code when command cannot be run' <<'EOF'
 xe /dev/null/calc.exe
 <<<
 a
->>>= 126
+>>>= 127
 EOF
 
 tap3 'exit code when command was not found' <<'EOF'
