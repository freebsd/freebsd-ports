--- panel/common/passencrypt.cpp.orig	2007-11-24 13:03:32 UTC
+++ panel/common/passencrypt.cpp
@@ -64,9 +64,9 @@ char	PasswdCrypt::HexValue(char      c)
 void	PasswdCrypt::DesECBEncode(const string& sKeyHex, const string& sDecode, string& sEncode)
 {
 	#ifdef __LINM_SFTP_USE__
-	des_key_schedule	tKeySchedule;
+	DES_key_schedule	tKeySchedule;
 
-	des_cblock			tHexBlock, tSrcBlock, tDecBlock;
+	DES_cblock			tHexBlock, tSrcBlock, tDecBlock;
 	char   				cHexa[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
 	unsigned char   	cMask[2]        = {0xF0, 0x0F};
 	char				cEncode[17];
@@ -93,8 +93,8 @@ void	PasswdCrypt::DesECBEncode(const str
 			tSrcBlock[i] = (unsigned char)' ';
 	}
 
-	des_set_key((const_des_cblock*)&tHexBlock, tKeySchedule);
-	des_ecb_encrypt((const_des_cblock*)&tSrcBlock, &tDecBlock, tKeySchedule, DES_ENCRYPT);
+	DES_set_key((const_DES_cblock*)&tHexBlock, &tKeySchedule);
+	DES_ecb_encrypt((const_DES_cblock*)&tSrcBlock, &tDecBlock, &tKeySchedule, DES_ENCRYPT);
 
 	for(i=0; i<8; i++)
 	{
@@ -110,9 +110,9 @@ void	PasswdCrypt::DesECBEncode(const str
 void	PasswdCrypt::DesECBDecode(const string& sKeyHex, const string& sEncode, string& sDecode)
 {
 	#ifdef __LINM_SFTP_USE__
-	des_key_schedule	tKeySchedule;
+	DES_key_schedule	tKeySchedule;
 
-	des_cblock			tKeyBlock, tEncBlock, tDecBlock;
+	DES_cblock			tKeyBlock, tEncBlock, tDecBlock;
 	char				cKeyHex[16];
 	char				cEncode[16];
 	int					i;
@@ -133,8 +133,8 @@ void	PasswdCrypt::DesECBDecode(const str
 		HEX2BYTE(*(tEncBlock+i), cEncode+i*2);
 	}
 
-	des_set_key((const_des_cblock*)&tKeyBlock, tKeySchedule);
-	des_ecb_encrypt((const_des_cblock*)&tEncBlock, &tDecBlock, tKeySchedule, DES_DECRYPT);
+	DES_set_key((const_DES_cblock*)&tKeyBlock, &tKeySchedule);
+	DES_ecb_encrypt((const_DES_cblock*)&tEncBlock, &tDecBlock, &tKeySchedule, DES_DECRYPT);
 
 	sDecode = "";
 	for(i=0; i<8; i++)
