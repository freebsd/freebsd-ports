Index: programs/Xserver/hw/xfree86/drivers/mga/HALlib/binding.h
===================================================================
RCS file: /cvs/xc/programs/Xserver/hw/xfree86/drivers/mga/HALlib/binding.h,v
retrieving revision 1.6
retrieving revision 1.7
diff -u -r1.6 -r1.7
--- programs/Xserver/hw/xfree86/drivers/mga/HALlib/binding.h	31 Mar 2004 16:37:09 -0000	1.6
+++ programs/Xserver/hw/xfree86/drivers/mga/HALlib/binding.h	26 Apr 2005 00:56:44 -0000	1.7
@@ -210,6 +210,8 @@
 #define MGAMODEINFO_FORCE_PITCH        (1L << 5) 
 #define MGAMODEINFO_FORCE_DISPLAYORG   (1L << 6) 
 #define MGAMODEINFO_TV                 (1L << 7)
+#define MGAMODEINFO_FLATPANEL1         (1L << 8)
+#define MGAMODEINFO_FLATPANEL2         (1L << 9)
 #define MGAMODEINFO_TESTONLY           0x80000000
 
 /* Cable Type */
@@ -243,7 +245,8 @@
 ULONG MGAGetBOARDHANDLESize(void);
 ULONG MGASetTVStandard(LPBOARDHANDLE pBoard, ULONG ulTVStandard);
 ULONG MGASetTVCableType(LPBOARDHANDLE pBoard, ULONG ulCableType);
-ULONG MGASetDisplayStart(LPBOARDHANDLE pBoard, ULONG ulX, ULONG ulY, ULONG ulCrtc);
+ULONG MGAForceFlatPanel(LPBOARDHANDLE pBoard);
+ULONG HALSetDisplayStart(LPBOARDHANDLE pBoard, ULONG ulX, ULONG ulY, ULONG ulCrtc);
 
 #if defined(__cplusplus)
     }
