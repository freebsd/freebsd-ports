Remove unsupported sysfs-dependent parts from manpage.

--- man/hid-decode.md.orig	2019-03-29 01:29:29 UTC
+++ man/hid-decode.md
@@ -11,8 +11,6 @@ SYNOPSIS
 
 **hid-decode** */dev/hidraw0*
 
-**hid-decode** */dev/input/event0*
-
 **hid-decode** *hid-recording*
 
 DESCRIPTION
@@ -20,11 +18,8 @@ DESCRIPTION
 **hid-decode** decodes one or more HID report descriptors into into
 human-readable format. It supports a variety of inputs:
 
-- a binary format as exported in sysfs, e.g.
-  _/sys/class/input/event0/device/device/report_descriptor_
 - the format exported by **hid-recorder(1)**
 - a _/dev/hidraw_ node
-- a _/dev/input/event_ node
 
 The format is deduced based on the input arguments. Undetected formats are
 assumed to be binary files.
