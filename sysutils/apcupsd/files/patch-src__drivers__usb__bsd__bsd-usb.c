--- ./src/drivers/usb/bsd/bsd-usb.c.orig	2007-10-27 20:15:14.000000000 +0300
+++ ./src/drivers/usb/bsd/bsd-usb.c	2008-03-29 20:21:50.000000000 +0200
@@ -351,9 +351,9 @@
 
 int pusb_ups_get_capabilities(UPSINFO *ups, const struct s_known_info *known_info)
 {
-   int i, rc, ci, phys;
+   int i, ci, phys, input, feature;
    USB_DATA *my_data = (USB_DATA *)ups->driver_internal_data;
-   hid_item_t item;
+   hid_item_t item, witem;
    USB_INFO *info;
 
    write_lock(ups);
@@ -506,7 +506,7 @@
 
       // Store a (possibly truncated) copy of the floating point value in the
       // integer field as well.
-      val.iValue = val.dValue;
+      val.iValue = (int) val.dValue;
 
       Dmsg4(200, "Def val=%d exp=%d dVal=%f ci=%d\n", info->value,
          exponent, val.dValue, info->ci);
@@ -775,7 +775,7 @@
    return true;
 }
 
-int pusb_write_int_to_ups(UPSINFO *ups, int ci, int value, char *name)
+int pusb_write_int_to_ups(UPSINFO *ups, int ci, int value, const char *name)
 {
    USB_DATA *my_data = (USB_DATA *)ups->driver_internal_data;
    USB_INFO *info;
