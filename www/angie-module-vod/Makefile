PORTNAME=	angie-module-vod
GH_TUPLE=	kaltura:nginx-vod-module:1.32:module

COMMENT=	VOD dynamic module for Angie

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libswscale.so:multimedia/ffmpeg

MASTERDIR=	${.CURDIR}/../../www/angie

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${MODDIR}

	${INSTALL_LIB} ${WRKSRC}/objs/ngx_http_vod_module.so \
	    ${STAGEDIR}${MODDIR}

	${INSTALL_MAN} ${WRKSRC_module}/README.md ${STAGEDIR}${DOCSDIR}

do-install-DEBUG-on:
	${INSTALL} ${COPY} -m ${_SHAREMODE} \
	    ${WRKSRC_DEBUG}/objs/ngx_http_vod_module.so \
	    ${STAGEDIR}${MODDIR}/ngx_http_vod_module-debug.so

.include "${MASTERDIR}/Makefile"
