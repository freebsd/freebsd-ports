*** src/drivers/usb/bsd/hidutils.c.orig	Fri Apr 22 02:28:40 2005
--- src/drivers/usb/bsd/hidutils.c	Sun Jul  3 13:02:26 2005
***************
*** 327,333 ****
      req.ucr_actlen = 0;
      req.ucr_addr = 0;
      req.ucr_data = data;
!     req.ucr_request.bmRequestType = UT_WRITE_CLASS_ENDPOINT;
      req.ucr_request.bRequest = UR_SET_REPORT;
      USETW(req.ucr_request.wValue, ((item->kind+1) << 8) | item->report_ID);
      USETW(req.ucr_request.wIndex, 0);
--- 327,333 ----
      req.ucr_actlen = 0;
      req.ucr_addr = 0;
      req.ucr_data = data;
!     req.ucr_request.bmRequestType = UT_WRITE_CLASS_INTERFACE;
      req.ucr_request.bRequest = UR_SET_REPORT;
      USETW(req.ucr_request.wValue, ((item->kind+1) << 8) | item->report_ID);
      USETW(req.ucr_request.wIndex, 0);
