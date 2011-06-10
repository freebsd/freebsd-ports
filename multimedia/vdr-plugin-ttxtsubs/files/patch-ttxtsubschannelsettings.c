--- a/ttxtsubschannelsettings.c
+++ b/ttxtsubschannelsettings.c
@@ -34,10 +34,19 @@ cTtxtSubsChannelSetting::cTtxtSubsChanne
 bool cTtxtSubsChannelSetting::Parse(const char *s)
 {
    bool result=false;
+#ifdef __FreeBSD__
+   char *buffer=MALLOC(char, 256);
+#else
    char *buffer=NULL;
+#endif
    int PageMode;
    int PageNumber;
-   if (3 == sscanf(s, "%a[^,],%d,%d\n", &buffer, &PageMode, &PageNumber)) {
+#ifdef __FreeBSD__
+   if (3 == sscanf(s, "%255[^,],%d,%d\n", buffer, &PageMode, &PageNumber))
+#else
+   if (3 == sscanf(s, "%a[^,],%d,%d\n", &buffer, &PageMode, &PageNumber))
+#endif
+   {
       tChannelID channelID=tChannelID::FromString(buffer);
       if (channelID.Valid()) {
         channelid=channelID;
