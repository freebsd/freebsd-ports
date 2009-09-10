Description: Add some more failure checks and fix some memory leaks.
Author: Peter Pentchev <roam@FreeBSD.org>
Forwarded: http://sourceforge.net/mailarchive/message.php?msg_name=20090910102100.GA26539%40straylight.m.ringlet.net
Last-Update: 2009-09-10

--- src/keygen_test.c.orig
+++ src/keygen_test.c
@@ -43,6 +43,12 @@
 
 	passlen=sizeof(PASSWORD1);
 	password = mutils_malloc(passlen+1);
+	if (password == NULL)
+	{
+		fprintf(stderr, "KEYGEN-Test (KEYGEN_MCRYPT): Failed\n");
+		fprintf(stderr, "Cannot allocate memory.\n");
+		return(MUTILS_SYSTEM_RESOURCE_ERROR);
+	}
 	mutils_strncpy(password, (mutils_word8 *) PASSWORD1, passlen);
 	
 	if (mhash_get_keygen_max_key_size(KEYGEN_MCRYPT)==0) {
@@ -64,6 +70,8 @@
 	{
 		fprintf(stderr, "KEYGEN-Test (KEYGEN_MCRYPT): Failed\n");
 		fprintf(stderr, "Cannot allocate memory.\n");
+		mutils_free(password);
+		mutils_free(salt);
 		return(MUTILS_SYSTEM_RESOURCE_ERROR);
 	}
 
@@ -74,12 +82,16 @@
 	
 	mhash_keygen_ext(KEYGEN_MCRYPT, data, key, keysize, password, passlen);
 
+	mutils_free(salt);
+
 	tmp = mutils_asciify(key, keysize);
 
 	if (tmp == NULL)
 	{
 		fprintf(stderr, "KEYGEN-Test (KEYGEN_MCRYPT): Failed\n");
 		fprintf(stderr, "Cannot allocate memory (2).\n");
+		mutils_free(password);
+		mutils_free(key);
 		return(MUTILS_SYSTEM_RESOURCE_ERROR);
 	}
 
@@ -91,6 +103,7 @@
 	if (result != 0) {
 		fprintf(stderr, "KEYGEN-Test (KEYGEN_MCRYPT): Failed\n");
 		fprintf(stderr, "Expecting: 0x%s\nGot: 0x%s\n", KEY1, tmp);
+		mutils_free(tmp);
 		return(MUTILS_INVALID_RESULT);
 	}
 
@@ -98,6 +111,12 @@
 
 	passlen = sizeof(PASSWORD2);
 	password = (mutils_word8 *) mutils_malloc(passlen + 1);
+	if (password == NULL)
+	{
+		fprintf(stderr, "KEYGEN-Test (KEYGEN_MCRYPT): Failed\n");
+		fprintf(stderr, "Cannot allocate memory.\n");
+		return(MUTILS_SYSTEM_RESOURCE_ERROR);
+	}
 	mutils_strncpy(password, (mutils_word8 *) PASSWORD2, passlen);
 	
 	if (mhash_get_keygen_max_key_size(KEYGEN_S2K_SALTED)==0) {
@@ -114,6 +133,15 @@
 	salt = (mutils_word8 *) mutils_malloc(salt_size);
 	key = (mutils_word8 *) mutils_malloc(keysize);
 	
+	if ((salt == NULL) || (key == NULL))
+	{
+		fprintf(stderr, "KEYGEN-Test (KEYGEN_MCRYPT): Failed\n");
+		fprintf(stderr, "Cannot allocate memory.\n");
+		mutils_free(password);
+		mutils_free(salt);
+		return(MUTILS_SYSTEM_RESOURCE_ERROR);
+	}
+
 	data.hash_algorithm[0] = MHASH_SHA1;
 	data.count = 0;
 	data.salt = salt;
@@ -121,10 +149,19 @@
 	
 	mhash_keygen_ext(KEYGEN_S2K_SALTED, data, key, keysize, password, passlen);
 
-	mutils_memset(tmp, 0, keysize * 2);
+	mutils_free(salt);
 
 	tmp = mutils_asciify(key, keysize);
 
+	if (tmp == NULL)
+	{
+		fprintf(stderr, "KEYGEN-Test (KEYGEN_MCRYPT): Failed\n");
+		fprintf(stderr, "Cannot allocate memory.\n");
+		mutils_free(password);
+		mutils_free(key);
+		return(MUTILS_SYSTEM_RESOURCE_ERROR);
+	}
+
 	result = mutils_strcmp((mutils_word8 *) KEY2, tmp);
 
 	mutils_free(password);
@@ -133,6 +170,7 @@
 	if (mutils_strcmp((mutils_word8 *) KEY2, tmp) != 0) {
 		fprintf(stderr, "KEYGEN-Test (KEYGEN_S2K_SALTED): Failed\n");
 		fprintf(stderr, "Expecting: 0x%s\nGot: 0x%s\n", KEY2, tmp);
+		mutils_free(tmp);
 		return(MUTILS_INVALID_RESULT);
 	}
 
