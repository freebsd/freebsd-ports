Description: Add some failure checks and fix a couple of memory leaks.
Author: Peter Pentchev <roam@FreeBSD.org>
Forwarded: http://sourceforge.net/mailarchive/message.php?msg_name=20090910102100.GA26539%40straylight.m.ringlet.net
Last-Update: 2009-09-10

--- src/hmac_test.c.orig
+++ src/hmac_test.c
@@ -45,10 +45,23 @@
 
 	passlen=sizeof(KEY1) - 1;
 	password = mutils_malloc(passlen + 1);
+	if (password == NULL)
+	{
+		fprintf(stderr, "HMAC-Test: Failed\n");
+		fprintf(stderr, "Cannot allocate memory.\n");
+		return(MUTILS_SYSTEM_RESOURCE_ERROR);
+	}
 	mutils_memcpy(password, (mutils_word8 *) KEY1, passlen);
 
 	datalen = mutils_strlen((mutils_word8 *) DATA1);
 	data = mutils_malloc(datalen+1);
+	if (data == NULL)
+	{
+		fprintf(stderr, "HMAC-Test: Failed\n");
+		fprintf(stderr, "Cannot allocate memory.\n");
+		mutils_free(password);
+		return(MUTILS_SYSTEM_RESOURCE_ERROR);
+	}
 	mutils_strcpy(data, (mutils_word8 *) DATA1);
 
 	td = mhash_hmac_init(MHASH_MD5, password, passlen,
@@ -58,6 +71,14 @@
 	mac = mhash_hmac_end(td);
 
 	tmp = mutils_asciify(mac, mhash_get_block_size(MHASH_MD5));
+	if (tmp == NULL)
+	{
+		fprintf(stderr, "HMAC-Test: Failed\n");
+		fprintf(stderr, "Cannot allocate memory.\n");
+		mutils_free(password);
+		mutils_free(data);
+		return(MUTILS_SYSTEM_RESOURCE_ERROR);
+	}
 	
 	result = mutils_strcmp((mutils_word8 *) DIGEST1, tmp);
 
@@ -69,6 +90,7 @@
 		fprintf(stderr, "Digest size: %d\n", mhash_get_block_size(MHASH_MD5));
 		fprintf(stderr, "Expecting: 0x%s\n", DIGEST1);
 		fprintf(stderr, "Got: 0x%s\n", tmp);
+		mutils_free(tmp);
 		return(MUTILS_INVALID_RESULT);
 	}
 
@@ -76,14 +98,25 @@
 
 	/* Test No 2 */	
 	
-	mutils_memset(tmp, 0, sizeof(tmp));
-	
 	passlen=sizeof(KEY2) - 1;
 	password = (mutils_word8 *) mutils_malloc(passlen+1);
+	if (password == NULL)
+	{
+		fprintf(stderr, "HMAC-Test: Failed\n");
+		fprintf(stderr, "Cannot allocate memory.\n");
+		return(MUTILS_SYSTEM_RESOURCE_ERROR);
+	}
 	mutils_memcpy(password, KEY2, passlen);
 	
 	datalen = mutils_strlen((mutils_word8 *) DATA2);
 	data = (mutils_word8 *) mutils_malloc(datalen+1);
+	if (data == NULL)
+	{
+		fprintf(stderr, "HMAC-Test: Failed\n");
+		fprintf(stderr, "Cannot allocate memory.\n");
+		mutils_free(password);
+		return(MUTILS_SYSTEM_RESOURCE_ERROR);
+	}
 	mutils_strcpy(data, (mutils_word8 *) DATA2);
 
 	td = mhash_hmac_init(MHASH_MD5, password, passlen,
@@ -93,6 +126,14 @@
 	mac = mhash_hmac_end(td);
 
 	tmp = mutils_asciify(mac, mhash_get_block_size(MHASH_MD5));
+	if (tmp == NULL)
+	{
+		fprintf(stderr, "HMAC-Test: Failed\n");
+		fprintf(stderr, "Cannot allocate memory.\n");
+		mutils_free(password);
+		mutils_free(data);
+		return(MUTILS_SYSTEM_RESOURCE_ERROR);
+	}
 	
 	result = mutils_strcmp((mutils_word8 *) DIGEST2, tmp);
 
@@ -103,6 +144,7 @@
 	{
 		fprintf(stderr, "HMAC-Test: Failed\n");
 		fprintf(stderr, "Expecting: 0x%s\nGot: 0x%s\n", DIGEST2, tmp);
+		mutils_free(tmp);
 		return(MUTILS_INVALID_RESULT);
 	}
 
