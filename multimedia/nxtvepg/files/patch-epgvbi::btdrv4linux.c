--- epgvbi/btdrv4linux.c.orig	Mon Nov 25 20:30:52 2002
+++ epgvbi/btdrv4linux.c	Mon Jan  6 16:01:47 2003
@@ -195,25 +195,26 @@
         switch (j) {
         case 0: //i map 0 to tuner
           input_id=METEOR_DEV1;
-          input_name ="tuner";
+          input_name = "tuner";
           break;
         case 1:
           input_id=METEOR_DEV0;
-          input_name="video";
+          input_name = "video";
           break;
         case 2:
           input_id=METEOR_DEV_SVIDEO;
-          input_name="svideo";
+          input_name = "svideo";
           break;
         case 3:
           input_id=METEOR_DEV2;
-          input_name ="csvideo";
+          input_name = "csvideo";
           break;
         }
+		
         if (ioctl(fd,METEORSINPUT,&input_id)==0) {
-          pVbiBuf->tv_cards[i].inputs[j].inputID=input_id;
+	      pVbiBuf->tv_cards[i].inputs[j].inputID=input_id;
           pVbiBuf->tv_cards[i].inputs[j].isTuner=(input_id==METEOR_DEV1);
-          strncpy((char*)pVbiBuf->tv_cards[i].inputs[j].name,input_name, DEV_MAX_NAME_LEN);
+          strncpy((char*)pVbiBuf->tv_cards[i].inputs[j].name,input_name, 20);
           pVbiBuf->tv_cards[i].inputs[j].isAvailable=1;
         }
         else
@@ -354,6 +355,14 @@
    #else //  __NetBSD__ || __FreeBSD__
    if (tuner_fd != -1)
    {
+      // unmute tuner
+      int mute_arg = AUDIO_UNMUTE;
+      if (ioctl (tuner_fd, BT848_SAUDIO, &mute_arg) == 0) {
+         dprintf0("Unmuting tuner.\n");
+      }
+      else 
+         SystemErrorMessage_Set(&pSysErrorText, errno, "unmuting the tuner (ioctl AUDIO_UNMUTE)", NULL);
+
       close(tuner_fd);
       tuner_fd = -1;
    }
@@ -433,17 +442,20 @@
    int cardIndex = pVbiBuf->cardIndex;
 
    // XXX TODO: need to set TV norm
-
-   if ((cardIndex<MAX_CARDS) && (inputIdx<MAX_INPUTS))
-     if (pVbiBuf->tv_cards[cardIndex].isAvailable)
-       if (!pVbiBuf->tv_cards[cardIndex].isBusy)
-         if (pVbiBuf->tv_cards[cardIndex].inputs[inputIdx].isAvailable) {
-           result=TRUE;
-           pVbiBuf->inputIndex=inputIdx;
-           if (pVbiBuf->tv_cards[cardIndex].inputs[inputIdx].isTuner)
-             *pIsTuner=TRUE;
-
-         }
+	if ((cardIndex<MAX_CARDS) && (inputIdx<MAX_INPUTS)) {
+		if (pVbiBuf->tv_cards[cardIndex].isAvailable) {
+			if (!pVbiBuf->tv_cards[cardIndex].isBusy) {
+				if (pVbiBuf->tv_cards[cardIndex].inputs[inputIdx].isAvailable) {
+					result=TRUE;
+					pVbiBuf->inputIndex=inputIdx;
+					if (pVbiBuf->tv_cards[cardIndex].inputs[inputIdx].isTuner) {
+						*pIsTuner=TRUE;
+					}
+
+				}
+			}
+		}
+	}
 
    return result;
 #endif
@@ -522,17 +534,27 @@
       {
          if (tuner_fd == -1)
          {
+           int mute_arg = AUDIO_MUTE;
            assert(devKeptOpen == FALSE);
            if (!pVbiBuf->tv_cards[pVbiBuf->cardIndex].isBusy) {
              sprintf(devName, TUNERNAME "%u", pVbiBuf->cardIndex);
              tuner_fd = open(devName, O_RDONLY);
-             if (tuner_fd == -1)
+             if (tuner_fd == -1) {
                SystemErrorMessage_Set(&pSysErrorText, errno, "open tuner device  ", devName, ": ", NULL);
+			  }
              else
                dprintf1("BtDriver-TuneChannel: opened tuner device, fd=%d\n", tuner_fd);
            }
            else
              SystemErrorMessage_Set(&pSysErrorText, 0, "tuner device ", devName, " is busy (-> close other video apps)", NULL);
+
+           // mute tuner
+           if (ioctl (tuner_fd, BT848_SAUDIO, &mute_arg) == 0) {
+              dprintf0("Muting tuner.\n");
+           }
+           else
+              SystemErrorMessage_Set(&pSysErrorText, errno, "muting the tuner (ioctl AUDIO_UNMUTE)", NULL);
+
          }
          if (tuner_fd != -1)
          {
@@ -553,6 +575,7 @@
             }
             else
                devKeptOpen = TRUE;
+			   
          }
       }
    }
@@ -1180,9 +1203,14 @@
    uint  line;
 
    #if defined(__NetBSD__) || defined(__FreeBSD__)
-   // wait 10 seconds for the read to complete. After this time, close
+   // wait 180 seconds for the read to complete. After this time, close
    // dev/vbi in the signal handler, avoiding endless blocking
-   alarm(10);
+   
+   // Changed to 180 because of channel gap at my tv provider: [Simon]
+   // E2 E3 ... E12 <huge gap> S2 ... S?
+   //
+   // Otherwisely, the application exits with an alarm during the gap
+   alarm(180);
    #endif
 
    stat = read(vbi_fdin, rawbuf, bufSize);
@@ -1232,7 +1260,7 @@
   int result=FALSE;
   int c;
   int close_fd=0;
-
+  
   width=100;
   height=100;
   geo.rows = height;
@@ -1319,6 +1347,7 @@
     }
 
     ioctl(tuner_fd, TVTUNER_SETTYPE, &c);
+
     if (close_fd) {
       close(tuner_fd);
       tuner_fd=-1;
