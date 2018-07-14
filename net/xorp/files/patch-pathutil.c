--- cli/libtecla/pathutil.c.orig	2018-07-10 13:09:21 UTC
+++ cli/libtecla/pathutil.c
@@ -168,7 +168,7 @@ char *_pn_append_to_path(PathName *path,
 /*
  * How many characters should be appended?
  */
-  if(slen < 0 || slen > strlen(string))
+  if(slen < 0 || (unsigned long)(slen) > strlen(string))
     slen = strlen(string);
 /*
  * Resize the pathname if needed.
@@ -239,7 +239,7 @@ char *_pn_prepend_to_path(PathName *path
 /*
  * How many characters should be appended?
  */
-  if(slen < 0 || slen > strlen(string))
+  if(slen < 0 || (unsigned long)(slen) > strlen(string))
     slen = strlen(string);
 /*
  * Work out how far we need to shift the original path string to make
@@ -494,7 +494,7 @@ char *_pu_start_of_path(const char *stri
 	break;
     };
   };
-  return (char *)string + i + 1;
+  return (char *)(string + i + 1);
 }
 
 /*.......................................................................
@@ -534,7 +534,7 @@ char *_pu_end_of_path(const char *string
       escaped = 1;
     };
   };
-  return (char *)string + i;
+  return (char *)(string + i);
 }
 
 /*.......................................................................
