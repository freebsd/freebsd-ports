--- echoping.c.orig	2025-05-05 00:28:45.988741000 +0700
+++ echoping.c	2025-05-05 01:44:14.970048000 +0700
@@ -9,6 +9,12 @@
  *
  *  */
 
+#include <iconv.h>
+#include <langinfo.h>
+#include <limits.h>
+#include <stdint.h>
+#include <strings.h>
+
 char           *progname;
 
 #include	"echoping.h"
@@ -54,6 +60,188 @@ static terminate_f plugin_terminate;
 struct timeval null_timeval;
 static struct timeval max_timeval;
 
+#ifdef LIBIDN
+/* Basically stolen from libidn with small modifications */
+
+static char * _str_cd_iconv (const char *src, iconv_t cd);
+static char * _str_iconv (const char *src, const char *from_codeset, const char *to_codeset);
+
+static char *
+_str_cd_iconv (const char *src, iconv_t cd)
+{
+  char *result;
+  size_t result_size;
+  size_t length;
+  const char *inptr = src;
+  size_t inbytes_remaining = strlen (src);
+
+  /* Make a guess for the worst-case output size, in order to avoid a
+     realloc.  It's OK if the guess is wrong as long as it is not zero and
+     doesn't lead to an integer overflow.  */
+  result_size = inbytes_remaining;
+  {
+    size_t approx_sqrt_SIZE_MAX = SIZE_MAX >> (sizeof (size_t) * CHAR_BIT / 2);
+    if (result_size <= approx_sqrt_SIZE_MAX / MB_LEN_MAX)
+      result_size *= MB_LEN_MAX;
+  }
+  result_size += 1; /* for the terminating NUL */
+
+  result = (char *) malloc (result_size);
+  if (result == NULL)
+    {
+      errno = ENOMEM;
+      return NULL;
+    }
+
+  /* Set to the initial state.  */
+  iconv (cd, NULL, NULL, NULL, NULL);
+
+  /* Do the conversion.  */
+  {
+    char *outptr = result;
+    size_t outbytes_remaining = result_size - 1;
+
+    for (;;)
+      {
+        /* Here inptr + inbytes_remaining = src + strlen (src),
+                outptr + outbytes_remaining = result + result_size - 1.  */
+        size_t res = iconv (cd,
+                            &inptr, &inbytes_remaining,
+                            &outptr, &outbytes_remaining);
+
+        if (res == (size_t)(-1))
+          {
+            if (errno == EINVAL)
+              break;
+            else if (errno == E2BIG)
+              {
+                size_t used = outptr - result;
+                size_t newsize = result_size * 2;
+                char *newresult;
+
+                if (!(newsize > result_size))
+                  {
+                    errno = ENOMEM;
+                    goto failed;
+                  }
+                newresult = (char *) realloc (result, newsize);
+                if (newresult == NULL)
+                  {
+                    errno = ENOMEM;
+                    goto failed;
+                  }
+                result = newresult;
+                result_size = newsize;
+                outptr = result + used;
+                outbytes_remaining = result_size - 1 - used;
+              }
+            else
+              goto failed;
+          }
+        else
+          break;
+      }
+    for (;;)
+      {
+        /* Here outptr + outbytes_remaining = result + result_size - 1.  */
+        size_t res = iconv (cd, NULL, NULL, &outptr, &outbytes_remaining);
+
+        if (res == (size_t)(-1))
+          {
+            if (errno == E2BIG)
+              {
+                size_t used = outptr - result;
+                size_t newsize = result_size * 2;
+                char *newresult;
+
+                if (!(newsize > result_size))
+                  {
+                    errno = ENOMEM;
+                    goto failed;
+                  }
+                newresult = (char *) realloc (result, newsize);
+                if (newresult == NULL)
+                  {
+                    errno = ENOMEM;
+                    goto failed;
+                  }
+                result = newresult;
+                result_size = newsize;
+                outptr = result + used;
+                outbytes_remaining = result_size - 1 - used;
+              }
+            else
+              goto failed;
+          }
+        else
+          break;
+      }
+
+    /* Add the terminating NUL byte.  */
+    *outptr++ = '\0';
+
+    length = outptr - result;
+  }
+
+  /* Give away unused memory.  */
+  if (length < result_size)
+    {
+      char *smaller_result = (char *) realloc (result, length);
+
+      if (smaller_result != NULL)
+        result = smaller_result;
+    }
+
+  return result;
+
+ failed:
+  free (result);
+  return NULL;
+}
+
+static char *
+_str_iconv (const char *src, const char *from_codeset, const char *to_codeset)
+{
+  if (*src == '\0' || strcasecmp (from_codeset, to_codeset) == 0)
+    {
+      char *result = strdup (src);
+
+      if (result == NULL)
+        errno = ENOMEM;
+      return result;
+    }
+  else
+    {
+      iconv_t cd;
+      char *result;
+
+      cd = iconv_open (to_codeset, from_codeset);
+      if (cd == (iconv_t) -1)
+        return NULL;
+
+      result = _str_cd_iconv (src, cd);
+
+      if (result == NULL)
+        {
+          /* Close cd, but preserve the errno from str_cd_iconv.  */
+          int saved_errno = errno;
+          iconv_close (cd);
+          errno = saved_errno;
+        }
+      else
+        {
+          if (iconv_close (cd) < 0)
+            {
+              free (result);
+              return NULL;
+            }
+        }
+      return result;
+    }
+}
+
+#endif
+
 int
 main(argc, argv)
     int             argc;
@@ -561,12 +749,12 @@ main(argc, argv)
     server = leftover[0];
 #ifdef LIBIDN
     locale_server = server;
-    utf8_server = stringprep_locale_to_utf8(server);
+    utf8_server = _str_iconv(server, nl_langinfo(CODESET), "UTF-8");
     if (utf8_server)
         server = utf8_server;
     else
         err_quit("Cannot convert %s to UTF-8 encoding: wrong locale (%s)?",
-                 server, stringprep_locale_charset());
+                 server, nl_langinfo(CODESET));
 #endif
     if (!http && !icp) {
         for (p = server; *p && (*p != ':'); p++) {
