# CVE-2005-3183

--- Library/src/HTBound.c.orig	1999-02-22 22:10:10 UTC
+++ Library/src/HTBound.c
@@ -11,9 +11,12 @@
 **
 ** Authors
 **	HF	Henrik Frystyk <frystyk@w3.org>
+**      SV      Sam Varshavchik <mrsam@courier-mta.com>
 **
 ** History:
 **	Nov 95	Written from scratch
+**   SV Jun 05  Rewrote HTBoundary_put_block.  Fixed many bugs+segfaults.
+**   SV Jul 05  Fix double-counting of processed bytes.
 **
 */
 
@@ -23,104 +26,395 @@
 #include "WWWCore.h"
 #include "HTMerge.h"
 #include "HTReqMan.h"
+#include "HTNetMan.h"
+#include "HTChannl.h"
 #include "HTBound.h"					 /* Implemented here */
 
-#define PUTBLOCK(b, l)	(*me->target->isa->put_block)(me->target, b, l)
+#define PUTBLOCK(b, l)	(me->target ? (*me->target->isa->put_block)(me->target, b, l):HT_OK)
+
 #define PUTDEBUG(b, l)	(*me->debug->isa->put_block)(me->debug, b, l)
 #define FREE_TARGET	(*me->target->isa->_free)(me->target)
 
 struct _HTStream {
     const HTStreamClass *	isa;
+    HTNet *                      net;
     HTStream *			target;
     HTStream *			orig_target;
     HTFormat			format;
     HTStream *			debug;		  /* For preamble and epilog */
     HTRequest *			request;
-    BOOL			body;		  /* Body or preamble|epilog */
-    HTEOLState			state;
-    int				dash;			 /* Number of dashes */
     char *			boundary;
-    char *			bpos;
+
+    BOOL                        keptcrlf;
+    int                         (*state)(HTStream *, const char *, int);
+
+    char                        *boundary_ptr;
+
 };
 
+PRIVATE int HTBoundary_flush (HTStream * me);
+
 /* ------------------------------------------------------------------------- */
 
+PRIVATE int start_of_line (HTStream * me, const char * b, int l);
+PRIVATE int seen_dash (HTStream * me, const char * b, int l);
+PRIVATE int seen_doubledash (HTStream * me, const char * b, int l);
+PRIVATE int seen_delimiter_nonterminal(HTStream * me, const char * b, int l);
+PRIVATE int seen_delimiter_nonterminal_CR(HTStream * me, const char * b, int l);
+PRIVATE int seen_delimiter_dash(HTStream * me, const char * b, int l);
+PRIVATE int seen_delimiter_terminal(HTStream * me, const char * b, int l);
+PRIVATE int seen_delimiter_terminal_CR(HTStream * me, const char * b, int l);
+PRIVATE int not_delimiter(HTStream * me, const char * b, int l, int extra);
+PRIVATE int seen_nothing(HTStream * me, const char * b, int l);
+PRIVATE int seen_cr(HTStream * me, const char * b, int l);
+PRIVATE void process_boundary(HTStream *me, int isterminal);
+
+#define UNUSED(l) (l=l)    /* Shut up about unused variables */
+
 PRIVATE int HTBoundary_put_block (HTStream * me, const char * b, int l)
 {
-    const char *start = b;
-    const char *end = b;
-    while (l-- > 0) {
-	if (me->state == EOL_FCR) {
-	    me->state = (*b == LF) ? EOL_FLF : EOL_BEGIN;
-	} else if (me->state == EOL_FLF) {
-	    if (me->dash == 2) {
-		while (l>0 && *me->bpos && *me->bpos==*b) l--, me->bpos++, b++;
-		if (!*me->bpos) {
-		    HTTRACE(STREAM_TRACE, "Boundary.... `%s\' found\n" _ me->boundary);
-		    me->bpos = me->boundary;
-		    me->body = YES;
-		    me->state = EOL_DOT;
-		} else if (l>0) {
-		    me->dash = 0;
-		    me->bpos = me->boundary;
-		    me->state = EOL_BEGIN;
-		}
-	    }
-	    if (*b == '-') {
-		me->dash++;
-	    } else if (*b != CR && *b != LF) {
-		me->dash = 0;
-		me->state = EOL_BEGIN;
-	    }
-	} else if (me->state == EOL_SLF) {	    /* Look for closing '--' */
-	    if (me->dash == 4) {
-		if (end > start) {
-		    int status = PUTBLOCK(start, end-start);
-		    if (status != HT_OK) return status;
+	/*
+	** The HTBoundary object gets attached downstream of HTMime.
+	** The HTBoundary object creates another HTMime object downstream of
+	** the HTBoundary object.
+	**
+	** When we push data downstream to the second HTBoundary object, it
+	** updates the bytes read count in the HTNet object.
+	**
+	** When we return to the parent HTMime object, itupdates the
+	** bytes read count in the HTNet object again.  Oops.
+	**
+	** Same thing happens with the consumed byte count.  We can prevent
+	** the consumed byte counts from being updated by temporary setting
+	** the input channel stream pointer to NULL, but for the byte counts
+	** we have to save them and restore them before existing.
+	**
+	** This bug was discovered by chance when a multipart/partial response
+	** was partially received, and as a result of double-counting the
+	** real response got cut off (because HTMime thought that more bytes
+	** were processed than actually were, thus it processed only the
+	** partial count of the remaining bytes in the response).  When the
+	** multipart/partial response was received all at once this bug did
+	** not get triggered.
+	*/
+
+	HTHost *host=HTNet_host(me->net);
+	HTChannel *c=HTHost_channel(host);
+	HTInputStream *i=HTChannel_input(c);
+
+	long saveBytesRead=HTNet_bytesRead(me->net);
+	long saveHeaderBytesRead=HTNet_headerBytesRead(me->net);
+
+	if (i)
+		HTChannel_setInput(c, NULL);
+
+	HTTRACE(STREAM_TRACE, "Boundary: processing %d bytes\n" _ l);
+	/* Main loop consumes all input */
+
+	while (l)
+	{
+		int n= (*me->state)(me, b, l);
+
+		if (n == 0)
+			return HT_ERROR;
+		b += n;
+		l -= n;
+	}
+
+	if (i)
+		HTChannel_setInput(c, i);
+	HTNet_setBytesRead(me->net, saveBytesRead);
+	HTNet_setHeaderBytesRead(me->net, saveHeaderBytesRead);
+
+	return HT_OK;
+}
+
+/*
+** Start of line, keptcrlf=YES if we've kept the preceding CRLF from downstream
+** and we'll pass it along if we decide that this is not a boundary delimiter.
+*/
+
+PRIVATE int start_of_line (HTStream * me, const char * b, int l)
+{
+	if (*b != '-')
+		return not_delimiter(me, b, l, 0);
+
+	HTTRACE(STREAM_TRACE, "Boundary: start of line: input '-'\n");
+
+	me->state= seen_dash;
+
+	return 1;
+}
+
+/*
+** Line: -
+*/
+
+PRIVATE int seen_dash (HTStream * me, const char * b, int l)
+{
+	if (*b != '-')
+		return not_delimiter(me, b, l, 1);
+
+	HTTRACE(STREAM_TRACE, "Boundary: start of line: input '--'\n");
+
+	me->state= seen_doubledash;
+	me->boundary_ptr=me->boundary;
+	return 1;
+}
+
+/*
+** Line: --
+*/
+
+PRIVATE int seen_doubledash (HTStream * me, const char * b, int l)
+{
+	me->state=seen_doubledash;
+
+	if (*me->boundary_ptr)
+	{
+		if (*b != *me->boundary_ptr)
+		{
+			return not_delimiter(me, b, l,
+					     me->boundary_ptr - me->boundary
+					     + 2);
 		}
-		HTTRACE(STREAM_TRACE, "Boundary.... Ending\n");
-		start = b;
-		me->dash = 0;
-		me->state = EOL_BEGIN;
-	    }
-	    if (*b == '-') {
-		me->dash++;
-	    } else if (*b != CR && *b != LF) {
-		me->dash = 0;
-		me->state = EOL_BEGIN;
+		++me->boundary_ptr;
+		return 1;
 	    }
-	    me->body = NO;
-	} else if (me->state == EOL_DOT) {
-	    int status;
-	    if (me->body) {
-		if (me->target) FREE_TARGET;
+
+	/*
+	** Line: --delimiter
+	*/
+
+	if (*b == '-')
+	{
+		HTTRACE(STREAM_TRACE,
+			"Boundary: start of line: input '--%s-'\n"
+			_ me->boundary);
+
+		me->state=seen_delimiter_dash;
+		return 1;
+	}
+
+	HTTRACE(STREAM_TRACE,
+		"Boundary: Found: '--%s'\n" _ me->boundary);
+	
+	return seen_delimiter_nonterminal(me, b, l);
+}
+
+/*
+** Line: --delimiter
+**
+** Waiting for CRLF.
+*/
+
+
+PRIVATE int seen_delimiter_nonterminal(HTStream * me, const char * b, int l)
+{
+	UNUSED(l);
+
+	me->state=seen_delimiter_nonterminal;
+	if (*b == CR)
+		me->state=seen_delimiter_nonterminal_CR;
+
+	return 1;
+}
+
+/*
+** Line: --delimiter<CR>
+*/
+
+PRIVATE int seen_delimiter_nonterminal_CR(HTStream * me, const char * b, int l)
+{
+	HTTRACE(STREAM_TRACE,
+		"Boundary: Found: '--%s<CR>'\n" _ me->boundary);
+	
+	if (*b != LF)
+		return seen_delimiter_nonterminal(me, b, l);
+
+	HTTRACE(STREAM_TRACE,
+		"Boundary: Found: '--%s<CR><LF>'\n" _ me->boundary);
+	
+	process_boundary(me, NO);
+	return 1;
+}
+
+/*
+** Line: --delimiter-
+*/
+
+PRIVATE int seen_delimiter_dash(HTStream * me, const char * b, int l)
+{
+	if (*b != '-')
+		return seen_delimiter_nonterminal(me, b, l);
+
+	HTTRACE(STREAM_TRACE,
+		"Boundary: start of line: input '--%s--'\n"
+		_ me->boundary);
+	
+	me->state=seen_delimiter_terminal;
+	return 1;
+}
+
+/*
+** Line: --delimiter--
+*/
+
+PRIVATE int seen_delimiter_terminal(HTStream * me, const char * b, int l)
+{
+	UNUSED(l);
+
+	me->state=seen_delimiter_terminal;
+
+	if (*b == CR)
+		me->state=seen_delimiter_terminal_CR;
+	return 1;
+}
+/*
+** Line: --delimiter--<CR>
+*/
+
+PRIVATE int seen_delimiter_terminal_CR(HTStream * me, const char * b, int l)
+{
+	HTTRACE(STREAM_TRACE,
+		"Boundary: Found '--%s--<CR>'\n"
+		_ me->boundary);
+	
+	if (*b != LF)
+		return seen_delimiter_terminal(me, b, l);
+	HTTRACE(STREAM_TRACE,
+		"Boundary: Found '--%s--<CR><LF>'\n"
+		_ me->boundary);
+	
+	process_boundary(me, YES);
+	return 1;
+}
+
+/*
+** Beginning of the line does not contain a delimiter.
+**
+**
+** extra: Count of characters in a partially matched delimiter.  Since it's
+** not a delimiter this is content that needs to go downstream.
+*/
+
+PRIVATE int not_delimiter(HTStream * me, const char * b, int l, int extra)
+{
+	HTTRACE(STREAM_TRACE, "Boundary: not a delimiter line\n");
+	
+	if (me->keptcrlf)
+	{
+		HTTRACE(STREAM_TRACE, "Boundary: Sending previous line's <CR><LF>\n");
+		/*
+		** Did not process CRLF from previous line, because prev CRLF
+		** is considered a part of the delimiter.  See MIME RFC.
+		*/
+
+		me->keptcrlf=NO;
+		if (PUTBLOCK("\r\n", 2) != HT_OK)
+			return 0;
+	}
+
+	/*
+	** Potentially matched some of: --DELIMITER
+	*/
+
+	if (extra)
+	{
+		HTTRACE(STREAM_TRACE, "Boundary: Sending partially-matched %d characters\n" _ extra);
+
+		if (PUTBLOCK("--", extra > 2 ? 2:extra) != HT_OK)
+			return 0;
+
+		if (extra > 2)
+			if (PUTBLOCK(me->boundary, extra-2) != HT_OK)
+				return 0;
+	}
+	return seen_nothing(me, b, l);
+}
+
+/*
+** We're not looking for a delimiter.  Look for the next line of input
+** in the data that could potentially be a delimiter.
+*/
+
+PRIVATE int seen_nothing(HTStream * me, const char * b, int l)
+{
+	int i;
+
+	me->state=seen_nothing;
+
+	for (i=0; i<l; i++)
+	{
+		if (b[i] != CR)
+			continue;
+
+		/*
+		** If we have at least four more characters in unconsumed
+		** input, and they're not \r\n--, we can safely skip over
+		** them.
+		*/
+
+		if (l-i > 4 &&
+		    strncmp(b+i, "\r\n--", 4))
+			continue;
+		break;
+	}
+
+	if (i == 0)
+	{
+		/* Could only be a CR here. */
+
+		me->state=seen_cr;
+		return 1;
+	}
+
+	HTTRACE(STREAM_TRACE, "Boundary: Processed %d (out of %d) bytes\n"
+		_ i _ l);
+
+	if (PUTBLOCK(b, i) != HT_OK)
+		return 0;
+
+	return i;
+}
+
+/*
+** State: seen a CR
+*/
+
+PRIVATE int seen_cr(HTStream * me, const char * b, int l)
+{
+	HTTRACE(STREAM_TRACE, "Boundary: Processed <CR>\n");
+
+	if (*b != LF)
+	{
+		HTTRACE(STREAM_TRACE, "Boundary: ... <LF> didn't follow\n");
+		if (PUTBLOCK("\r", 1) != HT_OK)
+			return 0;
+		return seen_nothing(me, b, l);
+    }
+
+	HTTRACE(STREAM_TRACE, "Boundary: Processed <CR><LF>\n");
+	me->state=start_of_line;
+	me->keptcrlf=YES;
+	return 1;
+}
+
+PRIVATE void process_boundary(HTStream *me, int isterminal)
+{
+	HTBoundary_flush(me);
+	if (me->target) FREE_TARGET;
+	me->target=NULL;
+	me->state=start_of_line;
+	me->keptcrlf=NO;
+
+	if (!isterminal)
 		me->target = HTStreamStack(WWW_MIME,me->format,
 					   HTMerge(me->orig_target, 2),
 					   me->request, YES);
-		if (end > start) {
-		    if ((status = PUTBLOCK(start, end-start)) != HT_OK)
-			return status;
-		}
-	    } else {
-		if (me->debug)
-		    if ((status = PUTDEBUG(start, end-start)) != HT_OK)
-			return status;
-	    }
-	    start = b;
-	    if (*b == '-') me->dash++;
-	    me->state = EOL_SLF;
-	} else if (*b == CR) {
-	    me->state = EOL_FCR;
-	    end = b;
-	} else if (*b == LF) {
-	    if (me->state != EOL_FCR) end = b;
-	    me->state = EOL_FLF;
-	}
-	b++;
-    }
-    return (start<b && me->body) ? PUTBLOCK(start, b-start) : HT_OK;
 }
 
+
 PRIVATE int HTBoundary_put_string (HTStream * me, const char * s)
 {
     return HTBoundary_put_block(me, s, (int) strlen(s));
@@ -133,6 +427,8 @@ PRIVATE int HTBoundary_put_character (HT
 
 PRIVATE int HTBoundary_flush (HTStream * me)
 {
+	if (me->target == NULL)
+		return HT_OK;
     return (*me->target->isa->flush)(me->target);
 }
 
@@ -182,18 +478,26 @@ PUBLIC HTStream * HTBoundary   (HTReques
 	HTResponse_formatParam(response) :
 	HTAnchor_formatParam(anchor);
     char * boundary = HTAssocList_findObject(type_param, "boundary");
+
+    UNUSED(param);
+    UNUSED(input_format);
+
     if (boundary) {
 	HTStream * me;
 	if ((me = (HTStream  *) HT_CALLOC(1, sizeof(HTStream))) == NULL)
 	    HT_OUTOFMEM("HTBoundary");
 	me->isa = &HTBoundaryClass;
+	me->net = HTRequest_net(request);
 	me->request = request;
 	me->format = output_format;
 	me->orig_target = output_stream;
 	me->debug = HTRequest_debugStream(request);
-	me->state = EOL_FLF;
+
+	me->state = start_of_line;
+	me->keptcrlf=NO;
+
 	StrAllocCopy(me->boundary, boundary);		       /* Local copy */
-	me->bpos = me->boundary;
+
 	HTTRACE(STREAM_TRACE, "Boundary.... Stream created with boundary '%s\'\n" _ me->boundary);
 	return me;
     } else {
