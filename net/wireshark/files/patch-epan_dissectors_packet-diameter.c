diff -ruN ethereal.orig/files/patch-packet-diameter.c ethereal/files/patch-packet-diameter.c
--- ethereal.orig/files/patch-packet-diameter.c	Thu Jan  1 03:00:00 1970
+++ ethereal/files/patch-packet-diameter.c	Thu May 12 03:30:32 2005
@@ -0,0 +1,19 @@
+--- epan/dissectors/packet-diameter.c.orig	Thu May 12 03:07:06 2005
++++ epan/dissectors/packet-diameter.c	Thu May 12 02:54:14 2005
+@@ -2022,13 +2022,13 @@
+ 		  { "Flags", "diameter.flags", FT_UINT8, BASE_HEX, NULL, 0x0,
+ 		    "", HFILL }},
+ 		{ &hf_diameter_flags_request,
+-		  { "Request", "diameter.flags.request", FT_BOOLEAN, 8, TFS(&flags_set_truth), DIAM_FLAGS_R,
++		  { "Request ", "diameter.flags.request", FT_BOOLEAN, 8, TFS(&flags_set_truth), DIAM_FLAGS_R,
+ 			"", HFILL }},
+ 		{ &hf_diameter_flags_proxyable,
+-		  { "Proxyable", "diameter.flags.proxyable", FT_BOOLEAN, 8, TFS(&flags_set_truth), DIAM_FLAGS_P,
++		  { "Proxyable ", "diameter.flags.proxyable", FT_BOOLEAN, 8, TFS(&flags_set_truth), DIAM_FLAGS_P,
+ 			"", HFILL }},
+ 		{ &hf_diameter_flags_error,
+-		  { "Error","diameter.flags.error", FT_BOOLEAN, 8, TFS(&flags_set_truth), DIAM_FLAGS_E,
++		  { "Error ","diameter.flags.error", FT_BOOLEAN, 8, TFS(&flags_set_truth), DIAM_FLAGS_E,
+ 			"", HFILL }},
+ 		{ &hf_diameter_flags_T,
+ 		  { "T(Potentially re-transmitted message)","diameter.flags.T", FT_BOOLEAN, 8, TFS(&flags_set_truth),DIAM_FLAGS_T,
