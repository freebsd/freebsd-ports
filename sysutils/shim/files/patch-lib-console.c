--- lib/console.c.orig	2019-10-23 08:09:31 UTC
+++ lib/console.c
@@ -360,7 +360,7 @@ static struct {
 	{  EFI_SECURITY_VIOLATION,     L"Security Violation"},
 
 	// warnings
-	{  EFI_WARN_UNKOWN_GLYPH,      L"Warning Unknown Glyph"},
+	{  EFI_WARN_UNKNOWN_GLYPH,     L"Warning Unknown Glyph"},
 	{  EFI_WARN_DELETE_FAILURE,    L"Warning Delete Failure"},
 	{  EFI_WARN_WRITE_FAILURE,     L"Warning Write Failure"},
 	{  EFI_WARN_BUFFER_TOO_SMALL,  L"Warning Buffer Too Small"},
