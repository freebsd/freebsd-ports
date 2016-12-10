--- sub/spudec.c.orig	2016-11-30 00:23:04 UTC
+++ sub/spudec.c
@@ -861,7 +861,7 @@ static void sws_spu_image(unsigned char
 		oldvar = spu_gaussvar;
 	}

-	ctx=sws_getContext(sw, sh, PIX_FMT_GRAY8, dw, dh, PIX_FMT_GRAY8, SWS_GAUSS, &filter, NULL, NULL);
+	ctx=sws_getContext(sw, sh, AV_PIX_FMT_GRAY8, dw, dh, AV_PIX_FMT_GRAY8, SWS_GAUSS, &filter, NULL, NULL);
 	sws_scale(ctx,&s1,&ss,0,sh,&d1,&ds);
 	for (i=ss*sh-1; i>=0; i--) if (!s2[i]) s2[i] = 255; //else s2[i] = 1;
 	sws_scale(ctx,(const uint8_t **)&s2,&ss,0,sh,&d2,&ds);
