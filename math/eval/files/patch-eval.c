--- /tmp/Eval/source/eval.c	Tue Apr 13 21:04:42 1993
+++ eval.c	Wed Sep 24 12:25:27 1997
@@ -44,6 +44,9 @@
 */
 
 #include   "eval.h"
+#include   <readline/readline.h>
+#include   <readline/history.h>
+#include   <signal.h>
 
 static char    tempname[80];
 static char    wdir[100];
@@ -122,6 +125,7 @@
 static BOOLEAN process_line(FILE *stream,int showinp,int showout,VARPTR vlist,
                             VARPTR clist,char *pinput);
 static void init_varlist(VARPTR vlist);
+static void init_sig(void);
 static void var_copy(VARPTR dest,VARPTR source);
 static int print_help(FILE *stream,int extended,int page,char *s);
 static int more(char *text,char *input,int pause);
@@ -143,6 +147,8 @@
 
 
     init_varlist(vlist);
+    initialize_readline();
+    init_sig();
     wdir[0]=EOS;
     rpath[0]=EOS;
     setobase(10);
@@ -462,6 +468,7 @@
         if (input[m0]!='?')
             {
             evaluate(&input[m0],showout,vlist,clist);
+	    init_sig(); 
             break;
             }
         if (!strcmp(&input[m0],"?"))
@@ -565,6 +572,24 @@
        vlist[i].name[0]=EOS;
    }
 
+static void ignore_fpe(void)
+{
+  printf("Floating point exception... ignore result!\n");
+  signal(SIGFPE, SIG_IGN);
+}
+
+/*
+** init_sig()
+**
+** initialize signal handler for floating point exceptions
+**
+*/
+
+static void init_sig(void)
+{
+  signal(SIGFPE, ignore_fpe);
+}
+
 /*
 ** var_copy(VARPTR dest,VARPTR source)
 **
@@ -839,24 +864,89 @@
     s[j+1]=EOS;
     }
 
+char *
+complete_consts (char *text, int state)
+{
+  static int i = 0, j = 0;
+
+  if (state == 0) {
+    i = 0;
+    j = 0;
+  }
+
+  while (i<MAXC) {
+    if (strncmp (clist[i].name, text, strlen(text)) == 0)
+      return strdup(clist[i++].name);
+    else
+      i++;
+  }
 
-static int nextline(char *s,FILE *stream)
-
+  while (j<NUMFUNCS) {
+    if (strncmp (flist[j].name, text, strlen(text)) == 0)
+      return strdup(flist[j++].name);
+    else
+      j++;
+  }
+    
+  return NULL;
+}
+    
+int initialize_readline ()
+{
+  /* Allow conditional parsing of the ~/.inputrc file. */
+  rl_readline_name = "Eval";
+  
+  rl_completion_entry_function = (Function *)complete_consts;
+}
+
+/* A static variable for holding the line. */
+static char *line_read = (char *)NULL;
+     
+/* Read a string, and return a pointer to it.  Returns NULL on EOF. */
+char *
+do_gets ()
+{
+  /* If the buffer has already been allocated, return the memory
+     to the free pool. */
+  if (line_read != (char *)NULL)
     {
-    while (1)
-
-        {
-        if (stream==stdin)
-            printf("%s",PROMPT);
-        if (fgets(s,MAXINPUT,stream)==NULL)
-            return(0);
-        fixup(s);
-        if (s[0]!=';')
-            break;
-        }
-    return(1);
+      free (line_read);
+      line_read = (char *)NULL;
     }
 
+  /* Get a line from the user. */
+  line_read = readline (PROMPT);
+  
+  /* If the line has any text in it, save it on the history. */
+  if (line_read && *line_read)
+    add_history (line_read);
+  
+  return (line_read);
+}
+
+
+static int nextline(char *s,FILE *stream)
+     
+{
+  while (1)
+    
+    {
+      if (stream==stdin) {
+	if (do_gets() == NULL)
+	  return 0;
+	else
+	  strncpy(s, line_read, MAXINPUT);
+      }
+      else
+	if (fgets(s,MAXINPUT,stream)==NULL)
+	  return(0);
+      fixup(s);
+      if (s[0]!=';')
+	break;
+    }
+  return(1);
+}
+     
 
 static void close_temp(int showout)
 
