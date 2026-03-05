--- mtx.h.orig	2023-06-08 15:05:44 UTC
+++ mtx.h
@@ -7,7 +7,7 @@
 
 	$Date: 2008-08-19 03:03:38 -0700 (Tue, 19 Aug 2008) $
 	$Revision: 193 $
-	See mtx.c for licensing information. 
+	See mtx.c for licensing information.
 
 */
 
@@ -68,6 +68,9 @@
 #  include <sys/param.h>
 #endif
 
+#if HAVE_STDBOOL_H
+#include <stdbool.h>
+#endif
 /* Now greatly modified to use GNU Autoconf stuff: */
 /* If we use the 'sg' interface, like Linux, do this: */
 #if HAVE_SCSI_SG_H
@@ -148,7 +151,7 @@ typedef dsreq_t *DEVICE_TYPE; /* 64-bit pointers/32bit
 #endif /* VMS protect. */
 
 /* Do a test for LITTLE_ENDIAN_BITFIELDS. Use WORDS_BIGENDIAN as set
- * by configure: 
+ * by configure:
  */
 
 #if WORDS_BIGENDIAN
@@ -183,7 +186,7 @@ typedef dsreq_t *DEVICE_TYPE; /* 64-bit pointers/32bit
 #undef S_VOLUME_OVERFLOW
 #endif
 
-/* Note: These are only used for defaults for when we don't have 
+/* Note: These are only used for defaults for when we don't have
  * the element assignment mode page to tell us real amount...
  */
 #define MAX_STORAGE_ELEMENTS 64 /* for the BIG jukeboxes! */
@@ -212,18 +215,11 @@ typedef struct SCSI_Flags_Struct
 }	SCSI_Flags_T;
 
 #ifdef _MSC_VER
-typedef unsigned char boolean;
-
-#define false   0
-#define true    1
-
 typedef unsigned char Direction_T;
 
 #define Input   0
 #define Output  1
 #else
-typedef enum { false, true } boolean;
-
 typedef enum { Input, Output } Direction_T;
 #endif
 
@@ -237,66 +233,66 @@ typedef struct Inquiry
   unsigned char PeripheralDeviceType:5;			/* Byte 0 Bits 0-4 */
   unsigned char PeripheralQualifier:3;			/* Byte 0 Bits 5-7 */
   unsigned char DeviceTypeModifier:7;			/* Byte 1 Bits 0-6 */
-  boolean RMB:1;					/* Byte 1 Bit 7 */
+  bool RMB:1;					/* Byte 1 Bit 7 */
   unsigned char ANSI_ApprovedVersion:3;			/* Byte 2 Bits 0-2 */
   unsigned char ECMA_Version:3;				/* Byte 2 Bits 3-5 */
   unsigned char ISO_Version:2;				/* Byte 2 Bits 6-7 */
   unsigned char ResponseDataFormat:4;			/* Byte 3 Bits 0-3 */
   unsigned char :2;					/* Byte 3 Bits 4-5 */
-  boolean TrmIOP:1;					/* Byte 3 Bit 6 */
-  boolean AENC:1;					/* Byte 3 Bit 7 */
+  bool TrmIOP:1;					/* Byte 3 Bit 6 */
+  bool AENC:1;					/* Byte 3 Bit 7 */
 #else
   unsigned char PeripheralQualifier:3;			/* Byte 0 Bits 5-7 */
   unsigned char PeripheralDeviceType:5;			/* Byte 0 Bits 0-4 */
-  boolean RMB:1;					/* Byte 1 Bit 7 */
+  bool RMB:1;					/* Byte 1 Bit 7 */
   unsigned char DeviceTypeModifier:7;			/* Byte 1 Bits 0-6 */
   unsigned char ISO_Version:2;				/* Byte 2 Bits 6-7 */
   unsigned char ECMA_Version:3;				/* Byte 2 Bits 3-5 */
   unsigned char ANSI_ApprovedVersion:3;			/* Byte 2 Bits 0-2 */
-  boolean AENC:1;					/* Byte 3 Bit 7 */
-  boolean TrmIOP:1;					/* Byte 3 Bit 6 */
+  bool AENC:1;					/* Byte 3 Bit 7 */
+  bool TrmIOP:1;					/* Byte 3 Bit 6 */
   unsigned char :2;					/* Byte 3 Bits 4-5 */
   unsigned char ResponseDataFormat:4;			/* Byte 3 Bits 0-3 */
 #endif
   unsigned char AdditionalLength;			/* Byte 4 */
   unsigned char :8;					/* Byte 5 */
 #ifdef LITTLE_ENDIAN_BITFIELDS
-  boolean ADDR16:1;                                    /* Byte 6 bit 0 */
-  boolean Obs6_1:1;                                    /* Byte 6 bit 1 */
-  boolean Obs6_2:1; /* obsolete */                     /* Byte 6 bit 2 */
-  boolean MChngr:1; /* Media Changer */                /* Byte 6 bit 3 */
-  boolean MultiP:1;                                    /* Byte 6 bit 4 */
-  boolean VS:1;                                        /* Byte 6 bit 5 */
-  boolean EncServ:1;                                   /* Byte 6 bit 6 */
-  boolean BQue:1;                                      /* Byte 6 bit 7 */
+  bool ADDR16:1;                                    /* Byte 6 bit 0 */
+  bool Obs6_1:1;                                    /* Byte 6 bit 1 */
+  bool Obs6_2:1; /* obsolete */                     /* Byte 6 bit 2 */
+  bool MChngr:1; /* Media Changer */                /* Byte 6 bit 3 */
+  bool MultiP:1;                                    /* Byte 6 bit 4 */
+  bool VS:1;                                        /* Byte 6 bit 5 */
+  bool EncServ:1;                                   /* Byte 6 bit 6 */
+  bool BQue:1;                                      /* Byte 6 bit 7 */
 #else
-  boolean BQue:1;                                      /* Byte 6 bit 7 */
-  boolean EncServ:1;                                   /* Byte 6 bit 6 */
-  boolean VS:1;                                        /* Byte 6 bit 5 */
-  boolean MultiP:1;                                    /* Byte 6 bit 4 */
-  boolean MChngr:1; /* Media Changer */                /* Byte 6 bit 3 */
-  boolean Obs6_2:1; /* obsolete */                     /* Byte 6 bit 2 */
-  boolean Obs6_1:1;                                    /* Byte 6 bit 1 */
-  boolean ADDR16:1;                                    /* Byte 6 bit 0 */
+  bool BQue:1;                                      /* Byte 6 bit 7 */
+  bool EncServ:1;                                   /* Byte 6 bit 6 */
+  bool VS:1;                                        /* Byte 6 bit 5 */
+  bool MultiP:1;                                    /* Byte 6 bit 4 */
+  bool MChngr:1; /* Media Changer */                /* Byte 6 bit 3 */
+  bool Obs6_2:1; /* obsolete */                     /* Byte 6 bit 2 */
+  bool Obs6_1:1;                                    /* Byte 6 bit 1 */
+  bool ADDR16:1;                                    /* Byte 6 bit 0 */
 #endif
 #ifdef LITTLE_ENDIAN_BITFIELDS
-  boolean SftRe:1;					/* Byte 7 Bit 0 */
-  boolean CmdQue:1;					/* Byte 7 Bit 1 */
-  boolean :1;						/* Byte 7 Bit 2 */
-  boolean Linked:1;					/* Byte 7 Bit 3 */
-  boolean Sync:1;					/* Byte 7 Bit 4 */
-  boolean WBus16:1;					/* Byte 7 Bit 5 */
-  boolean WBus32:1;					/* Byte 7 Bit 6 */
-  boolean RelAdr:1;					/* Byte 7 Bit 7 */
+  bool SftRe:1;					/* Byte 7 Bit 0 */
+  bool CmdQue:1;					/* Byte 7 Bit 1 */
+  bool :1;						/* Byte 7 Bit 2 */
+  bool Linked:1;					/* Byte 7 Bit 3 */
+  bool Sync:1;					/* Byte 7 Bit 4 */
+  bool WBus16:1;					/* Byte 7 Bit 5 */
+  bool WBus32:1;					/* Byte 7 Bit 6 */
+  bool RelAdr:1;					/* Byte 7 Bit 7 */
 #else
-  boolean RelAdr:1;					/* Byte 7 Bit 7 */
-  boolean WBus32:1;					/* Byte 7 Bit 6 */
-  boolean WBus16:1;					/* Byte 7 Bit 5 */
-  boolean Sync:1;					/* Byte 7 Bit 4 */
-  boolean Linked:1;					/* Byte 7 Bit 3 */
-  boolean :1;						/* Byte 7 Bit 2 */
-  boolean CmdQue:1;					/* Byte 7 Bit 1 */
-  boolean SftRe:1;					/* Byte 7 Bit 0 */
+  bool RelAdr:1;					/* Byte 7 Bit 7 */
+  bool WBus32:1;					/* Byte 7 Bit 6 */
+  bool WBus16:1;					/* Byte 7 Bit 5 */
+  bool Sync:1;					/* Byte 7 Bit 4 */
+  bool Linked:1;					/* Byte 7 Bit 3 */
+  bool :1;						/* Byte 7 Bit 2 */
+  bool CmdQue:1;					/* Byte 7 Bit 1 */
+  bool SftRe:1;					/* Byte 7 Bit 0 */
 #endif
   unsigned char VendorIdentification[8];		/* Bytes 8-15 */
   unsigned char ProductIdentification[16];		/* Bytes 16-31 */
@@ -319,22 +315,22 @@ typedef struct RequestSense
 {
 #ifdef LITTLE_ENDIAN_BITFIELDS
   unsigned char ErrorCode:7;				/* Byte 0 Bits 0-6 */
-  boolean Valid:1;					/* Byte 0 Bit 7 */
+  bool Valid:1;					/* Byte 0 Bit 7 */
 #else
-  boolean Valid:1;					/* Byte 0 Bit 7 */
+  bool Valid:1;					/* Byte 0 Bit 7 */
   unsigned char ErrorCode:7;				/* Byte 0 Bits 0-6 */
 #endif
   unsigned char SegmentNumber;				/* Byte 1 */
 #ifdef LITTLE_ENDIAN_BITFIELDS
   unsigned char SenseKey:4;				/* Byte 2 Bits 0-3 */
   unsigned char :1;					/* Byte 2 Bit 4 */
-  boolean ILI:1;					/* Byte 2 Bit 5 */
-  boolean EOM:1;					/* Byte 2 Bit 6 */
-  boolean Filemark:1;					/* Byte 2 Bit 7 */
+  bool ILI:1;					/* Byte 2 Bit 5 */
+  bool EOM:1;					/* Byte 2 Bit 6 */
+  bool Filemark:1;					/* Byte 2 Bit 7 */
 #else
-  boolean Filemark:1;					/* Byte 2 Bit 7 */
-  boolean EOM:1;					/* Byte 2 Bit 6 */
-  boolean ILI:1;					/* Byte 2 Bit 5 */
+  bool Filemark:1;					/* Byte 2 Bit 7 */
+  bool EOM:1;					/* Byte 2 Bit 6 */
+  bool ILI:1;					/* Byte 2 Bit 5 */
   unsigned char :1;					/* Byte 2 Bit 4 */
   unsigned char SenseKey:4;				/* Byte 2 Bits 0-3 */
 #endif
@@ -346,15 +342,15 @@ typedef struct RequestSense
   unsigned char :8;					/* Byte 14 */
 #ifdef LITTLE_ENDIAN_BITFIELDS
   unsigned char BitPointer:3;                           /* Byte 15 */
-  boolean BPV:1;
+  bool BPV:1;
   unsigned char :2;
-  boolean CommandData :1;
-  boolean SKSV:1;      
+  bool CommandData :1;
+  bool SKSV:1;
 #else
-  boolean SKSV:1;      
-  boolean CommandData :1;
+  bool SKSV:1;
+  bool CommandData :1;
   unsigned char :2;
-  boolean BPV:1;
+  bool BPV:1;
   unsigned char BitPointer:3;                           /* Byte 15 */
 #endif
   unsigned char FieldData[2];       	 		/* Byte 16,17 */
@@ -436,11 +432,11 @@ typedef struct ElementStatusPage
   ElementTypeCode_T ElementTypeCode:8;			/* Byte 0 */
 #ifdef LITTLE_ENDIAN_BITFIELDS
   unsigned char :6;					/* Byte 1 Bits 0-5 */
-  boolean AVolTag:1;					/* Byte 1 Bit 6 */
-  boolean PVolTag:1;					/* Byte 1 Bit 7 */
+  bool AVolTag:1;					/* Byte 1 Bit 6 */
+  bool PVolTag:1;					/* Byte 1 Bit 7 */
 #else
-  boolean PVolTag:1;					/* Byte 1 Bit 7 */
-  boolean AVolTag:1;					/* Byte 1 Bit 6 */
+  bool PVolTag:1;					/* Byte 1 Bit 7 */
+  bool AVolTag:1;					/* Byte 1 Bit 6 */
   unsigned char :6;					/* Byte 1 Bits 0-5 */
 #endif
   unsigned char ElementDescriptorLength[2];		/* Bytes 2-3 */
@@ -467,15 +463,15 @@ typedef struct TransportElementDescriptorShort
 {
   unsigned char ElementAddress[2];			/* Bytes 0-1 */
 #ifdef LITTLE_ENDIAN_BITFIELDS
-  boolean Full:1;					/* Byte 2 Bit 0 */
+  bool Full:1;					/* Byte 2 Bit 0 */
   unsigned char :1;					/* Byte 2 Bit 1 */
-  boolean Except:1;					/* Byte 2 Bit 2 */
+  bool Except:1;					/* Byte 2 Bit 2 */
   unsigned char :5;					/* Byte 2 Bits 3-7 */
 #else
   unsigned char :5;					/* Byte 2 Bits 3-7 */
-  boolean Except:1;					/* Byte 2 Bit 2 */
+  bool Except:1;					/* Byte 2 Bit 2 */
   unsigned char :1;					/* Byte 2 Bit 1 */
-  boolean Full:1;					/* Byte 2 Bit 0 */
+  bool Full:1;					/* Byte 2 Bit 0 */
 #endif
   unsigned char :8;					/* Byte 3 */
   unsigned char AdditionalSenseCode;			/* Byte 4 */
@@ -485,11 +481,11 @@ typedef struct TransportElementDescriptorShort
   unsigned char :8;					/* Byte 8 */
 #ifdef LITTLE_ENDIAN_BITFIELDS
   unsigned char :6;					/* Byte 9 Bits 0-5 */
-  boolean SValid:1;					/* Byte 9 Bit 6 */
-  boolean Invert:1;					/* Byte 9 Bit 7 */
+  bool SValid:1;					/* Byte 9 Bit 6 */
+  bool Invert:1;					/* Byte 9 Bit 7 */
 #else
-  boolean Invert:1;					/* Byte 9 Bit 7 */
-  boolean SValid:1;					/* Byte 9 Bit 6 */
+  bool Invert:1;					/* Byte 9 Bit 7 */
+  bool SValid:1;					/* Byte 9 Bit 6 */
   unsigned char :6;					/* Byte 9 Bits 0-5 */
 #endif
   unsigned char SourceStorageElementAddress[2];		/* Bytes 10-11 */
@@ -504,15 +500,15 @@ typedef struct TransportElementDescriptor
 {
   unsigned char ElementAddress[2];			/* Bytes 0-1 */
 #ifdef LITTLE_ENDIAN_BITFIELDS
-  boolean Full:1;					/* Byte 2 Bit 0 */
+  bool Full:1;					/* Byte 2 Bit 0 */
   unsigned char :1;					/* Byte 2 Bit 1 */
-  boolean Except:1;					/* Byte 2 Bit 2 */
+  bool Except:1;					/* Byte 2 Bit 2 */
   unsigned char :5;					/* Byte 2 Bits 3-7 */
 #else
   unsigned char :5;					/* Byte 2 Bits 3-7 */
-  boolean Except:1;					/* Byte 2 Bit 2 */
+  bool Except:1;					/* Byte 2 Bit 2 */
   unsigned char :1;					/* Byte 2 Bit 1 */
-  boolean Full:1;					/* Byte 2 Bit 0 */
+  bool Full:1;					/* Byte 2 Bit 0 */
 #endif
   unsigned char :8;					/* Byte 3 */
   unsigned char AdditionalSenseCode;			/* Byte 4 */
@@ -522,20 +518,20 @@ typedef struct TransportElementDescriptor
   unsigned char :8;					/* Byte 8 */
 #ifdef LITTLE_ENDIAN_BITFIELDS
   unsigned char :6;					/* Byte 9 Bits 0-5 */
-  boolean SValid:1;					/* Byte 9 Bit 6 */
-  boolean Invert:1;					/* Byte 9 Bit 7 */
+  bool SValid:1;					/* Byte 9 Bit 6 */
+  bool Invert:1;					/* Byte 9 Bit 7 */
 #else
-  boolean Invert:1;					/* Byte 9 Bit 7 */
-  boolean SValid:1;					/* Byte 9 Bit 6 */
+  bool Invert:1;					/* Byte 9 Bit 7 */
+  bool SValid:1;					/* Byte 9 Bit 6 */
   unsigned char :6;					/* Byte 9 Bits 0-5 */
 #endif
   unsigned char SourceStorageElementAddress[2];		/* Bytes 10-11 */
   unsigned char PrimaryVolumeTag[36];          /* barcode */
-  unsigned char AlternateVolumeTag[36];   
+  unsigned char AlternateVolumeTag[36];
 #ifdef HAS_LONG_DESCRIPTORS
   unsigned char Reserved[4];				/* 4 extra bytes? */
 #endif
-     
+
 }
 TransportElementDescriptor_T;
 
@@ -558,12 +554,12 @@ typedef struct ElementStatus {
   barcode *PrimaryVolumeTag;  /* array */
   barcode *AlternateVolumeTag; /* array */
   int *StorageElementAddress; /* array */
-  boolean *StorageElementIsImportExport; /* array */
+  bool *StorageElementIsImportExport; /* array */
 
   int TransportElementAddress;  /* assume only one of those... */
 
-  boolean *DataTransferElementFull; /* array */
-  boolean *StorageElementFull;  /* array */
+  bool *DataTransferElementFull; /* array */
+  bool *StorageElementFull;  /* array */
 
 } ElementStatus_T;
 
@@ -577,7 +573,7 @@ typedef struct scsi_id {
 #define MEDIUM_CHANGER_TYPE 8  /* what type bits are set for medium changers. */
 
 /* The following two structs are used for the brain-dead functions of the
- * NSM jukebox. 
+ * NSM jukebox.
  */
 
 typedef struct NSM_Param {
@@ -592,7 +588,7 @@ typedef struct NSM_Param {
   unsigned char command_params[2048]; /* egregious overkill. */
 } NSM_Param_T;
 
-extern RequestSense_T scsi_error_sense; 
+extern RequestSense_T scsi_error_sense;
 
 typedef struct NSM_Result {
   unsigned char page_code;
@@ -600,7 +596,7 @@ typedef struct NSM_Result {
   unsigned char page_len_msb;
   unsigned char page_len_lsb;
   unsigned char command_code[4];
-  unsigned char ces_code[2]; 
+  unsigned char ces_code[2];
   unsigned char return_data[0xffff]; /* egregioius overkill */
 } NSM_Result_T;
 
