--- pexpect/bashrc.sh.orig	2020-01-17 17:08:15 UTC
+++ pexpect/bashrc.sh
@@ -14,3 +14,5 @@ PS1="$"
 
 # Unset PROMPT_COMMAND, so that it can't change PS1 to something unexpected.
 unset PROMPT_COMMAND
+
+bind 'set enable-bracketed-paste off'
