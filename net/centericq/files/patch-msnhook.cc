--- src/hooks/msnhook.cc.orig	Mon Oct  6 01:01:52 2003
+++ src/hooks/msnhook.cc	Mon Oct  6 01:05:37 2003
@@ -248,7 +248,8 @@
     }
 
     icqcontact *c = clist.get(ev.getcontact());
-    text = siconv(text, conf.getrussian(msn) ? "koi8-u" : conf.getdefcharset(), "utf8");
+//    text = siconv(text, conf.getrussian(msn) ? "koi8-u" : conf.getdefcharset(), "utf8");
+    text = StrToUtf8(text);
 
     if(c)
     if(c->getstatus() != offline || !c->inlist()) {
@@ -378,11 +379,11 @@
 
 void msnhook::checkfriendly(icqcontact *c, const string friendlynick, bool forcefetch) {
     string oldnick = c->getnick();
-    string newnick = unmime(friendlynick);
+    string newnick = Utf8ToStr(unmime(friendlynick));
 
     c->setnick(newnick);
 
-    if(forcefetch || (oldnick != newnick && c->getdispnick() == oldnick) || oldnick.empty()) {
+    if(forcefetch || (oldnick != newnick && c->getdispnick() != oldnick) || oldnick.empty()) {
 	c->setdispnick(newnick);
 	face.relaxedupdate();
     }
@@ -602,7 +603,8 @@
 
     mhook.checkinlist(ic);
 
-    string text = siconv(msg->body, "utf8", conf.getrussian(msn) ? "koi8-u" : conf.getdefcharset());
+//    string text = siconv(msg->body, "utf8", conf.getrussian(msn) ? "koi8-u" : conf.getdefcharset());
+    string text = Utf8ToStr(msg->body);
     em.store(immessage(ic, imevent::incoming, text));
 }
 
@@ -779,5 +781,139 @@
 	log(string("[OUT] ") + buf);
     }
 }
+
+#if HAVE_ICONV_H
+int safe_iconv( iconv_t handle, const char **inbuf, size_t *inbytesleft,
+            char **outbuf, size_t *outbytesleft)
+{
+    int ret;
+    while (*inbytesleft) {
+        ret = iconv( handle, inbuf, inbytesleft,
+               outbuf, outbytesleft);
+       if (!*inbytesleft || !*outbytesleft)
+           return ret;
+       /*got invalid seq - so replace it with '?' */
+       **outbuf = '?'; (*outbuf)++; (*outbytesleft)--;
+       (*inbuf)++; (*inbytesleft)--;
+    }
+    return ret;
+}
+
+const char* guess_current_locale_charset()
+{
+    char *lang, *ch;
+    /* Return previously learned charset */
+    if (loc_charset[0])
+       return loc_charset;
+
+    lang = getenv("LANG");
+    if (!lang) {
+       strcpy( loc_charset, DEFAULT_CHARSET );
+       return loc_charset;
+    };
+    ch = strrchr( lang, '.' );
+    if (!ch)
+       strcpy( loc_charset, DEFAULT_CHARSET );
+    else {
+       iconv_t pt;
+       ch++;
+       strncpy( loc_charset, ch, sizeof(loc_charset) );
+       /* try to open iconv handle using guessed charset */
+       if ( (pt = iconv_open( loc_charset, loc_charset )) == (iconv_t)(-1) )
+       {
+           strcpy( loc_charset, DEFAULT_CHARSET );
+       } else {
+           iconv_close(pt);
+       };
+
+    }
+
+    return loc_charset;
+}
+
+char *StrToUtf8( const char *inbuf )
+{
+    size_t length = strlen( inbuf );
+    size_t outmaxlength = UTF8_BUF_LENGTH;
+    char *outbuf = utf8_buf;
+    char *outbuf_save = outbuf;
+    int ret;
+
+    iconv_t handle = iconv_open( "utf-8", guess_current_locale_charset() );
+    if(((int) handle) != -1) {
+       ret = safe_iconv( handle, (const char **) &inbuf, &length, &outbuf, &outmaxlength );
+
+       *outbuf = '\0';
+       iconv_close( handle );
+       return outbuf_save;
+    } else {
+       return (char *)inbuf;
+    };
+}
+
+std::string StrToUtf8( const std::string &instr )
+{
+    size_t length = instr.length();
+    size_t outmaxlength = UTF8_BUF_LENGTH;
+    const char *inbuf = instr.c_str();
+    char *outbuf = utf8_buf;
+    char *outbuf_save = outbuf;
+    int ret;
+
+    iconv_t handle = iconv_open( "utf-8", guess_current_locale_charset() );
+    if(((int) handle) != -1) {
+       ret = safe_iconv( handle, (const char **) &inbuf, &length, &outbuf, &outmaxlength );
+
+       *outbuf = '\0';
+       iconv_close( handle );
+
+       std::string return_me = outbuf_save;
+       return return_me;
+    } else {
+       return instr;
+    };
+}
+
+char *Utf8ToStr( const char *inbuf )
+{
+    size_t length = strlen( inbuf );
+    size_t outmaxlength = UTF8_BUF_LENGTH / 4;
+    char *outbuf = utf8_buf;
+    char *outbuf_save = outbuf;
+    int ret;
+
+    iconv_t handle = iconv_open( guess_current_locale_charset(), "utf-8" );
+    if(((int) handle) != -1) {
+       ret = safe_iconv( handle, (const char **) &inbuf, &length, &outbuf, &outmaxlength );
+       *outbuf = '\0';
+       iconv_close( handle );
+       return outbuf_save;
+    } else {
+       return (char *)inbuf;
+    };
+}
+
+std::string Utf8ToStr( const std::string &instr )
+{
+    size_t length = instr.length();
+    const char *inbuf = instr.c_str();
+    size_t outmaxlength = UTF8_BUF_LENGTH / 4;
+    char *outbuf = utf8_buf;
+    char *outbuf_save = outbuf;
+    int ret;
+
+    iconv_t handle = iconv_open( guess_current_locale_charset(), "utf-8" );
+
+    if(((int) handle) != -1) {
+       ret = safe_iconv( handle, (const char **) &inbuf, &length, &outbuf, &outmaxlength );
+       *outbuf = '\0';
+       iconv_close( handle );
+       std::string return_me = outbuf_save;
+       return return_me;
+    } else {
+       return instr;
+    };
+}
+#endif /* HAVE_ICONV_H */
 
 #endif
