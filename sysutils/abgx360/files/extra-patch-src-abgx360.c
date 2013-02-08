--- src/abgx360.c.orig	2012-05-07 10:23:05.997665157 -0400
+++ src/abgx360.c	2012-05-07 10:26:22.824665331 -0400
@@ -2220,82 +2220,8 @@
 
 int sendcdb(int direction, unsigned char *dataBuffer, unsigned long dataBufferSize,
             unsigned char *cdb, unsigned char cdbLen, bool checkreturnlength) {
-    int i;
-    union ccb *ccb = NULL;
-    ccb = cam_getccb(cam_dev);
-    if (ccb == NULL) {
-        color(red);
-        printf("ERROR: Memory allocation of CAM CCB failed! Game over man... Game over!%s", newline);
-        color(normal);
-      exit(1);
-    }
-    cam_fill_csio(&ccb->csio,
-                  1,                  // retries
-                  NULL,               // cbfcnp      // ?
-                  direction,          // flags
-                  MSG_SIMPLE_Q_TAG,   // tag_action  // What to do for tag queueing - ?
-                  dataBuffer,         // data_ptr
-                  dataBufferSize,     // dxfer_len
-                  96,                 // sense_len   // Number of bytes to autosense - ?
-                  cdbLen,             // cdb_len
-                  dvdtimeout * 1000); // timeout (ms)
-    memcpy(ccb->csio.cdb_io.cdb_bytes, cdb, cdbLen);
-    int rv = cam_send_ccb(cam_dev, ccb);
-    if (debug) {
-        printf("ccb->csio.sense_data.error_code = %02X%s", ccb->csio.sense_data.error_code, newline);
-        printf("ccb->csio.sense_data.segment = %02X%s", ccb->csio.sense_data.segment, newline);
-        printf("ccb->csio.sense_data.flags = %02X%s", ccb->csio.sense_data.flags, newline);
-        printf("ccb->csio.sense_data.info = %02X%02X%02X%02X%s", ccb->csio.sense_data.info[0], ccb->csio.sense_data.info[1], ccb->csio.sense_data.info[2], ccb->csio.sense_data.info[3], newline);
-        printf("ccb->csio.sense_data.extra_len = %02X%s", ccb->csio.sense_data.extra_len, newline);
-        printf("ccb->csio.sense_data.cmd_spec_info = %02X%02X%02X%02X%s", ccb->csio.sense_data.cmd_spec_info[0], ccb->csio.sense_data.cmd_spec_info[1], ccb->csio.sense_data.cmd_spec_info[2], ccb->csio.sense_data.cmd_spec_info[3], newline);
-        printf("ccb->csio.sense_data.add_sense_code = %02X%s", ccb->csio.sense_data.add_sense_code, newline);
-        printf("ccb->csio.sense_data.add_sense_code_qual = %02X%s", ccb->csio.sense_data.add_sense_code_qual, newline);
-        printf("ccb->csio.sense_data.fru = %02X%s", ccb->csio.sense_data.fru, newline);
-        printf("ccb->csio.sense_data.sense_key_spec = %02X%02X%02X%s", ccb->csio.sense_data.sense_key_spec[0], ccb->csio.sense_data.sense_key_spec[1], ccb->csio.sense_data.sense_key_spec[2], newline);
-        printf("ccb->csio.sense_data.extra_bytes = ");
-        for (i=0;i<14;i++) printf("%02X", ccb->csio.sense_data.extra_bytes[i]);
-        printf("%s", newline);
-    }
-    sprintf(sense, "%02X/%02X/%02X", ccb->csio.sense_data.flags, ccb->csio.sense_data.add_sense_code, ccb->csio.sense_data.add_sense_code_qual); // not 100% sure about this
-    if (rv == -1) {
-        if (debug || testingdvd) {
-            color(red);
-            printf("ERROR: cam_send_ccb returned -1! (%s)%s", strerror(errno), newline);
-            color(normal);
-        }
-	  return 1;
-    }
-    // check sense code (00/00/00 or 01/xx/xx is ok)
-    if (ccb->csio.sense_data.flags != 0x00 || ccb->csio.sense_data.add_sense_code != 0x00 || ccb->csio.sense_data.add_sense_code_qual != 0x00) {
-        if (ccb->csio.sense_data.flags != 0x01) {
-            if (debug || testingdvd) {
-                color(red);
-                printf("sense: %s (%s)%s", sense, cdberror(sense), newline);
-                color(normal);
-            }
-          return 1;
-        }
-        else if (debug || testingdvd) {
-            color(yellow);
-            printf("sense: %s (%s)%s", sense, cdberror(sense), newline);
-            color(normal);
-        }
-    }
-    else if (debug) printf("sense: %s (%s)%s", sense, cdberror(sense), newline);
-    // todo: check that the proper amount of bytes were returned
-    
-    if ((ccb->ccb_h.status & CAM_STATUS_MASK) != CAM_REQ_CMP) {
-        // error occured (includes sense errors - not sure if 01/xx/xx will trigger this or not)
-        if (debug || testingdvd) {
-            color(red);
-            printf("ERROR: ccb->ccb_h.status (%08X) & CAM_STATUS_MASK (%08X) [%08X] != CAM_REQ_CMP (%08X)%s",
-                   ccb->ccb_h.status, CAM_STATUS_MASK, ccb->ccb_h.status & CAM_STATUS_MASK, CAM_REQ_CMP, newline);
-            color(normal);
-        }
-	  return 1;
-    }
-    cam_freeccb(ccb);
-  return 0;
+    sprintf(sense, "UU/OO/SS"); // temp -- gives sense error "Unsupported Operat
+  return 1; // temp
 }
 
 #elif (defined(__OpenBSD__) || defined(__NetBSD__))
