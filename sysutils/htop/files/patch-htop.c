--- htop.c.orig	2012-10-05 07:55:31.000000000 +0800
+++ htop.c	2013-04-21 03:47:54.882373049 +0800
@@ -126,7 +126,7 @@
    mvaddstr(13, 0, "  Space: tag processes                      F: cursor follows process");
    mvaddstr(14, 0, "      U: untag all processes              + -: expand/collapse tree");
    mvaddstr(15, 0, "   F9 k: kill process/tagged processes  P M T: sort by CPU%, MEM% or TIME");
-   mvaddstr(16, 0, "   ] F7: higher priority (root only)        i: set IO priority");
+   mvaddstr(16, 0, "   ] F7: higher priority (root only)");
    mvaddstr(17, 0, "   [ F8: lower priority (+ nice)            I: invert sort order");
 #if (HAVE_LIBHWLOC || HAVE_NATIVE_AFFINITY)
    if (pl->cpuCount > 1)
@@ -146,7 +146,7 @@
    mvaddstr(13, 0, "  Space"); mvaddstr(13,40, "    F");
    mvaddstr(14, 0, "      U"); mvaddstr(14,40, "  + -");
    mvaddstr(15, 0, "   F9 k"); mvaddstr(15,40, "P M T");
-   mvaddstr(16, 0, "   ] F7"); mvaddstr(16,40, "    i");
+   mvaddstr(16, 0, "   ] F7");
    mvaddstr(17, 0, "   [ F8"); mvaddstr(17,40, "    I");
                                mvaddstr(18,40, " F6 >");
 #if (HAVE_LIBHWLOC || HAVE_NATIVE_AFFINITY)
@@ -850,7 +850,7 @@
          ((Object*)sortPanel)->delete((Object*)sortPanel);
          refreshTimeout = 0;
          break;
-      }
+      }/*
       case 'i':
       {
          Process* p = (Process*) Panel_getSelected(panel);
@@ -869,7 +869,7 @@
          ProcessList_printHeader(pl, Panel_getHeader(panel));
          refreshTimeout = 0;
          break;
-      }
+      }*/
       case 'I':
       {
          refreshTimeout = 0;
