--- lib/expat.h.orig	Fri Jan 17 07:03:42 2003
+++ lib/expat.h	Thu Feb  6 10:19:21 2003
@@ -57,6 +57,26 @@
 #define XML_TRUE   ((XML_Bool) 1)
 #define XML_FALSE  ((XML_Bool) 0)
 
+/* The XML_Status enum gives the possible return values for several
+   API functions.  The preprocessor #defines are included so this
+   stanza can be added to code that still needs to support older
+   versions of Expat 1.95.x:
+
+   #ifndef XML_STATUS_OK
+   #define XML_STATUS_OK    1
+   #define XML_STATUS_ERROR 0
+   #endif
+
+   Otherwise, the #define hackery is quite ugly and would have been
+   dropped.
+*/
+enum XML_Status {
+  XML_STATUS_ERROR = 0,
+#define XML_STATUS_ERROR XML_STATUS_ERROR
+  XML_STATUS_OK = 1
+#define XML_STATUS_OK XML_STATUS_OK
+};
+
 enum XML_Error {
   XML_ERROR_NONE,
   XML_ERROR_NO_MEMORY,
@@ -717,28 +737,11 @@
    detected.  The last call to XML_Parse must have isFinal true; len
    may be zero for this call (or any other).
 
-   The XML_Status enum gives the possible return values for the
-   XML_Parse and XML_ParseBuffer functions.  Though the return values
-   for these functions has always been described as a Boolean value,
-   the implementation, at least for the 1.95.x series, has always
-   returned exactly one of these values.  The preprocessor #defines
-   are included so this stanza can be added to code that still needs
-   to support older versions of Expat 1.95.x:
-
-   #ifndef XML_STATUS_OK
-   #define XML_STATUS_OK    1
-   #define XML_STATUS_ERROR 0
-   #endif
-
-   Otherwise, the #define hackery is quite ugly and would have been dropped.
+   Though the return values for these functions has always been
+   described as a Boolean value, the implementation, at least for the
+   1.95.x series, has always returned exactly one of the XML_Status
+   values.
 */
-enum XML_Status {
-  XML_STATUS_ERROR = 0,
-#define XML_STATUS_ERROR XML_STATUS_ERROR
-  XML_STATUS_OK = 1
-#define XML_STATUS_OK XML_STATUS_OK
-};
-
 XMLPARSEAPI(enum XML_Status)
 XML_Parse(XML_Parser parser, const char *s, int len, int isFinal);
 
