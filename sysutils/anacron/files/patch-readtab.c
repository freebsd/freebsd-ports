--- readtab.c.orig	Fri Jun 23 00:13:12 2000
+++ readtab.c	Thu Jun 16 17:35:07 2005
@@ -19,6 +19,11 @@
  
     The GNU General Public License can also be found in the file
     `COPYING' that comes with the Anacron source distribution.
+
+    Changes:
+
+    May 2003 (Derik van Zuetphen)
+	replaced obstack with malloc/realloc calls
 */
 
 
@@ -29,7 +34,6 @@
 #include <errno.h>
 #include <stdio.h>
 #include <stdlib.h>
-#include <obstack.h>
 #include <limits.h>
 #include <fnmatch.h>
 #include <unistd.h>
@@ -37,8 +41,6 @@
 #include "global.h"
 #include "matchrx.h"
 
-static struct obstack input_o;   /* holds input line */
-static struct obstack tab_o;    /* holds processed data read from anacrontab */
 static FILE *tab;
 job_rec **job_array;
 int njobs;                       /* number of jobs to run */
@@ -47,9 +49,7 @@
 static job_rec *last_job_rec;    /* last job stored in memory, at the moment */
 static env_rec *last_env_rec;    /* last environment assignment stored */
 
-/* some definitions for the obstack macros */
-#define obstack_chunk_alloc xmalloc
-#define obstack_chunk_free free
+#define MAXTABLINE	1000
 
 static void *
 xmalloc (size_t size)
@@ -63,6 +63,18 @@
     return ptr;
 }
 
+static void *
+xrealloc (void *mem, size_t size)
+/* Just like standard realloc(), only never returns NULL. */
+{
+    void * ptr;
+
+    ptr = realloc(mem,size);
+    if (ptr == NULL)
+	die("Memory exhausted");
+    return ptr;
+}
+
 static int
 conv2int(const char *s)
 /* Return the int or -1 on over/under-flow
@@ -78,19 +90,20 @@
 }
 
 static char *
-read_tab_line ()
+read_tab_line (char *line)
 /* Read one line and return a pointer to it.
 Return NULL if no more lines.
  */
 {
     int c;
+    int i = 0;
 
     if (feof(tab)) return NULL;
-    while ((c = getc(tab)) != EOF && c != '\n')
-	obstack_1grow(&input_o, c);
+    while (i < MAXTABLINE-1 && (c = getc(tab)) != EOF && c != '\n')
+	line[i++] = c;
     if (ferror(tab)) die_e("Error reading %s", anacrontab);
-    obstack_1grow(&input_o, '\0');
-    return obstack_finish(&input_o);
+    line[i] = 0;
+    return line;
 }
 
 static int
@@ -119,8 +132,8 @@
 
     var_len = strlen(env_var);
     val_len = strlen(value);
-    er = obstack_alloc(&tab_o, sizeof(env_rec));
-    er->assign = obstack_alloc(&tab_o, var_len + 1 + val_len + 1);
+    er = (env_rec*)xmalloc(sizeof(env_rec));
+    er->assign = (char*)xmalloc(var_len + 1 + val_len + 1);
     strcpy(er->assign, env_var);
     er->assign[var_len] = '=';
     strcpy(er->assign + var_len + 1, value);
@@ -151,14 +164,14 @@
 		 anacrontab, line_num);
 	return;
     }
-    jr = obstack_alloc(&tab_o, sizeof(job_rec));
+    jr = (job_rec*)xmalloc(sizeof(job_rec));
     jr->period = period;
     jr->delay = delay;
     jr->tab_line = line_num;
-    jr->ident = obstack_alloc(&tab_o, ident_len + 1);
+    jr->ident = (char*)xmalloc(ident_len + 1);
     strcpy(jr->ident, ident);
     jr->arg_num = job_arg_num(ident);
-    jr->command = obstack_alloc(&tab_o, command_len + 1);
+    jr->command = (char*)xmalloc(command_len + 1);
     strcpy(jr->command, command);
     jr->job_pid = jr->mailer_pid = 0;
     if (last_job_rec != NULL) last_job_rec->next = jr;
@@ -222,7 +235,7 @@
 read_tab()
 /* Read the anacrontab file into memory */
 {
-    char *tab_line;
+    char tab_line[MAXTABLINE];
 
     first_job_rec = last_job_rec = NULL;
     first_env_rec = last_env_rec = NULL;
@@ -231,14 +244,10 @@
     /* Open the anacrontab file */
     tab = fopen(anacrontab, "r");
     if (tab == NULL) die_e("Error opening %s", anacrontab);
-    /* Initialize the obstacks */
-    obstack_init(&input_o);
-    obstack_init(&tab_o);
-    while ((tab_line = read_tab_line()) != NULL)
+    while ((read_tab_line(tab_line)) != NULL)
     {
 	line_num++;
 	parse_tab_line(tab_line);
-	obstack_free(&input_o, tab_line);
     }
     if (fclose(tab)) die_e("Error closing %s", anacrontab);
 }
@@ -269,16 +278,17 @@
 
     j = first_job_rec;
     njobs = 0;
+    job_array = NULL;
     while (j != NULL)
     {
 	if (j->arg_num != -1 && (update_only || consider_job(j)))
 	{
+	    job_array = (job_rec**)xrealloc(job_array, (njobs+1)*sizeof(j));
+	    job_array[njobs] = j;
 	    njobs++;
-	    obstack_grow(&tab_o, &j, sizeof(j));
 	}
 	j = j->next;
     }
-    job_array = obstack_finish(&tab_o);
 
     /* sort the jobs */
     qsort(job_array, njobs, sizeof(*job_array),
