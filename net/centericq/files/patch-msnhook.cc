--- src/hooks/msnhook.cc	Tue Nov 19 10:18:22 2002
+++ src/hooks/msnhook.cc	Tue Nov 19 10:18:35 2002
@@ -30,6 +30,7 @@
 #include "eventmanager.h"
 #include "centericq.h"
 #include "imlogger.h"
+#include "utf8conv.h"
 
 msnhook mhook;
 
@@ -159,7 +160,8 @@
     }
 
     icqcontact *c = clist.get(ev.getcontact());
-    text = siconv(text, conf.getrussian() ? "koi8-u" : DEFAULT_CHARSET, "utf8");
+    text = StrToUtf8(text);
+//    text = siconv(text, conf.getrussian() ? "koi8-u" : DEFAULT_CHARSET, "utf8");
 //    text = toutf8(rusconv("kw", text));
 
     if(c)
@@ -274,8 +276,8 @@
 	m.homepage = "http://members.msn.com/" + b.email;
 
 	if(!friendlynicks[ic.nickname].empty()) {
-	    c->setdispnick(friendlynicks[ic.nickname]);
-	    b.fname = friendlynicks[ic.nickname];
+	    c->setdispnick(Utf8ToStr(friendlynicks[ic.nickname]));
+	    b.fname = Utf8ToStr(friendlynicks[ic.nickname]);
 	}
 
 	c->setbasicinfo(b);
@@ -371,7 +373,8 @@
 	}
 
 //        text = rusconv("wk", fromutf8(d->msg));
-	text = siconv(d->msg, "utf8", conf.getrussian() ? "koi8-u" : DEFAULT_CHARSET);
+//	text = siconv(d->msg, "utf8", conf.getrussian() ? "koi8-u" : DEFAULT_CHARSET);
+	text = Utf8ToStr(d->msg);
 	em.store(immessage(ic, imevent::incoming, text));
 
 	if(c)
@@ -453,3 +456,117 @@
 	clist.get(contactroot)->playsound(imevent::email);
     }
 }
+#if HAVE_ICONV_H
+int safe_iconv( iconv_t handle, const char **inbuf, size_t *inbytesleft,
+	     char **outbuf, size_t *outbytesleft)
+{
+    int ret;
+    while (*inbytesleft) {
+	 ret = iconv( handle, inbuf, inbytesleft,
+		outbuf, outbytesleft);
+	if (!*inbytesleft || !*outbytesleft)
+	    return ret;
+	/*got invalid seq - so replace it with '?' */
+	**outbuf = '?'; (*outbuf)++; (*outbytesleft)--;
+	(*inbuf)++; (*inbytesleft)--;
+    }
+    return ret;
+}
+
+const char* guess_current_locale_charset()
+{
+    char *lang, *ch;
+    /* Return previously learned charset */
+    if (loc_charset[0])
+	return loc_charset;
+
+    lang = getenv("LANG");
+    ch = strrchr( lang, '.' ) + 1;
+    if (!ch)
+	strcpy( loc_charset, DEFAULT_CHARSET );
+    else {
+	iconv_t pt;
+	strncpy( loc_charset, ch, sizeof(loc_charset) );
+	/* try to open iconv handle using guessed charset */
+	if ( (pt = iconv_open( loc_charset, loc_charset )) == (iconv_t)(-1) )
+	{
+	    strcpy( loc_charset, DEFAULT_CHARSET );
+	} else {
+	    iconv_close(pt);
+	};
+	
+    }
+
+    return loc_charset;
+}
+
+char *StrToUtf8( const char *inbuf )
+{
+    size_t length = strlen( inbuf );
+    size_t outmaxlength = length * 4; /* FIXME: Is x4 multiplier enoght? */
+    char *outbuf = (char*) malloc( outmaxlength + 1 );
+    char *outbuf_save = outbuf;
+    int ret;
+
+    iconv_t handle = iconv_open( "utf-8", guess_current_locale_charset() );
+    ret = safe_iconv( handle, (const char **) &inbuf, &length, &outbuf, &outmaxlength );
+    
+    iconv_close( handle );
+
+    return outbuf_save;
+}
+ 
+std::string StrToUtf8( const std::string &instr )
+{
+    size_t length = instr.length();
+    size_t outmaxlength = length * 4; /* FIXME: Is x4 multiplier enoght? */
+    const char *inbuf = instr.c_str();
+    char *outbuf = (char*) malloc( outmaxlength + 1 );
+    char *outbuf_save = outbuf;
+    int ret;
+
+    iconv_t handle = iconv_open( "utf-8", guess_current_locale_charset() );
+    ret = safe_iconv( handle, (const char **) &inbuf, &length, &outbuf, &outmaxlength );
+    
+    iconv_close( handle );
+
+    std::string return_me = outbuf_save;
+    return return_me;
+}
+ 
+char *Utf8ToStr( const char *inbuf )
+{
+    size_t length = strlen( inbuf );
+    size_t outmaxlength = length;
+    char *outbuf = (char*) malloc( outmaxlength + 1 );
+    char *outbuf_save = outbuf;
+    int ret;
+
+    iconv_t handle = iconv_open( guess_current_locale_charset(), "utf-8" );
+
+    ret = safe_iconv( handle, (const char **) &inbuf, &length, &outbuf, &outmaxlength );
+    
+    iconv_close( handle );
+
+    return outbuf_save;
+}
+
+std::string Utf8ToStr( const std::string &instr )
+{
+    size_t length = instr.length();
+    size_t outmaxlength = length;
+    const char *inbuf = instr.c_str();
+    char *outbuf = (char*) malloc( outmaxlength + 1 );
+    char *outbuf_save = outbuf;
+    int ret;
+
+    iconv_t handle = iconv_open( guess_current_locale_charset(), "utf-8" );
+
+    ret = safe_iconv( handle, (const char **) &inbuf, &length, &outbuf, &outmaxlength );
+
+    iconv_close( handle );
+
+    std::string return_me = outbuf_save;
+    return return_me;
+}
+#endif /* HAVE_ICONV_H */
