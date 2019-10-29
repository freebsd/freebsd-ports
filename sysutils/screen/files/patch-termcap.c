--- termcap.c.orig	2019-10-01 15:08:00.000000000 -0700
+++ termcap.c	2019-10-28 19:37:41.586957000 -0700
@@ -75,11 +75,10 @@
 
 char *extra_incap, *extra_outcap;
 
-static const char TermcapConst[] = "\\\n\
-\t:DO=\\E[%dB:LE=\\E[%dD:RI=\\E[%dC:UP=\\E[%dA:bs:bt=\\E[Z:\\\n\
-\t:cd=\\E[J:ce=\\E[K:cl=\\E[H\\E[J:cm=\\E[%i%d;%dH:ct=\\E[3g:\\\n\
-\t:do=^J:nd=\\E[C:pt:rc=\\E8:rs=\\Ec:sc=\\E7:st=\\EH:up=\\EM:\\\n\
-\t:le=^H:bl=^G:cr=^M:it#8:ho=\\E[H:nw=\\EE:ta=^I:is=\\E)0:";
+static const char TermcapConst[] = "DO=\\E[%dB:LE=\\E[%dD:RI=\\E[%dC:\
+UP=\\E[%dA:bs:bt=\\E[Z:cd=\\E[J:ce=\\E[K:cl=\\E[H\\E[J:cm=\\E[%i%d;%dH:\
+ct=\\E[3g:do=^J:nd=\\E[C:pt:rc=\\E8:rs=\\Ec:sc=\\E7:st=\\EH:up=\\EM:\
+le=^H:bl=^G:cr=^M:it#8:ho=\\E[H:nw=\\EE:ta=^I:is=\\E)0:";
 
 char *
 gettermcapstring(s)
@@ -227,7 +226,7 @@
 	  (D_CKM && (InStr(D_CKM, "\033[M") || InStr(D_CKM, "\033[<"))))
         {
           D_CXT = 1;
-          kmapdef[0] = SaveStr(D_CKM);
+          kmapdef[0] = D_CKM ? SaveStr(D_CKM) : NULL;
         }
       /* "be" seems to be standard for xterms... */
       if (D_CXT)
@@ -362,11 +361,7 @@
   if (D_CG0)
     {
       if (D_CS0 == 0)
-#ifdef TERMINFO
-        D_CS0 = "\033(%p1%c";
-#else
-        D_CS0 = "\033(%.";
-#endif
+	D_CS0 = "\033(%p1%c"; /* Old ncurses can't handle %. */
       if (D_CE0 == 0)
         D_CE0 = "\033(B";
       D_AC = 0;
@@ -827,21 +822,13 @@
 char *s;
 {
   register int n;
-
-  if (tcLineLen + (n = strlen(s)) > 55 && Termcaplen < TERMCAP_BUFSIZE - 4 - 1)
-    {
-      strcpy(Termcap + Termcaplen, "\\\n\t:");
-      Termcaplen += 4;
-      tcLineLen = 0;
-    }
+  n=strlen(s);
   if (Termcaplen + n < TERMCAP_BUFSIZE - 1)
     {
       strcpy(Termcap + Termcaplen, s);
       Termcaplen += n;
       tcLineLen += n;
     }
-  else
-    Panic(0, "TERMCAP overflow - sorry.");
 }
 
 /*
@@ -1077,6 +1064,12 @@
 	{
 	  if (i >= T_KEYPAD)	/* don't put keypad codes in TERMCAP */
 	    continue;		/* - makes it too big */
+#if (TERMCAP_BUF < 1024)
+          if (i >= T_FEXTRA && i < T_BACKTAB) /* also skip extra vt220 keys */
+            continue;
+          if (i > T_BACKTAB && i < T_NAVIGATE) /* more vt220 keys */
+            continue;
+#endif
 	  if (i >= T_CURSOR && i < T_OCAPS)
 	    {
 	      act = &umtab[i - (T_CURSOR - T_OCAPS + T_CAPS)];
@@ -1129,6 +1122,37 @@
     }
   debug("MakeTermcap: end\n");
   return Termcap;
+}
+
+#define TERMCAP_MAX_WIDTH 63
+void
+DumpTermcap(aflag, f)
+int aflag;
+FILE *f;
+{
+  register const char *p, *pe;
+  int n, col=0;
+
+  if ((p = index(MakeTermcap(aflag), '=')) == NULL)
+    return;
+  p++;
+  debug1("DumpTermcap: '%s'\n", p);
+  /* write termcap entry with wrapping */
+  while((pe = index(p, ':')))
+    {
+      n = pe - p + 1;
+      if((col > 8) && ((col + n) > TERMCAP_MAX_WIDTH))
+        {
+          fwrite("\\\n\t:", 1, 4, f);
+          col = 8;
+        }
+      fwrite(p, 1, n, f);
+      col += n;
+      p = ++pe;
+    }
+  if(*p)
+    fwrite(p, 1, strlen(p), f);
+  fputc('\n', f);
 }
 
 static void
