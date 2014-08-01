X-Git-Url: http://git.exim.org/exim.git/blobdiff_plain/1bd0d12bcbf4f51bd78c60d5bae01f1ff38c5a84..4fd5d2bf25195969b9c6a6c23a59c495400ece8d:/src/src/mime.c

diff --git a/src/src/mime.c b/src/src/mime.c
index 2233dac..95d3da4 100644
--- src/mime.c
+++ src/mime.c
@@ -6,7 +6,7 @@
 /* License: GPL */
 
 #include "exim.h"
-#ifdef WITH_CONTENT_SCAN
+#ifdef WITH_CONTENT_SCAN	/* entire file */
 #include "mime.h"
 #include <sys/stat.h>
 
@@ -21,7 +21,9 @@ uschar *mime_current_boundary = NULL;
    give info on detected "problems" in MIME
    encodings. Those are defined in mime.h. */
 
-void mime_set_anomaly(int level, const char *text) {
+void
+mime_set_anomaly(int level, const char *text)
+{
   mime_anomaly_level = level;
   mime_anomaly_text = CUS text;
 }
@@ -39,36 +41,37 @@ void mime_set_anomaly(int level, const char *text) {
            0-255 - char to write
 */
 
-uschar *mime_decode_qp_char(uschar *qp_p, int *c) {
-  uschar *initial_pos = qp_p;
+uschar *
+mime_decode_qp_char(uschar *qp_p, int *c)
+{
+uschar *initial_pos = qp_p;
+
+/* advance one char */
+qp_p++;
+
+/* Check for two hex digits and decode them */
+if (isxdigit(*qp_p) && isxdigit(qp_p[1]))
+  {
+  /* Do hex conversion */
+  *c = (isdigit(*qp_p) ? *qp_p - '0' : toupper(*qp_p) - 'A' + 10) <<4;
+  qp_p++;
+  *c |= isdigit(*qp_p) ? *qp_p - '0' : toupper(*qp_p) - 'A' + 10;
+  return qp_p + 1;
+  }
 
-  /* advance one char */
+/* tab or whitespace may follow just ignore it if it precedes \n */
+while (*qp_p == '\t' || *qp_p == ' ' || *qp_p == '\r')
   qp_p++;
 
-  /* Check for two hex digits and decode them */
-  if (isxdigit(*qp_p) && isxdigit(qp_p[1])) {
-    /* Do hex conversion */
-    if (isdigit(*qp_p)) {*c = *qp_p - '0';}
-    else {*c = toupper(*qp_p) - 'A' + 10;};
-    *c <<= 4;
-    if (isdigit(qp_p[1])) {*c |= qp_p[1] - '0';}
-    else {*c |= toupper(qp_p[1]) - 'A' + 10;};
-    return qp_p + 2;
-  };
-
-  /* tab or whitespace may follow just ignore it if it precedes \n */
-  while (*qp_p == '\t' || *qp_p == ' ' || *qp_p == '\r')
-    qp_p++;
-
-  if (*qp_p == '\n') {
-    /* hit soft line break */
-    *c = -1;
-    return qp_p;
-  };
-
-  /* illegal char here */
-  *c = -2;
-  return initial_pos;
+if (*qp_p == '\n')	/* hit soft line break */
+  {
+  *c = -1;
+  return qp_p;
+  }
+
+/* illegal char here */
+*c = -2;
+return initial_pos;
 }
 
 
@@ -79,18 +82,19 @@ mime_decode_asis(FILE* in, FILE* out, uschar* boundary)
   ssize_t len, size = 0;
   uschar buffer[MIME_MAX_LINE_LENGTH];
 
-  while(fgets(CS buffer, MIME_MAX_LINE_LENGTH, mime_stream) != NULL) {
+  while(fgets(CS buffer, MIME_MAX_LINE_LENGTH, mime_stream) != NULL)
+    {
     if (boundary != NULL
-      && Ustrncmp(buffer, "--", 2) == 0
-      && Ustrncmp((buffer+2), boundary, Ustrlen(boundary)) == 0
-    )
+       && Ustrncmp(buffer, "--", 2) == 0
+       && Ustrncmp((buffer+2), boundary, Ustrlen(boundary)) == 0
+       )
       break;
 
     len = Ustrlen(buffer);
     if (fwrite(buffer, 1, (size_t)len, out) < len)
       return -1;
     size += len;
-  } /* while */
+    } /* while */
   return size;
 }
 
@@ -107,26 +111,29 @@ mime_decode_base64(FILE* in, FILE* out, uschar* boundary)
   opos = obuf;
 
   while (Ufgets(ibuf, MIME_MAX_LINE_LENGTH, in) != NULL)
-  {
+    {
     if (boundary != NULL
-      && Ustrncmp(ibuf, "--", 2) == 0
-      && Ustrncmp((ibuf+2), boundary, Ustrlen(boundary)) == 0
-    )
+       && Ustrncmp(ibuf, "--", 2) == 0
+       && Ustrncmp((ibuf+2), boundary, Ustrlen(boundary)) == 0
+       )
       break;
 
-    for (ipos = ibuf ; *ipos != '\r' && *ipos != '\n' && *ipos != 0; ++ipos) {
-      /* skip padding */
-      if (*ipos == '=') {
+    for (ipos = ibuf ; *ipos != '\r' && *ipos != '\n' && *ipos != 0; ++ipos)
+      {
+      if (*ipos == '=')			/* skip padding */
+        {
         ++bytestate;
         continue;
-      }
-      /* skip bad characters */
-      if (mime_b64[*ipos] == 128) {
+	}
+      if (mime_b64[*ipos] == 128)	/* skip bad characters */
+        {
         mime_set_anomaly(MIME_ANOMALY_BROKEN_BASE64);
         continue;
-      }
+	}
+
       /* simple state-machine */
-      switch((bytestate++) & 3) {
+      switch((bytestate++) & 3)
+        {
         case 0:
           *opos = mime_b64[*ipos] << 2;
            break;
@@ -144,27 +151,28 @@ mime_decode_base64(FILE* in, FILE* out, uschar* boundary)
           *opos |= mime_b64[*ipos];
           ++opos;
           break;
-      } /* switch */
-    } /* for */
+	} /* switch */
+      } /* for */
+
     /* something to write? */
     len = opos - obuf;
-    if (len > 0) {
-      if (fwrite(obuf, 1, len, out) != len)
-        return -1; /* error */
+    if (len > 0)
+      {
+      if (fwrite(obuf, 1, len, out) != len) return -1; /* error */
       size += len;
       /* copy incomplete last byte to start of obuf, where we continue */
       if ((bytestate & 3) != 0)
         *obuf = *opos;
       opos = obuf;
-    }
-  } /* while */
+      }
+    } /* while */
 
   /* write out last byte if it was incomplete */
-  if (bytestate & 3) {
-      if (fwrite(obuf, 1, 1, out) != 1)
-          return -1;
-      ++size;
-  }
+  if (bytestate & 3)
+    {
+    if (fwrite(obuf, 1, 1, out) != 1) return -1;
+    ++size;
+    }
 
   return size;
 }
@@ -174,219 +182,232 @@ mime_decode_base64(FILE* in, FILE* out, uschar* boundary)
 static ssize_t
 mime_decode_qp(FILE* in, FILE* out, uschar* boundary)
 {
-  uschar ibuf[MIME_MAX_LINE_LENGTH], obuf[MIME_MAX_LINE_LENGTH];
-  uschar *ipos, *opos;
-  ssize_t len, size = 0;
+uschar ibuf[MIME_MAX_LINE_LENGTH], obuf[MIME_MAX_LINE_LENGTH];
+uschar *ipos, *opos;
+ssize_t len, size = 0;
 
-  while (fgets(CS ibuf, MIME_MAX_LINE_LENGTH, in) != NULL)
+while (fgets(CS ibuf, MIME_MAX_LINE_LENGTH, in) != NULL)
   {
-    if (boundary != NULL
-      && Ustrncmp(ibuf, "--", 2) == 0
-      && Ustrncmp((ibuf+2), boundary, Ustrlen(boundary)) == 0
-    )
-      break; /* todo: check for missing boundary */
+  if (boundary != NULL
+     && Ustrncmp(ibuf, "--", 2) == 0
+     && Ustrncmp((ibuf+2), boundary, Ustrlen(boundary)) == 0
+     )
+    break; /* todo: check for missing boundary */
 
-    ipos = ibuf;
-    opos = obuf;
-
-    while (*ipos != 0) {
-      if (*ipos == '=') {
-        int decode_qp_result;
-
-        ipos = mime_decode_qp_char(ipos, &decode_qp_result);
+  ipos = ibuf;
+  opos = obuf;
 
-        if (decode_qp_result == -2) {
-          /* Error from decoder. ipos is unchanged. */
-          mime_set_anomaly(MIME_ANOMALY_BROKEN_QP);
-          *opos = '=';
-          ++opos;
-          ++ipos;
-        }
-        else if (decode_qp_result == -1) {
-          break;
-        }
-        else if (decode_qp_result >= 0) {
-          *opos = decode_qp_result;
-          ++opos;
-        }
+  while (*ipos != 0)
+    {
+    if (*ipos == '=')
+      {
+      int decode_qp_result;
+
+      ipos = mime_decode_qp_char(ipos, &decode_qp_result);
+
+      if (decode_qp_result == -2)
+	{
+	/* Error from decoder. ipos is unchanged. */
+	mime_set_anomaly(MIME_ANOMALY_BROKEN_QP);
+	*opos = '=';
+	++opos;
+	++ipos;
+	}
+      else if (decode_qp_result == -1)
+	break;
+      else if (decode_qp_result >= 0)
+	{
+	*opos = decode_qp_result;
+	++opos;
+	}
       }
-      else {
-        *opos = *ipos;
-        ++opos;
-        ++ipos;
+    else
+      {
+      *opos = *ipos;
+      ++opos;
+      ++ipos;
       }
     }
-    /* something to write? */
-    len = opos - obuf;
-    if (len > 0) {
-      if (fwrite(obuf, 1, len, out) != len)
-        return -1; /* error */
-      size += len;
+  /* something to write? */
+  len = opos - obuf;
+  if (len > 0)
+    {
+    if (fwrite(obuf, 1, len, out) != len) return -1; /* error */
+    size += len;
     }
   }
-  return size;
+return size;
 }
 
 
-FILE *mime_get_decode_file(uschar *pname, uschar *fname) {
-  FILE *f = NULL;
-  uschar *filename;
+FILE *
+mime_get_decode_file(uschar *pname, uschar *fname)
+{
+FILE *f = NULL;
+uschar *filename;
 
-  filename = (uschar *)malloc(2048);
+filename = (uschar *)malloc(2048);
 
-  if ((pname != NULL) && (fname != NULL)) {
-    (void)string_format(filename, 2048, "%s/%s", pname, fname);
-    f = modefopen(filename,"wb+",SPOOL_MODE);
-  }
-  else if (pname == NULL) {
-    f = modefopen(fname,"wb+",SPOOL_MODE);
+if (pname && fname)
+  {
+  (void)string_format(filename, 2048, "%s/%s", pname, fname);
+  f = modefopen(filename,"wb+",SPOOL_MODE);
   }
-  else if (fname == NULL) {
-    int file_nr = 0;
-    int result = 0;
+else if (!pname)
+  f = modefopen(fname,"wb+",SPOOL_MODE);
+else if (!fname)
+  {
+  int file_nr = 0;
+  int result = 0;
+
+  /* must find first free sequential filename */
+  do
+    {
+    struct stat mystat;
+    (void)string_format(filename, 2048,
+      "%s/%s-%05u", pname, message_id, file_nr++);
+    /* security break */
+    if (file_nr >= 1024)
+      break;
+    result = stat(CS filename, &mystat);
+    } while(result != -1);
 
-    /* must find first free sequential filename */
-    do {
-      struct stat mystat;
-      (void)string_format(filename,2048,"%s/%s-%05u", pname, message_id, file_nr);
-      file_nr++;
-      /* security break */
-      if (file_nr >= 1024)
-        break;
-      result = stat(CS filename,&mystat);
-    }
-    while(result != -1);
-    f = modefopen(filename,"wb+",SPOOL_MODE);
-  };
+  f = modefopen(filename, "wb+", SPOOL_MODE);
+  }
 
-  /* set expansion variable */
-  mime_decoded_filename = filename;
+/* set expansion variable */
+mime_decoded_filename = filename;
 
-  return f;
+return f;
 }
 
 
-int mime_decode(uschar **listptr) {
-  int sep = 0;
-  uschar *list = *listptr;
-  uschar *option;
-  uschar option_buffer[1024];
-  uschar decode_path[1024];
-  FILE *decode_file = NULL;
-  long f_pos = 0;
-  ssize_t size_counter = 0;
-  ssize_t (*decode_function)(FILE*, FILE*, uschar*);
-
-  if (mime_stream == NULL)
+int
+mime_decode(uschar **listptr)
+{
+int sep = 0;
+uschar *list = *listptr;
+uschar *option;
+uschar option_buffer[1024];
+uschar decode_path[1024];
+FILE *decode_file = NULL;
+long f_pos = 0;
+ssize_t size_counter = 0;
+ssize_t (*decode_function)(FILE*, FILE*, uschar*);
+
+if (mime_stream == NULL)
+  return FAIL;
+
+f_pos = ftell(mime_stream);
+
+/* build default decode path (will exist since MBOX must be spooled up) */
+(void)string_format(decode_path,1024,"%s/scan/%s",spool_directory,message_id);
+
+/* try to find 1st option */
+if ((option = string_nextinlist(&list, &sep,
+				option_buffer,
+				sizeof(option_buffer))) != NULL)
+  {
+  /* parse 1st option */
+  if ( (Ustrcmp(option,"false") == 0) || (Ustrcmp(option,"0") == 0) )
+    /* explicitly no decoding */
     return FAIL;
 
-  f_pos = ftell(mime_stream);
-
-  /* build default decode path (will exist since MBOX must be spooled up) */
-  (void)string_format(decode_path,1024,"%s/scan/%s",spool_directory,message_id);
-
-  /* try to find 1st option */
-  if ((option = string_nextinlist(&list, &sep,
-                                  option_buffer,
-                                  sizeof(option_buffer))) != NULL) {
+  if (Ustrcmp(option,"default") == 0)
+    /* explicit default path + file names */
+    goto DEFAULT_PATH;
 
-    /* parse 1st option */
-    if ( (Ustrcmp(option,"false") == 0) || (Ustrcmp(option,"0") == 0) ) {
-      /* explicitly no decoding */
-      return FAIL;
-    };
+  if (option[0] == '/')
+    {
+    struct stat statbuf;
 
-    if (Ustrcmp(option,"default") == 0) {
-      /* explicit default path + file names */
-      goto DEFAULT_PATH;
-    };
+    memset(&statbuf,0,sizeof(statbuf));
 
-    if (option[0] == '/') {
-      struct stat statbuf;
-
-      memset(&statbuf,0,sizeof(statbuf));
-
-      /* assume either path or path+file name */
-      if ( (stat(CS option, &statbuf) == 0) && S_ISDIR(statbuf.st_mode) )
-        /* is directory, use it as decode_path */
-        decode_file = mime_get_decode_file(option, NULL);
-      else
-        /* does not exist or is a file, use as full file name */
-        decode_file = mime_get_decode_file(NULL, option);
-    }
+    /* assume either path or path+file name */
+    if ( (stat(CS option, &statbuf) == 0) && S_ISDIR(statbuf.st_mode) )
+      /* is directory, use it as decode_path */
+      decode_file = mime_get_decode_file(option, NULL);
     else
-      /* assume file name only, use default path */
-      decode_file = mime_get_decode_file(decode_path, option);
-  }
-  else
-    /* no option? patch default path */
-    DEFAULT_PATH: decode_file = mime_get_decode_file(decode_path, NULL);
-
-  if (decode_file == NULL)
-    return DEFER;
-
-  /* decode according to mime type */
-  if (mime_content_transfer_encoding == NULL)
-    /* no encoding, dump as-is */
-    decode_function = mime_decode_asis;
-  else if (Ustrcmp(mime_content_transfer_encoding, "base64") == 0)
-    decode_function = mime_decode_base64;
-  else if (Ustrcmp(mime_content_transfer_encoding, "quoted-printable") == 0)
-    decode_function = mime_decode_qp;
+      /* does not exist or is a file, use as full file name */
+      decode_file = mime_get_decode_file(NULL, option);
+    }
   else
-    /* unknown encoding type, just dump as-is */
-    decode_function = mime_decode_asis;
+    /* assume file name only, use default path */
+    decode_file = mime_get_decode_file(decode_path, option);
+  }
+else
+  {
+  /* no option? patch default path */
+DEFAULT_PATH:
+  decode_file = mime_get_decode_file(decode_path, NULL);
+  }
 
-  size_counter = decode_function(mime_stream, decode_file, mime_current_boundary);
+if (!decode_file)
+  return DEFER;
 
-  clearerr(mime_stream);
-  fseek(mime_stream, f_pos, SEEK_SET);
+/* decode according to mime type */
+decode_function =
+  !mime_content_transfer_encoding
+  ? mime_decode_asis	/* no encoding, dump as-is */
+  : Ustrcmp(mime_content_transfer_encoding, "base64") == 0
+  ? mime_decode_base64
+  : Ustrcmp(mime_content_transfer_encoding, "quoted-printable") == 0
+  ? mime_decode_qp
+  : mime_decode_asis;	/* unknown encoding type, just dump as-is */
 
-  if (fclose(decode_file) != 0 || size_counter < 0)
-    return DEFER;
+size_counter = decode_function(mime_stream, decode_file, mime_current_boundary);
 
-  /* round up to the next KiB */
-  mime_content_size = (size_counter + 1023) / 1024;
+clearerr(mime_stream);
+fseek(mime_stream, f_pos, SEEK_SET);
 
-  return OK;
-}
+if (fclose(decode_file) != 0 || size_counter < 0)
+  return DEFER;
 
-int mime_get_header(FILE *f, uschar *header) {
-  int c = EOF;
-  int done = 0;
-  int header_value_mode = 0;
-  int header_open_brackets = 0;
-  int num_copied = 0;
+/* round up to the next KiB */
+mime_content_size = (size_counter + 1023) / 1024;
 
-  while(!done) {
+return OK;
+}
 
-    c = fgetc(f);
-    if (c == EOF) break;
+int
+mime_get_header(FILE *f, uschar *header)
+{
+int c = EOF;
+int done = 0;
+int header_value_mode = 0;
+int header_open_brackets = 0;
+int num_copied = 0;
 
-    /* always skip CRs */
-    if (c == '\r') continue;
+while(!done)
+  {
+  if ((c = fgetc(f)) == EOF) break;
+
+  /* always skip CRs */
+  if (c == '\r') continue;
+
+  if (c == '\n')
+    {
+    if (num_copied > 0)
+      {
+      /* look if next char is '\t' or ' ' */
+      if ((c = fgetc(f)) == EOF) break;
+      if ( (c == '\t') || (c == ' ') ) continue;
+      (void)ungetc(c,f);
+      }
+    /* end of the header, terminate with ';' */
+    c = ';';
+    done = 1;
+    }
 
-    if (c == '\n') {
-      if (num_copied > 0) {
-        /* look if next char is '\t' or ' ' */
-        c = fgetc(f);
-        if (c == EOF) break;
-        if ( (c == '\t') || (c == ' ') ) continue;
-        (void)ungetc(c,f);
-      };
-      /* end of the header, terminate with ';' */
-      c = ';';
-      done = 1;
-    };
-
-    /* skip control characters */
-    if (c < 32) continue;
-
-    if (header_value_mode) {
-      /* --------- value mode ----------- */
-      /* skip leading whitespace */
-      if ( ((c == '\t') || (c == ' ')) && (header_value_mode == 1) )
-        continue;
+  /* skip control characters */
+  if (c < 32) continue;
+
+  if (header_value_mode)
+    {
+    /* --------- value mode ----------- */
+    /* skip leading whitespace */
+    if ( ((c == '\t') || (c == ' ')) && (header_value_mode == 1) )
+      continue;
 
       /* we have hit a non-whitespace char, start copying value data */
       header_value_mode = 2;
@@ -400,295 +421,320 @@ int mime_get_header(FILE *f, uschar *header) {
       };
       /* -------------------------------- */
     }
-    else {
-      /* -------- non-value mode -------- */
-      /* skip whitespace + tabs */
-      if ( (c == ' ') || (c == '\t') )
-        continue;
-      if (c == '\\') {
-        /* quote next char. can be used
-        to escape brackets. */
-        c = fgetc(f);
-        if (c == EOF) break;
+  else
+    {
+    /* -------- non-value mode -------- */
+    /* skip whitespace + tabs */
+    if ( (c == ' ') || (c == '\t') )
+      continue;
+    if (c == '\\')
+      {
+      /* quote next char. can be used
+      to escape brackets. */
+      if ((c = fgetc(f)) == EOF) break;
       }
-      else if (c == '(') {
-        header_open_brackets++;
-        continue;
+    else if (c == '(')
+      {
+      header_open_brackets++;
+      continue;
       }
-      else if ((c == ')') && header_open_brackets) {
-        header_open_brackets--;
-        continue;
+    else if ((c == ')') && header_open_brackets)
+      {
+      header_open_brackets--;
+      continue;
       }
-      else if ( (c == '=') && !header_open_brackets ) {
-        /* enter value mode */
-        header_value_mode = 1;
-      };
+    else if ( (c == '=') && !header_open_brackets ) /* enter value mode */
+      header_value_mode = 1;
 
-      /* skip chars while we are in a comment */
-      if (header_open_brackets > 0)
-        continue;
-      /* -------------------------------- */
-    };
+    /* skip chars while we are in a comment */
+    if (header_open_brackets > 0)
+      continue;
+    /* -------------------------------- */
+    }
 
-    /* copy the char to the buffer */
-    header[num_copied] = (uschar)c;
-    /* raise counter */
-    num_copied++;
+  /* copy the char to the buffer */
+  header[num_copied++] = (uschar)c;
 
-    /* break if header buffer is full */
-    if (num_copied > MIME_MAX_HEADER_SIZE-1) {
-      done = 1;
-    };
-  };
+  /* break if header buffer is full */
+  if (num_copied > MIME_MAX_HEADER_SIZE-1)
+    done = 1;
+  }
 
-  if ((num_copied > 0) && (header[num_copied-1] != ';')) {
-    header[num_copied-1] = ';';
-  };
+if ((num_copied > 0) && (header[num_copied-1] != ';'))
+  header[num_copied-1] = ';';
 
-  /* 0-terminate */
-  header[num_copied] = '\0';
+/* 0-terminate */
+header[num_copied] = '\0';
 
-  /* return 0 for EOF or empty line */
-  if ((c == EOF) || (num_copied == 1))
-    return 0;
-  else
-    return 1;
+/* return 0 for EOF or empty line */
+if ((c == EOF) || (num_copied == 1))
+  return 0;
+else
+  return 1;
 }
 
 
-int mime_acl_check(uschar *acl, FILE *f, struct mime_boundary_context *context,
-                   uschar **user_msgptr, uschar **log_msgptr) {
-  int rc = OK;
-  uschar *header = NULL;
-  struct mime_boundary_context nested_context;
-
-  /* reserve a line buffer to work in */
-  header = (uschar *)malloc(MIME_MAX_HEADER_SIZE+1);
-  if (header == NULL) {
-    log_write(0, LOG_PANIC,
-                 "MIME ACL: can't allocate %d bytes of memory.", MIME_MAX_HEADER_SIZE+1);
-    return DEFER;
-  };
-
-  /* Not actually used at the moment, but will be vital to fixing
-   * some RFC 2046 nonconformance later... */
-  nested_context.parent = context;
-
-  /* loop through parts */
-  while(1) {
-
-    /* reset all per-part mime variables */
-    mime_anomaly_level     = 0;
-    mime_anomaly_text      = NULL;
-    mime_boundary          = NULL;
-    mime_charset           = NULL;
-    mime_decoded_filename  = NULL;
-    mime_filename          = NULL;
-    mime_content_description = NULL;
-    mime_content_disposition = NULL;
-    mime_content_id        = NULL;
-    mime_content_transfer_encoding = NULL;
-    mime_content_type      = NULL;
-    mime_is_multipart      = 0;
-    mime_content_size      = 0;
-
-    /*
-    If boundary is null, we assume that *f is positioned on the start of headers (for example,
-    at the very beginning of a message.
-    If a boundary is given, we must first advance to it to reach the start of the next header
-    block.
-    */
-
-    /* NOTE -- there's an error here -- RFC2046 specifically says to
-     * check for outer boundaries.  This code doesn't do that, and
-     * I haven't fixed this.
-     *
-     * (I have moved partway towards adding support, however, by adding
-     * a "parent" field to my new boundary-context structure.)
-     */
-    if (context != NULL) {
-      while(fgets(CS header, MIME_MAX_HEADER_SIZE, f) != NULL) {
-        /* boundary line must start with 2 dashes */
-        if (Ustrncmp(header,"--",2) == 0) {
-          if (Ustrncmp((header+2),context->boundary,Ustrlen(context->boundary)) == 0) {
-            /* found boundary */
-            if (Ustrncmp((header+2+Ustrlen(context->boundary)),"--",2) == 0) {
-              /* END boundary found */
-              debug_printf("End boundary found %s\n", context->boundary);
-              return rc;
-            }
-            else {
-              debug_printf("Next part with boundary %s\n", context->boundary);
-            };
-            /* can't use break here */
-            goto DECODE_HEADERS;
-          }
-        };
+int
+mime_acl_check(uschar *acl, FILE *f, struct mime_boundary_context *context,
+                   uschar **user_msgptr, uschar **log_msgptr)
+{
+int rc = OK;
+uschar *header = NULL;
+struct mime_boundary_context nested_context;
+
+/* reserve a line buffer to work in */
+if (!(header = (uschar *)malloc(MIME_MAX_HEADER_SIZE+1)))
+  {
+  log_write(0, LOG_PANIC,
+       "MIME ACL: can't allocate %d bytes of memory.", MIME_MAX_HEADER_SIZE+1);
+  return DEFER;
+  }
+
+/* Not actually used at the moment, but will be vital to fixing
+ * some RFC 2046 nonconformance later... */
+nested_context.parent = context;
+
+/* loop through parts */
+while(1)
+  {
+  /* reset all per-part mime variables */
+  mime_anomaly_level     = 0;
+  mime_anomaly_text      = NULL;
+  mime_boundary          = NULL;
+  mime_charset           = NULL;
+  mime_decoded_filename  = NULL;
+  mime_filename          = NULL;
+  mime_content_description = NULL;
+  mime_content_disposition = NULL;
+  mime_content_id        = NULL;
+  mime_content_transfer_encoding = NULL;
+  mime_content_type      = NULL;
+  mime_is_multipart      = 0;
+  mime_content_size      = 0;
+
+  /*
+  If boundary is null, we assume that *f is positioned on the start of headers (for example,
+  at the very beginning of a message.
+  If a boundary is given, we must first advance to it to reach the start of the next header
+  block.
+  */
+
+  /* NOTE -- there's an error here -- RFC2046 specifically says to
+   * check for outer boundaries.  This code doesn't do that, and
+   * I haven't fixed this.
+   *
+   * (I have moved partway towards adding support, however, by adding
+   * a "parent" field to my new boundary-context structure.)
+   */
+  if (context != NULL)
+    {
+    while(fgets(CS header, MIME_MAX_HEADER_SIZE, f) != NULL)
+      {
+      /* boundary line must start with 2 dashes */
+      if (Ustrncmp(header,"--",2) == 0)
+        {
+	if (Ustrncmp((header+2),context->boundary,Ustrlen(context->boundary)) == 0)
+	  {
+	  /* found boundary */
+	  if (Ustrncmp((header+2+Ustrlen(context->boundary)),"--",2) == 0)
+	    {
+	    /* END boundary found */
+	    debug_printf("End boundary found %s\n", context->boundary);
+	    return rc;
+	    }
+	  else
+	    debug_printf("Next part with boundary %s\n", context->boundary);
+
+	  /* can't use break here */
+	  goto DECODE_HEADERS;
+	  }
+	}
       }
-      /* Hit EOF or read error. Ugh. */
-      debug_printf("Hit EOF ...\n");
-      return rc;
-    };
-
-    DECODE_HEADERS:
-    /* parse headers, set up expansion variables */
-    while(mime_get_header(f,header)) {
-      int i;
-      /* loop through header list */
-      for (i = 0; i < mime_header_list_size; i++) {
-        uschar *header_value = NULL;
-        int header_value_len = 0;
-
-        /* found an interesting header? */
-        if (strncmpic(mime_header_list[i].name,header,mime_header_list[i].namelen) == 0) {
-          uschar *p = header + mime_header_list[i].namelen;
-          /* yes, grab the value (normalize to lower case)
-             and copy to its corresponding expansion variable */
-          while(*p != ';') {
-            *p = tolower(*p);
-            p++;
-          };
-          header_value_len = (p - (header + mime_header_list[i].namelen));
-          header_value = (uschar *)malloc(header_value_len+1);
-          memset(header_value,0,header_value_len+1);
-          p = header + mime_header_list[i].namelen;
-          Ustrncpy(header_value, p, header_value_len);
-          debug_printf("Found %s MIME header, value is '%s'\n", mime_header_list[i].name, header_value);
-          *((uschar **)(mime_header_list[i].value)) = header_value;
-
-          /* make p point to the next character after the closing ';' */
-          p += (header_value_len+1);
-
-          /* grab all param=value tags on the remaining line, check if they are interesting */
-          NEXT_PARAM_SEARCH: while (*p != 0) {
-            int j;
-            for (j = 0; j < mime_parameter_list_size; j++) {
-              uschar *param_value = NULL;
-              int param_value_len = 0;
-
-              /* found an interesting parameter? */
-              if (strncmpic(mime_parameter_list[j].name,p,mime_parameter_list[j].namelen) == 0) {
-                uschar *q = p + mime_parameter_list[j].namelen;
-                /* yes, grab the value and copy to its corresponding expansion variable */
-	        while (*q && *q != ';')
-                  {
-                  if (*q == '"') do q++; while (*q != '"');
-                  q++;
-                  }
-
-                param_value_len = (q - (p + mime_parameter_list[j].namelen));
-                param_value = (uschar *)malloc(param_value_len+1);
-                memset(param_value,0,param_value_len+1);
-                q = p + mime_parameter_list[j].namelen;
-                Ustrncpy(param_value, q, param_value_len);
-                param_value = rfc2047_decode(param_value, check_rfc2047_length, NULL, 32, &param_value_len, &q);
-                debug_printf("Found %s MIME parameter in %s header, value is '%s'\n", mime_parameter_list[j].name, mime_header_list[i].name, param_value);
-                *((uschar **)(mime_parameter_list[j].value)) = param_value;
-                p += (mime_parameter_list[j].namelen + param_value_len + 1);
-                goto NEXT_PARAM_SEARCH;
-              };
-            }
-            /* There is something, but not one of our interesting parameters.
-               Advance to the next semicolon */
-            while(*p != ';') p++;
-            p++;
-          };
-        };
-      };
-    };
+    /* Hit EOF or read error. Ugh. */
+    debug_printf("Hit EOF ...\n");
+    return rc;
+    }
 
-    /* set additional flag variables (easier access) */
-    if ( (mime_content_type != NULL) &&
-         (Ustrncmp(mime_content_type,"multipart",9) == 0) )
-      mime_is_multipart = 1;
+DECODE_HEADERS:
+  /* parse headers, set up expansion variables */
+  while (mime_get_header(f,header))
+    {
+    int i;
+    /* loop through header list */
+    for (i = 0; i < mime_header_list_size; i++)
+      {
+      uschar *header_value = NULL;
+      int header_value_len = 0;
+
+      /* found an interesting header? */
+      if (strncmpic(mime_header_list[i].name,header,mime_header_list[i].namelen) == 0)
+	{
+	uschar *p = header + mime_header_list[i].namelen;
+	/* yes, grab the value (normalize to lower case)
+	   and copy to its corresponding expansion variable */
+	while(*p != ';')
+	  {
+	  *p = tolower(*p);
+	  p++;
+	  }
+	header_value_len = (p - (header + mime_header_list[i].namelen));
+	header_value = (uschar *)malloc(header_value_len+1);
+	memset(header_value,0,header_value_len+1);
+	p = header + mime_header_list[i].namelen;
+	Ustrncpy(header_value, p, header_value_len);
+	debug_printf("Found %s MIME header, value is '%s'\n", mime_header_list[i].name, header_value);
+	*((uschar **)(mime_header_list[i].value)) = header_value;
+
+	/* make p point to the next character after the closing ';' */
+	p += (header_value_len+1);
+
+	/* grab all param=value tags on the remaining line, check if they are interesting */
+NEXT_PARAM_SEARCH:
+	while (*p != 0)
+	  {
+	  mime_parameter * mp;
+	  for (mp = mime_parameter_list;
+	       mp < &mime_parameter_list[mime_parameter_list_size];
+	       mp++)
+	    {
+	    uschar *param_value = NULL;
+	    int param_value_len = 0;
+
+	    /* found an interesting parameter? */
+	    if (strncmpic(mp->name, p, mp->namelen) == 0)
+	      {
+	      uschar *q = p + mp->namelen;
+	      int size = 0;
+	      int ptr = 0;
+
+	      /* yes, grab the value and copy to its corresponding expansion variable */
+	      while(*q && *q != ';')		/* ; terminates */
+		{
+		if (*q == '"')
+		  {
+		  q++;				/* skip leading " */
+		  while(*q && *q != '"')	/* which protects ; */
+		    param_value = string_cat(param_value, &size, &ptr, q++, 1);
+		  if (*q) q++;			/* skip trailing " */
+		  }
+		else
+		  param_value = string_cat(param_value, &size, &ptr, q++, 1);
+		}
+	      param_value[ptr++] = '\0';
+	      param_value_len = ptr;
+
+	      param_value = rfc2047_decode(param_value, check_rfc2047_length, NULL, 32, &param_value_len, &q);
+	      debug_printf("Found %s MIME parameter in %s header, value is '%s'\n", mp->name, mime_header_list[i].name, param_value);
+	      *((uschar **)(mp->value)) = param_value;
+	      p += (mp->namelen + param_value_len + 1);
+	      goto NEXT_PARAM_SEARCH;
+	    }
+	  }
+	  /* There is something, but not one of our interesting parameters.
+	     Advance to the next semicolon */
+	  while(*p != ';') p++;
+	  p++;
+	}
+      }
+    }
+  }
 
-    /* Make a copy of the boundary pointer.
-       Required since mime_boundary is global
-       and can be overwritten further down in recursion */
-    nested_context.boundary = mime_boundary;
+  /* set additional flag variables (easier access) */
+  if ( (mime_content_type != NULL) &&
+       (Ustrncmp(mime_content_type,"multipart",9) == 0) )
+    mime_is_multipart = 1;
 
-    /* raise global counter */
-    mime_part_count++;
+  /* Make a copy of the boundary pointer.
+     Required since mime_boundary is global
+     and can be overwritten further down in recursion */
+  nested_context.boundary = mime_boundary;
 
-    /* copy current file handle to global variable */
-    mime_stream = f;
-    mime_current_boundary = context ? context->boundary : 0;
+  /* raise global counter */
+  mime_part_count++;
 
-    /* Note the context */
-    mime_is_coverletter = !(context && context->context == MBC_ATTACHMENT);
+  /* copy current file handle to global variable */
+  mime_stream = f;
+  mime_current_boundary = context ? context->boundary : 0;
 
-    /* call ACL handling function */
-    rc = acl_check(ACL_WHERE_MIME, NULL, acl, user_msgptr, log_msgptr);
+  /* Note the context */
+  mime_is_coverletter = !(context && context->context == MBC_ATTACHMENT);
 
-    mime_stream = NULL;
-    mime_current_boundary = NULL;
+  /* call ACL handling function */
+  rc = acl_check(ACL_WHERE_MIME, NULL, acl, user_msgptr, log_msgptr);
 
-    if (rc != OK) break;
+  mime_stream = NULL;
+  mime_current_boundary = NULL;
+
+  if (rc != OK) break;
 
-    /* If we have a multipart entity and a boundary, go recursive */
-    if ( (mime_content_type != NULL) &&
-         (nested_context.boundary != NULL) &&
-         (Ustrncmp(mime_content_type,"multipart",9) == 0) ) {
-      debug_printf("Entering multipart recursion, boundary '%s'\n", nested_context.boundary);
-
-      if (context && context->context == MBC_ATTACHMENT)
-        nested_context.context = MBC_ATTACHMENT;
-      else if (!Ustrcmp(mime_content_type,"multipart/alternative")
-            || !Ustrcmp(mime_content_type,"multipart/related"))
-        nested_context.context = MBC_COVERLETTER_ALL;
-      else
-        nested_context.context = MBC_COVERLETTER_ONESHOT;
-
-      rc = mime_acl_check(acl, f, &nested_context, user_msgptr, log_msgptr);
-      if (rc != OK) break;
+  /* If we have a multipart entity and a boundary, go recursive */
+  if ( (mime_content_type != NULL) &&
+       (nested_context.boundary != NULL) &&
+       (Ustrncmp(mime_content_type,"multipart",9) == 0) )
+    {
+    debug_printf("Entering multipart recursion, boundary '%s'\n", nested_context.boundary);
+
+    nested_context.context =
+      context && context->context == MBC_ATTACHMENT
+      ? MBC_ATTACHMENT
+      :    Ustrcmp(mime_content_type,"multipart/alternative") == 0
+	|| Ustrcmp(mime_content_type,"multipart/related") == 0
+      ? MBC_COVERLETTER_ALL
+      : MBC_COVERLETTER_ONESHOT;
+
+    rc = mime_acl_check(acl, f, &nested_context, user_msgptr, log_msgptr);
+    if (rc != OK) break;
     }
-    else if ( (mime_content_type != NULL) &&
-            (Ustrncmp(mime_content_type,"message/rfc822",14) == 0) ) {
-      uschar *rfc822name = NULL;
-      uschar filename[2048];
-      int file_nr = 0;
-      int result = 0;
-
-      /* must find first free sequential filename */
-      do {
-        struct stat mystat;
-        (void)string_format(filename,2048,"%s/scan/%s/__rfc822_%05u", spool_directory, message_id, file_nr);
-        file_nr++;
-        /* security break */
-        if (file_nr >= 128)
-          goto NO_RFC822;
-        result = stat(CS filename,&mystat);
-      }
-      while(result != -1);
-
-      rfc822name = filename;
-
-      /* decode RFC822 attachment */
-      mime_decoded_filename = NULL;
-      mime_stream = f;
-      mime_current_boundary = context ? context->boundary : NULL;
-      mime_decode(&rfc822name);
-      mime_stream = NULL;
-      mime_current_boundary = NULL;
-      if (mime_decoded_filename == NULL) {
-        /* decoding failed */
-        log_write(0, LOG_MAIN,
-             "mime_regex acl condition warning - could not decode RFC822 MIME part to file.");
-        return DEFER;
-      };
-      mime_decoded_filename = NULL;
-    };
+  else if ( (mime_content_type != NULL) &&
+	  (Ustrncmp(mime_content_type,"message/rfc822",14) == 0) )
+    {
+    uschar *rfc822name = NULL;
+    uschar filename[2048];
+    int file_nr = 0;
+    int result = 0;
 
-    NO_RFC822:
-    /* If the boundary of this instance is NULL, we are finished here */
-    if (context == NULL) break;
+    /* must find first free sequential filename */
+    do
+      {
+      struct stat mystat;
+      (void)string_format(filename, 2048,
+	"%s/scan/%s/__rfc822_%05u", spool_directory, message_id, file_nr++);
+      /* security break */
+      if (file_nr >= 128)
+	goto NO_RFC822;
+      result = stat(CS filename,&mystat);
+      } while (result != -1);
+
+    rfc822name = filename;
+
+    /* decode RFC822 attachment */
+    mime_decoded_filename = NULL;
+    mime_stream = f;
+    mime_current_boundary = context ? context->boundary : NULL;
+    mime_decode(&rfc822name);
+    mime_stream = NULL;
+    mime_current_boundary = NULL;
+    if (!mime_decoded_filename)		/* decoding failed */
+      {
+      log_write(0, LOG_MAIN,
+	   "mime_regex acl condition warning - could not decode RFC822 MIME part to file.");
+      return DEFER;
+      }
+    mime_decoded_filename = NULL;
+    }
 
-    if (context->context == MBC_COVERLETTER_ONESHOT)
-      context->context = MBC_ATTACHMENT;
+NO_RFC822:
+  /* If the boundary of this instance is NULL, we are finished here */
+  if (context == NULL) break;
 
-  };
+  if (context->context == MBC_COVERLETTER_ONESHOT)
+    context->context = MBC_ATTACHMENT;
+  }
 
-  return rc;
+return rc;
 }
 
-#endif
+#endif	/*WITH_CONTENT_SCAN*/
+
+/* vi: sw ai sw=2
+*/
