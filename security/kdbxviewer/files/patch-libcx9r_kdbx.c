--- libcx9r/kdbx.c.orig	2022-09-06 17:07:27 UTC
+++ libcx9r/kdbx.c
@@ -112,22 +112,25 @@ static cx9r_err kdbx_read_magic(cx9r_stream_t *stream)
 	uint8_t const kdbx_magic[KDBX_MAGIC_LENGTH] = { 0x03, 0xd9, 0xa2, 0x9a,
 			0x67, 0xfb, 0x4b, 0xb5 };
 DEBUG("Reading magic...\n");
-	uint8_t magic[KDBX_MAGIC_LENGTH];
+	union {
+		uint8_t magic[KDBX_MAGIC_LENGTH];
+		uint64_t joined;
+	} m;
 
 	// default return value
 	cx9r_err err = CX9R_OK;
 	// read magic bytes
-	CHECK((cx9r_sread(magic, 1, KDBX_MAGIC_LENGTH, stream) == KDBX_MAGIC_LENGTH),
+	CHECK((cx9r_sread(m.magic, 1, KDBX_MAGIC_LENGTH, stream) == KDBX_MAGIC_LENGTH),
 			err, CX9R_FILE_READ_ERR, kdbx_magic_bail);
 DEBUG("Proper magic length\n");
 
 	// compare magic bytes to expected
-	CHECK((memcmp(magic, kdbx_magic, KDBX_MAGIC_LENGTH) == 0), err,
+	CHECK((memcmp(m.magic, kdbx_magic, KDBX_MAGIC_LENGTH) == 0), err,
 			CX9R_BAD_MAGIC, kdbx_magic_bail);
 DEBUG("Proper magic content\n");
 
 	kdbx_magic_bail:
-DEBUG("%016lX  (%d)\n", *(uint64_t*)&magic, err);
+DEBUG("%016llX  (%d)\n", (unsigned long long)m.joined, err);
 	return err;
 }
 
