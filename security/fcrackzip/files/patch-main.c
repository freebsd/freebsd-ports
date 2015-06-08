--- main.c.orig	2005-09-10 19:58:44 UTC
+++ main.c
@@ -44,13 +44,112 @@ static int modul = 1;
 
 static FILE *dict_file;
 
+char *
+path_for_shell (char *dest, const char *str)
+{
+  /* backslash shell special charatcers */
+
+  char ch, *p = dest;
+  size_t len = strlen(str);
+  int i;
+
+  for (i = 0; i < len; i++)
+  {
+    ch = str[i];
+
+    switch (ch)
+    {
+    /* ASCII table order */
+    case 0x20: /* space */
+    case '!':
+    case '"':
+    case '#':
+    case '$':
+    case '&':
+    case 0x27: /* single quote */
+    case '(':
+    case ')':
+    case '*':
+    case '+':
+    case 0x2C: /* comma */
+    case ':':
+    case ';':
+    case '<':
+    case '>':
+    case '?':
+    case '[':
+    case '\\':
+    case ']':
+    case '^':
+    case '`':
+    case '{':
+    case '|':
+    case '}':
+    case '~':
+      /* backslash special characters */
+      *p++ = '\\';
+      *p++ = ch;
+      break;
+    default:
+      *p++ = ch;
+    }
+  }
+
+  /* terminate string */
+  *p = '\0';
+
+  return dest;
+}
+
+char *
+escape_pw (char *dest, const char *str)
+{
+  /* backslash shell special charatcers */
+
+  char ch, *p = dest;
+  size_t len = strlen(str);
+  int i;
+
+  for (i = 0; i < len; i++)
+  {
+    ch = str[i];
+
+    switch (ch)
+    {
+    /* ASCII table order */
+    case '"':
+    case '$':
+    case 0x27: /* single quote */
+    case '\\':
+    case '`':
+      /* backslash special characters */
+      *p++ = '\\';
+      *p++ = ch;
+      break;
+    default:
+      *p++ = ch;
+    }
+  }
+
+  /* terminate string */
+  *p = '\0';
+
+  return dest;
+}
+
 int REGPARAM
 check_unzip (const char *pw)
 {
   char buff[1024];
+  char path[1024];
+  char escpw[256];
   int status;
 
-  sprintf (buff, "unzip -qqtP \"%s\" %s " DEVNULL, pw, file_path[0]);
+  escape_pw (escpw, pw);
+  path_for_shell (path, file_path[0]);
+
+  sprintf (buff, "unzip -qqtP \"%s\" %s " DEVNULL, escpw, path); 
+
   status = system (buff);
 
 #undef REDIR
