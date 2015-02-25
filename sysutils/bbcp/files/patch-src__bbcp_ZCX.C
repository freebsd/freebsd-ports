--- src/bbcp_ZCX.C.orig	2015-01-16 12:06:04.000000000 -0800
+++ src/bbcp_ZCX.C	2015-01-16 12:06:59.000000000 -0800
@@ -144,7 +144,7 @@
 
 // If we have gotten here then all went well so far flush output
 //
-   if (obp->blen = outsz - ZStream.avail_out)
+   if ((obp->blen = outsz - ZStream.avail_out))
       {obp->boff = outbytes; outbytes += obp->blen;
        Obuff->putFullBuff(obp);
        if (!(obp = Obuff->getEmptyBuff())) return ENOBUFS;
