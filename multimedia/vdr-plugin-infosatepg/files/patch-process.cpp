--- a/process.cpp
+++ b/process.cpp
@@ -1047,7 +1047,9 @@ bool cProcessInfosatepg::ParseInfosatepg
     int ieventnr=1;
     cChannel *chan=NULL;
     cInfosatevent *ievent=NULL;
-#if VDRVERSNUM < 10701
+// XXX don't default to assuming UTF-8 on FreeBSD (that's what the NULL does),
+// its still often used without.
+#if VDRVERSNUM < 10701 || defined(__FreeBSD__)
     cCharSetConv *conv = new cCharSetConv("ISO-8859-1",cCharSetConv::SystemCharacterTable() ?
                                           cCharSetConv::SystemCharacterTable() : "UTF-8");
 #else
@@ -1139,7 +1141,12 @@ bool cProcessInfosatepg::ParseInfosatepg
             }
             int shour,sminute;
             char *title;
+#ifdef __FreeBSD__
+            title = (char *)malloc(strlen(s));
+            fields=sscanf(s,"%d:%d %[^^]",&shour,&sminute,title);
+#else
             fields=sscanf(s,"%d:%d %a[^^]",&shour,&sminute,&title);
+#endif
             if (fields==3)
             {
                 if (!ievent) ievent = new cInfosatevent;
