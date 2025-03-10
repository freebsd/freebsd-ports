--- cf/m4/proto.m4.orig	2024-01-31 06:38:32 UTC
+++ cf/m4/proto.m4
@@ -720,6 +720,9 @@ _OPTION(HeloName, `confHELO_NAME')
 # Name to use for EHLO (defaults to $j)
 _OPTION(HeloName, `confHELO_NAME')
 
+# Use Blacklistd
+_OPTION(UseBlacklist, `confBLACKLIST', `false')
+
 ifdef(`_NEED_SMTPOPMODES_', `dnl
 # SMTP operation modes
 C{SMTPOpModes} s d D')
