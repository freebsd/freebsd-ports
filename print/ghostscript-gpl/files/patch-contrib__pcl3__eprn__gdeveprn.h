--- contrib/pcl3/eprn/gdeveprn.h.orig	Thu Apr 26 01:33:54 2007
+++ contrib/pcl3/eprn/gdeveprn.h	Tue May 15 02:03:02 2007
@@ -396,8 +396,8 @@
 struct s_eprn_Device;
  /* The preceding statement is needed in order to establish a forward
     declaration for "struct s_eprn_Device" at file scope. */
-typedef void (*eprn_FlagMismatchReporter)(FILE *f,
-  const struct s_eprn_Device *dev, bool no_match);
+typedef void (*eprn_FlagMismatchReporter)(const struct s_eprn_Device *dev,
+		bool no_match);
 /*  A function of this kind will be called if the requested media flags cannot
     be satisfied by the printer although the size itself is supported for some
     (unspecified) set of flags. The parameter 'no_match' indicates whether the
@@ -406,7 +406,7 @@
     capabilities). The requested set of media selection flags is available in
     'dev->eprn.desired_flags' and 'dev->eprn.optional_flags' (MS_ROTATED_FLAG
     will never be set).
-    The function must write an error message on 'f'.
+    The function must write an error message.
 */
 
 /*****************************************************************************/
