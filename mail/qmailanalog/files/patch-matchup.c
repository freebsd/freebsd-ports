*** matchup.c-orig	Fri Jul  1 12:28:28 2005
--- matchup.c	Fri Jul  1 14:06:04 2005
***************
*** 417,422 ****
--- 417,463 ----
  
  stralloc outline = {0};
  
+ void fix_taia()
+ {
+   stralloc tai = {0};
+   stralloc tmp = {0};
+   char *p = line.s+field[0]+1;
+   unsigned long secs;
+   unsigned long nanosecs;
+   unsigned long u;
+   char ch;
+ 
+   secs = 0;
+   nanosecs = 0;
+   for (;;) {
+     ch = *p++;
+     u = ch - '0';
+     if (u >= 10) {
+       u = ch - 'a';
+       if (u >= 6) break;
+       u += 10;
+     }
+     secs <<= 4;
+     secs += nanosecs >> 28;
+     nanosecs &= 0xfffffff;
+     nanosecs <<= 4;
+     nanosecs += u;
+   }
+   secs -= 4611686018427387914ULL;
+ 
+   if (!stralloc_copyb(&tai, strnum,fmt_ulong(strnum,secs))) nomem();
+   if (!stralloc_cats(&tai,".")) nomem();
+   if (!stralloc_catb(&tai, strnum,fmt_ulong(strnum,nanosecs))) nomem();
+   if (!stralloc_0(&tai)) nomem();
+ 
+   if (!stralloc_copy(&tmp,&tai)) nomem();
+   while (tmp.len < field[1]) 
+     if (!stralloc_cats(&tmp," ")) nomem();
+   if (!stralloc_cats(&tmp,line.s + field[1])) nomem();
+   if (!stralloc_copy(&line,&tmp)) nomem();
+   if (!stralloc_0(&line)) nomem();
+ }
+ 
  void main()
  {
    int i;
***************
*** 452,457 ****
--- 493,500 ----
        while (j < line.len) if (!line.s[j]) break; else ++j;
      }
      if (!stralloc_0(&line)) nomem();
+ 
+     if ((line.s[field[0]]) == '@') fix_taia();
  
      if (str_equal(line.s + field[1],"status:")) ;
      else if (str_equal(line.s + field[1],"starting")) starting();
