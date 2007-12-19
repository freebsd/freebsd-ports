--- CONFIG/src/backend/archinfo_x86.c~	Tue Dec 19 06:47:11 2006
+++ CONFIG/src/backend/archinfo_x86.c	Wed Dec 27 12:05:00 2006
@@ -281,6 +281,7 @@
       case  9:
       case 13:
          iret = IntPM;
+         break;
       case 14:
          iret = IntCoreDuo;
          break;
