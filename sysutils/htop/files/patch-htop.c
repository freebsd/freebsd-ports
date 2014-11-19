--- htop.c.orig	2014-10-19 02:15:19.000000000 +0800
+++ htop.c	2014-10-19 02:17:10.000000000 +0800
@@ -96,7 +96,6 @@
 #if (HAVE_LIBHWLOC || HAVE_NATIVE_AFFINITY)
    { .key = "      a: ", .info = "set CPU affinity" },
 #endif
-   { .key = "      i: ", .info = "set IO prority" },
    { .key = "      l: ", .info = "list open files with lsof" },
    { .key = "      s: ", .info = "trace syscalls with strace" },
    { .key = "         ", .info = "" },
@@ -856,25 +855,6 @@
          }
          break;
       }
-      case 'i':
-      {
-         Process* p = (Process*) Panel_getSelected(panel);
-         if (!p) break;
-         IOPriority ioprio = p->ioPriority;
-         Panel* ioprioPanel = IOPriorityPanel_new(ioprio);
-         const char* fuFunctions[] = {"Set    ", "Cancel ", NULL};
-         void* set = pickFromVector(panel, ioprioPanel, 21, headerHeight, fuFunctions, defaultBar, header);
-         if (set) {
-            IOPriority ioprio = IOPriorityPanel_getIOPriority(ioprioPanel);
-            bool ok = foreachProcess(panel, (ForeachProcessFn) Process_setIOPriority, (size_t) ioprio, NULL);
-            if (!ok)
-               beep();
-         }
-         Panel_delete((Object*)ioprioPanel);
-         ProcessList_printHeader(pl, Panel_getHeader(panel));
-         refreshTimeout = 0;
-         break;
-      }
       case 'I':
       {
          refreshTimeout = 0;
