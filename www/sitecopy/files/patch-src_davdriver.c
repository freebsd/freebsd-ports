--- src/davdriver.c.orig	Fri Jan 26 22:21:41 2001
+++ src/davdriver.c	Fri Jan 26 22:21:59 2001
@@ -546,7 +546,7 @@
     dav_propfind_set_flat(ph, flat_props);
 
     /* The complex props. */
-    dav_propfind_set_complex(ph, complex_props, create_private, NULL);
+    dav_propfind_set_complex(ph, complex_props, create_private);
 
     /* Register the handler for the complex props. */
     hip_xml_push_handler(dav_propfind_get_parser(ph), fetch_elms,
