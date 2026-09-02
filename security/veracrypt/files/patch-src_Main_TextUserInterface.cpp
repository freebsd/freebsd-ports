TextUserInterface.cpp:122:5: error: const_cast from 'const wxScopedWCharBuffer' (aka 'const wxScopedCharTypeBuffer<wchar_t>') to 'wchar_t *' is not allowed
                                const_cast <wchar_t *> (passwordStr.wc_str())[i] = L'X';
                                ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

--- src/Main/TextUserInterface.cpp.orig	2026-06-09 10:55:00 UTC
+++ src/Main/TextUserInterface.cpp
@@ -172,7 +172,7 @@ namespace VeraCrypt
 			for (size_t i = 0; i < length && i < VolumePassword::MaxSize; ++i)
 			{
 				passwordBuf[i] = (wchar_t) passwordStr[i];
-				const_cast <wchar_t *> (passwordStr.wc_str())[i] = L'X';
+				passwordStr[i] = L'X';
 			}
 
 			if (verify && verPhase)
