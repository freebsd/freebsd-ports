CVE-2014-0210
CVE-2014-0211

--- src/fc/fserve.c.orig	2014-01-07 17:25:08.000000000 +0100
+++ src/fc/fserve.c	2014-05-13 18:12:13.000000000 +0200
@@ -70,6 +70,7 @@ in this Software without prior written a
 #include	"fservestr.h"
 #include	<X11/fonts/fontutil.h>
 #include	<errno.h>
+#include	<limits.h>
 
 #include	<time.h>
 #define Time_t time_t
@@ -91,6 +92,15 @@ in this Software without prior written a
 			     (pci)->descent || \
 			     (pci)->characterWidth)
 
+/*
+ * SIZEOF(r) is in bytes, length fields in the protocol are in 32-bit words,
+ * so this converts for doing size comparisons.
+ */
+#define LENGTHOF(r)	(SIZEOF(r) >> 2)
+
+/* Somewhat arbitrary limit on maximum reply size we'll try to read. */
+#define MAX_REPLY_LENGTH	((64 * 1024 * 1024) >> 2)
+
 extern void ErrorF(const char *f, ...);
 
 static int fs_read_glyphs ( FontPathElementPtr fpe, FSBlockDataPtr blockrec );
@@ -206,9 +216,22 @@ _fs_add_rep_log (FSFpePtr conn, fsGeneri
 		 rep->sequenceNumber,
 		 conn->reqbuffer[i].opcode);
 }
+
+#define _fs_reply_failed(rep, name, op) do {                            \
+    if (rep) {                                                          \
+        if (rep->type == FS_Error)                                      \
+            fprintf (stderr, "Error: %d Request: %s\n",                 \
+                     ((fsError *)rep)->request, #name);                 \
+        else                                                            \
+            fprintf (stderr, "Bad Length for %s Reply: %d %s %d\n",     \
+                     #name, rep->length, op, LENGTHOF(name));           \
+    }                                                                   \
+} while (0)
+
 #else
 #define _fs_add_req_log(conn,op)    ((conn)->current_seq++)
 #define _fs_add_rep_log(conn,rep)
+#define _fs_reply_failed(rep,name,op)
 #endif
 
 static Bool
@@ -600,6 +623,21 @@ fs_get_reply (FSFpePtr conn, int *error)
 
     rep = (fsGenericReply *) buf;
 
+    /*
+     * Refuse to accept replies longer than a maximum reasonable length,
+     * before we pass to _fs_start_read, since it will try to resize the
+     * incoming connection buffer to this size.  Also avoids integer overflow
+     * on 32-bit systems.
+     */
+    if (rep->length > MAX_REPLY_LENGTH)
+    {
+	ErrorF("fserve: reply length %d > MAX_REPLY_LENGTH, disconnecting"
+	       " from font server\n", rep->length);
+	_fs_connection_died (conn);
+	*error = FSIO_ERROR;
+	return 0;
+    }
+
     ret = _fs_start_read (conn, rep->length << 2, &buf);
     if (ret != FSIO_READY)
     {
@@ -682,13 +720,15 @@ fs_read_open_font(FontPathElementPtr fpe
     int			    ret;
 
     rep = (fsOpenBitmapFontReply *) fs_get_reply (conn, &ret);
-    if (!rep || rep->type == FS_Error)
+    if (!rep || rep->type == FS_Error ||
+	(rep->length != LENGTHOF(fsOpenBitmapFontReply)))
     {
 	if (ret == FSIO_BLOCK)
 	    return StillWorking;
 	if (rep)
 	    _fs_done_read (conn, rep->length << 2);
 	fs_cleanup_bfont (bfont);
+	_fs_reply_failed (rep, fsOpenBitmapFontReply, "!=");
 	return BadFontName;
     }
 
@@ -815,6 +855,7 @@ fs_read_query_info(FontPathElementPtr fp
     FSFpePtr		conn = (FSFpePtr) fpe->private;
     fsQueryXInfoReply	*rep;
     char		*buf;
+    long		bufleft; /* length of reply left to use */
     fsPropInfo		*pi;
     fsPropOffset	*po;
     pointer		pd;
@@ -824,13 +865,15 @@ fs_read_query_info(FontPathElementPtr fp
     int			ret;
 
     rep = (fsQueryXInfoReply *) fs_get_reply (conn, &ret);
-    if (!rep || rep->type == FS_Error)
+    if (!rep || rep->type == FS_Error ||
+	(rep->length < LENGTHOF(fsQueryXInfoReply)))
     {
 	if (ret == FSIO_BLOCK)
 	    return StillWorking;
 	if (rep)
 	    _fs_done_read (conn, rep->length << 2);
 	fs_cleanup_bfont (bfont);
+	_fs_reply_failed (rep, fsQueryXInfoReply, "<");
 	return BadFontName;
     }
 
@@ -844,6 +887,9 @@ fs_read_query_info(FontPathElementPtr fp
     buf = (char *) rep;
     buf += SIZEOF(fsQueryXInfoReply);
 
+    bufleft = rep->length << 2;
+    bufleft -= SIZEOF(fsQueryXInfoReply);
+
     /* move the data over */
     fsUnpack_XFontInfoHeader(rep, pInfo);
 
@@ -851,17 +897,50 @@ fs_read_query_info(FontPathElementPtr fp
     _fs_init_fontinfo(conn, pInfo);
 
     /* Compute offsets into the reply */
+    if (bufleft < SIZEOF(fsPropInfo))
+    {
+	ret = -1;
+#ifdef DEBUG
+	fprintf(stderr, "fsQueryXInfo: bufleft (%ld) < SIZEOF(fsPropInfo)\n",
+		bufleft);
+#endif
+	goto bail;
+    }
     pi = (fsPropInfo *) buf;
     buf += SIZEOF (fsPropInfo);
+    bufleft -= SIZEOF(fsPropInfo);
 
+    if ((bufleft / SIZEOF(fsPropOffset)) < pi->num_offsets)
+    {
+	ret = -1;
+#ifdef DEBUG
+	fprintf(stderr,
+		"fsQueryXInfo: bufleft (%ld) / SIZEOF(fsPropOffset) < %d\n",
+		bufleft, pi->num_offsets);
+#endif
+	goto bail;
+    }
     po = (fsPropOffset *) buf;
     buf += pi->num_offsets * SIZEOF(fsPropOffset);
+    bufleft -= pi->num_offsets * SIZEOF(fsPropOffset);
 
+    if (bufleft < pi->data_len)
+    {
+	ret = -1;
+#ifdef DEBUG
+	fprintf(stderr,
+		"fsQueryXInfo: bufleft (%ld) < data_len (%d)\n",
+		bufleft, pi->data_len);
+#endif
+	goto bail;
+    }
     pd = (pointer) buf;
     buf += pi->data_len;
+    bufleft -= pi->data_len;
 
     /* convert the properties and step over the reply */
     ret = _fs_convert_props(pi, po, pd, pInfo);
+  bail:
     _fs_done_read (conn, rep->length << 2);
 
     if (ret == -1)
@@ -951,13 +1030,15 @@ fs_read_extent_info(FontPathElementPtr f
     FontInfoRec		    *fi = &bfont->pfont->info;
 
     rep = (fsQueryXExtents16Reply *) fs_get_reply (conn, &ret);
-    if (!rep || rep->type == FS_Error)
+    if (!rep || rep->type == FS_Error ||
+	(rep->length < LENGTHOF(fsQueryXExtents16Reply)))
     {
 	if (ret == FSIO_BLOCK)
 	    return StillWorking;
 	if (rep)
 	    _fs_done_read (conn, rep->length << 2);
 	fs_cleanup_bfont (bfont);
+	_fs_reply_failed (rep, fsQueryXExtents16Reply, "<");
 	return BadFontName;
     }
 
@@ -970,7 +1051,26 @@ fs_read_extent_info(FontPathElementPtr f
 	numInfos *= 2;
 	haveInk = TRUE;
     }
-    ci = pCI = malloc(sizeof(CharInfoRec) * numInfos);
+    if (numInfos >= (INT_MAX / sizeof(CharInfoRec))) {
+#ifdef DEBUG
+	fprintf(stderr,
+		"fsQueryXExtents16: numInfos (%d) >= %ld\n",
+		numInfos, (INT_MAX / sizeof(CharInfoRec)));
+#endif
+	pCI = NULL;
+    }
+    else if (numExtents > ((rep->length - LENGTHOF(fsQueryXExtents16Reply))
+			    / LENGTHOF(fsXCharInfo))) {
+#ifdef DEBUG
+	fprintf(stderr,
+		"fsQueryXExtents16: numExtents (%d) > (%d - %d) / %d\n",
+		numExtents, rep->length,
+		LENGTHOF(fsQueryXExtents16Reply), LENGTHOF(fsXCharInfo));
+#endif
+	pCI = NULL;
+    }
+    else
+	pCI = malloc(sizeof(CharInfoRec) * numInfos);
 
     if (!pCI)
     {
@@ -1111,7 +1211,7 @@ fs_read_extent_info(FontPathElementPtr f
 }
 
 #ifdef DEBUG
-static char *fs_open_states[] = {
+static const char *fs_open_states[] = {
     "OPEN_REPLY  ",
     "INFO_REPLY  ",
     "EXTENT_REPLY",
@@ -1381,7 +1481,6 @@ fs_wakeup(FontPathElementPtr fpe, unsign
     {
 	FSBlockDataPtr	    blockrec;
 	FSBlockedFontPtr    bfont;
-	FSBlockedListPtr    blist;
 	static CARD32	    lastState;
 	static FSBlockDataPtr	lastBlock;
 
@@ -1405,7 +1504,6 @@ fs_wakeup(FontPathElementPtr fpe, unsign
 			 "<freed>");
 		break;
 	    case FS_LIST_FONTS:
-		blist = (FSBlockedListPtr) blockrec->data;
 		fprintf (stderr, "  Blocked list errcode %d sequence %d\n",
 			 blockrec->errcode, blockrec->sequenceNumber);
 		break;
@@ -1809,6 +1907,7 @@ fs_read_glyphs(FontPathElementPtr fpe, F
     FontInfoPtr		    pfi = &pfont->info;
     fsQueryXBitmaps16Reply  *rep;
     char		    *buf;
+    long		    bufleft; /* length of reply left to use */
     fsOffset32		    *ppbits;
     fsOffset32		    local_off;
     char		    *off_adr;
@@ -1825,22 +1924,48 @@ fs_read_glyphs(FontPathElementPtr fpe, F
     unsigned long	    minchar, maxchar;
 
     rep = (fsQueryXBitmaps16Reply *) fs_get_reply (conn, &ret);
-    if (!rep || rep->type == FS_Error)
+    if (!rep || rep->type == FS_Error ||
+	(rep->length < LENGTHOF(fsQueryXBitmaps16Reply)))
     {
 	if (ret == FSIO_BLOCK)
 	    return StillWorking;
 	if (rep)
 	    _fs_done_read (conn, rep->length << 2);
 	err = AllocError;
+	_fs_reply_failed (rep, fsQueryXBitmaps16Reply, "<");
 	goto bail;
     }
 
     buf = (char *) rep;
     buf += SIZEOF (fsQueryXBitmaps16Reply);
 
+    bufleft = rep->length << 2;
+    bufleft -= SIZEOF (fsQueryXBitmaps16Reply);
+
+    if ((bufleft / SIZEOF (fsOffset32)) < rep->num_chars)
+    {
+#ifdef DEBUG
+	fprintf(stderr,
+		"fsQueryXBitmaps16: num_chars (%d) > bufleft (%ld) / %d\n",
+		rep->num_chars, bufleft, SIZEOF (fsOffset32));
+#endif
+	err = AllocError;
+	goto bail;
+    }
     ppbits = (fsOffset32 *) buf;
     buf += SIZEOF (fsOffset32) * (rep->num_chars);
+    bufleft -= SIZEOF (fsOffset32) * (rep->num_chars);
 
+    if (bufleft < rep->nbytes)
+    {
+#ifdef DEBUG
+	fprintf(stderr,
+		"fsQueryXBitmaps16: nbytes (%d) > bufleft (%ld)\n",
+		rep->nbytes, bufleft);
+#endif
+	err = AllocError;
+	goto bail;
+    }
     pbitmaps = (pointer ) buf;
 
     if (blockrec->type == FS_LOAD_GLYPHS)
@@ -1898,7 +2023,9 @@ fs_read_glyphs(FontPathElementPtr fpe, F
 	     */
 	    if (NONZEROMETRICS(&fsdata->encoding[minchar].metrics))
 	    {
-		if (local_off.length)
+		if (local_off.length &&
+		    (local_off.position < rep->nbytes) &&
+		    (local_off.length <= (rep->nbytes - local_off.position)))
 		{
 		    bits = allbits;
 		    allbits += local_off.length;
@@ -2228,31 +2355,48 @@ fs_read_list(FontPathElementPtr fpe, FSB
     FSBlockedListPtr	blist = (FSBlockedListPtr) blockrec->data;
     fsListFontsReply	*rep;
     char		*data;
+    long		dataleft; /* length of reply left to use */
     int			length,
 			i,
 			ret;
     int			err;
 
     rep = (fsListFontsReply *) fs_get_reply (conn, &ret);
-    if (!rep || rep->type == FS_Error)
+    if (!rep || rep->type == FS_Error ||
+	(rep->length < LENGTHOF(fsListFontsReply)))
     {
 	if (ret == FSIO_BLOCK)
 	    return StillWorking;
 	if (rep)
 	    _fs_done_read (conn, rep->length << 2);
+	_fs_reply_failed (rep, fsListFontsReply, "<");
 	return AllocError;
     }
     data = (char *) rep + SIZEOF (fsListFontsReply);
+    dataleft = (rep->length << 2) - SIZEOF (fsListFontsReply);
 
     err = Successful;
     /* copy data into FontPathRecord */
     for (i = 0; i < rep->nFonts; i++)
     {
+	if (dataleft < 1)
+	    break;
 	length = *(unsigned char *)data++;
+	dataleft--; /* used length byte */
+	if (length > dataleft) {
+#ifdef DEBUG
+	    fprintf(stderr,
+		    "fsListFonts: name length (%d) > dataleft (%ld)\n",
+		    length, dataleft);
+#endif
+	    err = BadFontName;
+	    break;
+	}
 	err = AddFontNamesName(blist->names, data, length);
 	if (err != Successful)
 	    break;
 	data += length;
+	dataleft -= length;
     }
     _fs_done_read (conn, rep->length << 2);
     return err;
@@ -2347,6 +2491,7 @@ fs_read_list_info(FontPathElementPtr fpe
     FSBlockedListInfoPtr	binfo = (FSBlockedListInfoPtr) blockrec->data;
     fsListFontsWithXInfoReply	*rep;
     char			*buf;
+    long			bufleft;
     FSFpePtr			conn = (FSFpePtr) fpe->private;
     fsPropInfo			*pi;
     fsPropOffset		*po;
@@ -2358,12 +2503,15 @@ fs_read_list_info(FontPathElementPtr fpe
     _fs_free_props (&binfo->info);
 
     rep = (fsListFontsWithXInfoReply *) fs_get_reply (conn, &ret);
-    if (!rep || rep->type == FS_Error)
+    if (!rep || rep->type == FS_Error ||
+	((rep->nameLength != 0) &&
+	 (rep->length < LENGTHOF(fsListFontsWithXInfoReply))))
     {
 	if (ret == FSIO_BLOCK)
 	    return StillWorking;
 	binfo->status = FS_LFWI_FINISHED;
 	err = AllocError;
+	_fs_reply_failed (rep, fsListFontsWithXInfoReply, "<");
 	goto done;
     }
     /*
@@ -2380,6 +2528,7 @@ fs_read_list_info(FontPathElementPtr fpe
     }
 
     buf = (char *) rep + SIZEOF (fsListFontsWithXInfoReply);
+    bufleft = (rep->length << 2) - SIZEOF (fsListFontsWithXInfoReply);
 
     /*
      * The original FS implementation didn't match
@@ -2388,19 +2537,71 @@ fs_read_list_info(FontPathElementPtr fpe
      */
     if (conn->fsMajorVersion <= 1)
     {
+	if (rep->nameLength > bufleft) {
+#ifdef DEBUG
+	    fprintf(stderr,
+		    "fsListFontsWithXInfo: name length (%d) > bufleft (%ld)\n",
+		    (int) rep->nameLength, bufleft);
+#endif
+	    err = AllocError;
+	    goto done;
+	}
+	/* binfo->name is a 256 char array, rep->nameLength is a CARD8 */
 	memcpy (binfo->name, buf, rep->nameLength);
 	buf += _fs_pad_length (rep->nameLength);
+	bufleft -= _fs_pad_length (rep->nameLength);
     }
     pi = (fsPropInfo *) buf;
+    if (SIZEOF (fsPropInfo) > bufleft) {
+#ifdef DEBUG
+	fprintf(stderr,
+		"fsListFontsWithXInfo: PropInfo length (%d) > bufleft (%ld)\n",
+		(int) SIZEOF (fsPropInfo), bufleft);
+#endif
+	err = AllocError;
+	goto done;
+    }
+    bufleft -= SIZEOF (fsPropInfo);
     buf += SIZEOF (fsPropInfo);
     po = (fsPropOffset *) buf;
+    if (pi->num_offsets > (bufleft / SIZEOF (fsPropOffset))) {
+#ifdef DEBUG
+	fprintf(stderr,
+		"fsListFontsWithXInfo: offset length (%d * %d) > bufleft (%ld)\n",
+		pi->num_offsets, (int) SIZEOF (fsPropOffset), bufleft);
+#endif
+	err = AllocError;
+	goto done;
+    }
+    bufleft -= pi->num_offsets * SIZEOF (fsPropOffset);
     buf += pi->num_offsets * SIZEOF (fsPropOffset);
     pd = (pointer) buf;
+    if (pi->data_len > bufleft) {
+#ifdef DEBUG
+	fprintf(stderr,
+		"fsListFontsWithXInfo: data length (%d) > bufleft (%ld)\n",
+		pi->data_len, bufleft);
+#endif
+	err = AllocError;
+	goto done;
+    }
+    bufleft -= pi->data_len;
     buf += pi->data_len;
     if (conn->fsMajorVersion > 1)
     {
+	if (rep->nameLength > bufleft) {
+#ifdef DEBUG
+	    fprintf(stderr,
+		    "fsListFontsWithXInfo: name length (%d) > bufleft (%ld)\n",
+		    (int) rep->nameLength, bufleft);
+#endif
+	    err = AllocError;
+	    goto done;
+	}
+	/* binfo->name is a 256 char array, rep->nameLength is a CARD8 */
 	memcpy (binfo->name, buf, rep->nameLength);
 	buf += _fs_pad_length (rep->nameLength);
+	bufleft -= _fs_pad_length (rep->nameLength);
     }
 
 #ifdef DEBUG
@@ -2786,7 +2987,7 @@ _fs_recv_conn_setup (FSFpePtr conn)
     int			ret = FSIO_ERROR;
     fsConnSetup		*setup;
     FSFpeAltPtr		alts;
-    int			i, alt_len;
+    unsigned int	i, alt_len;
     int			setup_len;
     char		*alt_save, *alt_names;
 
@@ -2813,8 +3014,9 @@ _fs_recv_conn_setup (FSFpePtr conn)
 	}
 	if (setup->num_alternates)
 	{
+	    size_t alt_name_len = setup->alternate_len << 2;
 	    alts = malloc (setup->num_alternates * sizeof (FSFpeAltRec) +
-			   (setup->alternate_len << 2));
+			   alt_name_len);
 	    if (alts)
 	    {
 		alt_names = (char *) (setup + 1);
@@ -2823,10 +3025,25 @@ _fs_recv_conn_setup (FSFpePtr conn)
 		{
 		    alts[i].subset = alt_names[0];
 		    alt_len = alt_names[1];
+		    if (alt_len >= alt_name_len) {
+			/*
+			 * Length is longer than setup->alternate_len
+			 * told us to allocate room for, assume entire
+			 * alternate list is corrupted.
+			 */
+#ifdef DEBUG
+			fprintf (stderr,
+				 "invalid alt list (length %lx >= %lx)\n",
+				 (long) alt_len, (long) alt_name_len);
+#endif
+			free(alts);
+			return FSIO_ERROR;
+		    }
 		    alts[i].name = alt_save;
 		    memcpy (alt_save, alt_names + 2, alt_len);
 		    alt_save[alt_len] = '\0';
 		    alt_save += alt_len + 1;
+		    alt_name_len -= alt_len + 1;
 		    alt_names += _fs_pad_length (alt_len + 2);
 		}
 		conn->numAlts = setup->num_alternates;
@@ -2964,6 +3181,7 @@ _fs_send_cat_sync (FSFpePtr conn)
      * by a bogus catalogue
      */
     lcreq.reqType = FS_ListCatalogues;
+    lcreq.data = 0;
     lcreq.length = (SIZEOF(fsListCataloguesReq)) >> 2;
     lcreq.maxNames = 0;
     lcreq.nbytes = 0;
