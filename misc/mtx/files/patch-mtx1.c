--- mtxl.c.orig	2023-06-08 15:12:53 UTC
+++ mtxl.c
@@ -23,7 +23,7 @@
 
 /*
  *	FatalError: changed Feb. 2000 elg@badtux.org to eliminate a buffer
- *	overflow :-(. That could be important if mtxl is SUID for some reason. 
+ *	overflow :-(. That could be important if mtxl is SUID for some reason.
 */
 
 #include "mtx.h"
@@ -34,7 +34,7 @@
 /* #define DEBUG_MODE_SENSE 1 */
 /* #define DEBUG */
 /* #define DEBUG_SCSI */
-#define __WEIRD_CHAR_SUPPRESS 1 
+#define __WEIRD_CHAR_SUPPRESS 1
 
 /* zap the following define when we finally add real import/export support */
 #define IMPORT_EXPORT_HACK 1 /* for the moment, import/export == storage */
@@ -97,7 +97,7 @@ Inquiry_T *RequestInquiry(DEVICE_TYPE fd, RequestSense
 	Inquiry_T *Inquiry;
 	CDB_T CDB;
 
-	Inquiry = (Inquiry_T *) xmalloc(sizeof(Inquiry_T));  
+	Inquiry = (Inquiry_T *) xmalloc(sizeof(Inquiry_T));
 
 	CDB[0] = 0x12;		/* INQUIRY */
 	CDB[1] = 0;			/* EVPD = 0 */
@@ -277,10 +277,10 @@ int max(int x, int y)
 
 
 /* Okay, this is a hack for the NSM modular jukebox series, which
- * uses the "SEND DIAGNOSTIC" command to do shit. 
+ * uses the "SEND DIAGNOSTIC" command to do shit.
  */
 
-int SendNSMHack(DEVICE_TYPE MediumChangerFD, NSM_Param_T *nsm_command, 
+int SendNSMHack(DEVICE_TYPE MediumChangerFD, NSM_Param_T *nsm_command,
 		int param_len, int timeout)
 {
 	CDB_T CDB;
@@ -359,7 +359,7 @@ NSM_Result_T *RecNSMHack(	DEVICE_TYPE MediumChangerFD,
 
 /* Routine to inventory the library. Needed by, e.g., some Breece Hill
  * loaders. Sends an INITIALIZE_ELEMENT_STATUS command. This command
- * has no parameters, such as a range to scan :-(. 
+ * has no parameters, such as a range to scan :-(.
  */
 
 int Inventory(DEVICE_TYPE MediumChangerFD)
@@ -367,7 +367,7 @@ int Inventory(DEVICE_TYPE MediumChangerFD)
 	CDB_T	CDB;
 
 	/* okay, now for the command: */
-	CDB[0] = 0x07; 
+	CDB[0] = 0x07;
 	CDB[1] = CDB[2] = CDB[3] = CDB[4] = CDB[5] = 0;
 
 	/* set us a very long timeout, sigh... */
@@ -391,8 +391,8 @@ int Inventory(DEVICE_TYPE MediumChangerFD)
 /* Routine to read the Mode Sense Element Address Assignment Page */
 /* We try to read the page. If we can't read the page, we return NULL.
  * Our caller really isn't too worried about why we could not read the
- * page, it will simply default to some kind of default values. 
- */ 
+ * page, it will simply default to some kind of default values.
+ */
 ElementModeSense_T *ReadAssignmentPage(DEVICE_TYPE MediumChangerFD)
 {
 	CDB_T CDB;
@@ -402,7 +402,7 @@ ElementModeSense_T *ReadAssignmentPage(DEVICE_TYPE Med
 
 	/* okay, now for the command: */
 	CDB[0] = 0x1A; /* Mode Sense(6) */
-	CDB[1] = 0x08; 
+	CDB[1] = 0x08;
 	CDB[2] = 0x1D; /* Mode Sense Element Address Assignment Page */
 	CDB[3] = 0;
 	CDB[4] = 136; /* allocation_length... */
@@ -479,7 +479,7 @@ ElementModeSense_T *ReadAssignmentPage(DEVICE_TYPE Med
 		((int)sense_page->NumStorageHi << 8) + sense_page->NumStorageLo;
 
 	retval->ImportExportStart =
-		((int)sense_page->ImportExportStartHi << 8) + sense_page->ImportExportStartLo; 
+		((int)sense_page->ImportExportStartHi << 8) + sense_page->ImportExportStartLo;
 
 	retval->NumImportExport =
 		((int)sense_page->NumImportExportHi << 8) + sense_page->NumImportExportLo;
@@ -491,7 +491,7 @@ ElementModeSense_T *ReadAssignmentPage(DEVICE_TYPE Med
 		((int)sense_page->NumDataTransferHi << 8) + sense_page->NumDataTransferLo;
 
 	/* allocate a couple spares 'cause some HP autochangers and maybe others
-	* don't properly report the robotics arm(s) count here... 
+	* don't properly report the robotics arm(s) count here...
 	*/
 	retval->NumElements =
 		retval->NumStorage+retval->NumImportExport +
@@ -546,7 +546,7 @@ static ElementStatus_T *AllocateElementData(ElementMod
 
 	retval->DataTransferElementAddress =
 		(int *)xzmalloc(sizeof(int) * (mode_sense->NumDataTransfer + 1));
-	retval->DataTransferElementSourceStorageElementNumber = 
+	retval->DataTransferElementSourceStorageElementNumber =
 		(int *)xzmalloc(sizeof(int) * (mode_sense->NumDataTransfer + 1));
 	retval->DataTransferPrimaryVolumeTag =
 		(barcode *)xzmalloc(sizeof(barcode) * (mode_sense->NumDataTransfer + 1));
@@ -559,11 +559,11 @@ static ElementStatus_T *AllocateElementData(ElementMod
 	retval->StorageElementAddress =
 		(int *)xzmalloc(sizeof(int) * (mode_sense->NumStorage + 1));
 	retval->StorageElementIsImportExport =
-		(boolean *)xzmalloc(sizeof(boolean) * (mode_sense->NumStorage + 1));
+		(bool *)xzmalloc(sizeof(bool) * (mode_sense->NumStorage + 1));
 	retval->StorageElementFull =
-		(boolean *)xzmalloc(sizeof(boolean) * (mode_sense->NumStorage + 1));
+		(bool *)xzmalloc(sizeof(bool) * (mode_sense->NumStorage + 1));
 	retval->DataTransferElementFull =
-		(boolean *)xzmalloc(sizeof(boolean) * (mode_sense->NumDataTransfer + 1));
+		(bool *)xzmalloc(sizeof(bool) * (mode_sense->NumDataTransfer + 1));
 
 	return retval; /* sigh! */
 }
@@ -584,14 +584,14 @@ void copy_barcode(unsigned char *src, unsigned char *d
 
 		dest++;
 	}
-	*dest = 0; /* null-terminate */ 
+	*dest = 0; /* null-terminate */
 }
 
 /* This #%!@# routine has more parameters than I can count! */
 static unsigned char *SendElementStatusRequestActual(
 					DEVICE_TYPE MediumChangerFD,
 					RequestSense_T *RequestSense,
-					Inquiry_T *inquiry_info, 
+					Inquiry_T *inquiry_info,
 					SCSI_Flags_T *flags,
 					int ElementStart,
 					int NumElements,
@@ -599,14 +599,14 @@ static unsigned char *SendElementStatusRequestActual(
 					)
 {
 	CDB_T CDB;
-	boolean is_attached = false;
+	bool is_attached = false;
 
 	unsigned char *DataBuffer; /* size of data... */
 
 #ifdef HAVE_GET_ID_LUN
 	scsi_id_t *scsi_id;
 #endif
-	if (inquiry_info->MChngr && 
+	if (inquiry_info->MChngr &&
 		inquiry_info->PeripheralDeviceType != MEDIUM_CHANGER_TYPE)
 	{
 		is_attached = true;
@@ -614,7 +614,7 @@ static unsigned char *SendElementStatusRequestActual(
 
 	if (flags->no_attached)
 	{
-		/* override, sigh */ 
+		/* override, sigh */
 		is_attached = false;
 	}
 
@@ -630,11 +630,11 @@ static unsigned char *SendElementStatusRequestActual(
 
 	if (is_attached)
 	{
-		CDB[0] = 0xB4;  /* whoops, READ_ELEMENT_STATUS_ATTACHED! */ 
+		CDB[0] = 0xB4;  /* whoops, READ_ELEMENT_STATUS_ATTACHED! */
 	}
 
 #ifdef HAVE_GET_ID_LUN
-	CDB[1] = (scsi_id->lun << 5) | ((flags->no_barcodes) ? 
+	CDB[1] = (scsi_id->lun << 5) | ((flags->no_barcodes) ?
 		0 : 0x10) | flags->elementtype;  /* Lun + VolTag + Type code */
 	free(scsi_id);
 #else
@@ -674,7 +674,7 @@ static unsigned char *SendElementStatusRequestActual(
 
 		/*
 			First see if we have sense key of 'illegal request',
-			additional sense code of '24', additional sense qualfier of 
+			additional sense code of '24', additional sense qualfier of
 			'0', and field in error of '4'. This means that we issued a request
 			w/bar code reader and did not have one, thus must re-issue the request
 			w/out barcode :-(.
@@ -719,14 +719,14 @@ static unsigned char *SendElementStatusRequestActual(
 	PrintRequestSense(RequestSense); /* see what it sez :-(. */
 	fprintf(stderr,"Data:\n");
 	PrintHex(2, DataBuffer, 40);
-#endif  
+#endif
 	return DataBuffer; /* we succeeded! */
 }
 
 
 unsigned char *SendElementStatusRequest(DEVICE_TYPE MediumChangerFD,
 										RequestSense_T *RequestSense,
-										Inquiry_T *inquiry_info, 
+										Inquiry_T *inquiry_info,
 										SCSI_Flags_T *flags,
 										int ElementStart,
 										int NumElements,
@@ -747,7 +747,7 @@ unsigned char *SendElementStatusRequest(DEVICE_TYPE Me
 	/*
 		One weird loader wants either 8 or BYTE_COUNT_OF_REPORT
 		values for the ALLOCATION_LENGTH. Give it what it wants
-		if we get an Sense Key of 05 Illegal Request with a 
+		if we get an Sense Key of 05 Illegal Request with a
 		CDB position of 7 as the field in error.
 	*/
 
@@ -879,7 +879,7 @@ static void ParseElementStatus(	int *EmptyStorageEleme
 		{
 			/* TransportElementDescriptor =
 			(TransportElementDescriptor_T *) DataPointer; */
-			memcpy(&TEBuf, DataPointer, 
+			memcpy(&TEBuf, DataPointer,
 				(TransportElementDescriptorLength <= sizeof(TEBuf)) ?
 					TransportElementDescriptorLength  :
 					sizeof(TEBuf));
@@ -906,7 +906,7 @@ static void ParseElementStatus(	int *EmptyStorageEleme
 			case MediumTransportElement:
 				ElementStatus->TransportElementAddress = BigEndian16(TransportElementDescriptor->ElementAddress);
 #ifdef DEBUG
-				fprintf(stderr,"TransportElementAddress=%d\n",ElementStatus->TransportElementAddress); 
+				fprintf(stderr,"TransportElementAddress=%d\n",ElementStatus->TransportElementAddress);
 #endif
 				break;
 
@@ -933,7 +933,7 @@ static void ParseElementStatus(	int *EmptyStorageEleme
 				ElementStatus->StorageElementFull[ImportExportIndex] =
 					TransportElementDescriptor->Full;
 
-				if ( (TransportElementDescriptorLength > 11) && 
+				if ( (TransportElementDescriptorLength > 11) &&
 					(ElementStatusPage->VolBits & E2_AVOLTAG))
 				{
 					copy_barcode(TransportElementDescriptor->AlternateVolumeTag,
@@ -942,8 +942,8 @@ static void ParseElementStatus(	int *EmptyStorageEleme
 				else
 				{
 					ElementStatus->AlternateVolumeTag[ImportExportIndex][0] = 0;  /* null string. */;
-				} 
-				if ((TransportElementDescriptorLength > 11) && 
+				}
+				if ((TransportElementDescriptorLength > 11) &&
 					(ElementStatusPage->VolBits & E2_PVOLTAG))
 				{
 					copy_barcode(TransportElementDescriptor->PrimaryVolumeTag,
@@ -964,8 +964,8 @@ static void ParseElementStatus(	int *EmptyStorageEleme
 				fprintf(stderr,"StorageElementCount=%d  ElementAddress = %d ",ElementStatus->StorageElementCount,BigEndian16(TransportElementDescriptor->ElementAddress));
 #endif
 				/* ATL/Exabyte kludge -- skip slots that aren't installed :-( */
-				if (TransportElementDescriptor->AdditionalSenseCode==0x83 && 
-					TransportElementDescriptor->AdditionalSenseCodeQualifier==0x02) 
+				if (TransportElementDescriptor->AdditionalSenseCode==0x83 &&
+					TransportElementDescriptor->AdditionalSenseCodeQualifier==0x02)
 					continue;
 
 				ElementStatus->StorageElementAddress[ElementStatus->StorageElementCount] =
@@ -983,7 +983,7 @@ static void ParseElementStatus(	int *EmptyStorageEleme
 						ElementStatus->StorageElementCount; /* slot idx. */
 					/*   ElementStatus->StorageElementAddress[ElementStatus->StorageElementCount]; */
 				}
-				if ((TransportElementDescriptorLength >  11) && 
+				if ((TransportElementDescriptorLength >  11) &&
 					(ElementStatusPage->VolBits & E2_AVOLTAG))
 				{
 					copy_barcode(TransportElementDescriptor->AlternateVolumeTag,
@@ -992,8 +992,8 @@ static void ParseElementStatus(	int *EmptyStorageEleme
 				else
 				{
 					ElementStatus->AlternateVolumeTag[ElementStatus->StorageElementCount][0]=0;  /* null string. */;
-				} 
-				if ((TransportElementDescriptorLength > 11) && 
+				}
+				if ((TransportElementDescriptorLength > 11) &&
 					(ElementStatusPage->VolBits & E2_PVOLTAG))
 				{
 					copy_barcode(TransportElementDescriptor->PrimaryVolumeTag,
@@ -1006,9 +1006,9 @@ static void ParseElementStatus(	int *EmptyStorageEleme
 
 				ElementStatus->StorageElementCount++;
 				/*
-					Note that the original mtx had no check here for 
+					Note that the original mtx had no check here for
 					buffer overflow, though some drives might mistakingly
-					do one... 
+					do one...
 				*/
 
 				if (ElementStatus->StorageElementCount > mode_sense->NumStorage)
@@ -1030,33 +1030,33 @@ static void ParseElementStatus(	int *EmptyStorageEleme
 				report that they have a 2nd tape drive when they don't. We
 				could generalize this in an ideal world, but my attempt to
 				do so failed with dual-drive Exabyte tape libraries that
-				*DID* have the second drive. Sigh. 
+				*DID* have the second drive. Sigh.
 				*/
-				if (TransportElementDescriptor->AdditionalSenseCode==0x83 && 
+				if (TransportElementDescriptor->AdditionalSenseCode==0x83 &&
 					TransportElementDescriptor->AdditionalSenseCodeQualifier==0x04)
 				{
 					continue;
 				}
 
 				/*	generalize it. Does it work? Let's try it! */
-				/*	
+				/*
 					No, dammit, following does not work on dual-drive Exabyte
 					'cause if a tape is in the drive, it sets the AdditionalSense
 					code to something (sigh).
 				*/
 				/* if (TransportElementDescriptor->AdditionalSenseCode!=0)
 					continue;
-				*/ 
+				*/
 
 				ElementStatus->DataTransferElementAddress[ElementStatus->DataTransferElementCount] =
 					BigEndian16(TransportElementDescriptor->ElementAddress);
-				ElementStatus->DataTransferElementFull[ElementStatus->DataTransferElementCount] = 
+				ElementStatus->DataTransferElementFull[ElementStatus->DataTransferElementCount] =
 					TransportElementDescriptor->Full;
 				ElementStatus->DataTransferElementSourceStorageElementNumber[ElementStatus->DataTransferElementCount] =
 					BigEndian16(TransportElementDescriptor->SourceStorageElementAddress);
 
 #if DEBUG
-				fprintf(stderr, "%d: ElementAddress = %d, Full = %d, SourceElement = %d\n", 
+				fprintf(stderr, "%d: ElementAddress = %d, Full = %d, SourceElement = %d\n",
 						ElementStatus->DataTransferElementCount,
 						ElementStatus->DataTransferElementAddress[ElementStatus->DataTransferElementCount],
 						ElementStatus->DataTransferElementFull[ElementStatus->DataTransferElementCount],
@@ -1115,17 +1115,17 @@ static void ParseElementStatus(	int *EmptyStorageEleme
 /*
  * We no longer do the funky trick to figure out ALLOCATION_LENGTH.
  * Instead, we use the SCSI Generic command rather than SEND_SCSI_COMMAND
- * under Linux, which gets around the @#%@ 4k buffer size in Linux. 
+ * under Linux, which gets around the @#%@ 4k buffer size in Linux.
  * We still have the restriction that Linux cuts off the last two
  * bytes of the SENSE DATA (Q#@$%@#$^ Linux!). Which means that the
- * verbose widget won't work :-(. 
- 
+ * verbose widget won't work :-(.
+
  * We now look for that "attached" bit in the inquiry_info to see whether
  * to use READ_ELEMENT_ATTACHED or plain old READ_ELEMENT. In addition, we
  * look at the device type in the inquiry_info to see whether it is a media
  * changer or tape device, and if it's a media changer device, we ignore the
  * attached bit (one beta tester found an old 4-tape DAT changer that set
- * the attached bit for both the tape device AND the media changer device). 
+ * the attached bit for both the tape device AND the media changer device).
 
 */
 
@@ -1139,7 +1139,7 @@ ElementStatus_T *ReadElementStatus(DEVICE_TYPE MediumC
 	int *EmptyStorageElementAddress; /* [MAX_STORAGE_ELEMENTS]; */
 
 	int empty_idx = 0;
-	boolean is_attached = false;
+	bool is_attached = false;
 	int i,j;
 
 	ElementModeSense_T *mode_sense = NULL;
@@ -1151,7 +1151,7 @@ ElementStatus_T *ReadElementStatus(DEVICE_TYPE MediumC
 
 	if (flags->no_attached)
 	{
-		/* override, sigh */ 
+		/* override, sigh */
 		is_attached = false;
 	}
 
@@ -1181,7 +1181,7 @@ ElementStatus_T *ReadElementStatus(DEVICE_TYPE MediumC
 	ElementStatus->DataTransferElementCount = 0;
 
 	/* first, allocate some empty storage stuff: Note that we pass this
-	* down to ParseElementStatus (sigh!) 
+	* down to ParseElementStatus (sigh!)
 	*/
 
 	EmptyStorageElementAddress = (int *)xzmalloc((mode_sense->NumStorage+1)*sizeof(int));
@@ -1198,7 +1198,7 @@ ElementStatus_T *ReadElementStatus(DEVICE_TYPE MediumC
 	for (i = 0; i < mode_sense->NumDataTransfer; i++)
 	{
 		/* initialize them to an illegal # so that we can fix later... */
-		ElementStatus->DataTransferElementSourceStorageElementNumber[i] = -1; 
+		ElementStatus->DataTransferElementSourceStorageElementNumber[i] = -1;
 	}
 
 	if (flags->querytype == MTX_ELEMENTSTATUS_ORIGINAL)
@@ -1224,7 +1224,7 @@ ElementStatus_T *ReadElementStatus(DEVICE_TYPE MediumC
 			PrintRequestSense(RequestSense);
 #endif
 			FreeElementData(ElementStatus);
-			return NULL; 
+			return NULL;
 		}
 
 #ifdef DEBUG
@@ -1294,7 +1294,7 @@ ElementStatus_T *ReadElementStatus(DEVICE_TYPE MediumC
 			PrintRequestSense(RequestSense);
 #endif
 			FreeElementData(ElementStatus);
-			return NULL; 
+			return NULL;
 		}
 
 #ifdef DEBUG
@@ -1309,7 +1309,7 @@ ElementStatus_T *ReadElementStatus(DEVICE_TYPE MediumC
 
 		/* grr, damned brain dead HP doesn't report that it has any! */
 		if (!mode_sense->NumMediumTransport)
-		{ 
+		{
 			ElementStatus->TransportElementAddress = 0; /* default it sensibly :-(. */
 		}
 		else
@@ -1333,8 +1333,8 @@ ElementStatus_T *ReadElementStatus(DEVICE_TYPE MediumC
 				PrintRequestSense(RequestSense);
 #endif
 				FreeElementData(ElementStatus);
-				return NULL; 
-			} 
+				return NULL;
+			}
 #ifdef DEBUG
 			fprintf(stderr,"Parsing robot arm data\n");
 #endif
@@ -1352,8 +1352,8 @@ ElementStatus_T *ReadElementStatus(DEVICE_TYPE MediumC
 		fprintf(stderr,"Using alternative element status polling method (all elements)\n");
 #endif
 		/* ----------------- ALL Elements ---------------------- */
-		/*	Just keep asking for elements till no more are returned 
-			- increment our starting address as we go acording to the 
+		/*	Just keep asking for elements till no more are returned
+			- increment our starting address as we go acording to the
 			number of elements returned from the last call
 		*/
 
@@ -1370,7 +1370,7 @@ ElementStatus_T *ReadElementStatus(DEVICE_TYPE MediumC
 													mode_sense->MaxReadElementStatusData);
 			if (!DataBuffer)
 			{
-				if (RequestSense->AdditionalSenseCode == 0x21 && 
+				if (RequestSense->AdditionalSenseCode == 0x21 &&
 				RequestSense->AdditionalSenseCodeQualifier == 0x01)
 				{
 					/* Error is invalid element address, we've probably just hit the end */
@@ -1379,8 +1379,8 @@ ElementStatus_T *ReadElementStatus(DEVICE_TYPE MediumC
 
 				/* darn. Free up stuff and return. */
 				FreeElementData(ElementStatus);
-				return NULL; 
-			} 
+				return NULL;
+			}
 
 			nLastEl = nNextEl;
 
@@ -1409,7 +1409,7 @@ ElementStatus_T *ReadElementStatus(DEVICE_TYPE MediumC
 	 *
 	 * Pass1:
 	 *	Translate from raw element # to our translated # (if possible).
-	 *	First, check the SourceStorageElementNumbers against the list of 
+	 *	First, check the SourceStorageElementNumbers against the list of
 	 *	filled slots. If the slots indicated are empty, we accept that list as
 	 *	valid. Otherwise decide the SourceStorageElementNumbers are invalid.
 	 *
@@ -1418,7 +1418,7 @@ ElementStatus_T *ReadElementStatus(DEVICE_TYPE MediumC
 	 *	then we must search for free slots, and assign SourceStorageElementNumbers
 	 *	to those free slots. We happen to already built a list of free
 	 *	slots as part of the process of reading the storage element numbers
-	 *	from the tape. So that's easy enough to do! 
+	 *	from the tape. So that's easy enough to do!
 	 */
 
 #ifdef DEBUG_TAPELIST
@@ -1434,7 +1434,7 @@ ElementStatus_T *ReadElementStatus(DEVICE_TYPE MediumC
 
 	/*
 	 *	Now we re-assign origin slots if the "real" origin slot
-	 *	is obviously defective: 
+	 *	is obviously defective:
 	 */
 	/* pass one: */
 	for (i = 0; i < ElementStatus->DataTransferElementCount; i++)
@@ -1472,12 +1472,12 @@ ElementStatus_T *ReadElementStatus(DEVICE_TYPE MediumC
 	 *	drives will be assigned a -1 (see the initialization loop for
 	 *	EmptyStorageElementAddress above), which will be reported as "slot 0"
 	 *	by the user interface. This is an invalid value, but more useful for us
-	 *	to have than just crapping out here :-(. 
+	 *	to have than just crapping out here :-(.
 	*/
 	empty_idx=0;
 	for (i = 0; i < ElementStatus->DataTransferElementCount; i++)
 	{
-		if (ElementStatus->DataTransferElementFull[i] && 
+		if (ElementStatus->DataTransferElementFull[i] &&
 			ElementStatus->DataTransferElementSourceStorageElementNumber[i] < 0)
 		{
 #ifdef DEBUG_TAPELIST
@@ -1529,7 +1529,7 @@ RequestSense_T *PositionElement(DEVICE_TYPE MediumChan
 
 /* Now the actual media movement routine! */
 RequestSense_T *MoveMedium(	DEVICE_TYPE MediumChangerFD, int SourceAddress,
-							int DestinationAddress, 
+							int DestinationAddress,
 							ElementStatus_T *ElementStatus,
 							Inquiry_T *inquiry_info, SCSI_Flags_T *flags)
 {
@@ -1632,7 +1632,7 @@ RequestSense_T *ExchangeMedium(	DEVICE_TYPE MediumChan
 
 #ifdef DEBUG_EXCHANGE
 	dump_cdb(&CDB,12);
-#endif  
+#endif
 
 	if (SCSI_ExecuteCommand(MediumChangerFD, Output, &CDB, 12,
 							NULL, 0, RequestSense) != 0)
@@ -1676,8 +1676,8 @@ RequestSense_T *Erase(DEVICE_TYPE MediumChangerFD)
 	return NULL;		/* Success! */
 }
 
-/* Routine to send an LOAD/UNLOAD from the MMC/SSC spec to a device. 
- * For tapes and changers this can be used either to eject a tape 
+/* Routine to send an LOAD/UNLOAD from the MMC/SSC spec to a device.
+ * For tapes and changers this can be used either to eject a tape
  * or to eject a magazine (on some Seagate changers, when sent to LUN 1 ).
  * For CD/DVDs this is used to Load or Unload a disc which is required by
  * some media changers.
@@ -1707,8 +1707,8 @@ int LoadUnload(DEVICE_TYPE fd, int bLoad)
 	return 0; /* did do! */
 }
 
-/* Routine to send an START/STOP from the MMC/SSC spec to a device. 
- * For tape drives this may be required prior to using the changer 
+/* Routine to send an START/STOP from the MMC/SSC spec to a device.
+ * For tape drives this may be required prior to using the changer
  * Load or Unload commands.
  * For CD/DVD drives this is used to Load or Unload a disc which may be
  * required by some media changers.
@@ -1732,9 +1732,9 @@ int StartStop(DEVICE_TYPE fd, int bStart)
 	return 0; /* did do! */
 }
 
-/* Routine to send a LOCK/UNLOCK from the SSC/MMC spec to a device. 
+/* Routine to send a LOCK/UNLOCK from the SSC/MMC spec to a device.
  * This can be used to prevent or allow the Tape or CD/DVD from being
- * removed. 
+ * removed.
  */
 
 int LockUnlock(DEVICE_TYPE fd, int bLock)
@@ -1862,7 +1862,7 @@ void PrintRequestSense(RequestSense_T *RequestSense)
 	fprintf(stderr, "mtx: Request Sense: Valid Residual=%s\n", RequestSense->Valid ? Yes : No);
 
 	if (RequestSense->ErrorCode == 0x70)
-	{ 
+	{
 		msg = "Current" ;
 	}
 	else if (RequestSense->ErrorCode == 0x71)

