--- cutter.c.orig
+++ cutter.c
@@ -83,7 +83,18 @@ void cCuttingThread::Action(void)
      int LastIFrame = 0;
      toMarks.Add(0);
      toMarks.Save();
+#ifdef __FreeBSD__
+     // XXX save thread stack space
+     uchar *buffer = MALLOC(uchar, MAXFRAMESIZE);
+     uchar *buffer2 = MALLOC(uchar, MAXFRAMESIZE);
+     if (buffer == NULL || buffer2 == NULL) {
+        free(buffer);
+        error = "malloc";
+        return;
+        }
+#else
      uchar buffer[MAXFRAMESIZE], buffer2[MAXFRAMESIZE];
+#endif
      int Length2;
      bool CheckForSeamlessStream = false;
      bool LastMark = false;
@@ -108,7 +119,7 @@ void cCuttingThread::Action(void)
                  CurrentFileNumber = FileNumber;
                  }
               if (fromFile) {
-                 int len = ReadFrame(fromFile, buffer,  Length, sizeof(buffer));
+                 int len = ReadFrame(fromFile, buffer,  Length, MAXFRAMESIZE);
                  if (len < 0) {
                     error = "ReadFrame";
                     break;
@@ -193,7 +204,7 @@ void cCuttingThread::Action(void)
                     if (FileNumber != CurrentFileNumber)
                        fromFile = fromFileName->SetOffset(FileNumber, FileOffset);
                     if (fromFile) {
-                       int len = ReadFrame(fromFile, buffer2, Length2, sizeof(buffer2));
+                       int len = ReadFrame(fromFile, buffer2, Length2, MAXFRAMESIZE);
                        if (len >= 0 && len == Length2)
                           CheckForSeamlessStream = true;
                        }
@@ -216,6 +227,10 @@ void cCuttingThread::Action(void)
               }
            }
      Recordings.TouchUpdate();
+#ifdef __FreeBSD__
+     free(buffer);
+     free(buffer2);
+#endif
      }
   else
      esyslog("no editing marks found!");
--- thread.c.orig
+++ thread.c
@@ -242,7 +242,7 @@ void cThread::SetPriority(int Priority)
 void cThread::SetIOPriority(int Priority)
 {
 #ifdef __FreeBSD__
-  esyslog("ERROR: syscall(SYS_ioprio_set ...) unsupported on FreeBSD");
+  // esyslog("ERROR: syscall(SYS_ioprio_set ...) unsupported on FreeBSD");
 #else
   if (syscall(SYS_ioprio_set, 1, 0, (Priority & 0xff) | (2 << 13)) < 0) // best effort class
      LOG_ERROR;
