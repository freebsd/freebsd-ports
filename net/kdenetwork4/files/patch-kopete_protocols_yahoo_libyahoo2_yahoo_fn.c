--- kopete/protocols/yahoo/libyahoo2/yahoo_fn.c	18 Jan 2004 20:03:39 -0000	1.1.2.1
+++ kopete/protocols/yahoo/libyahoo2/yahoo_fn.c	26 Jun 2004 00:37:08 -0000	1.1.2.3
@@ -4386,7 +4386,7 @@ struct yahoo_fn yahoo_fntable[5][96] = 
      { XOR, 0x77D64B90, 0 },
      { BITFLD, (long)table_103, 0 },
      { LOOKUP, (long)table_104, 0 },
-     { MULADD, 0x7D1428CB, 0x89F6853D },
+     { MULADD, 0x7D1428CB, 0x3D },
      { XOR, 0x6F872C49, 0 },
      { XOR, 0x2E484655, 0 },
      { MULADD, 0x1E3349F7, 0x41F5 },
