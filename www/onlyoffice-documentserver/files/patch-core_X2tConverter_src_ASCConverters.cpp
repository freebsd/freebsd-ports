--- core/X2tConverter/src/ASCConverters.cpp.orig	2021-09-30 12:13:32 UTC
+++ core/X2tConverter/src/ASCConverters.cpp
@@ -4342,7 +4342,7 @@ namespace NExtractTools
 	{
 		params.m_bMacro = true;
 		
-		_UINT32 nRes = ConvertXls2Xlsx( sFrom, sTo, params.getPassword(), params.getFontPath(), sTemp, NULL, params.m_bMacro);
+		_UINT32 nRes = ConvertXls2Xlsx( sFrom, sTo, params.getPassword(), params.getFontPath(), sTemp, 0, params.m_bMacro);
 
 		nRes = processEncryptionError(nRes, sFrom, params);
 		return nRes;
@@ -4375,7 +4375,7 @@ namespace NExtractTools
 		NSDirectory::CreateDirectory(sResultXlsxDir);
 
 		params.m_bMacro = true;
-		_UINT32 nRes = ConvertXls2Xlsx( sFrom, sResultXlsxDir, params.getPassword(), params.getFontPath(), sTemp, NULL, params.m_bMacro);
+		_UINT32 nRes = ConvertXls2Xlsx( sFrom, sResultXlsxDir, params.getPassword(), params.getFontPath(), sTemp, 0, params.m_bMacro);
 
 		nRes = processEncryptionError(nRes, sFrom, params);
 		if (SUCCEEDED_X2T(nRes))
